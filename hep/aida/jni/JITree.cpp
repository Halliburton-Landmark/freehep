
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IManagedObject.h"
#include "AIDA/ITree.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JIDataPointSet.h"
#include "JIFunction.h"
#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"
#include "JITree.h"
#include "JITuple.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JITree::JITree(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {

    jclass cls = env->GetObjectClass(getRef());

    cdOLjava_lang_StringECVMethod = env->GetMethodID(cls, "cd", "(Ljava/lang/String;)V");
    if (cdOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "cd" << "(Ljava/lang/String;)V" << std::endl;
    }

    mvOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "mv", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (mvOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "mv" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    unmountOLjava_lang_StringECVMethod = env->GetMethodID(cls, "unmount", "(Ljava/lang/String;)V");
    if (unmountOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "unmount" << "(Ljava/lang/String;)V" << std::endl;
    }

    listObjectNamesOLjava_lang_StringEZCALjava_lang_StringEMethod = env->GetMethodID(cls, "listObjectNames", "(Ljava/lang/String;Z)[Ljava/lang/String;");
    if (listObjectNamesOLjava_lang_StringEZCALjava_lang_StringEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "listObjectNames" << "(Ljava/lang/String;Z)[Ljava/lang/String;" << std::endl;
    }

    mkdirsOLjava_lang_StringECVMethod = env->GetMethodID(cls, "mkdirs", "(Ljava/lang/String;)V");
    if (mkdirsOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "mkdirs" << "(Ljava/lang/String;)V" << std::endl;
    }

    findPathOLhep_aida_IManagedObjectECLjava_lang_StringEMethod = env->GetMethodID(cls, "findPath", "(Lhep/aida/IManagedObject;)Ljava/lang/String;");
    if (findPathOLhep_aida_IManagedObjectECLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "findPath" << "(Lhep/aida/IManagedObject;)Ljava/lang/String;" << std::endl;
    }

    mkdirOLjava_lang_StringECVMethod = env->GetMethodID(cls, "mkdir", "(Ljava/lang/String;)V");
    if (mkdirOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "mkdir" << "(Ljava/lang/String;)V" << std::endl;
    }

    mountOLjava_lang_StringELhep_aida_ITreeELjava_lang_StringECVMethod = env->GetMethodID(cls, "mount", "(Ljava/lang/String;Lhep/aida/ITree;Ljava/lang/String;)V");
    if (mountOLjava_lang_StringELhep_aida_ITreeELjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "mount" << "(Ljava/lang/String;Lhep/aida/ITree;Ljava/lang/String;)V" << std::endl;
    }

    setOverwriteOZCVMethod = env->GetMethodID(cls, "setOverwrite", "(Z)V");
    if (setOverwriteOZCVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "setOverwrite" << "(Z)V" << std::endl;
    }

    closeOCVMethod = env->GetMethodID(cls, "close", "()V");
    if (closeOCVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "close" << "()V" << std::endl;
    }

    cpOLjava_lang_StringELjava_lang_StringEZCVMethod = env->GetMethodID(cls, "cp", "(Ljava/lang/String;Ljava/lang/String;Z)V");
    if (cpOLjava_lang_StringELjava_lang_StringEZCVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "cp" << "(Ljava/lang/String;Ljava/lang/String;Z)V" << std::endl;
    }

    symlinkOLjava_lang_StringELjava_lang_StringECVMethod = env->GetMethodID(cls, "symlink", "(Ljava/lang/String;Ljava/lang/String;)V");
    if (symlinkOLjava_lang_StringELjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "symlink" << "(Ljava/lang/String;Ljava/lang/String;)V" << std::endl;
    }

    listObjectTypesOLjava_lang_StringEZCALjava_lang_StringEMethod = env->GetMethodID(cls, "listObjectTypes", "(Ljava/lang/String;Z)[Ljava/lang/String;");
    if (listObjectTypesOLjava_lang_StringEZCALjava_lang_StringEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "listObjectTypes" << "(Ljava/lang/String;Z)[Ljava/lang/String;" << std::endl;
    }

    findOLjava_lang_StringECLhep_aida_IManagedObjectEMethod = env->GetMethodID(cls, "find", "(Ljava/lang/String;)Lhep/aida/IManagedObject;");
    if (findOLjava_lang_StringECLhep_aida_IManagedObjectEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "find" << "(Ljava/lang/String;)Lhep/aida/IManagedObject;" << std::endl;
    }

    pwdOCLjava_lang_StringEMethod = env->GetMethodID(cls, "pwd", "()Ljava/lang/String;");
    if (pwdOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "pwd" << "()Ljava/lang/String;" << std::endl;
    }

    storeNameOCLjava_lang_StringEMethod = env->GetMethodID(cls, "storeName", "()Ljava/lang/String;");
    if (storeNameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "storeName" << "()Ljava/lang/String;" << std::endl;
    }

    rmOLjava_lang_StringECVMethod = env->GetMethodID(cls, "rm", "(Ljava/lang/String;)V");
    if (rmOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "rm" << "(Ljava/lang/String;)V" << std::endl;
    }

    lsOLjava_lang_StringEZLjava_io_OutputStreamECVMethod = env->GetMethodID(cls, "ls", "(Ljava/lang/String;ZLjava/io/OutputStream;)V");
    if (lsOLjava_lang_StringEZLjava_io_OutputStreamECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "ls" << "(Ljava/lang/String;ZLjava/io/OutputStream;)V" << std::endl;
    }

    rmdirOLjava_lang_StringECVMethod = env->GetMethodID(cls, "rmdir", "(Ljava/lang/String;)V");
    if (rmdirOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "rmdir" << "(Ljava/lang/String;)V" << std::endl;
    }

    commitOCVMethod = env->GetMethodID(cls, "commit", "()V");
    if (commitOCVMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "commit" << "()V" << std::endl;
    }

    findTreeOLjava_lang_StringECLhep_aida_ITreeEMethod = env->GetMethodID(cls, "findTree", "(Ljava/lang/String;)Lhep/aida/ITree;");
    if (findTreeOLjava_lang_StringECLhep_aida_ITreeEMethod == NULL) {
        std::cerr << "ITree" << ": Could not find method: " << "findTree" << "(Ljava/lang/String;)Lhep/aida/ITree;" << std::endl;
    }
}

