/*
 * StreamerInfoTreeModel.java
 *
 * Created on June 2, 2001, 4:09 PM
 */
package hep.io.root.util;

import hep.io.root.interfaces.*;

import java.util.*;

import javax.swing.tree.*;


/**
 * A tree model for viewing StreamerInfo in a root file
 * @author tonyj
 * @version $Id: StreamerInfoTreeModel.java,v 1.2 2003/04/24 19:36:23 tonyj Exp $
 */
public class StreamerInfoTreeModel implements TreeModel
{
   private List root;

   /** Creates new StreamerInfoTreeModel */
   public StreamerInfoTreeModel(List streamerInfoList)
   {
      root = streamerInfoList;
   }

   public Object getChild(Object parent, int index)
   {
      if (parent instanceof List)
         return ((List) parent).get(index);
      else if (parent instanceof TStreamerInfo)
         return ((TStreamerInfo) parent).getElements().getElementAt(index);
      else
         return null;
   }

   public int getChildCount(Object parent)
   {
      if (parent instanceof List)
         return ((List) parent).size();
      else if (parent instanceof TStreamerInfo)
         return ((TStreamerInfo) parent).getElements().size();
      else
         return 0;
   }

   public int getIndexOfChild(Object parent, Object child)
   {
      if (parent instanceof List)
         return ((List) parent).indexOf(child);
      else if (parent instanceof TStreamerInfo)
         return ((TStreamerInfo) parent).getElements().indexOf(child);
      else
         return 0;
   }

   public boolean isLeaf(Object obj)
   {
      return !(obj instanceof List || obj instanceof TStreamerInfo);
   }

   public Object getRoot()
   {
      return root;
   }

   public void addTreeModelListener(javax.swing.event.TreeModelListener treeModelListener) {}

   public void removeTreeModelListener(javax.swing.event.TreeModelListener treeModelListener) {}

   // The remaining methods are not needed since tree is immutable
   public void valueForPathChanged(javax.swing.tree.TreePath treePath, java.lang.Object obj) {}
}
