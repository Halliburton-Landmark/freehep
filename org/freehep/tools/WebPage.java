package org.freehep.tools;

import java.io.*;
import java.util.*;
import java.util.regex.*;
import javax.servlet.http.*;

import org.apache.velocity.Template;
import org.apache.velocity.VelocityContext;
import org.apache.velocity.exception.ResourceNotFoundException;
import org.apache.velocity.app.Velocity;
import org.apache.velocity.app.event.EventCartridge;
import org.apache.velocity.app.event.ReferenceInsertionEventHandler;
import org.apache.velocity.context.Context;
import org.apache.velocity.io.VelocityWriter;
import org.apache.velocity.servlet.VelocityServlet;

public class WebPage extends VelocityServlet {

    private WebPageIncluder includer;
    private Properties config;
    private static final String configPropertiesName        = "WebPageConfiguration.properties";
    private static final String webPagePropertiesName       = "WebPage.properties";
    private static final String printableKey                = "printable";
    private static final String sourceExtensionKey          = "sourceExtension";
    private static final String destinationExtensionKey     = "destinationExtension";
    private static final String webPageKey                  = "webPage";
    private static final String webPageStyleSheetKey        = "webPageStyleSheet";
    private static final String printablePageKey            = "printablePage";
    private static final String printablePageStyleSheetKey  = "printablePageStyleSheet";
    private static final String searchRealmKey              = "searchRealm";
    private static final String searchURLKey                = "searchURL";
    private static final String showFullMenuKey             = "showFullMenu";

    private static WebPageFileResourceLoader resourceLoader;

    public WebPage() {
    }

    public static void setResourceLoader(WebPageFileResourceLoader loader) {
        resourceLoader = loader;
    }

    private void offlineInit() throws Exception {
        Properties velocityProperties = new Properties();
        velocityProperties.load(WebPage.class.getResourceAsStream(configPropertiesName));
        Velocity.init(velocityProperties);

        config = new Properties();
        // load the default properties
        config.load(WebPage.class.getResourceAsStream(webPagePropertiesName));
        // load the user properties
        try {
            config.load(new FileInputStream(webPagePropertiesName));
            System.out.println("User properties file loaded.");
        } catch (FileNotFoundException fnfe) {
        }
    }

    public Template handleRequest(HttpServletRequest request,
                                  HttpServletResponse response,
                                  Context context)
                throws Exception {

        includer = new WebPageIncluder(context);

        String path = "";

        // FIXME extract printable
        boolean printable = false;

        // FIXME convert request to baseName
        String baseName = "";

        String srcExt = config.getProperty(sourceExtensionKey);
        String dstExt = ".html";

        return template(baseName, srcExt, dstExt, printable, context);
    }

    private void convert(String srcName) throws Exception {
        Context context = new VelocityContext();
        context.put("isOffline", "true");
        includer = new WebPageIncluder(context);

        int dot = srcName.lastIndexOf(".");
        String baseName = dot < 0 ? srcName : srcName.substring(0, dot);
        String srcExt = dot < 0 ? "" : srcName.substring(dot);

        write(baseName, srcExt, false, context);
        if (config.getProperty(printableKey) != null) {
            write(baseName, srcExt, true, context);
        }
    }