JNIEXPORT JITree::~JITree() {
}

JNIEXPORT std::string JITree::storeName() const {
    // Call to Java
    jstring jstoreName = (jstring)env->CallObjectMethod(ref, storeNameOCLjava_lang_StringEMethod);
    if (jstoreName == NULL) return emptyString;

    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jstoreName, &isCopy);
    string storeNameString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jstoreName, utf);
    return storeNameString;
}

JNIEXPORT IManagedObject * JITree::find(const std::string & path) {
	jstring jpath;
	NEWSTRING(jpath, path)
 	jobject obj = env->CallObjectMethod(ref, findOLjava_lang_StringECLhep_aida_IManagedObjectEMethod, jpath);
    DELSTRING(jpath);
	if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIManagedObject(env, obj);
}

JNIEXPORT ITree * JITree::findTree(const std::string & path) {
	jstring jpath;
	NEWSTRING(jpath, path)
 	jobject obj = env->CallObjectMethod(ref, findTreeOLjava_lang_StringECLhep_aida_ITreeEMethod, jpath);
    DELSTRING(jpath);
	if (JNIUtil::exceptions(env)) return NULL;
    return factory->createITree(env, obj);
}

JNIEXPORT bool JITree::cd(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, cdOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JITree::pwd() const {
    // Call to Java
    jstring jpwd = (jstring)env->CallObjectMethod(ref, pwdOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jpwd, &isCopy);
    string pwdString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jpwd, utf);
    return pwdString;
}

JNIEXPORT bool JITree::ls(const std::string & path, bool recursive, std::ostream & os) const {
    // FIXME 4.0, hard to do with an ostream...
    std::cerr << "'JITree.ls(..)' not implemented, because ostream is inconvertible into a java.io.OutputStream." << std::endl;
    return true;
}

