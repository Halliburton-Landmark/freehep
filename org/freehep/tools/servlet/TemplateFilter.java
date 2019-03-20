package org.freehep.tools.servlet;

import javax.servlet.*;
import javax.servlet.http.*;
import java.io.*;
import java.util.regex.*;

/**
 * A simple servlet for dealing with .thtml files
 * @author Tony Johnson
 * @version $Id: TemplateFilter.java,v 1.3 2002/07/15 07:06:01 tonyj Exp $
 */
public class TemplateFilter implements Filter
{
   private String template;
   private Matcher templateMatcher;
   private Pattern templatePattern = Pattern.compile("<subst\\s+data\\s*=\\s*\"(.*)\"\\s*/>",Pattern.CASE_INSENSITIVE);
   private Pattern pagePattern = Pattern.compile("<head>(.*)</head>.*<body>(.*)</body>",Pattern.CASE_INSENSITIVE+Pattern.DOTALL);
   /** Initializes the servlet.
    */
   public void init(FilterConfig config) throws ServletException
   {
      String template = config.getInitParameter("template");
      if (template == null) throw new ServletException("No template specified");
      String path = config.getServletContext().getRealPath(template);
      if (path == null) throw new ServletException("Invalid template specified: "+template);
      try
      {
         char[] buffer = new char[1024];
         Reader in = new FileReader(path);
         StringWriter out = new StringWriter();
         for (;;)
         {
            int n = in.read(buffer);
            if (n < 0 ) break;
            out.write(buffer,0,n);
         }
         in.close();
         out.close();
         this.template = out.toString();
         templateMatcher = templatePattern.matcher(this.template);
      }
      catch (IOException x)
      {
         throw new ServletException("Error reading template: "+path);
      }
   }
   
   /** Destroys the servlet.
    */
   public void destroy()
   {
      
   }
   
   public void doFilter(ServletRequest servletRequest, ServletResponse servletResponse, FilterChain filterChain) throws java.io.IOException, javax.servlet.ServletException
   {
      final ByteArrayOutputStream pageBuffer = new ByteArrayOutputStream();
      HttpServletResponseWrapper wrap = new HttpServletResponseWrapper((HttpServletResponse) servletResponse)
      {
         public ServletOutputStream getOutputStream() throws IOException
         {
            return new ServletOutputStream()
            {
               public void write(int i) throws IOException
               {
                  pageBuffer.write((byte) i);
               }
               public void write(byte[] b) throws IOException 
               {
                  pageBuffer.write(b);
               }
               public void write(byte[] b, int off, int len) throws IOException 
               {
                  pageBuffer.write(b, off, len);
               }
            };
         }
         public PrintWriter getWriter() throws IOException
         { 
            return new PrintWriter(getOutputStream(), true); 
         }
         public void setContentLength(int length)
         {
         }
      };
      filterChain.doFilter(servletRequest,wrap);
      
      PrintWriter out = servletResponse.getWriter();
      Matcher match = pagePattern.matcher(pageBuffer.toString());
      boolean ok = match.find();
      if (ok)
      {
         String head = match.group(1);
         String body = match.group(2);
         
         int pos = 0;
         while (templateMatcher.find(pos))
         {
            out.print(template.substring(pos,templateMatcher.start()));
            String group = templateMatcher.group(1);
            if      (group.equalsIgnoreCase("head")) out.print(head);
            else if (group.equalsIgnoreCase("body")) out.print(body);
            pos = templateMatcher.end();
         }
         out.print(template.substring(pos));
      }
      else servletResponse.getWriter().print(pageBuffer);
      out.close();
   }
}