    private void write(String baseName, String srcExt, boolean printable, Context context)
                throws Exception {

        String dstExt = config.getProperty(destinationExtensionKey);
        String dstName = baseName + (printable ? config.getProperty(printableKey) : "") + dstExt;
        CharArrayWriter charWriter = new CharArrayWriter();
        Writer writer = new VelocityWriter(charWriter);
        Template template = template(baseName, srcExt, dstExt, printable, context);
        template.merge(context, writer);
        writer.close();
        String buffer = charWriter.toString();

        writer = new FileWriter(dstName);

        // filter
        Pattern pattern = Pattern.compile(
            ".*?<html.*?>.*?<head.*?>(.*?)<title.*?>.*?</title.*?>(.*?)</head.*?>.*?<body.*?>(.*?)"+  // tvm top (1-3)
            "(<html.*?>.*?<body.*?>(.*?)</body.*?>.*?</html.*?>(.*?))?"+   // menu (4-5,6)
            "(<html.*?>).*?(<head.*?>)(.*?)(</head.*?>).*?(<body.*?>)(.*)(</body.*?>).*?(</html.*?>)"+ // main page (7-14)
            "(.*?)</body.*?>.*?</html.*?>.*",     // remaining part (15)
            Pattern.CASE_INSENSITIVE+Pattern.DOTALL);
        // writing order: 6, 7, 1, 2, 8, 9, 10, 3, 4, 5, 11, 14, 12, 13
        Matcher matcher = pattern.matcher(buffer);
        if (!matcher.matches() || (matcher.groupCount() != 15)) {
            System.out.println("Error: Cannot filter webpage: "+baseName+", written without filtering");
            System.out.println(matcher.groupCount());
            writer.write(buffer);
        } else {
            writer.write(matcher.group(7));
            writer.write(matcher.group(8));
            writer.write(matcher.group(1));
            writer.write(matcher.group(2));
            writer.write(matcher.group(9));
            writer.write(matcher.group(10));
            writer.write(matcher.group(11));
            writer.write(matcher.group(3));
            if (matcher.group(4) != null) {
                writer.write(matcher.group(5));
                writer.write(matcher.group(6));
            }
            writer.write(matcher.group(12));
            writer.write(matcher.group(15));
            writer.write(matcher.group(13));
            writer.write(matcher.group(14));
        }
        writer.close();
    }

    private Template template(String baseName, String srcExt, String dstExt, boolean printable, Context context)
            throws Exception {

        String srcName = baseName+srcExt;
        String dstName = baseName+dstExt;

        String baseURL = "";
        String unixName = baseName.replace('\\','/');

        int slash = 0;
        StringBuffer prefix = new StringBuffer("");
        while (slash >= 0) {
            slash = unixName.indexOf('/', slash);
            if (slash >= 0) {
                prefix.append("../");
                slash++;
            }
        }

        baseURL = prefix.toString();

        EventCartridge eventCartridge = new EventCartridge();
        eventCartridge.addEventHandler(new ReferenceInsertionEventHandler() {
            public Object referenceInsert(String reference, Object value) {
//                System.out.println(reference+" "+value);
                // make sure non-set references are replaced by empty strings
                if (value == null) return "";
                return value;
            }
        });
        eventCartridge.attachToContext(context);

        context.put("includer", includer);

        context.put("baseURL", baseURL);

        // handle the select hightlight
        context.put("selected", dstName.replace('\\','/'));

        // include the correct content page
        context.put("contentPage", srcName);

        String searchRealm = config.getProperty(searchRealmKey);
        if (searchRealm != null) {
            context.put("searchRealm", searchRealm);
            context.put("searchURL", config.getProperty(searchURLKey));
        }
        
        context.put(webPageStyleSheetKey,
                    url(config.getProperty(webPageStyleSheetKey), baseURL));

        // only when we want printable pages generated
        if (config.getProperty(printableKey) != null) {
            context.put("printablePageURL",
                        baseURL+baseName+config.getProperty(printableKey)+dstExt);
            context.put(printablePageStyleSheetKey,
                        url(config.getProperty(printablePageStyleSheetKey), baseURL));
        }

        // copy menu key
//        context.put(showFullMenuKey, config.getProperty(showFullMenuKey));
        context.put(showFullMenuKey, new Boolean(true));

        // tell the resource loader so it can tell us about the <head> sections
        resourceLoader.setContext(context);

        // run source so we get access to the <head> section
        Template src = Velocity.getTemplate(srcName);

        String templateName = printable ?
                config.getProperty(printablePageKey) : config.getProperty(webPageKey);
        Template template = Velocity.getTemplate(templateName);

        return template;
    }

    private String url(String url, String baseURL) {
        if (url.startsWith("/")) return url;
        if (url.indexOf("//") >= 0) return url;
        return baseURL+url;
    }

    private static String filter(String in) {
        return in;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
            // FIXME add proper command line parsing here
            System.err.println("Usage: WebPage page1 [...pageN]");
            System.err.println("    where page1 is the name of the source page");
            System.exit(1);
        }

        WebPage web = new WebPage();
        web.offlineInit();

        System.out.print("Processing: ");
        for (int i=0; i<args.length; i++) {
            if (i > 0) System.out.print(", ");
            System.out.print(args[i]);
            web.convert(args[i]);
        }
        System.out.println(".");
        System.out.println("Finished");
    }
}
