// Copyright 2000-2005, FreeHEP.
package org.freehep.tools;

import java.io.*;
import java.util.*;

import org.freehep.util.argv.*;

/**
 * JNeeds picks up a class file, or a whole directory of class files and 
 * possibly all subdirectories of class files, and lists the dependencies.
 * The first column lists the package the classes depend of, the second
 * column the classes used from each of those packages, and the last
 * column which files these classes were referred from.
 *
 * @author Mark Donszelmann
 * @version $Id: JNeeds.java,v 1.6 2005/01/01 20:58:04 duns Exp $
 */
public class JNeeds {
        
    /**
     * Creates the package map.
     */
    private static TreeMap getPackageNames(TreeMap classMap) {
        TreeMap dependencies = new TreeMap();
       
        Set classKeys = classMap.keySet();
        
        for (Iterator i = classKeys.iterator(); i.hasNext(); ) {
            String className = (String)i.next();
            TreeSet fileSet = (TreeSet)classMap.get(className);
            
            className = className.replace('/','.');
            className = className.replace('\\','.');
                        
            if ((!className.startsWith("java.") && 
                 !className.startsWith("javax.swing.") && 
                 !className.startsWith("org.omg.CORBA.") &&
                 !className.startsWith("org.omg.CosNaming.")) || 
                 system.getValue()) {
                
                int dot = className.lastIndexOf('.');
                String packageName = className.substring(0, dot);
                className = className.substring(dot+1);

                TreeMap map = (TreeMap)dependencies.get(packageName);
                if (map == null) {
                    map = new TreeMap();
                    dependencies.put(packageName, map);
                } 
                map.put(className, fileSet);
            }
        }
        
        return dependencies;
    } 
    
    /**
     * Parses the string to find class reference encodings of the type L....;
     *
     */
    private static Vector parse(String string) {
        Vector names = new Vector();
        
        boolean inName = false;
        StringBuffer name = new StringBuffer();
        for (int i=0; i<string.length(); i++) {
            if (inName) {
                if (string.charAt(i) == ';') {
                    inName = false;
                    names.add(name.toString());
                    name = new StringBuffer();
                } else {
                    name.append(string.charAt(i));
                }
            } else {
                if (string.charAt(i) == 'L') {
                    inName = true;
                }
            }
        }
        return names;
    }
    
    /**
     * Reads in a class file and returns the names of referred classes.
     *
     * The ClassPool is examined to find: 1. class references which contain a slash, and
     * 2. UTF strings which contain a slash and a semicolon. The later show the encoding
     * of references to class files.
     */
    private static Vector readClassFile(String file) throws IOException {
        Vector classNames = new Vector();

        FileInputStream fis = new FileInputStream(file);        
        DataInputStream dis = new DataInputStream(fis);
        
        // read and check header
        int magic = dis.readInt();
        short minor = dis.readShort();
        short major = dis.readShort();
        if (magic != 0xCAFEBABE) {
            throw new IOException("Magic number in class file wrong, maybe not a class file");
        }
        
        // read constant pool        
        short numberOfConstants = dis.readShort();
        Object[] constants = new Object[numberOfConstants];
        
        for (int i=1; i<numberOfConstants; i++) {
            byte b;
            switch(b = dis.readByte()) {
                case 1: // UTF check for "/" and ";" and parse (first char should be "(" or "L").
                        String value = dis.readUTF();
                        constants[i] = value;
                        if ((value.indexOf("/") >= 0) && 
                            (value.indexOf(";") >= 0) && 
                            ((value.charAt(0) == 'L') || (value.charAt(0) == '('))) {
                            classNames.addAll(parse(value));
                        }
                        break;  

                case 3: // Integer
                        int dummy1 = dis.readInt();
                        break;

                case 4: // Float
                        float dummy2 = dis.readFloat();
                        break;
        
                case 5: // Long
                        dis.readLong();
                        i++;
                        break;
       
                case 6: // Double
                        dis.readDouble();
                        i++;
                        break;      
                      
                case 7: // Class Entry
                        short index = dis.readShort();
                        constants[i] = new Short(index);
                        break;
                        
                case 8: // String
                        short dummy5 = dis.readShort();
                        break;
        
                case 9: // FieldRef
                        short dummy6 = dis.readShort();
                        short dummy7 = dis.readShort();
                        break;
        
                case 10: // MethodRef
                        short dummy8 = dis.readShort();
                        short dummy9 = dis.readShort();
                        break;
        
                case 11: // InterfaceMethodRef
                        short dummy10 = dis.readShort();
                        short dummy11 = dis.readShort();
                        break;
                        
                case 12: // NameAndType
                        short dummy12 = dis.readShort();
                        short dummy13 = dis.readShort();
                        break;
                        
                default:
                        throw new IOException("Unknown tag in constant pool '"+b+"'  of file "+file+".");
            }
        }
        dis.close();
        fis.close();
        
        // look at all (dereferenced) class entries
        for (int i=1; i<constants.length; i++) {
            if (constants[i] instanceof Short) {
                String value = (String)constants[((Short)constants[i]).shortValue()];
                if (value.indexOf("/") >=0 ) {
                    if (value.indexOf(";") >= 0) {
                        classNames.addAll(parse(value));                        
                    } else {
                        classNames.add(value);
                    }
                }
            }
        }

        return classNames;
    }
   
