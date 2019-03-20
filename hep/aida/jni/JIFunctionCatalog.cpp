
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IFunction.h"
#include "JIFunction.h"
#include "JIFunctionCatalog.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIFunctionCatalog::JIFunctionCatalog(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    addOLjava_lang_StringELjava_lang_StringECZMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Ljava/lang/String;)Z");
    if (addOLjava_lang_StringELjava_lang_StringECZMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "add" << "(Ljava/lang/String;Ljava/lang/String;)Z" << std::endl;
    }

    addOLjava_lang_StringELhep_aida_IFunctionECZMethod = env->GetMethodID(cls, "add", "(Ljava/lang/String;Lhep/aida/IFunction;)Z");
    if (addOLjava_lang_StringELhep_aida_IFunctionECZMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "add" << "(Ljava/lang/String;Lhep/aida/IFunction;)Z" << std::endl;
    }

    storeAllOLjava_lang_StringECVMethod = env->GetMethodID(cls, "storeAll", "(Ljava/lang/String;)V");
    if (storeAllOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "storeAll" << "(Ljava/lang/String;)V" << std::endl;
    }

    removeOLjava_lang_StringECVMethod = env->GetMethodID(cls, "remove", "(Ljava/lang/String;)V");
    if (removeOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "remove" << "(Ljava/lang/String;)V" << std::endl;
    }

    listOCALjava_lang_StringEMethod = env->GetMethodID(cls, "list", "()[Ljava/lang/String;");
    if (listOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "list" << "()[Ljava/lang/String;" << std::endl;
    }

    loadAllOLjava_lang_StringECVMethod = env->GetMethodID(cls, "loadAll", "(Ljava/lang/String;)V");
    if (loadAllOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "IFunctionCatalog" << ": Could not find method: " << "loadAll" << "(Ljava/lang/String;)V" << std::endl;
    }

}

JNIEXPORT JIFunctionCatalog::~JIFunctionCatalog() {
}

JNIEXPORT bool JIFunctionCatalog::add(std::string nameId, IFunction * func) {
    jobject jfunction = factory->create(env, *func);
    jstring jnameId;
    NEWSTRING(jnameId, nameId)
    jboolean result = env->CallBooleanMethod(ref, addOLjava_lang_StringELhep_aida_IFunctionECZMethod, jnameId, jfunction);
    DELSTRING(jnameId)
	JNIUtil::checkExceptions(env);
	return result;
}

JNIEXPORT bool JIFunctionCatalog::add(std::string nameId, const std::string & codelet) {
    jstring jnameId, jcodelet;
    NEWSTRING(jnameId, nameId)
    NEWSTRING(jcodelet, codelet)
    jboolean result = env->CallBooleanMethod(ref, addOLjava_lang_StringELjava_lang_StringECZMethod, jnameId, jcodelet );
    DELSTRING(jnameId)
    DELSTRING(jcodelet)
	JNIUtil::checkExceptions(env);
    return result;
}

JNIEXPORT std::vector<std::string> JIFunctionCatalog::list() {
    std::vector<std::string> listVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, listOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            listVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return listVector;
}

JNIEXPORT void JIFunctionCatalog::remove(const std::string & nameId) {
    jstring jnameId;
    NEWSTRING(jnameId, nameId)
    env->CallVoidMethod(ref, removeOLjava_lang_StringECVMethod, jnameId);
    DELSTRING(jnameId)
	JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JIFunctionCatalog::storeAll(const std::string & nameOnDisk) {
    jstring jnameOnDisk;
    NEWSTRING(jnameOnDisk, nameOnDisk)
    env->CallVoidMethod(ref, storeAllOLjava_lang_StringECVMethod, jnameOnDisk);
    DELSTRING(jnameOnDisk)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JIFunctionCatalog::loadAll(const std::string & nameOnDisk) {
    jstring jnameOnDisk;
    NEWSTRING(jnameOnDisk, nameOnDisk)
    env->CallVoidMethod(ref, loadAllOLjava_lang_StringECVMethod, jnameOnDisk);
    DELSTRING(jnameOnDisk)
	return !JNIUtil::exceptions(env);
}
