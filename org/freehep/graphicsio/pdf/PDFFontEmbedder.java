// Copyright 2001-2005 freehep
package org.freehep.graphicsio.pdf;

import java.io.IOException;
import java.awt.Shape;
import java.awt.Font;
import java.awt.geom.PathIterator;
import java.awt.geom.Rectangle2D;
import java.awt.font.GlyphMetrics;
import java.awt.font.FontRenderContext;

import org.freehep.graphics2d.font.CharTable;
import org.freehep.graphicsio.font.FontEmbedder;

/**
 *  Superclass of all FontEmbedders for PDF documents. Subclasses must implement
 *  all abstract methods which are called in the following order:
 *  <ul>
 *    <li>addAdditionalEntries
 *    <li>addAdditionalInitDicts
 *    <li>writeGlyph once for each glyph in the order of the encoding
 *  </ul>
 * @author Simon Fischer
 * @version $Id: PDFFontEmbedder.java,v 1.2 2005/01/04 00:45:54 duns Exp $
 */
public abstract class PDFFontEmbedder extends FontEmbedder {

    /** sloppily declared protected */
    protected PDFWriter pdf;

    private PDFDictionary fontDict;
    private String reference;
    private PDFRedundanceTracker redundanceTracker;

    public PDFFontEmbedder(FontRenderContext context,
               PDFWriter pdf,
               String reference,
               PDFRedundanceTracker tracker) {
        super(context);
        this.pdf = pdf;
        this.reference = reference;
        this.redundanceTracker = tracker;
    }

    /** Returns the font subtype (currently only Type3). */
    protected abstract String getSubtype();

    /** Add additional entries to the font Dictionary. */
    protected abstract void addAdditionalEntries(PDFDictionary fontDict)
            throws IOException;

    /** Add additional dicionaries to the PDFWriter which may be referenced by
     *  entries generated by <tt>addAdditionalEntries()</tt>*/
    protected abstract void addAdditionalInitDicts() throws IOException;


    /** Returns the reference String that identifies the font dictionary.
     *  Use this reference plus underscore plus suffix for other dictionaries. */
    protected String getReference() {
        return reference;
    }

    protected void openIncludeFont() throws IOException {

        fontDict = pdf.openDictionary(reference);

        fontDict.entry("Type", pdf.name("Font"));
        fontDict.entry("Subtype", pdf.name(getSubtype()));
        fontDict.entry("Name", pdf.name(getFontName()));

        fontDict.entry("FirstChar", 0);
        fontDict.entry("LastChar", 255);
        //fontDict.entry("Encoding", pdf.ref(reference+"Encoding"));
        fontDict.entry("Encoding",
                   redundanceTracker.getReference(getEncodingTable(),
                                  PDFCharTableWriter.getInstance()));
        fontDict.entry("Widths", pdf.ref(reference+"Widths"));

        addAdditionalEntries(fontDict);

        pdf.close(fontDict);

        addAdditionalInitDicts();
    }

    protected void closeEmbedFont() {
    }

    protected void writeWidths(double[] widths) throws IOException {
        Object[] widthsObj = new Object[256];
        for (int i = 0; i < widthsObj.length; i++) {
            widthsObj[i] = new Double(widths[i]);
        }
        pdf.object(reference+"Widths", widthsObj);
    }

    protected void writeEncoding(CharTable charTable) throws IOException {
        //writeEncoding(pdf, reference+"Encoding", charTable);
    }

    public static void writeEncoding(PDFWriter pdf, String ref, CharTable charTable)
            throws IOException {
        PDFDictionary encoding = pdf.openDictionary(ref);
        encoding.entry("Type", pdf.name("Encoding"));

        Object[] differences = new Object[257];
        differences[0] = new Integer(0);
        for (int i = 0; i < 256; i++) {
            String charName = charTable.toName(i);
            differences[i+1] = (charName != null) ? pdf.name(charName) : pdf.name(NOTDEF);
        }
        encoding.entry("Differences", differences);

        pdf.close(encoding);
    }

    protected String createCharacterReference(String characterName) {
        return "Glyph_"+reference+":"+characterName;
    }

}
