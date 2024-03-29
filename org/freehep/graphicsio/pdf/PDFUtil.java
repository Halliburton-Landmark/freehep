// Copyright 2004, FreeHEP.
package org.freehep.graphicsio.pdf;

import java.text.*;
import java.util.*;

import org.freehep.util.ScientificFormat;

/**
 * Utility functions for the PDFWriter. This class handles escaping of strings,
 * formatting of dates, ...
 * <p>
 * @author Mark Donszelmann
 * @version $Id: PDFUtil.java,v 1.3 2004/12/30 07:41:35 duns Exp $
 */
public class PDFUtil implements PDFConstants {

    // static class
    private PDFUtil() {
    }

    public static String escape(String string) {
        StringBuffer escape = new StringBuffer();

        for (int i=0; i<string.length(); i++) {
            char c = string.charAt(i);
            switch(c) {
                case '(':
                case ')':
                case '\\':
                    escape.append('\\');
                    escape.append(c);
                    break;
                default:
                    escape.append(c);
                    break;
            }
        }
        return escape.toString();
    }

    public static String date(Calendar date) {
        int offset = date.get(Calendar.ZONE_OFFSET) +
                     date.get(Calendar.DST_OFFSET);

        String tz;
        if (offset == 0) {
            tz = "Z";
        } else {
            DecimalFormat fmt = new DecimalFormat("00");
            int tzh = Math.abs(offset / 3600000);
            int tzm = Math.abs(offset % 3600000);
            if (offset > 0) {
                tz = "+"+fmt.format(tzh)+"'"+fmt.format(tzm)+"'";
            } else {
                tz = "-"+fmt.format(tzh)+"'"+fmt.format(tzm)+"'";
            }
        }
        return "(D:"+dateFormat.format(date.getTime())+tz+")";
    }

    private static final ScientificFormat scientific = new ScientificFormat(5,100,false);
    public static String fixedPrecision(double v) {
	    return scientific.format(v);
    }

}
