package org.freehep.tools;

import java.io.File;
import java.io.FileWriter;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * A simple program for creating scripts to set the FreeHEP CLASSPATH
 * @author tonyj
 */
public class MakeClasspath implements FilenameFilter
{
   private MakeClasspath()
   {
   }

   /**
    * @param args the command line arguments
    */
   public static void main(String[] args) throws IOException
   {
      File dir = new File("lib");
      File[] jars = dir.listFiles(new MakeClasspath());

      PrintWriter out = new PrintWriter(new FileWriter(new File("setclasspath.bat")));
      out.println("@echo off");
      out.println("set CLASSPATH=.");
      for (int i=0; i<jars.length; i++)
      {
         out.println(" set CLASSPATH=%CLASSPATH%;%FREEHEP%\\"+jars[i]);
      }
      out.println(" set CLASSPATH=%CLASSPATH%;tools/junit.jar");
      out.close();
   }

   public boolean accept(File dir, String name)
   {
       return name.endsWith(".jar");
   }
}
