package org.freehep.tools.servlet;

import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

import java.net.URL;

import javax.servlet.ServletConfig;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerConfigurationException;
import javax.xml.transform.TransformerException;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.stream.StreamSource;

import org.jdom.Document;
import org.jdom.Element;
import org.jdom.JDOMException;
import org.jdom.input.SAXBuilder;
import org.jdom.transform.JDOMResult;
import org.jdom.transform.JDOMSource;


/**
 *
 * @author tonyj
 * @version $Id: RedirectServlet.java,v 1.1 2004/02/02 20:11:51 tonyj Exp $
 */
public class RedirectServlet extends HttpServlet
{
   private Element root;
   private URL configURL;
   
   /** Returns a short description of the servlet.
    */
   public String getServletInfo()
   {
      return "Redirection Servlet";
   }
   
   /** Destroys the servlet.
    */
   public void destroy()
   {
   }
   
   /** Initializes the servlet.
    */
   public void init(ServletConfig config) throws ServletException
   {
      super.init(config);
      
      String url = config.getInitParameter("RedirectURL");
      try
      {
         configURL = new URL(url);
         root = readConfig(configURL);
      }
      catch (Throwable t)
      {
         throw new ServletException("Error initializing RedirectServlet", t);
      }
   }
   
   /** Handles the HTTP <code>GET</code> method.
    * @param request servlet request
    * @param response servlet response
    */
   protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
   {
      processRequest(request, response);
   }
   
   /** Handles the HTTP <code>POST</code> method.
    * @param request servlet request
    * @param response servlet response
    */
   protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
   {
      processRequest(request, response);
   }
   
   /** Processes requests for both HTTP <code>GET</code> and <code>POST</code> methods.
    * @param request servlet request
    * @param response servlet response
    */
   protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException
   {
      if (request.getParameter("init") != null)
      {
         try
         {
            root = readConfig(configURL);
            PrintWriter out = response.getWriter();
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Redirect Servlet</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("Initialization complete. " + configURL);
            out.println("</body>");
            out.println("</html>");
            out.close();
         }
         catch (Throwable t)
         {
            throw new ServletException("Error initializing RedirectServlet", t);
         }
      }
      else
      {
         String projectName = request.getParameter("project");
         String areaName = request.getParameter("area");
         
         Element project = root.getChild(projectName);
         Element area = (project == null) ? null : project.getChild(areaName);
         if (area != null)
         {
            response.sendRedirect(area.getText());
            response.setContentType("text/html");
         }
         else
         {
            PrintWriter out = response.getWriter();
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Redirect Servlet</title>");
            out.println("</head>");
            out.println("<body>");
            out.println("No page found. Project=" + projectName + " area=" + areaName);
            out.println("</body>");
            out.println("</html>");
            out.close();
         }
      }
   }
   
   private Element readConfig(URL url) throws IOException, JDOMException, TransformerConfigurationException, TransformerException
   {
      SAXBuilder builder = new SAXBuilder();
      Document doc = builder.build(url);
      
      InputStream stylesheet = RedirectServlet.class.getResourceAsStream("RedirectTransform.xsl");
      Transformer transformer = TransformerFactory.newInstance().newTransformer(new StreamSource(stylesheet));
      
      JDOMResult out = new JDOMResult();
      transformer.transform(new JDOMSource(doc), out);
      stylesheet.close();
      
      return out.getDocument().getRootElement();
   }
}
