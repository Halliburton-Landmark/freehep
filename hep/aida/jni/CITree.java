package hep.aida.jni;

import java.io.*;

import hep.aida.*;

public class CITree extends CProxy implements ITree {

    public CITree(long crefID) {
        super(crefID);
    }

    public native  String storeName();

    public native  IManagedObject find(String path) throws IllegalArgumentException;

    public native  ITree findTree(String path) throws IllegalArgumentException;

    public native  void cd(String path) throws IllegalArgumentException;

    public native  String pwd();

    public native  void ls() throws IllegalArgumentException;
    public native  void ls(String path) throws IllegalArgumentException;
    public native  void ls(String path, boolean recursive) throws IllegalArgumentException;
    public native  void ls(String path, boolean recursive, OutputStream os) throws IllegalArgumentException;

    public native  String[] listObjectNames() throws IllegalArgumentException;
    public native  String[] listObjectNames(String path) throws IllegalArgumentException;
    public native  String[] listObjectNames(String path, boolean recursive) throws IllegalArgumentException;

    public native  String[] listObjectTypes() throws IllegalArgumentException;
    public native  String[] listObjectTypes(String path) throws IllegalArgumentException;
    public native  String[] listObjectTypes(String path, boolean recursive) throws IllegalArgumentException;

    public native  void mkdir(String path) throws IllegalArgumentException;

    public native  void mkdirs(String path) throws IllegalArgumentException;

    public native  void rmdir(String path) throws IllegalArgumentException;

    public native  void rm(String path) throws IllegalArgumentException;

    public native  String findPath(IManagedObject object) throws IllegalArgumentException;

    public native  void mv(String oldPath, String newPath) throws IllegalArgumentException;

    public native  void commit() throws IOException;

    public native  void setOverwrite();
    public native  void setOverwrite(boolean overwrite);

    public native  void cp(String oldPath, String newPath) throws IllegalArgumentException;
    public native  void cp(String oldPath, String newPath, boolean recursive) throws IllegalArgumentException;

    public native  void symlink(String path, String alias) throws IllegalArgumentException;

    public native  void mount(String path, ITree tree, String treePath) throws IllegalArgumentException;

    public native  void unmount(String path) throws IllegalArgumentException;

    public native  void close() throws IOException;

//    public native  boolean isReadOnly();
}

