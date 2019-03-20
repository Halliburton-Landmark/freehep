
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "AIDA/IAnnotation.h"
#include "AIDA/ICloud1D.h"
#include "AIDA/ICloud2D.h"
#include "AIDA/ICloud3D.h"
#include "AIDA/IEvaluator.h"
#include "AIDA/IFilter.h"
#include "AIDA/IHistogram1D.h"
#include "AIDA/IHistogram2D.h"
#include "AIDA/IHistogram3D.h"
#include "AIDA/IProfile1D.h"
#include "AIDA/IProfile2D.h"
#include "AIDA/ITuple.h"
#include "AIDA/ITupleEntry.h"
#include "JIAnnotation.h"
#include "JIEvaluator.h"
#include "JIFilter.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"
#include "JITuple.h"

#include "ProxyFactory.h"

#include "CUtil.h"

#include "JNIUtil.hh"
#include "JNIMacros.hh"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JITuple::JITuple(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory), JIManagedObject(jnienv, object),
        iAnnotation(NULL) {

    jclass cls = env->GetObjectClass(getRef());

    columnMeanOICDMethod = env->GetMethodID(cls, "columnMean", "(I)D");
    if (columnMeanOICDMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnMean" << "(I)D" << std::endl;
    }

    fillOADCVMethod = env->GetMethodID(cls, "fill", "([D)V");
    if (fillOADCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "([D)V" << std::endl;
    }

    projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    skipOICVMethod = env->GetMethodID(cls, "skip", "(I)V");
    if (skipOICVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "skip" << "(I)V" << std::endl;
    }

    getBooleanOICZMethod = env->GetMethodID(cls, "getBoolean", "(I)Z");
    if (getBooleanOICZMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getBoolean" << "(I)Z" << std::endl;
    }

    getIntOICIMethod = env->GetMethodID(cls, "getInt", "(I)I");
    if (getIntOICIMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getInt" << "(I)I" << std::endl;
    }

    projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    findColumnOLjava_lang_StringECIMethod = env->GetMethodID(cls, "findColumn", "(Ljava/lang/String;)I");
    if (findColumnOLjava_lang_StringECIMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "findColumn" << "(Ljava/lang/String;)I" << std::endl;
    }

    projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    startOCVMethod = env->GetMethodID(cls, "start", "()V");
    if (startOCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "start" << "()V" << std::endl;
    }

    projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    fillOIJCVMethod = env->GetMethodID(cls, "fill", "(IJ)V");
    if (fillOIJCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(IJ)V" << std::endl;
    }

    getFloatOICFMethod = env->GetMethodID(cls, "getFloat", "(I)F");
    if (getFloatOICFMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getFloat" << "(I)F" << std::endl;
    }

    getShortOICSMethod = env->GetMethodID(cls, "getShort", "(I)S");
    if (getShortOICSMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getShort" << "(I)S" << std::endl;
    }

    getCharOICCMethod = env->GetMethodID(cls, "getChar", "(I)C");
    if (getCharOICCMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getChar" << "(I)C" << std::endl;
    }

    getStringOICLjava_lang_StringEMethod = env->GetMethodID(cls, "getString", "(I)Ljava/lang/String;");
    if (getStringOICLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getString" << "(I)Ljava/lang/String;" << std::endl;
    }

    columnsOCIMethod = env->GetMethodID(cls, "columns", "()I");
    if (columnsOCIMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columns" << "()I" << std::endl;
    }

    titleOCLjava_lang_StringEMethod = env->GetMethodID(cls, "title", "()Ljava/lang/String;");
    if (titleOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "title" << "()Ljava/lang/String;" << std::endl;
    }

    projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    columnMaxOICDMethod = env->GetMethodID(cls, "columnMax", "(I)D");
    if (columnMaxOICDMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnMax" << "(I)D" << std::endl;
    }

    projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    fillOILhep_aida_ITupleEntryECVMethod = env->GetMethodID(cls, "fill", "(ILjava/lang/Object;)V");
    if (fillOILhep_aida_ITupleEntryECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(ILjava/lang/Object;)V" << std::endl;
    }

    fillOILjava_lang_StringECVMethod = env->GetMethodID(cls, "fill", "(ILjava/lang/String;)V");
    if (fillOILjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(ILjava/lang/String;)V" << std::endl;
    }

    annotationOCLhep_aida_IAnnotationEMethod = env->GetMethodID(cls, "annotation", "()Lhep/aida/IAnnotation;");
    if (annotationOCLhep_aida_IAnnotationEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "annotation" << "()Lhep/aida/IAnnotation;" << std::endl;
    }

    projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    fillOIICVMethod = env->GetMethodID(cls, "fill", "(II)V");
    if (fillOIICVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(II)V" << std::endl;
    }

    fillOISCVMethod = env->GetMethodID(cls, "fill", "(IS)V");
    if (fillOISCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(IS)V" << std::endl;
    }

    projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    getTupleOICLhep_aida_ITupleEMethod = env->GetMethodID(cls, "getTuple", "(I)Lhep/aida/ITuple;");
    if (getTupleOICLhep_aida_ITupleEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getTuple" << "(I)Lhep/aida/ITuple;" << std::endl;
    }

    projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    addRowOCVMethod = env->GetMethodID(cls, "addRow", "()V");
    if (addRowOCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "addRow" << "()V" << std::endl;
    }

    columnNameOICLjava_lang_StringEMethod = env->GetMethodID(cls, "columnName", "(I)Ljava/lang/String;");
    if (columnNameOICLjava_lang_StringEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnName" << "(I)Ljava/lang/String;" << std::endl;
    }

    projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    fillOAFCVMethod = env->GetMethodID(cls, "fill", "([F)V");
    if (fillOAFCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "([F)V" << std::endl;
    }

    getLongOICJMethod = env->GetMethodID(cls, "getLong", "(I)J");
    if (getLongOICJMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getLong" << "(I)J" << std::endl;
    }

    projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    resetOCVMethod = env->GetMethodID(cls, "reset", "()V");
    if (resetOCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "reset" << "()V" << std::endl;
    }

    projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    resetRowOCVMethod = env->GetMethodID(cls, "resetRow", "()V");
    if (resetRowOCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "resetRow" << "()V" << std::endl;
    }

    columnMinOICDMethod = env->GetMethodID(cls, "columnMin", "(I)D");
    if (columnMinOICDMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnMin" << "(I)D" << std::endl;
    }

    projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    nextOCZMethod = env->GetMethodID(cls, "next", "()Z");
    if (nextOCZMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "next" << "()Z" << std::endl;
    }

    setTitleOLjava_lang_StringECVMethod = env->GetMethodID(cls, "setTitle", "(Ljava/lang/String;)V");
    if (setTitleOLjava_lang_StringECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "setTitle" << "(Ljava/lang/String;)V" << std::endl;
    }

    columnRmsOICDMethod = env->GetMethodID(cls, "columnRms", "(I)D");
    if (columnRmsOICDMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnRms" << "(I)D" << std::endl;
    }

    projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    fillOIDCVMethod = env->GetMethodID(cls, "fill", "(ID)V");
    if (fillOIDCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(ID)V" << std::endl;
    }

    projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    setRowOICVMethod = env->GetMethodID(cls, "setRow", "(I)V");
    if (setRowOICVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "setRow" << "(I)V" << std::endl;
    }

    projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    getDoubleOICDMethod = env->GetMethodID(cls, "getDouble", "(I)D");
    if (getDoubleOICDMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getDouble" << "(I)D" << std::endl;
    }

    projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    columnTypeOICLhep_aida_StringClassEMethod = env->GetMethodID(cls, "columnType", "(I)Ljava/lang/Class;");
    if (columnTypeOICLhep_aida_StringClassEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnType" << "(I)Ljava/lang/Class;" << std::endl;
    }

    fillOIZCVMethod = env->GetMethodID(cls, "fill", "(IZ)V");
    if (fillOIZCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(IZ)V" << std::endl;
    }

    fillOIFCVMethod = env->GetMethodID(cls, "fill", "(IF)V");
    if (fillOIFCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(IF)V" << std::endl;
    }

    getObjectOICLhep_aida_ITupleEntryEMethod = env->GetMethodID(cls, "getObject", "(I)Ljava/lang/Object;");
    if (getObjectOICLhep_aida_ITupleEntryEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "getObject" << "(I)Ljava/lang/Object;" << std::endl;
    }

    rowsOCIMethod = env->GetMethodID(cls, "rows", "()I");
    if (rowsOCIMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "rows" << "()I" << std::endl;
    }

    fillOICCVMethod = env->GetMethodID(cls, "fill", "(IC)V");
    if (fillOICCVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "fill" << "(IC)V" << std::endl;
    }

    projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V");
    if (projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V" << std::endl;
    }

    projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod = env->GetMethodID(cls, "project", "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V");
    if (projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "project" << "(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V" << std::endl;
    }

    columnNamesOCALjava_lang_StringEMethod = env->GetMethodID(cls, "columnNames", "()[Ljava/lang/String;");
    if (columnNamesOCALjava_lang_StringEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnNames" << "()[Ljava/lang/String;" << std::endl;
    }

    columnTypesOCALjava_lang_ClassEMethod = env->GetMethodID(cls, "columnTypes", "()[Ljava/lang/Class;");
    if (columnTypesOCALjava_lang_ClassEMethod == NULL) {
        std::cerr << "ITuple" << ": Could not find method: " << "columnTypes" << "()[Ljava/lang/Class;" << std::endl;
    }
}

JNIEXPORT JITuple::~JITuple() {
    delete iAnnotation;
}

JNIEXPORT std::string JITuple::title() const {
    // Call to Java
    jstring jtitle = (jstring)env->CallObjectMethod(ref, titleOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jtitle, &isCopy);
    string titleString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jtitle, utf);
    return titleString;
}

