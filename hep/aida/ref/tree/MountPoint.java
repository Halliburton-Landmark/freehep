package hep.aida.ref.tree;

import hep.aida.*;
import hep.aida.ref.event.*;

/**
 * A mount point allows one tree to be "mounted" in another.
 * Mount point extends Folder so that it appears as just another folder
 * to the tree, but it overrides all of Folders methods and forwards
 * them to the mountPoint within the mounted tree.
 * @author tonyj
 * @version $Id: MountPoint.java,v 1.9 2005/11/01 02:08:35 serbo Exp $
 */
public class MountPoint extends Folder implements AIDAListener {
    private Folder mountPoint;
    private Tree tree;
    private Tree source;
    private boolean isUnmounted = false;
    
    int mountDepth;
    String[] prefix;
    
    MountPoint(Tree source, Path prefix, Tree tree, Folder mountPoint, Path mountPath) {
        super(prefix.getName());
        this.tree = tree;
        this.mountPoint = mountPoint;
        this.source = source;
        this.prefix = prefix.toArray();
        this.mountDepth = mountPath.size();
        tree.addListener(this);
    }
    public void stateChanged(java.util.EventObject e) {
        if ( ! isUnmounted ) {
            TreeEvent te = (TreeEvent) e;
            String [] oldPath = te.getPath();
            int newDepth = oldPath.length - mountDepth + prefix.length;
            String[] newPath = new String[newDepth];
            int i=0;
            for (; i<prefix.length; i++) newPath[i] = prefix[i];
            for (; i<newDepth; i++) newPath[i] = oldPath[i-prefix.length+mountDepth];
            TreeEvent newEvent = new TreeEvent(source, te.getID(), newPath, te.getType(), te.getFlags());
            source.fireStateChanged(newEvent);
        }
    }
    
    IManagedObject getChild(int index) {
        return mountPoint.getChild(index);
    }
    
    IManagedObject getChild(String name) {
        return mountPoint.getChild(name);
    }
    
    protected void unmount() {
        boolean wasUnmounted = isUnmounted;
        isUnmounted = true;
        if ( ! wasUnmounted ) {
            Tree t = getTree();
            t.removeListener(this);
            try {
                if (t.decrementMountCount() == 0) t.close();
            } catch (java.io.IOException ioe) {
                throw new RuntimeException( ioe.getMessage() );
            }
        }
    }
    
    
    int getChildCount() {
        return mountPoint.getChildCount();
    }
    
    int getIndexOfChild(IManagedObject child) {
        return mountPoint.getIndexOfChild(child);
    }
    
    void add(IManagedObject object) {
        mountPoint.add(object);
    }
    
    void remove(IManagedObject child) {
        mountPoint.remove(child);
    }
    public String type() {
        return "mnt";
    }
    public Tree getTree() {
        return tree;
    }
    
    void setIsBeingWatched(boolean value) {
        super.setIsBeingWatched(value);
        mountPoint.setIsBeingWatched(value);
    }
    
}