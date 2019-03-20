package hep.aida.ref;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Iterator;
import java.util.StringTokenizer;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author turri
 * @version $Id: AidaUtils.java,v 1.15 2005/11/01 02:08:31 serbo Exp $
 */
public abstract class AidaUtils {
    private static Pattern pattern = Pattern.compile("(\\w+)\\s*((=\\s*(\"(.*?)\"|([^,;$]*)))\\s*)?(,|;|$)");
    private static Pattern stringPattern = Pattern.compile("\\s*((\"(.*?)\")|([^,;$]*))\\s*?(,|;|$)");
    /**
     * Parse AIDA options. Accepts values of the form:
     * <pre>
     * a=b;c=d
     * a="Some Options",c="My , Funny Value"
     * testCase     (equivalent to testCase=true)
     * </pre>
     * @param options The options string to be parsed
     * @return A map containing all the found options
     * @throws IllegalArgumentException if the options string is invalid
     */
    public static Map parseOptions(String options) {
        if (options == null || options.trim().length() == 0) return Collections.EMPTY_MAP;
        Map hashValues = new HashMap();
        Matcher matcher = pattern.matcher(options);
        while (matcher.find()) {
            String key = matcher.group(1);
            String value = matcher.group(5);
            if (value == null) {
                value = matcher.group(6);
                //This is to remove the trailing spaces in group(6)
                if ( value != null )
                    value = value.trim();
            }
            if (value == null) value = "true";
            hashValues.put(key,value);
            if (matcher.end()  == options.length()) return hashValues;
        }
        throw new IllegalArgumentException("Invalid options: "+options);
    }
    
    public static String[] parseString(String options) {
        if (options == null || options.trim().length() == 0) return new String[0];
        ArrayList list = new ArrayList();
        Matcher matcher =stringPattern.matcher(options);
        while (matcher.find()) {
            int g = matcher.groupCount();
            String value = matcher.group(3);
            if (value == null) value = matcher.group(1);
            if (value != null) {
                list.add(value.trim());
            }
            if (matcher.end()  == options.length()) {
                String[] array = new String[list.size()];
                if (list.size() > 0) array = (String[]) list.toArray(array);
                return array;
            }
        }
        throw new IllegalArgumentException("Invalid options: "+options);
    }
    

    // Creates path array from String. Path should start with "/"
    // Does not take escaped "/"  ("\\/") as a path element separator
    public static String[] stringToArray(String path) {
        String[] result = null;
        if ( path == null || path.equals("")) return result;
        
        StringTokenizer tokenizer = new StringTokenizer(path, "/");
        ArrayList list = new ArrayList(tokenizer.countTokens());
        while (tokenizer.hasMoreTokens()) {
            String token = tokenizer.nextToken();
            while (token.endsWith("\\")) {
                token = token.substring(0, token.length()-1)+ "/";
                if (tokenizer.hasMoreTokens()) token = token  + tokenizer.nextToken();
            }
            list.add(token);
        }
        result = new String[list.size()];
        list.toArray(result);
        
        return result;
    }
    
    // Escape all "/" -> "\\/"
    public static String modifyName(String name) {
        if (name.indexOf('/') < 0) return name;
        String newName = "";
        
        int index = -1;
        for (int i=0; i<name.length(); i++) {
            if (name.charAt(i) == '/') {
                if (i > 0 && name.charAt(i-1) == '\\') continue;
                if (i > index) {
                    newName = newName + name.substring(index+1, i) + "\\/";
                    index = i;
                } else if (i == index) {
                    newName = newName + "\\/";
                }
            }
        }
        newName += name.substring(index+1);
        
        return newName;
    }
    
    public static String parseName(String pathString) {
        if (pathString == null || pathString.equals("/") || pathString.endsWith("/")) return "";
        if (pathString.indexOf("/") < 0) return pathString;
        String[] path = stringToArray(pathString);
        String name = path[path.length-1];
        return name;
    }
    
    public static String parseDirName(String pathString) {
        if (pathString == null || pathString.equals("/") || pathString.endsWith("/")) return pathString;
        if (pathString.indexOf("/") < 0) return "";
        String dirName = "";
        String[] path = stringToArray(pathString);
        if (path.length <= 1) return "/";
        else {
            dirName = "/";
            for (int i=0; i<path.length-1; i++) { dirName += path[i] + "/"; }
        }
        return dirName;
    }
    
    // returns -1 if nothing was found
    public static int findInArray(String string, String[] array) {
        int index = -1;
        if (string == null || array == null || array.length == 0) return index;
        
        for (int i=0; i<array.length; i++) {
            if (string.equals(array[i])) {
                index = i;
                break;
            }
        }
        return index;
    }   
    
    public static void main(String[] args) {
        Map map = AidaUtils.parseOptions("annotation.xAxis=date, annotation.customOverlay=hep.aida.ref.plotter.adapter.TimeHistoryOverlay");
        Iterator it = map.keySet().iterator();
        while (it.hasNext()) {
            String key = (String) it.next();
            String val = (String) map.get(key);
            System.out.println("key="+key+", val="+val);
        }
        
        String options = "annotation.xAxis=date, annotation.customOverlay=hep.aida.ref.plotter.adapter.TimeHistoryOverlay";
        //String options = "\"g1 - 2 \" ,ln(x[0]),a, b;\"abc / de - f\", 0.0";
        String[] array = AidaUtils.parseString(options);
        for (int i=0; i<array.length; i++) System.out.println("*"+array[i]+"*");

        String path = "/hist/dir1/subdir/h11";
        String name = AidaUtils.parseName(path);
        String dir = AidaUtils.parseDirName(path);
        System.out.println("\nPath="+path+"\n\tdir="+dir+"\n\tname="+name);
        
        path = "/dir0/";
        name = AidaUtils.parseName(path);
        dir = AidaUtils.parseDirName(path);
        System.out.println("\nPath="+path+"\n\tdir="+dir+"\n\tname="+name);
        
        path = "/hist1D";
        name = AidaUtils.parseName(path);
        dir = AidaUtils.parseDirName(path);
        System.out.println("\nPath="+path+"\n\tdir="+dir+"\n\tname="+name);
        
        path = "hist1D";
        name = AidaUtils.parseName(path);
        dir = AidaUtils.parseDirName(path);
        System.out.println("\nPath="+path+"\n\tdir="+dir+"\n\tname="+name);
        
        path = "/hist/dir1/subdir/";
        name = AidaUtils.parseName(path);
        dir = AidaUtils.parseDirName(path);
        System.out.println("\nPath="+path+"\n\tdir="+dir+"\n\tname="+name);
        
    }
    
}

