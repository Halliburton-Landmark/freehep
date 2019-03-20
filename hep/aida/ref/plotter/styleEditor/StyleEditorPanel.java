/*
 * StyleEditorPanel.java
 *
 * Created on June 14, 2005, 9:32 AM
 */

package hep.aida.ref.plotter.styleEditor;

import java.awt.*;
import java.awt.event.*;
import java.beans.PropertyChangeEvent;
import java.beans.PropertyChangeListener;
import java.util.Random;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import javax.swing.tree.*;

import hep.aida.*;
import hep.aida.ref.plotter.*;

import com.l2fprod.common.swing.LookAndFeelTweaks;
import com.l2fprod.common.propertysheet.*;

/**
 *
 * @author  serbo
 */
public class StyleEditorPanel extends JSplitPane implements TreeSelectionListener, PropertyChangeListener {
    private IPlotterStyle style;
    private JComboBox previewTypeBox;
    private Class previewType = IHistogram1D.class;
    private JTree styleTree;
    private DefaultTreeModel styleModel;
    private StylePreviewCreator stylePreviewCreator;
    private JSplitPane rightPanel;
    private boolean previewFitRegion = true;

    private PropertySheetPanel currentStylePanel;

    /** Creates a new instance of StyleEditorPanel */
    public StyleEditorPanel(IPlotterStyle style) {
        this(style, null, StylePreviewCreator.getPossiblePreviewTypes()[0]);
    }
    
    public StyleEditorPanel(IPlotterStyle style, Class previewType) {
        this(style, null, previewType);
    }
    
    public StyleEditorPanel(IPlotterStyle style, ConfigurePreviewPanel configurePanel) {
        this(style, configurePanel, StylePreviewCreator.getPossiblePreviewTypes()[0]);
    }
    
    public StyleEditorPanel(IPlotterStyle style, ConfigurePreviewPanel configurePanel, Class previewType) {
        super(JSplitPane.HORIZONTAL_SPLIT);
        init(style, configurePanel, previewType);
    }
    
    public IPlotterStyle getStyle() { return style; }
    
    public void setCurrentPreviewPanelDimension(Dimension d) {
        if (d.width < 0 && d.height < 0) {
            previewFitRegion = true;
        } else {
            previewFitRegion = false;
        }
        stylePreviewCreator.setPreviewPanelDimension(d);
        updatePreview();
    }
    
    public Dimension getCurrentPreviewPanelDimension() {
        return ((JComponent) rightPanel.getBottomComponent()).getComponent(1).getSize();
    }
    
    public void setupEditorPanel(ConfigurePreviewPanel configurePanel) {
        stylePreviewCreator.setupPreviewCreator(configurePanel);
        Dimension d = null;
        if (configurePanel == null || configurePanel.previewFitRegion) {
            d = new Dimension(-1, -1);
            previewFitRegion = true;
        } else {
            d = new Dimension(configurePanel.previewWidth, configurePanel.previewHeight);   
            previewFitRegion = false;
        }
        setCurrentPreviewPanelDimension(d);
    }
    
    public void clear() {
        if (styleTree != null) styleTree.removeTreeSelectionListener(this);
        
    }
    
    public void setPreviewType(Class previewType) {
        previewTypeBox.setSelectedItem(previewType.getName());
    }
    void executeSetPreviewType(Class previewType) {
        this.previewType = previewType;
        updatePreview();
    }
   
    public Class getPreviewType() { return previewType; }
    
    public void updatePreview() {
        //int dl = rightPanel.getDividerLocation();
        //rightPanel.setBottomComponent(stylePreviewCreator.getPreviewPanel(style, previewType));
        JComponent bp = (JComponent) rightPanel.getBottomComponent();
        try {
            bp.getComponent(1);
            bp.remove(1);
        } catch (ArrayIndexOutOfBoundsException e) { }
        
        JComponent newComponent = stylePreviewCreator.getPreviewPanel(style, previewType);
        
        if (previewFitRegion) {
            Dimension d = null;
            newComponent.setMaximumSize(d);
            newComponent.setPreferredSize(d);
            newComponent.setMinimumSize(d);
        }
        bp.add(newComponent, BorderLayout.CENTER);
        //rightPanel.setDividerLocation(dl);
    }
    