JNIEXPORT std::vector<std::string>  JITree::listObjectNames(const std::string & path, bool recursive) const {
    std::vector<std::string> result;
    jstring jpath;
    NEWSTRING(jpath, path)

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, listObjectNamesOLjava_lang_StringEZCALjava_lang_StringEMethod, jpath, recursive);
    DELSTRING(jpath)
    // NOTE: return empty list in case of failure
    if (JNIUtil::exceptions(env)) return result;

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            result.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string>  JITree::listObjectTypes(const std::string & path, bool recursive) const {
    std::vector<std::string> result;
    jstring jpath;
    NEWSTRING(jpath, path)

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, listObjectTypesOLjava_lang_StringEZCALjava_lang_StringEMethod, jpath, recursive);
    DELSTRING(jpath)
    // NOTE: return empty list in case of failure
    if (JNIUtil::exceptions(env)) return result;

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            result.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT bool JITree::mkdir(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, mkdirOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::mkdirs(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, mkdirsOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::rmdir(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, rmdirOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::rm(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, rmOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT std::string JITree::findPath(const IManagedObject & object) const {
    jobject jmanagedObject = factory->create(env, object);
    // Call to Java
    jstring jpath = (jstring)env->CallObjectMethod(ref, findPathOLhep_aida_IManagedObjectECLjava_lang_StringEMethod, jmanagedObject);
    string path;
    if (jpath != NULL) {
        // converting String to string
        jboolean isCopy;
        const char* utf = env->GetStringUTFChars(jpath, &isCopy);
        path = utf;
        if (isCopy) env->ReleaseStringUTFChars(jpath, utf);
    } else {
        path = emptyString;
    }
	if (JNIUtil::exceptions(env)) return emptyString;
	else return path;
}

JNIEXPORT bool JITree::mv(const std::string & oldPath, const std::string & newPath) {
    jstring joldPath, jnewPath;
    NEWSTRING(joldPath, oldPath)
    NEWSTRING(jnewPath, newPath)
    env->CallVoidMethod(ref, mvOLjava_lang_StringELjava_lang_StringECVMethod, joldPath, jnewPath);
    DELSTRING(jnewPath)
    DELSTRING(joldPath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::commit() {
    env->CallVoidMethod(ref, commitOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void JITree::setOverwrite(bool overwrite) {
    env->CallVoidMethod(ref, setOverwriteOZCVMethod, overwrite);
    JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JITree::cp(const std::string & oldPath, const std::string & newPath, bool recursive) {
    jstring joldPath, jnewPath;
    NEWSTRING(joldPath, oldPath)
    NEWSTRING(jnewPath, newPath)
    env->CallVoidMethod(ref, cpOLjava_lang_StringELjava_lang_StringEZCVMethod, joldPath, jnewPath, recursive);
    DELSTRING(jnewPath)
    DELSTRING(joldPath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::symlink(const std::string & path, const std::string & alias) {
    jstring jpath, jalias;
    NEWSTRING(jpath, path)
    NEWSTRING(jalias, alias)
    env->CallVoidMethod(ref, symlinkOLjava_lang_StringELjava_lang_StringECVMethod, jpath, jalias);
    DELSTRING(jalias)
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::mount(const std::string & path, ITree & tree, const std::string & treePath) {
    jstring jpath, jtreePath;
    jobject jtree = factory->create(env, tree);
    NEWSTRING(jpath, path)
    NEWSTRING(jtreePath, treePath)
    env->CallVoidMethod(ref, mountOLjava_lang_StringELhep_aida_ITreeELjava_lang_StringECVMethod,
            jpath, jtree, jtreePath);
    DELSTRING(jtreePath)
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::unmount(const std::string & path) {
    jstring jpath;
    NEWSTRING(jpath, path)
    env->CallVoidMethod(ref, unmountOLjava_lang_StringECVMethod, jpath);
    DELSTRING(jpath)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITree::close() {
    env->CallVoidMethod(ref, closeOCVMethod);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JITree::cast(const std::string & className) const {
    return (className == "AIDA::ITree") ? (void *)this : NULL;
}
