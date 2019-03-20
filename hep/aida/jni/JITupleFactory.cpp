
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IEvaluator.h"
#include "AIDA/IFilter.h"
#include "AIDA/ITuple.h"
#include "JITupleFactory.h"
#include "JIEvaluator.h"
#include "JIFilter.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

#include "JITuple.h"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JITupleFactory::JITupleFactory(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    createFilterOLjava_lang_StringEIICLhep_aida_IFilterEMethod = env->GetMethodID(cls, "createFilter", "(Ljava/lang/String;II)Lhep/aida/IFilter;");
    if (createFilterOLjava_lang_StringEIICLhep_aida_IFilterEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createFilter" << "(Ljava/lang/String;II)Lhep/aida/IFilter;" << std::endl;
    }

    createChainedOLjava_lang_StringELjava_lang_StringEALjava_lang_StringECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "createChained", "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Lhep/aida/ITuple;");
    if (createChainedOLjava_lang_StringELjava_lang_StringEALjava_lang_StringECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createChained" << "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Lhep/aida/ITuple;" << std::endl;
    }

    createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "createFiltered", "(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;)Lhep/aida/ITuple;");
    if (createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createFiltered" << "(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;)Lhep/aida/ITuple;" << std::endl;
    }

    createOLjava_lang_StringELjava_lang_StringEALjava_lang_StringEAALhep_aida_ELjava_lang_StringECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/String;)Lhep/aida/ITuple;");
    if (createOLjava_lang_StringELjava_lang_StringEALjava_lang_StringEAALhep_aida_ELjava_lang_StringECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/String;)Lhep/aida/ITuple;" << std::endl;
    }

    createEvaluatorOLjava_lang_StringECLhep_aida_IEvaluatorEMethod = env->GetMethodID(cls, "createEvaluator", "(Ljava/lang/String;)Lhep/aida/IEvaluator;");
    if (createEvaluatorOLjava_lang_StringECLhep_aida_IEvaluatorEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createEvaluator" << "(Ljava/lang/String;)Lhep/aida/IEvaluator;" << std::endl;
    }

    createOLjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "create", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;");
    if (createOLjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "create" << "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;" << std::endl;
    }

    createFilterOLjava_lang_StringECLhep_aida_IFilterEMethod = env->GetMethodID(cls, "createFilter", "(Ljava/lang/String;)Lhep/aida/IFilter;");
    if (createFilterOLjava_lang_StringECLhep_aida_IFilterEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createFilter" << "(Ljava/lang/String;)Lhep/aida/IFilter;" << std::endl;
    }

    createChainedOLjava_lang_StringELjava_lang_StringEAALhep_aida_ECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "createChained", "(Ljava/lang/String;Ljava/lang/String;[Lhep/aida/ITuple;)Lhep/aida/ITuple;");
    if (createChainedOLjava_lang_StringELjava_lang_StringEAALhep_aida_ECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createChained" << "(Ljava/lang/String;Ljava/lang/String;[Lhep/aida/ITuple;)Lhep/aida/ITuple;" << std::endl;
    }

    createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterEALjava_lang_StringECLhep_aida_ITupleEMethod = env->GetMethodID(cls, "createFiltered", "(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;[Ljava/lang/String;)Lhep/aida/ITuple;");
    if (createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterEALjava_lang_StringECLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITupleFactory" << ": Could not find method: " << "createFiltered" << "(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;[Ljava/lang/String;)Lhep/aida/ITuple;" << std::endl;
    }

    // Initialize class types for column types
    GETPRIMITIVECLASS(intClass,         "java/lang/Integer")
    GETPRIMITIVECLASS(shortClass,       "java/lang/Short")
    GETPRIMITIVECLASS(longClass,        "java/lang/Long")
    GETPRIMITIVECLASS(floatClass,       "java/lang/Float")
    GETPRIMITIVECLASS(doubleClass,      "java/lang/Double")
    GETPRIMITIVECLASS(booleanClass,     "java/lang/Boolean")
    GETPRIMITIVECLASS(byteClass,        "java/lang/Byte")
    GETPRIMITIVECLASS(characterClass,   "java/lang/Character")

    stringClass = env->FindClass("java/lang/String");
    objectClass = env->FindClass("java/lang/Object");
    tupleClass =  env->FindClass("hep/aida/ITuple");
}

JNIEXPORT JITupleFactory::~JITupleFactory() {
}

JNIEXPORT ITuple * JITupleFactory::create(const std::string & name, const std::string & title, const std::vector<std::string>  & columnNames, const std::vector<std::string>  & columnTypes, const std::string & options) {
    jstring jname, jtitle, joptions;
    jobjectArray jcolumnNames, jcolumnTypes;
    NEWSTRING(jname, name)
    NEWSTRING(jtitle, title)
    NEWSTRINGARRAY(jcolumnNames, columnNames)
    NEWSTRING(joptions, options)

    // Convert String types to Class types
    jclass classClass = env->FindClass("java/lang/Class");
    jcolumnTypes = (jobjectArray)env->NewObjectArray(columnTypes.size(), classClass, NULL);
    for (unsigned int index=0; index<columnTypes.size(); index++) {
        if (columnTypes[index] == "int") {
            env->SetObjectArrayElement(jcolumnTypes, index, intClass);
        } else if (columnTypes[index] == "short") {
            env->SetObjectArrayElement(jcolumnTypes, index, shortClass);
        } else if (columnTypes[index] == "long") {
            env->SetObjectArrayElement(jcolumnTypes, index, longClass);
        } else if (columnTypes[index] == "float") {
            env->SetObjectArrayElement(jcolumnTypes, index, floatClass);
        } else if (columnTypes[index] == "double") {
            env->SetObjectArrayElement(jcolumnTypes, index, doubleClass);
        } else if (columnTypes[index] == "boolean") {
            env->SetObjectArrayElement(jcolumnTypes, index, booleanClass);
        } else if (columnTypes[index] == "byte") {
            env->SetObjectArrayElement(jcolumnTypes, index, byteClass);
        } else if (columnTypes[index] == "char") {
            env->SetObjectArrayElement(jcolumnTypes, index, characterClass);
        } else if (columnTypes[index] == "string") {
            env->SetObjectArrayElement(jcolumnTypes, index, stringClass);
        } else if (columnTypes[index] == "java.lang.String") {
            // for compatibility with AIDA 3.2.1
            env->SetObjectArrayElement(jcolumnTypes, index, stringClass);
        } else if (columnTypes[index] == "java.lang.Object") {
            env->SetObjectArrayElement(jcolumnTypes, index, objectClass);
        } else if (columnTypes[index] == "ITuple") {
            env->SetObjectArrayElement(jcolumnTypes, index, tupleClass);
        } else if (columnTypes[index] == "hep.aida.ITuple") { 
            // for compatibility with AIDA 3.2.1
            env->SetObjectArrayElement(jcolumnTypes, index, tupleClass);
        } else {
            cerr << "Unknown columnType: " << columnTypes[index] << endl;
        }
    }

    jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELjava_lang_StringEALjava_lang_StringEAALhep_aida_ELjava_lang_StringECLhep_aida_ITupleEMethod, jname, jtitle, jcolumnNames, jcolumnTypes, joptions);
    DELSTRING(jname)
    DELSTRING(jtitle)
    DELSTRINGARRAY(jcolumnNames)
    env->DeleteLocalRef(jcolumnTypes);
    DELSTRING(joptions)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITupleFactory::create(const std::string & name, const std::string & title, const std::string & columns, const std::string & options) {
    jstring jname, jtitle, joptions, jcolumns;
   
    string compatibleColumns = columns;
    
    // backward compatibility with JAIDA 3.2.0, remove for JAIDA-45
    string s = "string";
    string r = "java.lang.String";
    string::size_type pos = compatibleColumns.find(s);
    while (pos != string::npos) {
        compatibleColumns = compatibleColumns.replace(pos, s.size(), r);
        pos = compatibleColumns.find(s, pos+r.size());
    }
   
    // backward compatibility with JAIDA 3.2.0, remove for JAIDA-45
    s = "ITuple";
    r = "hep.aida.ITuple";
    pos = compatibleColumns.find(s);
    while (pos != string::npos) {
        compatibleColumns.replace(pos, s.size(), r);
        pos = compatibleColumns.find(s, pos+r.size());
    }
   
    NEWSTRING(jname, name)
    NEWSTRING(jtitle, title)
    NEWSTRING(jcolumns, compatibleColumns)
    NEWSTRING(joptions, options)
    jobject obj = env->CallObjectMethod(ref, createOLjava_lang_StringELjava_lang_StringELjava_lang_StringELjava_lang_StringECLhep_aida_ITupleEMethod, jname, jtitle, jcolumns, joptions);
    DELSTRING(jname)
    DELSTRING(jtitle)
    DELSTRING(jcolumns)
    DELSTRING(joptions)
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITupleFactory::createChained(const std::string & name, const std::string & title, const std::vector<ITuple *>  & set) {
    jstring jname, jtitle;
    NEWSTRING(jname, name)
    NEWSTRING(jtitle, title)

    jobjectArray jset = (jobjectArray)env->NewObjectArray(set.size(), tupleClass, NULL);
    for (unsigned int index=0; index<set.size(); index++) {
        jobject jtuple = factory->create(env, *set[index]);
        env->SetObjectArrayElement(jset, index, jtuple);
    }

    jobject obj = env->CallObjectMethod(ref, createChainedOLjava_lang_StringELjava_lang_StringEAALhep_aida_ECLhep_aida_ITupleEMethod, jname, jtitle, jset);
    DELSTRING(jname)
    DELSTRING(jtitle)
    env->DeleteLocalRef(jset);
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITupleFactory::createChained(const std::string & name, const std::string & title, const std::vector<std::string>  & set) {
    jstring jname;
    jstring jtitle;
    jobjectArray jset;
    NEWSTRING(jname, name)
    NEWSTRING(jtitle, title)
    NEWSTRINGARRAY(jset, set)
    jobject obj = env->CallObjectMethod(ref, createChainedOLjava_lang_StringELjava_lang_StringEALjava_lang_StringECLhep_aida_ITupleEMethod, jname, jtitle, jset);
    DELSTRING(jname)
    DELSTRING(jtitle)
    DELSTRINGARRAY(jset)
    if (obj == NULL) return NULL;
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITupleFactory::createFiltered(const std::string & name, ITuple & tuple, IFilter & filter) {
    jstring jname;
    NEWSTRING(jname, name)
    jobject jtuple = factory->create(env, tuple);
    jobject jfilter = factory->create(env, filter);
    jobject obj = env->CallObjectMethod(ref, createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterECLhep_aida_ITupleEMethod, jname, jtuple, jfilter);
    DELSTRING(jname)
    if (obj == NULL) return NULL;
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITupleFactory::createFiltered(const std::string & name, ITuple & tuple, IFilter & filter, const std::vector<std::string>  & columns) {
    jstring jname;
    jobjectArray jcolumns;
    NEWSTRING(jname, name)
    NEWSTRINGARRAY(jcolumns, columns)
    jobject jtuple = factory->create(env, tuple);
    jobject jfilter = factory->create(env, filter);
    jobject obj = env->CallObjectMethod(ref, createFilteredOLjava_lang_StringELhep_aida_ITupleELhep_aida_IFilterEALjava_lang_StringECLhep_aida_ITupleEMethod, jname, jtuple, jfilter, jcolumns);
    DELSTRING(jname)
    DELSTRINGARRAY(jcolumns)
    if (obj == NULL) return NULL;
    if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT IFilter * JITupleFactory::createFilter(const std::string & expression) {
	jstring jexpression;
	NEWSTRING(jexpression, expression)
 	jobject obj = env->CallObjectMethod(ref, createFilterOLjava_lang_StringECLhep_aida_IFilterEMethod, jexpression);
	DELSTRING(jexpression)
    if (obj == NULL) return NULL;
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFilter(env, obj);
}

JNIEXPORT IFilter * JITupleFactory::createFilter(const std::string & expression, int rowsToProcess, int startingRow) {
	jstring jexpression;
	NEWSTRING(jexpression, expression)
 	jobject obj = env->CallObjectMethod(ref, createFilterOLjava_lang_StringEIICLhep_aida_IFilterEMethod, jexpression, rowsToProcess, startingRow);
	DELSTRING(jexpression)
    if (obj == NULL) return NULL;
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIFilter(env, obj);
}

JNIEXPORT IEvaluator * JITupleFactory::createEvaluator(const std::string & expression) {
	jstring jexpression;
	NEWSTRING(jexpression, expression)
 	jobject obj = env->CallObjectMethod(ref, createEvaluatorOLjava_lang_StringECLhep_aida_IEvaluatorEMethod, jexpression);
	DELSTRING(jexpression)
    if (obj == NULL) return NULL;
	if (JNIUtil::exceptions(env)) return NULL;
	else return factory->createIEvaluator(env, obj);
}