    private void init(IPlotterStyle ps, ConfigurePreviewPanel configurePanel, Class previewType) {
        this.style = ps;
        this.previewType = previewType;
        
        rightPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT);
        createStyleTree(ps);
        
        this.setRightComponent(rightPanel);
        this.setDividerLocation(200);
        rightPanel.setDividerLocation(250);
        
        JPanel bp = new JPanel();
        bp.setLayout(new BoxLayout(bp, BoxLayout.Y_AXIS));
        
        Class[] possibleTypes = StylePreviewCreator.getPossiblePreviewTypes();
        String[] possibleTypesString = new String[possibleTypes.length];
        for (int i=0; i<possibleTypes.length; i++) { possibleTypesString[i] = possibleTypes[i].getName(); }
        previewTypeBox = new JComboBox(possibleTypesString);
        previewTypeBox.setSelectedItem(previewType.getName());
        previewTypeBox.addItemListener(new  ItemListener() {
            public void itemStateChanged(ItemEvent evt) {
                if (evt.getStateChange() == ItemEvent.SELECTED) {
                    try {
                        Class pt = Class.forName((String) evt.getItem());
                        executeSetPreviewType(pt);
                    } catch (Exception e) { e.printStackTrace(); }
                }
            }
        });
        
        JPanel toolsPanel = new JPanel(new FlowLayout(FlowLayout.LEFT));
        toolsPanel.add(new JLabel("Preview Type: "));
        toolsPanel.add(previewTypeBox);
        bp.add(toolsPanel);
        
        rightPanel.setBottomComponent(bp);
        
        
        //(JComponent) rightPanel.getBottomComponent()).addPropertyChangeListener(this);

        stylePreviewCreator = new StylePreviewCreator(configurePanel);
        previewFitRegion = configurePanel.previewFitRegion;
        
        styleTree.expandRow(0);
        styleTree.setSelectionRow(0);
        updatePreview();
    }
    
    private void createStyleTree(IPlotterStyle plotterStyle) {
        StyleTreeNode rootNode = new StyleTreeNode(plotterStyle, false);
        TreePath rootPath = new TreePath(rootNode);
        styleModel = new DefaultTreeModel(rootNode);
        styleTree = new JTree(styleModel);
        
        styleTree.addTreeSelectionListener(this);
        this.setLeftComponent(new JScrollPane(styleTree));
    }
       
   
    // TreeSelectionListener methods
    
    public void valueChanged(TreeSelectionEvent e) {
        Object obj = e.getNewLeadSelectionPath().getLastPathComponent();
        if (obj instanceof StyleTreeNode) {
            StyleTreeNode node = (StyleTreeNode) obj;
            JComponent panel = node.getStylePanel();
            int rdl = rightPanel.getDividerLocation();
            
            //Component tc = rightPanel.getTopComponent();
            if (currentStylePanel != null) currentStylePanel.removePropertySheetChangeListener(this);
            
            rightPanel.setTopComponent(panel);
            rightPanel.setDividerLocation(rdl);
            if (panel instanceof PropertySheetPanel) {
                currentStylePanel = (PropertySheetPanel) panel;
                currentStylePanel.addPropertySheetChangeListener(this);
            }
        }
    }
    

    // PropertyChangeLisener methods
    
    public void propertyChange(PropertyChangeEvent evt) {
        Property prop = (Property)evt.getSource();
        updatePreview();
    }
    
    public static void main(String[] args) throws Exception {
        //UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        //LookAndFeelTweaks.tweak();
        
        JFrame frame = new JFrame("PropertySheet");
        frame.getContentPane().setLayout(new BorderLayout());
        
        IPlotterStyle style = IAnalysisFactory.create().createPlotterFactory().createPlotterStyle();
        
        StyleEditorPanel sePanel = new StyleEditorPanel(style, IHistogram1D.class);
        frame.getContentPane().add("Center", sePanel);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setSize(600, 500);
        Dimension d = Toolkit.getDefaultToolkit().getScreenSize();
        frame.setLocation( (d.width-frame.getSize().width )/2, (d.height-frame.getSize().height )/2 );
        frame.setVisible(true);
    }
    
}
