
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AIDA/IFunction.h"
#include "AIDA/IFunctionCatalog.h"
#include "JIFunction.h"
#include "JIFunctionCatalog.h"
#include "JIFunctionFactory.h"
#include "JIModelFunction.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIFunctionFactory::JIFunctionFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    cloneFunctionOLjava_lang_StringELhep_aida_IFunctionECLhep_aida_IFunctionEMethod = env->GetMethodID(cls, "cloneFunction", "(Ljava/lang/String;Lhep/aida/IFunction;)Lhep/aida/IFunction;");
    if (cloneFunctionOLjava_lang_StringELhep_aida_IFunctionECLhep_aida_IFunctionEMethod == NULL) {
        std::cerr << "IFunctionFactory" << ": Could not find method: " << "cloneFunction" << "(Ljava/lang/String;Lhep/aida/IFunction;)Lhep/aida/IFunction;" << std::endl;
    }

    createFunctionByNameOLjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod = env->GetMethodID(cls, "createFunctionByName", "(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;");
    if (createFunctionByNameOLjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod == NULL) {
        std::cerr << "IFunctionFactory" << ": Could not find method: " << "createFunctionByName" << "(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;" << std::endl;
    }

    createFunctionFromScriptOLjava_lang_StringEILjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod = env->GetMethodID(cls, "createFunctionFromScript", "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;");
    if (createFunctionFromScriptOLjava_lang_StringEILjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod == NULL) {
        std::cerr << "IFunctionFactory" << ": Could not find method: " << "createFunctionFromScript" << "(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;" << std::endl;
    }

    catalogOCLhep_aida_IFunctionCatalogEMethod = env->GetMethodID(cls, "catalog", "()Lhep/aida/IFunctionCatalog;");
    if (catalogOCLhep_aida_IFunctionCatalogEMethod == NULL) {
        std::cerr << "IFunctionFactory" << ": Could not find method: " << "catalog" << "()Lhep/aida/IFunctionCatalog;" << std::endl;
    }
}

JNIEXPORT JIFunctionFactory::~JIFunctionFactory() {
}

JNIEXPORT IFunction * JIFunctionFactory::createFunctionByName(const std::string & name, const std::string & model) {
    jstring jname, jmodel;
    NEWSTRING(jname, name)
    NEWSTRING(jmodel, model)
    jobject obj = env->CallObjectMethod(ref, createFunctionByNameOLjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod, jname, jmodel);
    DELSTRING(jmodel)
    DELSTRING(jname)
    if (JNIUtil::exceptions(env)) return NULL;
    return factory->createIFunction(env, obj);
}

JNIEXPORT IFunction * JIFunctionFactory::createFunctionFromScript(const std::string & name, int dim, const std::string & valexpr, const std::string & parameters, const std::string & description, const std::string & gradexpr) {
    jstring jname, jvalexpr, jparameters, jdescription, jgradexpr;
    NEWSTRING(jname, name)
    NEWSTRING(jvalexpr, valexpr)
    NEWSTRING(jparameters, parameters)
    NEWSTRING(jdescription, description)
    NEWSTRING(jgradexpr, gradexpr)
    jobject obj = env->CallObjectMethod(ref, createFunctionFromScriptOLjava_lang_StringEILjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_IFunctionEMethod,
                        jname, dim, jvalexpr, jparameters, jdescription, jgradexpr);
    DELSTRING(jgradexpr)
    DELSTRING(jdescription)
    DELSTRING(jparameters)
    DELSTRING(jvalexpr)
    DELSTRING(jname)
    if (JNIUtil::exceptions(env)) return NULL;
    return factory->createIFunction(env, obj);
}

JNIEXPORT IFunction * JIFunctionFactory::cloneFunction(const std::string & name, IFunction & f) {
    jstring jname;
    jobject jfun = factory->create(env, f);
    NEWSTRING(jname, name)
    jobject obj = env->CallObjectMethod(ref, cloneFunctionOLjava_lang_StringELhep_aida_IFunctionECLhep_aida_IFunctionEMethod, jfun);
    DELSTRING(jname)
    if (JNIUtil::exceptions(env)) return NULL;
    return factory->createIFunction(env, obj);
}

JNIEXPORT IFunctionCatalog * JIFunctionFactory::catalog() {
    jobject obj = env->CallObjectMethod(ref, catalogOCLhep_aida_IFunctionCatalogEMethod);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createIFunctionCatalog(env, obj);
}
