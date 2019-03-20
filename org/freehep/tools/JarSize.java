// Copyright 2000, CERN, Geneva, Switzerland and SLAC, Stanford, U.S.A.
package org.freehep.tools;

import java.io.IOException;
import java.util.Enumeration;
import java.util.Iterator;
import java.util.Map;
import java.util.TreeMap;
import java.util.jar.JarEntry;
import java.util.jar.JarFile;

/**
 * @author Mark Donszelmann
 * @version $Id: JarSize.java,v 1.1 2001/11/25 12:01:51 duns Exp $
 */
public class JarSize {

    public static final double KBYTE = 1024;

    public static String format(long value) {
        String p = "      ";
        String s = ""+value;
        return p.substring(0, p.length()-s.length()) + s;
    }

    public static void main(String args[]) throws IOException {
        if (args.length != 1) {
            System.out.println("Usage: JarSize file.jar");
            System.exit(1);
        }
    
        Map packages = new TreeMap();
        JarFile jar = new JarFile(args[0]);
        for (Enumeration e=jar.entries(); e.hasMoreElements(); ) {
            JarEntry jarEntry = (JarEntry)e.nextElement();
            if (jarEntry.isDirectory()) continue;
            String name = jarEntry.getName();
            String packageName = name.substring(0, name.lastIndexOf('/'));
            Entry entry = (Entry)packages.get(packageName);
            if (entry == null) {
                entry = new Entry();
                packages.put(packageName, entry);
            }
            entry.add(jarEntry.getSize(), jarEntry.getCompressedSize());
        }
        jar.close();
        
        int number = 0;
        long size = 0;
        long compressedSize = 0;
        long largestSize = 0;
        System.out.println(" N     Size  Comp  Large  Ave    Package");
        System.out.println(" ----- ----- ----- -----  -----  -------");
        for (Iterator i=packages.entrySet().iterator(); i.hasNext(); ) {
            Map.Entry mapEntry = (Map.Entry)i.next();
            Entry entry = (Entry)mapEntry.getValue();
            number += entry.getNumber();
            size += entry.getSize();
            compressedSize += entry.getCompressedSize();
            largestSize = Math.max(largestSize, entry.getLargestSize());
            System.out.print(format(entry.getNumber()));
            System.out.print(format(Math.round(entry.getSize()/KBYTE)));
            System.out.print(format(Math.round(entry.getCompressedSize()/KBYTE)));
            System.out.print(format(Math.round(entry.getLargestSize()/KBYTE)));
            System.out.print(" ");
            System.out.print(format(Math.round(entry.getCompressedSize()/entry.getNumber())));
            System.out.print("  ");
            System.out.print((String)mapEntry.getKey());
            System.out.println();
        }
        System.out.print(format(number));
        System.out.print(format(Math.round(size/KBYTE)));
        System.out.print(format(Math.round(compressedSize/KBYTE)));
        System.out.print(format(Math.round(largestSize/KBYTE)));
        System.out.print(" ");
        System.out.print(format(Math.round(compressedSize/number)));
        System.out.println("  Total");
    }
    
    static class Entry {
        private int number;
        private long size;
        private long compressedSize;
        private long largestSize;
        
        Entry() {
            number = 0;
            size = 0;
            compressedSize = 0;
            largestSize = 0;
        }
        
        void add(long size, long compressedSize) {
            number++;
            this.size += size;
            this.compressedSize += compressedSize;
            largestSize = Math.max(largestSize, compressedSize);
        }
                
        int getNumber() {
            return number;
        }        
           
        long getSize() {
            return size;
        }
        
        long getCompressedSize() {
            return compressedSize;
        }

        long getLargestSize() {
            return largestSize;
        }
    }
}