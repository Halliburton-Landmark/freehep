/*
 * TestForm.java
 *
 * Created on June 14, 2001, 5:38 PM
 */

package org.freehep.j3d.plot.test;
import org.freehep.j3d.plot.*;
import java.awt.Toolkit;
import java.text.NumberFormat;
import java.text.ParseException;
import java.util.Locale;

/**
 *
 * @author  tonyj
 */
public class LegoControlPanel extends javax.swing.JPanel {

   /** Creates new form TestForm */
    public LegoControlPanel(LegoPlot plot) {
        this.lego = plot;
        this.plot = plot;
        initComponents();
        savedSparsThreshold = lego.getSparsifyThreshold();
    }

    /** This method is called from within the constructor to
     * initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is
     * always regenerated by the Form Editor.
     */
    private void initComponents() {//GEN-BEGIN:initComponents
        buttonGroup1 = new javax.swing.ButtonGroup();
        PlotTypePanel = new javax.swing.JPanel();
        jRadioButton1 = new javax.swing.JRadioButton();
        jRadioButton2 = new javax.swing.JRadioButton();
        jRadioButton3 = new javax.swing.JRadioButton();
        OptionPanel = new javax.swing.JPanel();
        jCheckBox1 = new javax.swing.JCheckBox();
        jCheckBox2 = new javax.swing.JCheckBox();
        AnimationPanel = new javax.swing.JPanel();
        jCheckBox3 = new javax.swing.JCheckBox();
        jCheckBox4 = new javax.swing.JCheckBox();
        jPanel5 = new javax.swing.JPanel();
        jLabel4 = new javax.swing.JLabel();
        jTextField4 = new javax.swing.JTextField();
        AxisLabelPanel = new javax.swing.JPanel();
        jLabel1 = new javax.swing.JLabel();
        jTextField1 = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jTextField2 = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jTextField3 = new javax.swing.JTextField();
        
        
        setLayout(new java.awt.BorderLayout());
        
        PlotTypePanel.setLayout(new java.awt.FlowLayout(java.awt.FlowLayout.CENTER, 5, 0));
        
        PlotTypePanel.setBorder(new javax.swing.border.TitledBorder("Plot Type"));
        jRadioButton1.setSelected(lego.getDrawBlocks());
        jRadioButton1.setText("Lego Plot");
        buttonGroup1.add(jRadioButton1);
        jRadioButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton1ActionPerformed(evt);
            }
        });
        
        PlotTypePanel.add(jRadioButton1);
        
        jRadioButton2.setToolTipText("a lego with vertical lines instead of boxes");
        jRadioButton2.setSelected(!lego.getDrawBlocks());
        jRadioButton2.setText("Line Plot");
        buttonGroup1.add(jRadioButton2);
        jRadioButton2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton2ActionPerformed(evt);
            }
        });
        
        PlotTypePanel.add(jRadioButton2);
        
        jRadioButton3.setText("Surface Plot");
        buttonGroup1.add(jRadioButton3);
        jRadioButton3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jRadioButton3ActionPerformed(evt);
            }
        });
        
        PlotTypePanel.add(jRadioButton3);
        
        add(PlotTypePanel, java.awt.BorderLayout.NORTH);
        
        OptionPanel.setLayout(new javax.swing.BoxLayout(OptionPanel, javax.swing.BoxLayout.Y_AXIS));
        
        OptionPanel.setBorder(new javax.swing.border.TitledBorder("Options"));
        jCheckBox1.setSelected(lego.getLogZscaling());
        jCheckBox1.setText("Log Z Axis");
        jCheckBox1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCheckBox1ActionPerformed(evt);
            }
        });
        
        OptionPanel.add(jCheckBox1);
        
        jCheckBox2.setToolTipText("Perspective or Parallel projection");
        jCheckBox2.setSelected(!lego.getParallelProjection());
        jCheckBox2.setText("Perspective");
        jCheckBox2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                JCheckBox2ActionPerformed(evt);
            }
        });
        
        OptionPanel.add(jCheckBox2);
        
        add(OptionPanel, java.awt.BorderLayout.WEST);
        
        AnimationPanel.setLayout(new javax.swing.BoxLayout(AnimationPanel, javax.swing.BoxLayout.Y_AXIS));
        
        AnimationPanel.setBorder(new javax.swing.border.TitledBorder("Animation"));
        jCheckBox3.setSelected(lego.getLinesWhileAnim());
        jCheckBox3.setText("Lines while animating");
        jCheckBox3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCheckBox3ActionPerformed(evt);
            }
        });
        
        AnimationPanel.add(jCheckBox3);
        
        jCheckBox4.setSelected(true);
        jCheckBox4.setText("Sparsification");
        jCheckBox4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jCheckBox4ActionPerformed(evt);
            }
        });
        
        AnimationPanel.add(jCheckBox4);
        
        jPanel5.setAlignmentX(0.0F);
        jLabel4.setText("Threshold");
        jLabel4.setToolTipText("Suggested # wire bins to draw when sparsifying");
        jLabel4.setForeground(java.awt.Color.black);
        jPanel5.add(jLabel4);
        
        jTextField4.setColumns(8);
        jTextField4.setText(String.valueOf(lego.getSparsifyThreshold()));
        jTextField4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField4ActionPerformed(evt);
            }
        });
        
        jPanel5.add(jTextField4);
        
        AnimationPanel.add(jPanel5);
        
        add(AnimationPanel, java.awt.BorderLayout.CENTER);
        
        AxisLabelPanel.setLayout(new java.awt.GridBagLayout());
        java.awt.GridBagConstraints gridBagConstraints1;
        
        AxisLabelPanel.setBorder(new javax.swing.border.TitledBorder("Axis Labels"));
        jLabel1.setText("X");
        jLabel1.setForeground(java.awt.Color.black);
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        gridBagConstraints1.ipadx = 5;
        AxisLabelPanel.add(jLabel1, gridBagConstraints1);
        
        jTextField1.setToolTipText("Type a new X Axis Label & press Enter");
        jTextField1.setColumns(20);
        jTextField1.setText(lego.getXAxisLabel());
        jTextField1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField1ActionPerformed(evt);
            }
        });
        
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        gridBagConstraints1.gridwidth = java.awt.GridBagConstraints.REMAINDER;
        AxisLabelPanel.add(jTextField1, gridBagConstraints1);
        
        jLabel2.setText("Y");
        jLabel2.setForeground(java.awt.Color.black);
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        gridBagConstraints1.ipadx = 5;
        AxisLabelPanel.add(jLabel2, gridBagConstraints1);
        
        jTextField2.setToolTipText("Type a new Y Axis Label & press Enter");
        jTextField2.setColumns(20);
        jTextField2.setText(lego.getYAxisLabel());
        jTextField2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField2ActionPerformed(evt);
            }
        });
        
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        gridBagConstraints1.gridwidth = java.awt.GridBagConstraints.REMAINDER;
        AxisLabelPanel.add(jTextField2, gridBagConstraints1);
        
        jLabel3.setText("Z");
        jLabel3.setForeground(java.awt.Color.black);
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        gridBagConstraints1.ipadx = 5;
        AxisLabelPanel.add(jLabel3, gridBagConstraints1);
        
        jTextField3.setToolTipText("Type a new Z Axis Label & press Enter");
        jTextField3.setColumns(20);
        jTextField3.setText(lego.getZAxisLabel());
        jTextField3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField3ActionPerformed(evt);
            }
        });
        
        gridBagConstraints1 = new java.awt.GridBagConstraints();
        AxisLabelPanel.add(jTextField3, gridBagConstraints1);
        
        add(AxisLabelPanel, java.awt.BorderLayout.SOUTH);
        
    }//GEN-END:initComponents

    private void jRadioButton3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jRadioButton3ActionPerformed
        // Add your handling code here:
        // User has selected Surface Plot
        if (jRadioButton3.isSelected()) {
            try {
                surf = DemoGUI.getSurfacePlot();
                plot = surf;
                surf.setLogZscaling(jCheckBox1.isSelected());
                surf.setParallelProjection(!jCheckBox2.isSelected());
                surf.setXAxisLabel(jTextField1.getText());
                surf.setYAxisLabel(jTextField2.getText());
                surf.setZAxisLabel(jTextField3.getText());
                jCheckBox3.setEnabled(false);
                jCheckBox4.setEnabled(false);
                jLabel4.setEnabled(false);
                jTextField4.setEnabled(false);
            }
            catch (Exception e) {
            }
        }
    }//GEN-LAST:event_jRadioButton3ActionPerformed

    private void jCheckBox4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBox4ActionPerformed
        // Add your handling code here:
        if (jCheckBox4.isSelected()) {
            jTextField4.setEnabled(true);
            jLabel4.setEnabled(true);
            try {
                int i = java.lang.Integer.getInteger(jTextField4.getText()).intValue();
                lego.setSparsifyThreshold(i == Integer.MAX_VALUE ? savedSparsThreshold : i);
            }
            catch (Exception e) {
                jTextField4.setText("600");
                lego.setSparsifyThreshold(600);
            }
        }
        else {
            jTextField4.setEnabled(false);
            jLabel4.setEnabled(false);
            savedSparsThreshold = lego.getSparsifyThreshold();
            lego.setSparsifyThreshold(Integer.MAX_VALUE);
        }
    }//GEN-LAST:event_jCheckBox4ActionPerformed

    private void JCheckBox2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_JCheckBox2ActionPerformed
        // Add your handling code here:
        plot.setParallelProjection(!jCheckBox2.isSelected());
    }//GEN-LAST:event_JCheckBox2ActionPerformed

    private void jTextField3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField3ActionPerformed
        // Add your handling code here:
        if (plot instanceof SurfacePlot) 
            surf.setZAxisLabel(jTextField3.getText());
        else
            lego.setZAxisLabel(jTextField3.getText());
    }//GEN-LAST:event_jTextField3ActionPerformed

    private void jTextField2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField2ActionPerformed
        // Add your handling code here:
        if (plot instanceof SurfacePlot) 
            surf.setYAxisLabel(jTextField2.getText());
        else
            lego.setYAxisLabel(jTextField2.getText());
    }//GEN-LAST:event_jTextField2ActionPerformed

    private void jCheckBox3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBox3ActionPerformed
        // Add your handling code here:
        lego.setLinesWhileAnim(jCheckBox3.isSelected());
        if (!jCheckBox3.isSelected()) {
            jCheckBox4.setEnabled(false);
            jLabel4.setEnabled(false);
            jTextField4.setEnabled(false);
        }
        else {
            jTextField4.setEnabled(true);
            jLabel4.setEnabled(true);
            int i = lego.getSparsifyThreshold();
            jTextField4.setText(java.lang.Integer.toString(i == Integer.MAX_VALUE ? savedSparsThreshold : i));
            jCheckBox4.setSelected(true);
        }
    }//GEN-LAST:event_jCheckBox3ActionPerformed

    private void jCheckBox1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBox1ActionPerformed
        if (plot instanceof SurfacePlot) 
            surf.setLogZscaling(jCheckBox1.isSelected());
        else
            lego.setLogZscaling(jCheckBox1.isSelected());
    }//GEN-LAST:event_jCheckBox1ActionPerformed

    private void jTextField4ActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_jTextField4ActionPerformed
    {//GEN-HEADEREND:event_jTextField4ActionPerformed
       // Add your handling code here:
        Toolkit toolkit = Toolkit.getDefaultToolkit();
        NumberFormat integerFormatter = NumberFormat.getNumberInstance(Locale.US);
        integerFormatter.setParseIntegerOnly(true);
        int retVal = 600;
        try {
            retVal = integerFormatter.parse(jTextField4.getText()).intValue();
        } catch (ParseException e) {
            // System.out.println("in jTextField4ActionPerformed: parse exception");
            toolkit.beep();
            jTextField4.setText("600");
        }
        jTextField4.setText(java.lang.Integer.toString(retVal));
        lego.setSparsifyThreshold(retVal);
       // System.out.println("in jTextField4ActionPerformed: retval="+retVal);
    }//GEN-LAST:event_jTextField4ActionPerformed

    private void jTextField1ActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_jTextField1ActionPerformed
    {//GEN-HEADEREND:event_jTextField1ActionPerformed
       // Add your handling code here:
        if (plot instanceof SurfacePlot) 
            surf.setXAxisLabel(jTextField1.getText());
        else
            lego.setXAxisLabel(jTextField1.getText());
    }//GEN-LAST:event_jTextField1ActionPerformed

    private void jRadioButton2ActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_jRadioButton2ActionPerformed
    {//GEN-HEADEREND:event_jRadioButton2ActionPerformed
       // Add your handling code here:
        // System.out.println("in jRadioButton2ActionPerformed");
        if (jRadioButton2.isSelected()) {    // Line Plot (Radio Button)
            lego.setDrawBlocks(false);          // Tell plot to draw wire lines
            setPlotToLego();                    // Ensure lego/line plot is in the canvas
            jCheckBox3.setEnabled(false);       // Disable "Lines while animating" check box in GUI
        }
    }//GEN-LAST:event_jRadioButton2ActionPerformed

    private void jRadioButton1ActionPerformed(java.awt.event.ActionEvent evt)//GEN-FIRST:event_jRadioButton1ActionPerformed
    {//GEN-HEADEREND:event_jRadioButton1ActionPerformed
       // Add your handling code here:
        // System.out.println("in jRadioButton1ActionPerformed");
        if (jRadioButton1.isSelected()) {   // Lego Plot (radio button)
            lego.setDrawBlocks(true);           // Tell lego to draw blocks
            jCheckBox3.setEnabled(true);        // Enable "Lines while animating" check box
            setPlotToLego();                    // Ensure lego/line plot is in the canvas
        }
    }//GEN-LAST:event_jRadioButton1ActionPerformed

    // Ensure that lego/line plot is now in the canvas,
    // Update it with the GUI's current settings, & ensure the animation panel is enabled
    private void setPlotToLego()
    {
        if (plot instanceof SurfacePlot) {
            lego.setLogZscaling(jCheckBox1.isSelected());
            lego.setParallelProjection(!jCheckBox2.isSelected());
            lego.setXAxisLabel(jTextField1.getText());
            lego.setYAxisLabel(jTextField2.getText());
            lego.setZAxisLabel(jTextField3.getText());
            plot = DemoGUI.getLegoPlot();           // Set the canvas to lego plot
            // System.out.println("setting plot to Lego");
            jCheckBox3.setEnabled(true);
            jCheckBox4.setEnabled(true);
            jLabel4.setEnabled(true);
            jTextField4.setEnabled(true);
        }
    }
    
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.ButtonGroup buttonGroup1;
    private javax.swing.JPanel PlotTypePanel;
    private javax.swing.JRadioButton jRadioButton1;
    private javax.swing.JRadioButton jRadioButton2;
    private javax.swing.JRadioButton jRadioButton3;
    private javax.swing.JPanel OptionPanel;
    private javax.swing.JCheckBox jCheckBox1;
    private javax.swing.JCheckBox jCheckBox2;
    private javax.swing.JPanel AnimationPanel;
    private javax.swing.JCheckBox jCheckBox3;
    private javax.swing.JCheckBox jCheckBox4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JTextField jTextField4;
    private javax.swing.JPanel AxisLabelPanel;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JTextField jTextField1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JTextField jTextField2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JTextField jTextField3;
    // End of variables declaration//GEN-END:variables
    private LegoPlot lego;
    private SurfacePlot surf;
    private Plot3D plot;
    private int savedSparsThreshold;
}
