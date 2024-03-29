// Copyright 2001-2005 freehep
package org.freehep.graphicsio.pdf;

import java.io.IOException;
import java.awt.Shape;
import java.awt.Font;
import java.awt.geom.PathIterator;
import java.awt.geom.Rectangle2D;
import java.awt.font.GlyphMetrics;
import java.awt.font.FontRenderContext;

import org.freehep.graphics2d.font.Lookup;
import org.freehep.graphics2d.font.CharTable;

/**
 * @author Simon Fischer
 * @version $Id: PDFFontEmbedderType3.java,v 1.2 2005/01/04 00:45:55 duns Exp $
 */
public class PDFFontEmbedderType3 extends PDFFontEmbedder {

    public PDFFontEmbedderType3(FontRenderContext context,
                PDFWriter pdf,
                String reference,
                PDFRedundanceTracker tracker) {
        super(context, pdf, reference, tracker);
    }


    protected String getSubtype() {
        return "Type3";
    }

    protected void addAdditionalEntries(PDFDictionary fontDict)
    throws IOException {
        Rectangle2D boundingBox = getFontBBox();
        double llx = boundingBox.getX();
        double lly = boundingBox.getY();
        double urx = boundingBox.getX()+boundingBox.getWidth();
        double ury = boundingBox.getY()+boundingBox.getHeight();
        fontDict.entry("FontBBox", new double[] { llx, lly, urx, ury });

        fontDict.entry("FontMatrix", new double[] {1/FONT_SIZE,0,
                                                   0,1/FONT_SIZE,
                                                   0,0});

        fontDict.entry("CharProcs", pdf.ref(getReference()+"CharProcs"));

        PDFDictionary resources = fontDict.openDictionary("Resources");
        resources.entry("ProcSet", new Object[] { pdf.name("PDF") });
        fontDict.close(resources);
    }

    protected void addAdditionalInitDicts() throws IOException {
        // CharProcs
        PDFDictionary charProcs = pdf.openDictionary(getReference()+"CharProcs");
        //boolean undefined = false;
        for (int i = 0; i < 256; i++) {
            String charName = getEncodingTable().toName(i);
            if (charName != null) {
                charProcs.entry(charName,
                        pdf.ref(createCharacterReference(charName)));
            } else {
                //undefined = true;
            }
        }
        //if (undefined)
        charProcs.entry(NOTDEF, pdf.ref(createCharacterReference(NOTDEF)));
        pdf.close(charProcs);
    }

    protected void writeGlyph(String characterName, Shape glyph,
                  GlyphMetrics glyphMetrics) throws IOException {

        PDFStream glyphStream =
            pdf.openStream(createCharacterReference(characterName),
                   new String[] { "Flate", "ASCII85" });

        Rectangle2D bounds = glyphMetrics != null ?
            glyphMetrics.getBounds2D() :
            glyph.getBounds2D();
        double advance = glyphMetrics != null ?
            glyphMetrics.getAdvance() :
            getUndefinedWidth();
        glyphStream.glyph(advance, 0,
                  bounds.getX(), bounds.getY(),
                  bounds.getX()+bounds.getWidth(), bounds.getY()+bounds.getHeight());

        boolean windingRule = glyphStream.drawPath(glyph);
        if (windingRule) {
            glyphStream.fillEvenOdd();
        } else {
            glyphStream.fill();
        }
        pdf.close(glyphStream);
    }
}
