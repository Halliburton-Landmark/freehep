
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/ITree.h"
#include "ProxyFactory.h"
#include "JITreeFactory.h"
#include "JITree.h"
#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;

JNIEXPORT JITreeFactory::JITreeFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createOLjava_lang_StringELjava_lang_StringEZZLjava_lang_StringECLhep_aida_ITreeEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)Lhep/aida/ITree;");
    if (createOLjava_lang_StringELjava_lang_StringEZZLjava_lang_StringECLhep_aida_ITreeEMethod == NULL) {
        std::cerr << "ITreeFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)Lhep/aida/ITree;" << std::endl;
    }

    createOCLhep_aida_ITreeEMethod = env->GetMethodID(cls, "create", "()Lhep/aida/ITree;");
    if (createOCLhep_aida_ITreeEMethod == NULL) {
        std::cerr << "ITreeFactory" << ": Could not find method: " << "create" << "()Lhep/aida/ITree;" << std::endl;
    }

}

JNIEXPORT JITreeFactory::~JITreeFactory() {
}

JNIEXPORT ITree * JITreeFactory::create() {
 	jobject obj = env->CallObjectMethod(ref, createOCLhep_aida_ITreeEMethod);
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createITree(env, obj);
}

JNIEXPORT ITree * JITreeFactory::create(const std::string & storeName, const std::string & storeType, bool readOnly, bool createNew, const std::string & options) {
	jstring jstoreType, jstoreName, joptions;
	NEWSTRING(jstoreType, storeType)
	NEWSTRING(jstoreName, storeName)
	NEWSTRING(joptions, options)
 	jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELjava_lang_StringEZZLjava_lang_StringECLhep_aida_ITreeEMethod, jstoreName, jstoreType, readOnly, createNew, joptions);
        DELSTRING(jstoreType);
        DELSTRING(jstoreName);
	DELSTRING(joptions);
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createITree(env, obj);
}
