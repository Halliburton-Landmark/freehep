/*
 * @(#)AllClassesFrameWriter.java	1.23 03/01/23
 *
 * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package org.freehep.tools.doclet;

import com.sun.javadoc.*;
import com.sun.tools.doclets.*;
import java.io.*;
import java.lang.*;
import java.util.*;

/**
 * Generate the file with list of all the classes in this run. This page will be
 * used in the left-hand bottom frame, when "All Classes" link is clicked in
 * the left-hand top frame. The name of the generated file is
 * "allclasses-frame.html".
 *
 * @author Atul M Dambalkar
 * @author Doug Kramer
 */
public class AllClassesFrameWriter extends HtmlStandardWriter {

    /**
     * The name of the output file with frames
     */
    public static final String OUTPUT_FILE_NAME_FRAMES = "allclasses-frame.html";
   
    /**
     * The name of the output file without frames
     */
    public static final String OUTPUT_FILE_NAME_NOFRAMES = "allclasses-noframe.html";

    /**
     * Index of all the classes.
     */
    protected IndexBuilder indexbuilder;

    /**
     * Construct AllClassesFrameWriter object. Also initilises the indexbuilder
     * variable in this class.
     * @throws IOException
     * @throws DocletAbortException
     */
    public AllClassesFrameWriter(ConfigurationStandard configuration,
                                 String filename, IndexBuilder indexbuilder)
                              throws IOException {
        super(configuration, filename);
        this.indexbuilder = indexbuilder;
    }

    /**
     * Create AllClassesFrameWriter object. Then use it to generate the
     * "allclasses-frame.html" file. Generate the file in the current or the
     * destination directory.
     *
     * @param indexbuilder IndexBuilder object for all classes index.
     * @throws DocletAbortException
     */
    public static void generate(ConfigurationStandard configuration,
                                IndexBuilder indexbuilder) {
        AllClassesFrameWriter allclassgen;
        String filename = OUTPUT_FILE_NAME_FRAMES;
        try {
            allclassgen = new AllClassesFrameWriter(configuration,
                                                    filename, indexbuilder);
            allclassgen.generateAllClassesFile(true);
            allclassgen.close();
            filename = OUTPUT_FILE_NAME_NOFRAMES;
            allclassgen = new AllClassesFrameWriter(configuration,
                                                    filename, indexbuilder);
            allclassgen.generateAllClassesFile(false);
            allclassgen.close();
        } catch (IOException exc) {
            configuration.standardmessage.
                     error("doclet.exception_encountered",
                           exc.toString(), filename);
            throw new DocletAbortException();
        }
    }

    /**
     * Print all the classes in table format in the file.
     * @param wantFrames True if we want frames.
     */
    protected void generateAllClassesFile(boolean wantFrames) throws IOException {
        String label = getText("doclet.All_Classes");

        printHtmlHeader(label, null, false);

        printAllClassesTableHeader();
        printAllClasses(wantFrames);
        printAllClassesTableFooter();

        printBodyHtmlEnd();
    }

    /**
     * Use the sorted index of all the classes and print all the classes.
     *
     * @param wantFrames True if we want frames.
     */
    protected void printAllClasses(boolean wantFrames) {
        for (int i = 0; i < indexbuilder.elements().length; i++) {
            Character unicode = (Character)((indexbuilder.elements())[i]);
            generateContents(indexbuilder.getMemberList(unicode), wantFrames);
        }
    }

    /**
     * Given a list of classes, generate links for each class or interface.
     * If the class kind is interface, print it in the italics font. Also all
     * links should target the right-hand frame. If clicked on any class name
     * in this page, appropriate class page should get opened in the right-hand
     * frame.
     *
     * @param classlist Sorted list of classes.
     * @param wantFrames True if we want frames.
     */
    protected void generateContents(List classlist, boolean wantFrames) {
        for (int i = 0; i < classlist.size(); i++) {
            ClassDoc cd = (ClassDoc)(classlist.get(i));
            if (!Util.isCoreClass(cd)) {
                continue;
            }
            String label = italicsClassName(cd, false);
            if(wantFrames){
                print(getClassLink(cd, "", label, false, "", "classFrame"));
            } else {
                print(getClassLink(cd, "", label, false, "", ""));
            }
            br();
        }
    }

    /**
     * Print the heading "All Classes" and also print Html table tag.
     */
    protected void printAllClassesTableHeader() {
        fontSizeStyle("+1", "FrameHeadingFont");
        boldText("doclet.All_Classes");
        fontEnd();
        br();
        table();
        tr();
        tdNowrap();
        fontStyle("FrameItemFont");
    }

    /**
     * Print Html closing table tag.
     */
    protected void printAllClassesTableFooter() {
        fontEnd();
        tdEnd();
        trEnd();
        tableEnd();
    }
}