    /**
     * Expands the dependencies of a single class file.
     * 
     * @returns a map of a set of referrer classes, indexed by class name.
     */ 
    private static TreeMap expandFile(String file) throws FileNotFoundException, IOException {
        TreeMap dependencies = new TreeMap();
        
        Vector classNames = readClassFile(file);

        for (Enumeration e=classNames.elements(); e.hasMoreElements(); ) {
            String name = (String)e.nextElement();
            TreeSet tree = (TreeSet)dependencies.get(name);
            if (tree == null) {
                tree = new TreeSet();
                dependencies.put(name, tree);
                tree.add(file);
//                try {
//                    System.out.println(name);
//                    dependencies = merge(dependencies, expandFile(name+".class"));
//                } catch (FileNotFoundException ignored) {
//                }
            } else {
                tree.add(file);
            }
        }
        
        return dependencies;
    }
    
    /**
     * returns a name with the proper File seperator character
     */
    private static String getSystemName(String name) {
        name = name.replace('.',File.separatorChar);
        name = name.replace('/',File.separatorChar);
        name = name.replace('\\',File.separatorChar);
        return name;
    }        
    
    /**
     * returns a name with dots rather
     */
    private static String getDottedName(String name) {
        name = getSystemName(name);
        name = name.replace(File.separatorChar, '.');
        return name;
    }
    
    /**
     * Expands a package to find its dependencies.
     * If the package is a directory, all class files in that directory will be
     * handled and optionally the class files in subdirectories.
     *
     */
    private static TreeMap expand(String pkgs, TreeSet input) throws FileNotFoundException, IOException {
        TreeMap dependencies = new TreeMap();

        String dotPkgs = getDottedName(pkgs);                

        File file = new File(pkgs);
        if (!file.exists()) {
            file = new File(getSystemName(pkgs));
            if (!file.exists()) {
                throw new FileNotFoundException("File or Directory does not exist '"+pkgs+"'");
            }
        }
        
        if (file.isFile()) {
            if (pkgs.endsWith(".class")) {
                input.add(dotPkgs);
                dependencies = expandFile(pkgs);
            }
        } else {
            String[] files = file.list(new FilenameFilter() {
                public boolean accept(File dir, String name) {
                    return name.endsWith(".class");
                }
            });
            if ((files != null) && (files.length > 0)) {
                input.add(dotPkgs);
                for (int i=0; i<files.length; i++) {
                    String name = file.getPath()+File.separator+files[i];
                    dependencies = merge(dependencies, expandFile(name));
                }
            }
            
            if (!local.getValue()) {
                // search for subdirs
                files = file.list();
                if (files != null) {
                    for (int i=0; i<files.length; i++) {
                        String name = file.getPath()+File.separator+files[i];
                        File subdir = new File(name);
                        if (subdir.isDirectory()) {
                            dependencies = merge(dependencies, expand(name, input));
                        }
                    }
                }
            }               
        }
      
        return dependencies;        
    }
    
