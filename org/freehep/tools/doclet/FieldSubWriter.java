/*
 * @(#)FieldSubWriter.java	1.30 03/01/23
 *
 * Copyright 2003 Sun Microsystems, Inc. All rights reserved.
 * SUN PROPRIETARY/CONFIDENTIAL. Use is subject to license terms.
 */

package org.freehep.tools.doclet;

import com.sun.tools.doclets.*;
import com.sun.javadoc.*;

/**
 *
 * @author Robert Field
 * @author Atul M Dambalkar
 */
public class FieldSubWriter extends AbstractSubWriter {
    
    public FieldSubWriter(SubWriterHolderWriter writer, ClassDoc classdoc) {
        super(writer, classdoc);
    }
    
    public FieldSubWriter(SubWriterHolderWriter writer) {
        super(writer);
    }
    
    public int getMemberKind() {
        return VisibleMemberMap.FIELDS;
    }
    
    public void printSummaryLabel(ClassDoc cd) {
        writer.boldText("doclet.Field_Summary");
    }
    
    public void printSummaryAnchor(ClassDoc cd) {
        writer.anchor("field_summary");
    }
    
    public void printInheritedSummaryAnchor(ClassDoc cd) {
        writer.anchor("fields_inherited_from_class_" + configuration().getClassName(cd));
    }
    
    public void printInheritedSummaryLabel(ClassDoc cd) {
        String classlink = writer.getPreQualifiedClassLink(cd);
        writer.bold();
        writer.printText(cd.isClass()?
                             "doclet.Fields_Inherited_From_Class":
                             "doclet.Fields_Inherited_From_Interface",
                         classlink);
        writer.boldEnd();
    }
    
    void printSignature(MemberDoc member) {
        FieldDoc field = (FieldDoc)member;
        writer.pre();
        printModifiers(field);
        printTypeLink(field.type());
        print(' ');
        if (configuration().genSrc) {
            writer.printSrcLink(field, field.name());
        } else {
            bold(field.name());
        }
        writer.preEnd();
    }
    
    protected void printSummaryLink(ClassDoc cd, ProgramElementDoc member) {
        String name = member.name();
        writer.bold();
        writer.printClassLink(cd, name, name, false);
        writer.boldEnd();
    }
    
    protected void printInheritedSummaryLink(ClassDoc cd,
                                             ProgramElementDoc member) {
        String name = member.name();
        writer.printClassLink(cd, name, name, false);
    }
    
    protected void printSummaryType(ProgramElementDoc member) {
        FieldDoc field = (FieldDoc)member;
        printModifierAndType(field, field.type());
    }
    
    protected void printHeader(ClassDoc cd) {
        writer.anchor("field_detail");
        writer.printTableHeadingBackground(writer.
                                               getText("doclet.Field_Detail"));
    }
    
    protected void printBodyHtmlEnd(ClassDoc cd) {
    }
    
    protected void printMember(ProgramElementDoc member) {
        FieldDoc field = (FieldDoc)member;
        writer.anchor(field.name());
        printHead(field);
        printSignature(field);
        printFullComment(field);
    }
    
    protected void printDeprecatedLink(ProgramElementDoc member) {
        writer.printClassLink(member.containingClass(), member.name(),
                                  ((FieldDoc)member).qualifiedName());
    }
    
    protected void printNavSummaryLink(ClassDoc cd, boolean link) {
        if (link) {
            writer.printHyperLink("", (cd == null)?
                                      "field_summary":
                                      "fields_inherited_from_class_" +
                                      configuration().getClassName(cd),
                                  writer.getText("doclet.navField"));
        } else {
            writer.printText("doclet.navField");
        }
    }
    
    protected void printNavDetailLink(boolean link) {
        if (link) {
            writer.printHyperLink("", "field_detail",
                                  writer.getText("doclet.navField"));
        } else {
            writer.printText("doclet.navField");
        }
    }
}


