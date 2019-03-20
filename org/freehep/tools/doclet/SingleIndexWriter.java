/*
 * @(#)SingleIndexWriter.java	1.15 03/01/23
 *
 * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package org.freehep.tools.doclet;

import com.sun.tools.doclets.*;
import com.sun.javadoc.*;
import java.io.*;
import java.lang.*;
import java.util.*;

/**
 * Generate only one index file for all the Member Names with Indexing in 
 * Unicode Order. The name of the generated file is "index-all.html" and it is
 * generated in current or the destination directory.
 *
 * @see java.lang.Character
 * @author Atul M Dambalkar
 */
public class SingleIndexWriter extends AbstractIndexWriter {

    /**
     * Construct the SingleIndexWriter with filename "index-all.html" and the 
     * {@link IndexBuilder}
     * 
     * @param filename     Name of the index file to be generated.
     * @param indexbuilder Unicode based Index from {@link IndexBuilder}
     */
    public SingleIndexWriter(ConfigurationStandard configuration,
                             String filename, 
                             IndexBuilder indexbuilder) throws IOException {
        super(configuration, filename, indexbuilder);
    }

    /**
     * Generate single index file, for all Unicode characters.
     * 
     * @param indexbuilder IndexBuilder built by {@link IndexBuilder}
     * @throws DocletAbortException
     */
    public static void generate(ConfigurationStandard configuration,
                                IndexBuilder indexbuilder) {
        SingleIndexWriter indexgen;
        String filename = "index-all.html";
        try {
            indexgen = new SingleIndexWriter(configuration, 
                                             filename, indexbuilder);
            indexgen.generateIndexFile();
            indexgen.close();
        } catch (IOException exc) {
            configuration.standardmessage.error(
                        "doclet.exception_encountered",
                        exc.toString(), filename);
            throw new DocletAbortException();
        }
    }

    /**
     * Generate the contents of each index file, with Header, Footer, 
     * Member Field, Method and Constructor Description.
     */
    protected void generateIndexFile() throws IOException {
        printHtmlHeader(getText("doclet.Window_Single_Index"));
        navLinks(true);
        printLinksForIndexes();
        
        hr();
    
        for (int i = 0; i < indexbuilder.elements().length; i++) {
            Character unicode = (Character)((indexbuilder.elements())[i]);
            generateContents(unicode, indexbuilder.getMemberList(unicode));
        }

        printLinksForIndexes();
        navLinks(false);
        
        printBottom(); 
        printBodyHtmlEnd();
    }

    /**
     * Print Links for all the Index Files per unicode character.
     */
    protected void printLinksForIndexes() {
        for (int i = 0; i < indexbuilder.elements().length; i++) {
            String unicode = (indexbuilder.elements())[i].toString();
            printHyperLink("#_" + unicode + "_", unicode);
            print(' ');
        }
    }
}
