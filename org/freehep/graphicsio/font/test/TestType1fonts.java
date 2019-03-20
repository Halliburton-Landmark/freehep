// Copyright 2003-2005, FreeHEP.
package org.freehep.graphicsio.font.test;

import java.awt.Font;
import java.io.*;
import java.awt.font.FontRenderContext;

import org.freehep.graphics2d.font.Lookup;
import org.freehep.graphicsio.font.FontIncluder;
import org.freehep.graphicsio.font.FontEmbedderType1;

public class TestType1fonts {

    public static void main(String[] argv) {

	try {

	    FontIncluder fi = new FontEmbedderType1(new FontRenderContext(null, true, true),
						    System.out, false);

	    fi.includeFont(new Font("arial", Font.PLAIN, 1000),
			   Lookup.getInstance().getTable("PDFLatin"),
			   "MyFont");

	} catch (Exception e) {
	    e.printStackTrace();
	}
    }
}