JNIEXPORT bool JITuple::setTitle(const std::string & title) {
    jstring jtitle;
    NEWSTRING(jtitle, title)
    env->CallObjectMethod(ref, setTitleOLjava_lang_StringECVMethod, jtitle);
    DELSTRING(jtitle)
    return !JNIUtil::exceptions(env);
}

JNIEXPORT IAnnotation & JITuple::annotation() {
    if (iAnnotation == NULL) {
        jobject jannotation = env->CallObjectMethod(ref, annotationOCLhep_aida_IAnnotationEMethod);
        iAnnotation = factory->createIAnnotation(env, jannotation);
    }
    return *iAnnotation;
}

JNIEXPORT const IAnnotation & JITuple::annotation() const {
   return *iAnnotation;
}

JNIEXPORT bool JITuple::fill(int column, double value) {
	env->CallVoidMethod(ref, fillOIDCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, float value) {
	env->CallVoidMethod(ref, fillOIFCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, int value) {
	env->CallVoidMethod(ref, fillOIICVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, short value) {
	env->CallVoidMethod(ref, fillOISCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, long value) {
	env->CallVoidMethod(ref, fillOIJCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, char value) {
	env->CallVoidMethod(ref, fillOICCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, bool value) {
	env->CallVoidMethod(ref, fillOIZCVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, const std::string & value) {
    jstring jvalue;
    NEWSTRING(jvalue, value)
	env->CallVoidMethod(ref, fillOILjava_lang_StringECVMethod, column, jvalue);
	DELSTRING(jvalue);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(int column, const ITupleEntry & value) {
// FIXME 4.0
    std::cerr << "'JITuple.fill(..., ITupleEntry)' not implemented." << std::endl;
//	env->CallVoidMethod(ref, fillOILhep_aida_ITupleEntryECVMethod, column, value);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(const std::vector<double>  & values) {
    jdoubleArray jvalues;
    NEWDOUBLEARRAY(jvalues, values)
	env->CallVoidMethod(ref, fillOADCVMethod, jvalues);
    DELDOUBLEARRAY(jvalues)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::fill(const std::vector<float>  & values) {
    jfloatArray jvalues;
    NEWFLOATARRAY(jvalues, values)
	env->CallVoidMethod(ref, fillOAFCVMethod, jvalues);
    DELFLOATARRAY(jvalues)
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::addRow() {
	env->CallVoidMethod(ref, addRowOCVMethod);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT void JITuple::resetRow() {
	env->CallVoidMethod(ref, resetRowOCVMethod);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT void JITuple::reset() {
	env->CallVoidMethod(ref, resetOCVMethod);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT int JITuple::rows() const {
	jint r = env->CallIntMethod(ref, rowsOCIMethod);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT void JITuple::start() {
	env->CallVoidMethod(ref, startOCVMethod);
	JNIUtil::checkExceptions(env);
}

JNIEXPORT bool JITuple::skip(int rows) {
	env->CallVoidMethod(ref, skipOICVMethod, rows);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::next() {
	jboolean r = env->CallBooleanMethod(ref, nextOCZMethod);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JITuple::setRow(int rowIndex) {
	env->CallVoidMethod(ref, setRowOICVMethod, rowIndex);
	return !JNIUtil::exceptions(env);
}

JNIEXPORT int JITuple::findColumn(const std::string & name) const {
    jstring jname;
    NEWSTRING(jname, name)
	jint r = env->CallIntMethod(ref, findColumnOLjava_lang_StringECIMethod, jname);
    DELSTRING(jname);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT double JITuple::getDouble(int column) const {
	jdouble r = env->CallDoubleMethod(ref, getDoubleOICDMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT float JITuple::getFloat(int column) const {
	jfloat r = env->CallFloatMethod(ref, getFloatOICFMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT int JITuple::getInt(int column) const {
	jint r = env->CallIntMethod(ref, getIntOICIMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT short JITuple::getShort(int column) const {
	jshort r = env->CallShortMethod(ref, getShortOICSMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT long JITuple::getLong(int column) const {
	jlong r = env->CallLongMethod(ref, getLongOICJMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT char JITuple::getChar(int column) const {
	jchar r = env->CallCharMethod(ref, getCharOICCMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JITuple::getBoolean(int column) const {
	jboolean r = env->CallBooleanMethod(ref, getBooleanOICZMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT std::string JITuple::getString(int column) const {
    // Call to Java
    jstring jstringString = (jstring)env->CallObjectMethod(ref, getStringOICLjava_lang_StringEMethod, column);
    if (jstringString == NULL) return emptyString;

    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jstringString, &isCopy);
    string stringString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jstringString, utf);
    return stringString;
}

JNIEXPORT const ITupleEntry * JITuple::getObject(int column) const {
    // Call to Java
    // NOTE assumes we have an ITuple as object
    jobject obj = env->CallObjectMethod(ref, getObjectOICLhep_aida_ITupleEntryEMethod, column);
	if (JNIUtil::exceptions(env)) return NULL;
    else return dynamic_cast<ITupleEntry*>(factory->createITuple(env, obj));
}

JNIEXPORT const ITuple * JITuple::getTuple(int column) const {
    // Call to Java
    jobject obj = env->CallObjectMethod(ref, getTupleOICLhep_aida_ITupleEMethod, column);
	if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT ITuple * JITuple::getTuple(int column) {
    // Call to Java
    jobject obj = env->CallObjectMethod(ref, getTupleOICLhep_aida_ITupleEMethod, column);
	if (JNIUtil::exceptions(env)) return NULL;
    else return factory->createITuple(env, obj);
}

JNIEXPORT int JITuple::columns() const {
	jint r = env->CallIntMethod(ref, columnsOCIMethod);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT std::string JITuple::columnName(int column) const {
    // Call to Java
    jstring jname = (jstring)env->CallObjectMethod(ref, columnNameOICLjava_lang_StringEMethod, column);
    if (jname == NULL) return emptyString;

    // converting String to string
    jboolean isCopy;
    const char* utf = env->GetStringUTFChars(jname, &isCopy);
    string columnNameString = utf;
    if (isCopy) env->ReleaseStringUTFChars(jname, utf);
    return columnNameString;
}

JNIEXPORT std::vector<std::string> JITuple::columnNames() const {
    std::vector<std::string> columnNamesVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, columnNamesOCALjava_lang_StringEMethod);

    if (array != NULL) {
        // convert string[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jstring jname = (jstring)env->GetObjectArrayElement(array, i);
            jboolean isCopy;
            const char* utf = env->GetStringUTFChars(jname, &isCopy);
            string name = utf;
            if (isCopy) env->ReleaseStringUTFChars(jname, utf);
            columnNamesVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return columnNamesVector;
}


JNIEXPORT std::string JITuple::columnType(int column) const {
    // Call to Java
    jclass jtype = (jclass)env->CallObjectMethod(ref, columnTypeOICLhep_aida_StringClassEMethod, column);
    if (jtype == NULL) return emptyString;

    return Java_hep_aida_jni_convert_to_string(env, jtype); 
}

JNIEXPORT std::vector<std::string> JITuple::columnTypes() const {
    std::vector<std::string> columnTypesVector;

    // Call to Java
    jobjectArray array = (jobjectArray)env->CallObjectMethod(ref, columnTypesOCALjava_lang_ClassEMethod);

    if (array != NULL) {
        // convert class[] to vector<string>
        unsigned int len = env->GetArrayLength(array);
        for (unsigned int i=0; i<len; i++) {
            jclass c = (jclass)env->GetObjectArrayElement(array, i);
            string name = Java_hep_aida_jni_convert_to_string(env, c);
            columnTypesVector.push_back(name);
        }
    }
    JNIUtil::checkExceptions(env);
    return columnTypesVector;
}

JNIEXPORT double JITuple::columnMin(int column) const {
	jdouble r = env->CallDoubleMethod(ref, columnMinOICDMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT double JITuple::columnMax(int column) const {
	jdouble r = env->CallDoubleMethod(ref, columnMaxOICDMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT double JITuple::columnMean(int column) const {
	jdouble r = env->CallDoubleMethod(ref, columnMeanOICDMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT double JITuple::columnRms(int column) const {
	jdouble r = env->CallDoubleMethod(ref, columnRmsOICDMethod, column);
	JNIUtil::checkExceptions(env);
    return r;
}

JNIEXPORT bool JITuple::project(IHistogram1D & histogram, IEvaluator & evaluatorX) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorECVMethod, h, ex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram1D & histogram, IEvaluator & evaluatorX, IFilter & filter) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, h, ex, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram1D & histogram, IEvaluator & evaluatorX, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, h, ex, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram1D & histogram, IEvaluator & evaluatorX, IFilter & filter, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, h, ex, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, h, ex, ey);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, h, ex, ey, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, h, ex, ey, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram2D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, h, ex, ey, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, h, ex, ey, ez);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, h, ex, ey, ez, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, h, ex, ey, ez, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IHistogram3D & histogram, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) {
    jobject h = factory->create(env, histogram);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IHistogram3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, h, ex, ey, ez, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud1D & cloud, IEvaluator & evaluatorX) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorECVMethod, c, ex);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud1D & cloud, IEvaluator & evaluatorX, IFilter & filter) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, c, ex, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud1D & cloud, IEvaluator & evaluatorX, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, c, ex, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud1D & cloud, IEvaluator & evaluatorX, IFilter & filter, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud1DELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, c, ex, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, c, ex, ey);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, c, ex, ey, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, c, ex, ey, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud2D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, c, ex, ey, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, c, ex, ey, ez);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, c, ex, ey, ez, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, c, ex, ey, ez, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(ICloud3D & cloud, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) {
    jobject c = factory->create(env, cloud);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_ICloud3DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, c, ex, ey, ez, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, p, ex, ey);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, p, ex, ey, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & weight) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, p, ex, ey, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile1D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IFilter & filter, IEvaluator & weight) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile1DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, p, ex, ey, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, p, ex, ey, ez);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterECVMethod, p, ex, ey, ez, f);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IEvaluator & weight) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorECVMethod, p, ex, ey, ez, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT bool JITuple::project(IProfile2D & profile, IEvaluator & evaluatorX, IEvaluator & evaluatorY, IEvaluator & evaluatorZ, IFilter & filter, IEvaluator & weight) {
    jobject p = factory->create(env, profile);
    jobject ex = factory->create(env, evaluatorX);
    jobject ey = factory->create(env, evaluatorY);
    jobject ez = factory->create(env, evaluatorZ);
    jobject f = factory->create(env, filter);
    jobject w = factory->create(env, weight);
    env->CallVoidMethod(ref, projectOLhep_aida_IProfile2DELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IEvaluatorELhep_aida_IFilterELhep_aida_IEvaluatorECVMethod, p, ex, ey, ez, f, w);
    return !JNIUtil::exceptions(env);
}

JNIEXPORT void * JITuple::cast(const std::string & className) const {
    return (className == "AIDA::ITuple") ? (void *)this : NULL;
}
