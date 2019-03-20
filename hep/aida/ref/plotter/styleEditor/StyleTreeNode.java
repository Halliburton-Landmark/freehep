/*
 * StyleTreeNode.java
 *
 * Created on June 13, 2005, 6:14 PM
 */

package hep.aida.ref.plotter.styleEditor;

import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;

import java.util.*;
import javax.swing.*;
import javax.swing.border.*;
import javax.swing.tree.*;

import hep.aida.*;
import com.l2fprod.common.propertysheet.*;

/**
 *
 * @author  The FreeHEP team @ SLAC
 */

public class StyleTreeNode implements TreeNode {
    
    private IBaseStyle style;
    private TreePath path;
    private PropertySheetPanel stylePanel;
    private JScrollPane scrollPanel;
    
    private Vector children;
    private int nChildren;
    private boolean recursive;
    private boolean hasBeenFilled = false;
    private StyleTreeNode parent;
    private TreePath parentPath;
    
    
    // Mainly for constructing root node
    public StyleTreeNode(IPlotterStyle style) {
        this(style, true);
    }    
    public StyleTreeNode(IPlotterStyle style, boolean recursive) {
        this(style, null, null, recursive);
    }
    
    // For constructing child nodes
    public StyleTreeNode(IBaseStyle style, StyleTreeNode parent, TreePath parentPath) {
                this(style, parent, parentPath, true);
    }    
    public StyleTreeNode(IBaseStyle style, StyleTreeNode parent, TreePath parentPath, boolean recursive) {
        this.style  = style;
        this.parent = parent;
        this.parentPath = parentPath;
        if (parentPath == null) path = new TreePath(style.name());
        else path = parentPath.pathByAddingChild(style.name());
        
        createChildren();
        
        createPanel();
    }
    
    
    // Service methods
    
    public String toString() { return style.name(); }
    
    public IBaseStyle getStyle() {
        return style;
    }
    
    public JComponent getStylePanel() {
        return stylePanel;
    }
    public JComponent getScrollPanel() {
        return scrollPanel;
    }
    
    private void createChildren() {
        IBaseStyle[] ch = style.children();
        if (ch == null || ch.length == 0) { 
            nChildren = 0;
            children = new Vector();
            hasBeenFilled = true;            
            return;
        }
        nChildren = ch.length;
        
        if (recursive) fillChildren();
    }
    
    private void fillChildren() {
        IBaseStyle[] ch = style.children();
        
        if (children == null) children = new Vector();
        for (int i=0; i<ch.length; i++) {
            StyleTreeNode childNode = new StyleTreeNode(ch[i], this, path, recursive);
            children.add(childNode);
        }
        hasBeenFilled = true;
    }
    
    private void createPanel() {
        PropertySheetTable pt = new PropertySheetTable(new StylePropertyTableModel(style));
        pt.setEditorFactory(new StylePropertyEditorRegistry());
        stylePanel = new PropertySheetPanel(pt);
        stylePanel.setBorder(BorderFactory.createTitledBorder(BorderFactory.createEtchedBorder(EtchedBorder.LOWERED), path.toString()));

        scrollPanel = new JScrollPane(stylePanel);
        
        // everytime a property change, update the button with it
        PropertyChangeListener listener = new PropertyChangeListener() {
            public void propertyChange(PropertyChangeEvent evt) {
                Property prop = (Property)evt.getSource();
                prop.writeToObject(style);
            }
        };
        stylePanel.addPropertySheetChangeListener(listener);
    }
   
    // TreeNode methods
    
    public java.util.Enumeration children() {
        if (!hasBeenFilled) fillChildren();
        return children.elements();
    }
    
    public boolean getAllowsChildren() {
        return (nChildren > 0);
    }
    
    public TreeNode getChildAt(int childIndex) {
        if (!hasBeenFilled) fillChildren();
        return (TreeNode) children.get(childIndex);
    }
    
    public int getChildCount() {
        return nChildren;
    }
    
    public int getIndex(TreeNode node) {
        if (!hasBeenFilled) fillChildren();
        return children.indexOf(node);
    }
    
    public TreeNode getParent() {
        return parent;
    }
    
    public boolean isLeaf() {
        return (nChildren == 0);
    }
}

