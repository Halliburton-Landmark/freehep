// Copyright 2003, FreeHEP.
package org.freehep.graphicsio.cgm.test;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

import hep.aida.*;

import org.freehep.graphicsio.cgm.CGMDummyTag;
import org.freehep.graphicsio.cgm.CGMInputStream;
import org.freehep.util.io.Tag;

/**
 * @author Mark Donszelmann
 * @version $Id: CGMAnalyze.java,v 1.1 2003/12/02 23:40:30 duns Exp $
 */
public class CGMAnalyze {

    public static void main(String[] args) {

        try {
            IAnalysisFactory af = IAnalysisFactory.create();
            ITree tree = af.createTreeFactory().create("CGMAnalyze.aida","xml",false,true);
            IHistogramFactory hf = af.createHistogramFactory(tree);
            IHistogram1D tagType = hf.createHistogram1D("TagType", 1000, 0, 1000);
            IHistogram1D tagSize = hf.createHistogram1D("TagSize", 100, 0, 100);

            FileInputStream fis = new FileInputStream(args[0]);
            CGMInputStream cgm = new CGMInputStream(fis);

            long start = System.currentTimeMillis();
            
            Tag tag = cgm.readTag();
            while (tag != null) {
//                System.out.println(tag);
                tagType.fill(tag.getTag());
                tagSize.fill(((CGMDummyTag)tag).getLength());
                tag = cgm.readTag();
            }
            tree.commit();
            System.out.println("Analyzed file in: "+(System.currentTimeMillis()-start)+" ms.");
        } catch (IOException e) {
            e.printStackTrace();
        } 
    }
}
