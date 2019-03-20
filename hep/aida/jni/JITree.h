// -*- C++ -*-
#ifndef JAIDA_JITREE_H
#define JAIDA_JITREE_H 1

//  This file is part of the AIDA library
//  Copyright (C) 2002 by the AIDA team.  All rights reserved.
//  This library is free software and under the terms of the
//  GNU Library General Public License described in the LGPL.txt

#include <iostream>
#include <jni.h>
#include <string>
#include <vector>

#include "AIDA/IManagedObject.h"
#include "AIDA/ITree.h"
#include "JAID/JAIDRef.h"

#include "JProxy.h"

namespace JAIDA {

/**
 * User level interface to a Tree.
 *
 * All paths follow unix convention .., ., /,
 * backslash is the escape character.
 * Relative paths are allowed.
 *
 * NOTE: - this tree keeps a current position(pwd) within the tree.
 * This may be implemented on a per-thread basis.
 *
 * @author The AIDA team (http://aida.freehep.org/)
 *
 */

class JITree: public JProxy, public virtual AIDA::ITree {

private:
    jmethodID cdOLjava_lang_StringECVMethod;
    jmethodID mvOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID unmountOLjava_lang_StringECVMethod;
    jmethodID listObjectNamesOLjava_lang_StringEZCALjava_lang_StringEMethod;
    jmethodID mkdirsOLjava_lang_StringECVMethod;
    jmethodID findPathOLhep_aida_IManagedObjectECLjava_lang_StringEMethod;
    jmethodID mkdirOLjava_lang_StringECVMethod;
    jmethodID mountOLjava_lang_StringELhep_aida_ITreeELjava_lang_StringECVMethod;
    jmethodID setOverwriteOZCVMethod;
    jmethodID closeOCVMethod;
    jmethodID cpOLjava_lang_StringELjava_lang_StringEZCVMethod;
    jmethodID symlinkOLjava_lang_StringELjava_lang_StringECVMethod;
    jmethodID listObjectTypesOLjava_lang_StringEZCALjava_lang_StringEMethod;
    jmethodID findOLjava_lang_StringECLhep_aida_IManagedObjectEMethod;
    jmethodID pwdOCLjava_lang_StringEMethod;
    jmethodID storeNameOCLjava_lang_StringEMethod;
    jmethodID rmOLjava_lang_StringECVMethod;
    jmethodID lsOLjava_lang_StringEZLjava_io_OutputStreamECVMethod;
    jmethodID rmdirOLjava_lang_StringECVMethod;
    jmethodID commitOCVMethod;
    jmethodID findTreeOLjava_lang_StringECLhep_aida_ITreeEMethod;
    
    std::string emptyString;

protected:
    inline JITree() { };
    inline JITree(const JITree& r):JProxy(r) { };
    inline JITree& operator=(const JITree&) { return *this; };

public:
    /**
     * Default JNI Constructor
     */
    JNIEXPORT JITree(JNIEnv *env, jobject object, const ProxyFactory & factory);

    /// Destructor.
    JNIEXPORT virtual ~JITree();

  /**
   * Get the name of the store.
   * @return The store's name.
   *
   */
    JNIEXPORT virtual std::string storeName() const;

  /**
   * Get the IManagedObject at a given path in the ITree. The path can either be
   * absolute or relative to the current working directory.
   * @param path The path.
   * @return     The corresponding IManagedObject.
   *
   */
    JNIEXPORT virtual AIDA::IManagedObject * find(const std::string & path);

  /**
   * Get a mounted ITree at a given path in the current ITree. The path can either be
   * absolute or relative to the current working directory.
   * @param path The path.
   * @return     The corresponding ITree.
   *
   */
    JNIEXPORT virtual AIDA::ITree * findTree(const std::string & path);

  /**
   * Change to a given directory.
   * @param path The absolute or relative path of the directory we are changing to.
   * @return false If the path does not exist.
   *
   */
    JNIEXPORT virtual bool cd(const std::string & path);

  /**
   * Get the path of the current working directory.
   * @return The path of the current working directory.
   *
   */
    JNIEXPORT virtual std::string pwd() const;

  /**
   * List, into a given output stream, all the IManagedObjects, including directories
   * (but not "." and ".."), in a given path. Directories end with "/". The list can be recursive.
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   * @param os        The output stream into which the list is dumped (by default the standard output).
   * @return false If the path does not exist.
   *
   */
    JNIEXPORT virtual bool ls(const std::string & path, bool recursive, std::ostream & os) const;

  /**
   * Get the list of names of the IManagedObjects under a given path, including directories
   * (but not "." and ".."). Directories end with "/".
   * The returned names are appended to the given path unless the latter is ".".
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   *
   */
    JNIEXPORT virtual std::vector<std::string>  listObjectNames(const std::string & path, bool recursive) const;

