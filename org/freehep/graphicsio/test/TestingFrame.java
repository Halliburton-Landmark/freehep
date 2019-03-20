// Copyright 2001-2005, FreeHEP.
package org.freehep.graphicsio.test;

import java.awt.*;
import java.awt.datatransfer.*;
import java.awt.event.*;
import javax.swing.*;

import javax.swing.border.*;

import java.io.FileOutputStream;
import java.io.OutputStream;

import org.freehep.graphicsio.*;
import org.freehep.util.export.*;

/**
 * @author Charles Loomis
 * @author Mark Donszelmann
 * @version $Id: TestingFrame.java,v 1.6 2005/01/06 00:51:42 duns Exp $
 */
public class TestingFrame
    extends JFrame {

    private String title;
    private ExportDialog dialog;

    private JComponent singlePanel;
    private JTabbedPane multiPanel;

    public TestingFrame(String title) {

        // Title this frame.
        super(title);
        this.title = title;
        
        // Make this exit when the close button is clicked.
        setDefaultCloseOperation(WindowConstants.
                                 DO_NOTHING_ON_CLOSE);
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {quit();}
        });

        // Create the Export dialog.
        dialog = new ExportDialog();

        // Make a menu bar
        JMenuBar menuBar = new JMenuBar();

        // File Menu
        JMenu file = new JMenu("File");
        menuBar.add(file);

        // Add Export...
        JMenuItem export = new JMenuItem("Export...");
        file.add(export);
        export.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                export();
            }
        });

        // Add Quit...
        JMenuItem quit = new JMenuItem("Quit");
        file.add(quit);
        quit.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                quit();
            }
        });

        // Edit Menu
        JMenu edit = new JMenu("Edit");
        menuBar.add(edit);

        // Add Copy
        JMenuItem copy = new JMenuItem("Copy");
        edit.add(copy);
        copy.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                copy();
            }
        });

        // Add this to the frame.
        setJMenuBar(menuBar);
    }

    public void export() {
        if (multiPanel != null) {
            // FIXME the current export dialog does not allow to write multiple files at once...
            dialog.showExportDialog(this, "Export...", multiPanel.getSelectedComponent(), title);
        } else if (singlePanel != null) {
            dialog.showExportDialog(this, "Export...", singlePanel, title);
        } else {
            System.err.println("Failed to export");
        }
    }   
    
    public void addPanel(JComponent c) {
        addPanel(null, c);
    }

    /**
     * Add a test panel to the frame. 
     */
    public void addPanel(String name, JComponent c) {

        if (name == null) {
            singlePanel = c;
            setContentPane(singlePanel);
        } else {
            if (multiPanel == null) {
                multiPanel = new JTabbedPane();
                setContentPane(multiPanel);
            }
            multiPanel.addTab(name, c);
        }

        // Create a border of white surrounded by black.
        Border border = BorderFactory.createCompoundBorder( BorderFactory.createMatteBorder(1,1,1,1,Color.white),
                                                            BorderFactory.createMatteBorder(2,2,2,2,Color.green));
        c.setBorder(border);
    }

    public void copy() {
        Clipboard clipBoard = Toolkit.getDefaultToolkit().getSystemClipboard();
        VectorGraphicsTransferable transferable = new VectorGraphicsTransferable(multiPanel == null ? singlePanel : multiPanel.getSelectedComponent());
        clipBoard.setContents(transferable, transferable);
    }

    public void quit() {
        int n = JOptionPane.showConfirmDialog(this, "Do you really want to quit?", "Confirm Quit", JOptionPane.YES_NO_OPTION);

        if (n==JOptionPane.YES_OPTION) System.exit(0);
    }

}