    /**
     * Merges two TreeMaps together. If the TreeMaps contain
     * TreeSets it will merge the sets. If the TreeMaps contain
     * other TreeMaps, this method will call itself recursively.
     *
     */
    private static TreeMap merge(TreeMap map, TreeMap other) {
        TreeMap newMap = new TreeMap();
        newMap.putAll(map);
        
        Set keys = other.keySet();
        
        for (Iterator i = keys.iterator(); i.hasNext(); ) {
            String key = (String)i.next();
            
            Object value = newMap.get(key);
            
            if (value == null) {
                newMap.put(key, other.get(key));
                
            } else if (value instanceof TreeMap) {
                // we are on the map level
                newMap.put(key, merge((TreeMap)value, (TreeMap)other.get(key)));
               
            } else {
                // we are on the set level
                TreeSet set = (TreeSet)value;
                set.addAll((TreeSet)other.get(key));
            }
        }
            
        return newMap;
    }

    private static BooleanOption system;
    private static BooleanOption local;

    public static void main(String[] args) {
        
        BooleanOption help = new BooleanOption("-help", "-h", "shows this help");
        BooleanOption cls = new BooleanOption("-class", "-c", "shows which classes are referred");
        BooleanOption all = new BooleanOption("-all", "-a", "shows all, also where classes are referred from");
        local = new BooleanOption("-local", "-l", "ignores subdirectories");
        system = new BooleanOption("-system", "-s", "show references to system classes");
        ListParameter classes = new ListParameter("Package or Class filenames", "package or class filenames, separated by dots of slashes");
        
        ArgumentParser parser = new ArgumentParser("JNeeds");
        parser.add(help);
        parser.add(cls);
        parser.add(all);
        parser.add(local);
        parser.add(system);
        parser.add(classes);
        
        try {
            List extra = parser.parse(args);
            
            if( !extra.isEmpty() || help.getValue()) {
                parser.printUsage( System.out );
                System.exit( 0 );
            }
        } catch (MissingArgumentException mae) {
            System.out.println(mae.getMessage());
            System.exit(0);
        } catch (ArgumentFormatException afe) {
            System.out.println(afe.getMessage());
            System.exit(0);
        }

        try {
            TreeMap dependencies = new TreeMap();
            TreeSet inputSet = new TreeSet();
            
            for (Iterator m=classes.getValue().iterator(); m.hasNext(); ) {
                dependencies = merge(dependencies, expand((String)m.next(), inputSet));
            }
            
            System.out.println("-------------------------- Input Classes -------------------------");

            if (inputSet.isEmpty()) {
                System.out.println("   No Input Files");
                System.out.println("------------------------------------------------------------------");
            } else {
                for (Iterator i = inputSet.iterator(); i.hasNext(); ) {
                    System.out.println("   "+i.next());
                }
            
                System.out.println("-------------------------- Depend(s) on --------------------------");
                
                TreeMap packageMap = getPackageNames(dependencies);
                Set packageKeys = packageMap.keySet();
                
                for (Iterator i = packageKeys.iterator(); i.hasNext(); ) {
                    String packageName = (String)i.next();
                    if (!inputSet.contains(packageName)) {
                        System.out.println("         "+packageName);
                        
                        if (all.getValue() || cls.getValue()) {
                            TreeMap classMap = (TreeMap)packageMap.get(packageName);
                            Set classKeys = classMap.keySet();
                            
                            for (Iterator j = classKeys.iterator(); j.hasNext(); ) {
                                String className = (String)j.next();
                                System.out.println("                  "+className);
                         
                                if (all.getValue()) {       
                                    TreeSet fileSet = (TreeSet)classMap.get(className);
                                    for (Iterator k = fileSet.iterator(); k.hasNext(); ) {
                                        System.out.println("                           "+k.next());
                                    }
                                }
                            }
                            
                            System.out.println();
                        }
                    }
                }
            }
        } catch (FileNotFoundException fnfe) {
            System.err.println(fnfe);
        } catch (Exception ex) {
            System.err.println("Error: "+ex);
            ex.printStackTrace();
        }
    }
}
