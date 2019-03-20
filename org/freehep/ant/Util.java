// Copyright 2000-2004, FreeHEP.
package org.freehep.ant;

import java.util.*;

/**
 * @author Mark Donszelmann
 * @version $Id: Util.java,v 1.4 2004/01/19 21:23:47 duns Exp $
 */

public class Util {

    public static String delimiters = "\t ,";

    /**
     * Appends each suffix (m) to each prefix (n) giving a comma delimited
     * result of n*m combinations.
     *
     * @param prefixes a comma delimited set of prefixes
     * @param suffixes a comma delimited set of suffixes
     * @return a comma delimited set of combinations
     */

    public static String expand(String prefixes, String suffixes) {

        if (prefixes == null) prefixes = "";
        if (suffixes == null) suffixes = "";

        StringBuffer result = null;

        StringTokenizer prefixTokenizer = new StringTokenizer(prefixes, delimiters);
        while(prefixTokenizer.hasMoreTokens()) {
            String prefix = prefixTokenizer.nextToken();
            if (prefix.endsWith("*")) {
                prefix += "*";
            }
            if (!prefix.endsWith("/")) {
                prefix += "/";
            }
            StringTokenizer suffixTokenizer = new StringTokenizer(suffixes, delimiters);
            while (suffixTokenizer.hasMoreTokens()) {
                String entry = prefix + suffixTokenizer.nextToken();

                if (result == null) {
                    result = new StringBuffer(entry);
                } else {
                    result.append(", ");
                    result.append(entry);
                }
            }
        }

        if (result == null) {
            return "";
        } else {
            return result.toString();
        }
    }

}
