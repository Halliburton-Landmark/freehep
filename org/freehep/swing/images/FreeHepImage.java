package org.freehep.swing.images;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

import javax.swing.*;

import org.freehep.util.images.*;

public class FreeHepImage extends TempImageHandler {

    // only static methods
    protected FreeHepImage() {
    }

    public static Image getImage(String name) {
        return getImage(name, FreeHepImage.class);
    }

    public static Cursor getCursor(String name) {
        return getCursor(name, FreeHepImage.class);
    }

    public static Cursor getCursor(String name, int x, int y) {
        return getCursor(name, FreeHepImage.class, x, y);
    }

    public static Icon getIcon(String name) {
        return getIcon(name, FreeHepImage.class);
    }

}