  /**
   * Get the list of types of the IManagedObjects under a given path.
   * The types are the leaf class of the Interface, e.g. "IHistogram1D", "ITuple", etc.
   * Directories are marked with "dir".
   * The order of the types is the same as the order for the listObjectNames() method
   * to achieve a one-to-one correspondance between object names and types.
   * @param path      The path where the list has to be performed (by default the current directory ".").
   * @param recursive If <code>true</code> the list is extended recursively
   *                  in all the directories under path (the default is <code>false</code>.
   *
   */
    JNIEXPORT virtual std::vector<std::string>  listObjectTypes(const std::string & path, bool recursive) const;

  /**
   * Create a new directory. Given a path only the last directory
   * in it is created if all the intermediate subdirectories already exist.
   * @param path The absolute or relative path of the new directory.
   * @return false If a subdirectory within the path does
   *             not exist or it is not a directory. Also if the directory already exists.
   *
   */
    JNIEXPORT virtual bool mkdir(const std::string & path);

  /**
   * Create a directory recursively. Given a path the last directory
   * and all the intermediate non-existing subdirectories are created.
   * @param path The absolute or relative path of the new directory.
   * @return false If an intermediate subdirectory
   *             is not a directory, or if the directory already exists.
   *
   */
    JNIEXPORT virtual bool mkdirs(const std::string & path);

  /**
   * Remove a directory and all the contents underneeth.
   * @param path The absolute or relative path of the directory to be removed.
   * @return false If path does not exist or if it is not
   *             a directory.
   *
   */
    JNIEXPORT virtual bool rmdir(const std::string & path);

  /**
   * Remove an IManagedObject by specifying its path.
   * If the path points to a mount point, the mount point should first commit, then
   * close and delete the tree object.
   * @param path The absolute or relative path of the IManagedObject to be removed.
   * @return false If path does not exist.
   *
   */
    JNIEXPORT virtual bool rm(const std::string & path);

  /**
   * Get the full path of an IManagedObject.
   * @param object The IManagedObject whose path is to be returned.
   * @return       The object's absolute path.
   *               In C++ if the object does not exist, an empty string is returned.
   *
   */
    JNIEXPORT virtual std::string findPath(const AIDA::IManagedObject & object) const;

  /**
   * Move an IManagedObject or a directory from one directory to another.
   * @param oldPath The path of the IManagedObject or direcoty to be moved.
   * @param newPath The path of the diretory in which the object has to be moved to.
   * @return false If either path does not exist.
   *
   */
    JNIEXPORT virtual bool mv(const std::string & oldPath, const std::string & newPath);

  /**
   * Commit any open transaction to the underlying store(s).
   * It flushes objects into the disk for non-memory-mapped stores.
   * @return false If the underlying store cannot be written out.
   *
   */
    JNIEXPORT virtual bool commit();

  /**
   * Set the strategy of what should happen if two objects have the same path.
   * Default is overwrite.
   * @param overwrite <code>true</code> to enable overwriting.
   *
   */
    JNIEXPORT virtual void setOverwrite(bool overwrite);

  /**
   * Copy an object from a path to another.
   * @param oldPath   The path of the object to be copied.
   * @param newPath   The path where the object is to be copied.
   * @param recursive <code>true</code> if a recursive copy has to be performed.
   * @return false If either path does not exist.
   *
   */
    JNIEXPORT virtual bool cp(const std::string & oldPath, const std::string & newPath, bool recursive);

  /**
   * Create a symbolic link to an object in the ITree.
   * @param path  The absolute or relative path of the object to be linked.
   * @param alias The absolute or relative name of the link.
   * @return false If path or any
   *              subidrectory within path does not exist.
   *
   */
    JNIEXPORT virtual bool symlink(const std::string & path, const std::string & alias);

  /**
   * Mounts a tree within another (target) tree. A tree can only be mounted once.
   * Example:
   * <pre>
   *     target.mount("/home/tonyj",tree,"/");
   * </pre>
   * @param path     The path in the target tree
   * @param tree     The tree to mount within the target tree
   * @param treePath The mount point within the tree to be mounted.
   * @return false If something does not exist.
   *
   */
    JNIEXPORT virtual bool mount(const std::string & path, AIDA::ITree & tree, const std::string & treePath);

  /**
   * Unmount a subtree at a given path (mount point).
   * Whenever a tree is destroyed it first unmounts all dependent trees.
   * @param path The path of the subtree to be unmounted.
   * @return false If path does not exist.
   *
   */
    JNIEXPORT virtual bool unmount(const std::string & path);

  /**
   * Closes the underlying store.
   * Changes will be saved only if commit() has been called before.
   * The call is propagated to the dependent mounted trees.
   * @return false If there are problems writing out
   *         the underlying store.
   *
   */
    JNIEXPORT virtual bool close();

  /**
   *  See IManagedObject for a description.
   * @param className The name of the class to cast on.
   * @return The right pointer. Return 0 if failure.
   */ 
    JNIEXPORT virtual void * cast(const std::string & className) const;
}; // class
} // namespace JAIDA
#endif /* ifndef JAIDA_JITREE_H */
