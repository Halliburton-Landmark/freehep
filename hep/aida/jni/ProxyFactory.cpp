
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "JIAnnotation.h"
#include "JIAxis.h"
#include "JIAxisStyle.h"
#include "JIBaseHistogram.h"
#include "JICloud1D.h"
#include "JICloud2D.h"
#include "JICloud3D.h"
#include "JIDataPoint.h"
#include "JIDataPointSet.h"
#include "JIDataPointSetFactory.h"
#include "JIDataStyle.h"
#include "JIEvaluator.h"
#include "JIFillStyle.h"
#include "JIFilter.h"
#include "JIFitData.h"
#include "JIFitFactory.h"
#include "JIFitParameterSettings.h"
#include "JIFitResult.h"
#include "JIFitter.h"
#include "JIFunction.h"
#include "JIFunctionCatalog.h"
#include "JIFunctionFactory.h"
#include "JIHistogramFactory.h"
#include "JIHistogram1D.h"
#include "JIHistogram2D.h"
#include "JIHistogram3D.h"
#include "JIInfo.h"
#include "JIInfoStyle.h"
#include "JILineStyle.h"
#include "JIMarkerStyle.h"
#include "JIMeasurement.h"
#include "JIModelFunction.h"
#include "JIPlotter.h"
#include "JIPlotterFactory.h"
#include "JIPlotterLayout.h"
#include "JIPlotterRegion.h"
#include "JIPlotterStyle.h"
#include "JIProfile1D.h"
#include "JIProfile2D.h"
#include "JIRangeSet.h"
#include "JITextStyle.h"
#include "JITitleStyle.h"
#include "JITree.h"
#include "JITreeFactory.h"
#include "JITuple.h"
#include "JITupleFactory.h"

#include "CProxy.h"
#include "CIAnnotation.h"
#include "CIAxis.h"
#include "CIAxisStyle.h"
#include "CIBaseHistogram.h"
#include "CIBaseStyle.h"
#include "CIBrushStyle.h"
#include "CICloud.h"
#include "CICloud1D.h"
#include "CICloud2D.h"
#include "CICloud3D.h"
#include "CIDataPoint.h"
#include "CIDataPointSet.h"
#include "CIDataPointSetFactory.h"
#include "CIDataStyle.h"
#include "CIEvaluator.h"
#include "CIFillStyle.h"
#include "CIFilter.h"
#include "CIFitData.h"
#include "CIFitFactory.h"
#include "CIFitParameterSettings.h"
#include "CIFitResult.h"
#include "CIFitter.h"
#include "CIFunction.h"
#include "CIFunctionFactory.h"
#include "CIFunctionCatalog.h"
#include "CIHistogram.h"
#include "CIHistogramFactory.h"
#include "CIHistogram1D.h"
#include "CIHistogram2D.h"
#include "CIHistogram3D.h"
#include "CIInfo.h"
#include "CIInfoStyle.h"
#include "CILineStyle.h"
#include "CIManagedObject.h"
#include "CIMarkerStyle.h"
#include "CIMeasurement.h"
#include "CIModelFunction.h"
#include "CIPlotter.h"
#include "CIPlotterFactory.h"
#include "CIPlotterLayout.h"
#include "CIPlotterRegion.h"
#include "CIPlotterStyle.h"
#include "CIProfile.h"
#include "CIProfile1D.h"
#include "CIProfile2D.h"
#include "CIRangeSet.h"
#include "CITextStyle.h"
#include "CITitleStyle.h"
#include "CITree.h"
#include "CITreeFactory.h"
#include "CITuple.h"
#include "CITupleFactory.h"

#include "ProxyFactory.h"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


jlong ProxyFactory::crefIDcount = 0;
ProxyFactory* ProxyFactory::factory = NULL;


// finds class "classname" and returns it in "class"
#define FINDCLASS(class,classname) \
    if (class == NULL) { \
        class = env->FindClass(classname); \
        if (class == NULL) { \
            cerr << "FATAL: cannot find class '" << classname << "'" << endl; \
            abort(); \
        } \
    }

// looks if "obj" (implicit) is of instance "class" and returns its looked up "cref"
// casted to "interface". If not, continues.
#define RETURNCREF(interface,class,crefField,obj) \
    if (env->IsInstanceOf(obj, class)) { \
	    return (interface*)getCRef(env->GetLongField(object, crefField)); \
    }

// dynamicly casts "obj" to "class" and returns its getRef() value if possible.
// If not, continues.
#define RETURNJREF(class,obj) \
    { \
        const class* jobj = dynamic_cast<const class*>(&obj); \
        if (jobj != NULL) return jobj->getRef(); \
    }
    
// dynamicly casts "obj" to "class" and calls create value if possible.
// If not, continues.
#define RETURNCREATE(class,obj) \
    { \
        const class* jobj = dynamic_cast<const class*>(&obj); \
        if (jobj != NULL) return create(env, *jobj); \
    }

// tries to find jobj associated with obj, and returns this, otherwise
// creates a new object of "class" from "obj" returns that. 
// Issues a warning if the new object could not be created, and returns NULL
// NOTE: We used to look up crefs first to see if a wrapper was around,
// but C++ may replace the CREF, making the wrapper invalid,
// if the replaced object is of a different type.
// Checking the type seems to fail also.
// We now generate wrappers for any object.
//    jobject jobj = getJRef(&obj);
//    jclass jcls = getJClass(&obj);
//    if ((jobj == NULL) || (jcls != class)) {
//        if (jcls != class) cerr << "WARNING: classes not equal, new wrapper generated." << endl;
//    } 
#define RETURNCI(class,ctor,obj) \
        jobject jobj = env->NewObject(class, ctor, crefIDcount); \
        if (jobj == NULL) { \
            cerr << "WARNING: cannot create object of class '" << class << "'" << endl; \
        } else { \
            addRef(crefIDcount, &obj, jobj, class); \
            crefIDcount++; \
        } \
    return jobj;

// finds class "classname" and sets class, ctor "(J)", and crefID "J" field
// then registers natives
#define LOADCLASS(class,classname,ctor,crefID,methods,numberOfMethods) \
    class = env->FindClass(classname); \
    if (class == NULL) { \
        cerr << "FATAL: cannot find class '" << classname << "'" << endl; \
        abort(); \
    } \
    ctor = env->GetMethodID(class, "<init>", "(J)V"); \
    if (ctor == NULL) { \
        cerr << "FATAL: cannot find constructor (J) in class '" << classname << "'" << endl; \
        abort(); \
    } \
    crefID = env->GetFieldID(class, "crefID", "J"); \
    if (crefID == NULL) { \
        cerr << "FATAL: cannot find field 'crefID' in class '" << classname << "'" << endl; \
        abort(); \
    } \
    env->RegisterNatives(class,methods,numberOfMethods);


JNIEXPORT ProxyFactory::ProxyFactory(JNIEnv *env) :
            cloud1Dclass(NULL),
            cloud2Dclass(NULL),
            cloud3Dclass(NULL),
            dataPointSetClass(NULL),
            functionClass(NULL),
            modelFunctionClass(NULL),
            histogram1Dclass(NULL),
            histogram2Dclass(NULL),
            histogram3Dclass(NULL),
            profile1Dclass(NULL),
            profile2Dclass(NULL),
            tupleClass(NULL) {
        
    factory = this;

    JNINativeMethod methodsCIAnnotation[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },
        
        { (char*)"addItem",    (char*)"(Ljava/lang/String;Ljava/lang/String;)V",  (void*)Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"addItem",    (char*)"(Ljava/lang/String;Ljava/lang/String;Z)V", (void*)Java_hep_aida_jni_CIAnnotation_addItem__Ljava_lang_String_2Ljava_lang_String_2Z },
        { (char*)"removeItem", (char*)"(Ljava/lang/String;)V",                    (void*)Java_hep_aida_jni_CIAnnotation_removeItem },
        { (char*)"value",      (char*)"(Ljava/lang/String;)Ljava/lang/String;",   (void*)Java_hep_aida_jni_CIAnnotation_value__Ljava_lang_String_2 },
        { (char*)"setValue",   (char*)"(Ljava/lang/String;Ljava/lang/String;)V",  (void*)Java_hep_aida_jni_CIAnnotation_setValue },
        { (char*)"setSticky",  (char*)"(Ljava/lang/String;Z)V",                   (void*)Java_hep_aida_jni_CIAnnotation_setSticky },
        { (char*)"size",       (char*)"()I",                                      (void*)Java_hep_aida_jni_CIAnnotation_size },
        { (char*)"key",        (char*)"(I)Ljava/lang/String;",                    (void*)Java_hep_aida_jni_CIAnnotation_key },
        { (char*)"value",      (char*)"(I)Ljava/lang/String;",                    (void*)Java_hep_aida_jni_CIAnnotation_value__I },
        { (char*)"reset",      (char*)"()V",                                      (void*)Java_hep_aida_jni_CIAnnotation_reset },
    };
    LOADCLASS(classCIAnnotation, "hep/aida/jni/CIAnnotation", ctorCIAnnotation, 
              crefCIAnnotation, methodsCIAnnotation, 1+10);

    JNINativeMethod methodsCIAxis[] = {
        { (char*)"finalize",       (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"isFixedBinning", (char*)"()Z",  (void*)Java_hep_aida_jni_CIAxis_isFixedBinning },
        { (char*)"lowerEdge",      (char*)"()D",  (void*)Java_hep_aida_jni_CIAxis_lowerEdge },
        { (char*)"upperEdge",      (char*)"()D",  (void*)Java_hep_aida_jni_CIAxis_upperEdge },
        { (char*)"bins",           (char*)"()I",  (void*)Java_hep_aida_jni_CIAxis_bins },
        { (char*)"binLowerEdge",   (char*)"(I)D", (void*)Java_hep_aida_jni_CIAxis_binLowerEdge },
        { (char*)"binUpperEdge",   (char*)"(I)D", (void*)Java_hep_aida_jni_CIAxis_binUpperEdge },
        { (char*)"binWidth",       (char*)"(I)D", (void*)Java_hep_aida_jni_CIAxis_binWidth },
        { (char*)"coordToIndex",   (char*)"(D)I", (void*)Java_hep_aida_jni_CIAxis_coordToIndex },
    };
    LOADCLASS(classCIAxis, "hep/aida/jni/CIAxis", ctorCIAxis,
              crefCIAxis, methodsCIAxis, 1+8);
              
    JNINativeMethod methodsCIAxisStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"lineStyle", (char*)"()Lhep/aida/ILineStyle;", (void*)Java_hep_aida_jni_CIAxisStyle_lineStyle },
        { (char*)"tickLabelStyle", (char*)"()Lhep/aida/ITextStyle;", (void*)Java_hep_aida_jni_CIAxisStyle_tickLabelStyle },
        { (char*)"labelStyle", (char*)"()Lhep/aida/ITextStyle;", (void*)Java_hep_aida_jni_CIAxisStyle_labelStyle },
        { (char*)"setlineStyle", (char*)"(Lhep/aida/ILineStyle;)Z", (void*)Java_hep_aida_jni_CIAxisStyle_setlineStyle },
        { (char*)"setTickLabelStyle", (char*)"(Lhep/aida/ITextStyle;)Z", (void*)Java_hep_aida_jni_CIAxisStyle_setTickLabelStyle },
        { (char*)"setLabelStyle", (char*)"(Lhep/aida/ITextStyle;)Z", (void*)Java_hep_aida_jni_CIAxisStyle_setLabelStyle },
        { (char*)"setLabel", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIAxisStyle_setLabel },
    };
    LOADCLASS(classCIAxisStyle, "hep/aida/jni/CIAxisStyle", ctorCIAxisStyle, 
              crefCIAxisStyle, methodsCIAxisStyle, 1+6+7);
                            
    JNINativeMethod methodsCIBaseHistogram[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },
    };
    LOADCLASS(classCIBaseHistogram, "hep/aida/jni/CIBaseHistogram", ctorCIBaseHistogram, 
              crefCIBaseHistogram, methodsCIBaseHistogram, 1+6);

    JNINativeMethod methodsCICloud1D[] = {
        { (char*)"finalize",               (char*)"(J)V",                         (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title",                  (char*)"()Ljava/lang/String;",         (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle",               (char*)"(Ljava/lang/String;)V",        (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation",             (char*)"()Lhep/aida/IAnnotation;",     (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension",              (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset",                  (char*)"()V",                          (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries",                (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"sumOfWeights",           (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud_sumOfWeights },
        { (char*)"convertToHistogram",     (char*)"()V",                          (void*)Java_hep_aida_jni_CICloud_convertToHistogram },
        { (char*)"isConverted",            (char*)"()Z",                          (void*)Java_hep_aida_jni_CICloud_isConverted },
        { (char*)"maxEntries",             (char*)"()I",                          (void*)Java_hep_aida_jni_CICloud_maxEntries },
        { (char*)"scale",                  (char*)"(D)V",                         (void*)Java_hep_aida_jni_CICloud_scale },

        { (char*)"fill",                   (char*)"(D)V",                         (void*)Java_hep_aida_jni_CICloud1D_fill__D },
        { (char*)"fill",                   (char*)"(DD)V",                        (void*)Java_hep_aida_jni_CICloud1D_fill__DD },
        { (char*)"lowerEdge",              (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud1D_lowerEdge },
        { (char*)"upperEdge",              (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud1D_upperEdge },
        { (char*)"value",                  (char*)"(I)D",                         (void*)Java_hep_aida_jni_CICloud1D_value },
        { (char*)"weight",                 (char*)"(I)D",                         (void*)Java_hep_aida_jni_CICloud1D_weight },
        { (char*)"mean",                   (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud1D_mean },
        { (char*)"rms",                    (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud1D_rms },
        { (char*)"convert",                (char*)"(IDD)V",                       (void*)Java_hep_aida_jni_CICloud1D_convert__IDD },
        { (char*)"convert",                (char*)"([D)V",                        (void*)Java_hep_aida_jni_CICloud1D_convert___3D },
        { (char*)"histogram",              (char*)"()Lhep/aida/IHistogram1D;",    (void*)Java_hep_aida_jni_CICloud1D_histogram },
        { (char*)"fillHistogram",          (char*)"(Lhep/aida/IHistogram1D;)V",   (void*)Java_hep_aida_jni_CICloud1D_fillHistogram },
    };
    LOADCLASS(classCICloud1D, "hep/aida/jni/CICloud1D", ctorCICloud1D,          
              crefCICloud1D, methodsCICloud1D, 1+6+5+12);

    JNINativeMethod methodsCloud2D[] = {
        { (char*)"finalize",               (char*)"(J)V",                         (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title",                  (char*)"()Ljava/lang/String;",         (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle",               (char*)"(Ljava/lang/String;)V",        (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation",             (char*)"()Lhep/aida/IAnnotation;",     (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension",              (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset",                  (char*)"()V",                          (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries",                (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"sumOfWeights",           (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud_sumOfWeights },
        { (char*)"convertToHistogram",     (char*)"()V",                          (void*)Java_hep_aida_jni_CICloud_convertToHistogram },
        { (char*)"isConverted",            (char*)"()Z",                          (void*)Java_hep_aida_jni_CICloud_isConverted },
        { (char*)"maxEntries",             (char*)"()I",                          (void*)Java_hep_aida_jni_CICloud_maxEntries },
        { (char*)"scale",                  (char*)"(D)V",                         (void*)Java_hep_aida_jni_CICloud_scale },

        { (char*)"fill", (char*)"(DD)V", (void*)Java_hep_aida_jni_CICloud2D_fill__DD },
        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CICloud2D_fill__DDD },
        { (char*)"lowerEdgeX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_lowerEdgeX },
        { (char*)"lowerEdgeY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_lowerEdgeY },
        { (char*)"upperEdgeX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_upperEdgeX },
        { (char*)"upperEdgeY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_upperEdgeY },
        { (char*)"valueX", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud2D_valueX },
        { (char*)"valueY", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud2D_valueY },
        { (char*)"weight", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud2D_weight },
        { (char*)"meanX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_meanX },
        { (char*)"meanY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_meanY },
        { (char*)"rmsX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_rmsX },
        { (char*)"rmsY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud2D_rmsY },
        { (char*)"convert", (char*)"(IDDIDD)V", (void*)Java_hep_aida_jni_CICloud2D_convert__IDDIDD },
        { (char*)"convert", (char*)"([D[D)V", (void*)Java_hep_aida_jni_CICloud2D_convert___3D_3D },
        { (char*)"histogram", (char*)"()Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CICloud2D_histogram },
        { (char*)"fillHistogram", (char*)"(Lhep/aida/IHistogram2D;)V", (void*)Java_hep_aida_jni_CICloud2D_fillHistogram },
    };
    LOADCLASS(classCICloud2D, "hep/aida/jni/CICloud2D", ctorCICloud2D,          
              crefCICloud2D, methodsCloud2D, 1+6+5+17);

    JNINativeMethod methodsCloud3D[] = {
        { (char*)"finalize",               (char*)"(J)V",                         (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title",                  (char*)"()Ljava/lang/String;",         (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle",               (char*)"(Ljava/lang/String;)V",        (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation",             (char*)"()Lhep/aida/IAnnotation;",     (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension",              (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset",                  (char*)"()V",                          (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries",                (char*)"()I",                          (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"sumOfWeights",           (char*)"()D",                          (void*)Java_hep_aida_jni_CICloud_sumOfWeights },
        { (char*)"convertToHistogram",     (char*)"()V",                          (void*)Java_hep_aida_jni_CICloud_convertToHistogram },
        { (char*)"isConverted",            (char*)"()Z",                          (void*)Java_hep_aida_jni_CICloud_isConverted },
        { (char*)"maxEntries",             (char*)"()I",                          (void*)Java_hep_aida_jni_CICloud_maxEntries },
        { (char*)"scale",                  (char*)"(D)V",                         (void*)Java_hep_aida_jni_CICloud_scale },

        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CICloud3D_fill__DDD },
        { (char*)"fill", (char*)"(DDDD)V", (void*)Java_hep_aida_jni_CICloud3D_fill__DDDD },
        { (char*)"lowerEdgeX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_lowerEdgeX },
        { (char*)"lowerEdgeY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_lowerEdgeY },
        { (char*)"lowerEdgeZ", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_lowerEdgeZ },
        { (char*)"upperEdgeX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_upperEdgeX },
        { (char*)"upperEdgeY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_upperEdgeY },
        { (char*)"upperEdgeZ", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_upperEdgeZ },
        { (char*)"valueX", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud3D_valueX },
        { (char*)"valueY", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud3D_valueY },
        { (char*)"valueZ", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud3D_valueZ },
        { (char*)"weight", (char*)"(I)D", (void*)Java_hep_aida_jni_CICloud3D_weight },
        { (char*)"meanX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_meanX },
        { (char*)"meanY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_meanY },
        { (char*)"meanZ", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_meanZ },
        { (char*)"rmsX", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_rmsX },
        { (char*)"rmsY", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_rmsY },
        { (char*)"rmsZ", (char*)"()D", (void*)Java_hep_aida_jni_CICloud3D_rmsZ },
        { (char*)"convert", (char*)"(IDDIDDIDD)V", (void*)Java_hep_aida_jni_CICloud3D_convert__IDDIDDIDD },
        { (char*)"convert", (char*)"([D[D[D)V", (void*)Java_hep_aida_jni_CICloud3D_convert___3D_3D_3D },
        { (char*)"histogram", (char*)"()Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CICloud3D_histogram },
        { (char*)"fillHistogram", (char*)"(Lhep/aida/IHistogram3D;)V", (void*)Java_hep_aida_jni_CICloud3D_fillHistogram },
    };
    LOADCLASS(classCICloud3D, "hep/aida/jni/CICloud3D", ctorCICloud3D,
              crefCICloud3D, methodsCloud3D, 1+6+5+22);
              
    JNINativeMethod methodsCIDataPoint[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIDataPoint_dimension },
        { (char*)"coordinate", (char*)"(I)Lhep/aida/IMeasurement;", (void*)Java_hep_aida_jni_CIDataPoint_coordinate },
    };
    LOADCLASS(classCIDataPoint, "hep/aida/jni/CIDataPoint", ctorCIDataPoint,        
              crefCIDataPoint, methodsCIDataPoint, 1+2);

    JNINativeMethod methodsCIDataPointSet[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIDataPointSet_annotation },
        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIDataPointSet_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIDataPointSet_setTitle },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIDataPointSet_dimension },
        { (char*)"clear", (char*)"()V", (void*)Java_hep_aida_jni_CIDataPointSet_clear },
        { (char*)"size", (char*)"()I", (void*)Java_hep_aida_jni_CIDataPointSet_size },
        { (char*)"point", (char*)"(I)Lhep/aida/IDataPoint;", (void*)Java_hep_aida_jni_CIDataPointSet_point },
        { (char*)"setCoordinate", (char*)"(I[D[D)V", (void*)Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D },
        { (char*)"setCoordinate", (char*)"(I[D[D[D)V", (void*)Java_hep_aida_jni_CIDataPointSet_setCoordinate__I_3D_3D_3D },
        { (char*)"addPoint", (char*)"()Lhep/aida/IDataPoint;", (void*)Java_hep_aida_jni_CIDataPointSet_addPoint__ },
        { (char*)"addPoint", (char*)"(Lhep/aida/IDataPoint;)V", (void*)Java_hep_aida_jni_CIDataPointSet_addPoint__Lhep_aida_IDataPoint_2 },
        { (char*)"removePoint", (char*)"(I)V", (void*)Java_hep_aida_jni_CIDataPointSet_removePoint },
        { (char*)"lowerExtent", (char*)"(I)D", (void*)Java_hep_aida_jni_CIDataPointSet_lowerExtent },
        { (char*)"upperExtent", (char*)"(I)D", (void*)Java_hep_aida_jni_CIDataPointSet_upperExtent },
        { (char*)"scale", (char*)"(D)V", (void*)Java_hep_aida_jni_CIDataPointSet_scale },
        { (char*)"scaleValues", (char*)"(D)V", (void*)Java_hep_aida_jni_CIDataPointSet_scaleValues },
        { (char*)"scaleErrors", (char*)"(D)V", (void*)Java_hep_aida_jni_CIDataPointSet_scaleErrors },
    };
    LOADCLASS(classCIDataPointSet, "hep/aida/jni/CIDataPointSet", ctorCIDataPointSet,     
              crefCIDataPointSet, methodsCIDataPointSet, 1+17);
/* FIXME 3.2.4
    JNINativeMethod methodsCIDataPointSetFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Ljava_lang_String_2I },
        { (char*)"create", (char*)"(Ljava/lang/String;I)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2I },
        { (char*)"createY", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createY__Ljava_lang_String_2Ljava_lang_String_2_3D_3D },
        { (char*)"createY", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createY__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D },
        { (char*)"createY", (char*)"(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createY__Ljava_lang_String_2_3D_3D },
        { (char*)"createY", (char*)"(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createY__Ljava_lang_String_2_3D_3D_3D },
        { (char*)"createX", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createX__Ljava_lang_String_2Ljava_lang_String_2_3D_3D },
        { (char*)"createX", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createX__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D },
        { (char*)"createX", (char*)"(Ljava/lang/String;[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createX__Ljava_lang_String_2_3D_3D },
        { (char*)"createX", (char*)"(Ljava/lang/String;[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createX__Ljava_lang_String_2_3D_3D_3D },
        { (char*)"createXY", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXY__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D_3D_3D_3D },
        { (char*)"createXY", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXY__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D_3D },
        { (char*)"createXY", (char*)"(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXY__Ljava_lang_String_2_3D_3D_3D_3D_3D_3D },
        { (char*)"createXY", (char*)"(Ljava/lang/String;[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXY__Ljava_lang_String_2_3D_3D_3D_3D },
        { (char*)"createXYZ", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXYZ__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D_3D_3D_3D_3D_3D_3D },
        { (char*)"createXYZ", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXYZ__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D_3D_3D_3D },
        { (char*)"createXYZ", (char*)"(Ljava/lang/String;[D[D[D[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXYZ__Ljava_lang_String_2_3D_3D_3D_3D_3D_3D_3D_3D_3D },
        { (char*)"createXYZ", (char*)"(Ljava/lang/String;[D[D[D[D[D[D)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createXYZ__Ljava_lang_String_2_3D_3D_3D_3D_3D_3D },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_createCopy },
        { (char*)"destroy", (char*)"(Lhep/aida/IDataPointSet;)V", (void*)Java_hep_aida_jni_CIDataPointSetFactory_destroy },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram1D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram1D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram2D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram2D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram3D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IHistogram3D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud1D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud1D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud1D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud2D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud2D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud2D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud3D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud3D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/ICloud3D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_ICloud3D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IProfile1D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IProfile1D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IProfile1D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IProfile1D_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IProfile2D;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IProfile2D_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Lhep/aida/IProfile2D;Ljava/lang/String;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_create__Ljava_lang_String_2Lhep_aida_IProfile2D_2Ljava_lang_String_2 },
        { (char*)"add", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_add },
        { (char*)"subtract", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_subtract },
        { (char*)"multiply", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_multiply },
        { (char*)"divide", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_divide },
        { (char*)"weightedMean", (char*)"(Ljava/lang/String;Lhep/aida/IDataPointSet;Lhep/aida/IDataPointSet;)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIDataPointSetFactory_weightedMean },
    };
    LOADCLASS(classCIDataPointSetFactory, "hep/aida/jni/CIDataPointSetFactory", ctorCIDataPointSetFactory,     
              crefCIDataPointSetFactory, methodsCIDataPointSetFactory, 1+41);
*/
    JNINativeMethod methodsCIDataStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"lineStyle", (char*)"()Lhep/aida/ILineStyle;", (void*)Java_hep_aida_jni_CIDataStyle_lineStyle },
        { (char*)"markerStyle", (char*)"()Lhep/aida/IMarkerStyle;", (void*)Java_hep_aida_jni_CIDataStyle_markerStyle },
        { (char*)"fillStyle", (char*)"()Lhep/aida/IFillStyle;", (void*)Java_hep_aida_jni_CIDataStyle_fillStyle },
        { (char*)"setLineStyle", (char*)"(Lhep/aida/ILineStyle;)Z", (void*)Java_hep_aida_jni_CIDataStyle_setLineStyle },
        { (char*)"setMarkerStyle", (char*)"(Lhep/aida/IMarkerStyle;)Z", (void*)Java_hep_aida_jni_CIDataStyle_setMarkerStyle },
        { (char*)"setFillStyle", (char*)"(Lhep/aida/IFillStyle;)Z", (void*)Java_hep_aida_jni_CIDataStyle_setFillStyle },
    };
    LOADCLASS(classCIDataStyle, "hep/aida/jni/CIDataStyle", ctorCIDataStyle, 
              crefCIDataStyle, methodsCIDataStyle, 1+6+6);

    JNINativeMethod methodsCIEvaluator[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"initialize", (char*)"(Lhep/aida/ITuple;)V", (void*)Java_hep_aida_jni_CIEvaluator_initialize },
        { (char*)"evaluateDouble", (char*)"()D", (void*)Java_hep_aida_jni_CIEvaluator_evaluateDouble },
        { (char*)"expression", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIEvaluator_expression },
    };
    LOADCLASS(classCIEvaluator, "hep/aida/jni/CIEvaluator", ctorCIEvaluator,
              crefCIEvaluator, methodsCIEvaluator, 1+3);

    JNINativeMethod methodsCIFillStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"availableColors", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_availableColors },
        { (char*)"color", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_color },
        { (char*)"opacity", (char*)"()D", (void*)Java_hep_aida_jni_CIBrushStyle_opacity },
        { (char*)"setColor", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setColor },
        { (char*)"setOpacity", (char*)"(D)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setOpacity },

        { (char*)"availablePatterns", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFillStyle_availablePatterns },
        { (char*)"pattern", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFillStyle_pattern },
        { (char*)"setPattern", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIFillStyle_setPattern },
    };
    LOADCLASS(classCIFillStyle, "hep/aida/jni/CIFillStyle", ctorCIFillStyle, 
              crefCIFillStyle, methodsCIFillStyle, 1+6+5+3);

    JNINativeMethod methodsCIFilter[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"initialize", (char*)"(Lhep/aida/ITuple;)V", (void*)Java_hep_aida_jni_CIFilter_initialize },
        { (char*)"accept", (char*)"()Z", (void*)Java_hep_aida_jni_CIFilter_accept },
        { (char*)"expression", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFilter_expression },
    };
    LOADCLASS(classCIFilter, "hep/aida/jni/CIFilter", ctorCIFilter,
              crefCIFilter, methodsCIFilter, 1+3);

    JNINativeMethod methodsCIFitData[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"create1DConnection", (char*)"(Lhep/aida/IHistogram1D;)V", (void*)Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IHistogram1D_2 },
        { (char*)"create1DConnection", (char*)"(Lhep/aida/ICloud1D;)V", (void*)Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_ICloud1D_2 },
        { (char*)"create1DConnection", (char*)"(Lhep/aida/IProfile1D;)V", (void*)Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IProfile1D_2 },
        { (char*)"create1DConnection", (char*)"(Lhep/aida/IDataPointSet;II)V", (void*)Java_hep_aida_jni_CIFitData_create1DConnection__Lhep_aida_IDataPointSet_2II },
//        { (char*)"create1DConnection", (char*)"([D[D[[D)V", (void*)Java_hep_aida_jni_CIFitData_create1DConnection___3D_3D_3_3D },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/IHistogram2D;)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IHistogram2D_2 },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/IHistogram2D;II)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IHistogram2D_2II },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/ICloud2D;)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_ICloud2D_2 },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/ICloud2D;II)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_ICloud2D_2II },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/IProfile2D;)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IProfile2D_2 },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/IProfile2D;II)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IProfile2D_2II },
        { (char*)"create2DConnection", (char*)"(Lhep/aida/IDataPointSet;III)V", (void*)Java_hep_aida_jni_CIFitData_create2DConnection__Lhep_aida_IDataPointSet_2III },
        { (char*)"create3DConnection", (char*)"(Lhep/aida/IHistogram3D;)V", (void*)Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IHistogram3D_2 },
        { (char*)"create3DConnection", (char*)"(Lhep/aida/IHistogram3D;III)V", (void*)Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IHistogram3D_2III },
        { (char*)"create3DConnection", (char*)"(Lhep/aida/ICloud3D;)V", (void*)Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_ICloud3D_2 },
        { (char*)"create3DConnection", (char*)"(Lhep/aida/ICloud3D;III)V", (void*)Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_ICloud3D_2III },
        { (char*)"create3DConnection", (char*)"(Lhep/aida/IDataPointSet;IIII)V", (void*)Java_hep_aida_jni_CIFitData_create3DConnection__Lhep_aida_IDataPointSet_2IIII },
        { (char*)"createConnection", (char*)"(Lhep/aida/ITuple;[Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_ITuple_2_3Ljava_lang_String_2 },
        { (char*)"createConnection", (char*)"(Lhep/aida/ITuple;[Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_ITuple_2_3Lhep_aida_IEvaluator_2 },
        { (char*)"createConnection", (char*)"(Lhep/aida/IDataPointSet;[II)V", (void*)Java_hep_aida_jni_CIFitData_createConnection__Lhep_aida_IDataPointSet_2_3II },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIFitData_reset },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIFitData_dimension },
        { (char*)"dataDescription", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitData_dataDescription },
        { (char*)"range", (char*)"(I)Lhep/aida/IRangeSet;", (void*)Java_hep_aida_jni_CIFitData_range },
    };
    LOADCLASS(classCIFitData, "hep/aida/jni/CIFitData", ctorCIFitData,
              crefCIFitData, methodsCIFitData, 1+24);

    JNINativeMethod methodsCIFitFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"createFitData", (char*)"()Lhep/aida/IFitData;", (void*)Java_hep_aida_jni_CIFitFactory_createFitData },
        { (char*)"createFitter", (char*)"()Lhep/aida/IFitter;", (void*)Java_hep_aida_jni_CIFitFactory_createFitter__ },
        { (char*)"createFitter", (char*)"(Ljava/lang/String;)Lhep/aida/IFitter;", (void*)Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2 },
        { (char*)"createFitter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;", (void*)Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createFitter", (char*)"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFitter;", (void*)Java_hep_aida_jni_CIFitFactory_createFitter__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 },
    };
    LOADCLASS(classCIFitFactory, "hep/aida/jni/CIFitFactory", ctorCIFitFactory,
              crefCIFitFactory, methodsCIFitFactory, 1+5);

    JNINativeMethod methodsCIFitParameterSettings[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"name", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitParameterSettings_name },
        { (char*)"stepSize", (char*)"()D", (void*)Java_hep_aida_jni_CIFitParameterSettings_stepSize },
        { (char*)"upperBound", (char*)"()D", (void*)Java_hep_aida_jni_CIFitParameterSettings_upperBound },
        { (char*)"lowerBound", (char*)"()D", (void*)Java_hep_aida_jni_CIFitParameterSettings_lowerBound },
        { (char*)"isBound", (char*)"()Z", (void*)Java_hep_aida_jni_CIFitParameterSettings_isBound },
        { (char*)"isFixed", (char*)"()Z", (void*)Java_hep_aida_jni_CIFitParameterSettings_isFixed },
        { (char*)"setStepSize", (char*)"(D)V", (void*)Java_hep_aida_jni_CIFitParameterSettings_setStepSize },
        { (char*)"setBounds", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIFitParameterSettings_setBounds },
        { (char*)"removeBounds", (char*)"()V", (void*)Java_hep_aida_jni_CIFitParameterSettings_removeBounds },
        { (char*)"setFixed", (char*)"(Z)V", (void*)Java_hep_aida_jni_CIFitParameterSettings_setFixed },
        { (char*)"setLowerBound", (char*)"(D)V", (void*)Java_hep_aida_jni_CIFitParameterSettings_setLowerBound },
        { (char*)"setUpperBound", (char*)"(D)V", (void*)Java_hep_aida_jni_CIFitParameterSettings_setUpperBound },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIFitParameterSettings_reset },
    };
    LOADCLASS(classCIFitParameterSettings, "hep/aida/jni/CIFitParameterSettings", ctorCIFitParameterSettings,        
              crefCIFitParameterSettings, methodsCIFitParameterSettings, 1+13);

    JNINativeMethod methodsCIFitResult[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"isValid", (char*)"()Z", (void*)Java_hep_aida_jni_CIFitResult_isValid },
        { (char*)"fitStatus", (char*)"()I", (void*)Java_hep_aida_jni_CIFitResult_fitStatus },
        { (char*)"fittedFunction", (char*)"()Lhep/aida/IFunction;", (void*)Java_hep_aida_jni_CIFitResult_fittedFunction },
        { (char*)"quality", (char*)"()D", (void*)Java_hep_aida_jni_CIFitResult_quality },
        { (char*)"ndf", (char*)"()I", (void*)Java_hep_aida_jni_CIFitResult_ndf },
        { (char*)"covMatrixElement", (char*)"(II)D", (void*)Java_hep_aida_jni_CIFitResult_covMatrixElement },
        { (char*)"fitMethodName", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitResult_fitMethodName },
        { (char*)"engineName", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitResult_engineName },
        { (char*)"dataDescription", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitResult_dataDescription },
        { (char*)"constraints", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitResult_constraints },
        { (char*)"fitParameterSettings", (char*)"(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;", (void*)Java_hep_aida_jni_CIFitResult_fitParameterSettings },
        { (char*)"fittedParameters", (char*)"()[D", (void*)Java_hep_aida_jni_CIFitResult_fittedParameters },
        { (char*)"fittedParameterNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitResult_fittedParameterNames },
        { (char*)"fittedParameter", (char*)"(Ljava/lang/String;)D", (void*)Java_hep_aida_jni_CIFitResult_fittedParameter },
        { (char*)"errors", (char*)"()[D", (void*)Java_hep_aida_jni_CIFitResult_errors },
        { (char*)"errorsPlus", (char*)"()[D", (void*)Java_hep_aida_jni_CIFitResult_errorsPlus },
        { (char*)"errorsMinus", (char*)"()[D", (void*)Java_hep_aida_jni_CIFitResult_errorsMinus },
    };
    LOADCLASS(classCIFitResult, "hep/aida/jni/CIFitResult", ctorCIFitResult,        
              crefCIFitResult, methodsCIFitResult, 1+17);

    JNINativeMethod methodsCIFitter[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"fit", (char*)"(Lhep/aida/IFitData;Lhep/aida/IFunction;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Lhep_aida_IFunction_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IBaseHistogram;Lhep/aida/IFunction;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Lhep_aida_IFunction_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IBaseHistogram;Ljava/lang/String;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IBaseHistogram;Ljava/lang/String;[D)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2_3D },
        { (char*)"fit", (char*)"(Lhep/aida/IDataPointSet;Lhep/aida/IFunction;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Lhep_aida_IFunction_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IDataPointSet;Ljava/lang/String;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Ljava_lang_String_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IDataPointSet;Ljava/lang/String;[D)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IDataPointSet_2Ljava_lang_String_2_3D },
        { (char*)"fit", (char*)"(Lhep/aida/IFitData;Ljava/lang/String;)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Ljava_lang_String_2 },
        { (char*)"fit", (char*)"(Lhep/aida/IFitData;Ljava/lang/String;[D)Lhep/aida/IFitResult;", (void*)Java_hep_aida_jni_CIFitter_fit__Lhep_aida_IFitData_2Ljava_lang_String_2_3D },
        { (char*)"setEngine", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFitter_setEngine },
        { (char*)"engineName", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitter_engineName },
        { (char*)"fitParameterSettings", (char*)"(Ljava/lang/String;)Lhep/aida/IFitParameterSettings;", (void*)Java_hep_aida_jni_CIFitter_fitParameterSettings },
        { (char*)"listParameterSettings", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitter_listParameterSettings },
        { (char*)"resetParameterSettings", (char*)"()V", (void*)Java_hep_aida_jni_CIFitter_resetParameterSettings },
        { (char*)"setConstraint", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFitter_setConstraint },
        { (char*)"constraints", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitter_constraints },
        { (char*)"resetConstraints", (char*)"()V", (void*)Java_hep_aida_jni_CIFitter_resetConstraints },
        { (char*)"setFitMethod", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFitter_setFitMethod },
        { (char*)"fitMethodName", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFitter_fitMethodName },
        { (char*)"createScan1D", (char*)"(Lhep/aida/IFitData;Lhep/aida/IFunction;Ljava/lang/String;IDD)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIFitter_createScan1D },
        { (char*)"createContour", (char*)"(Lhep/aida/IFitData;Lhep/aida/IFitResult;Ljava/lang/String;Ljava/lang/String;ID)Lhep/aida/IDataPointSet;", (void*)Java_hep_aida_jni_CIFitter_createContour },
        { (char*)"setUseFunctionGradient", (char*)"(Z)V", (void*)Java_hep_aida_jni_CIFitter_setUseFunctionGradient },
        { (char*)"useFunctionGradient", (char*)"()Z", (void*)Java_hep_aida_jni_CIFitter_useFunctionGradient },
    };
    LOADCLASS(classCIFitter, "hep/aida/jni/CIFitter", ctorCIFitter,        
              crefCIFitter, methodsCIFitter, 1+23);

    JNINativeMethod methodsCIFunction[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFunction_setTitle },
        { (char*)"value", (char*)"([D)D", (void*)Java_hep_aida_jni_CIFunction_value },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIFunction_dimension },
        { (char*)"isEqual", (char*)"(Lhep/aida/IFunction;)Z", (void*)Java_hep_aida_jni_CIFunction_isEqual },
        { (char*)"gradient", (char*)"([D)[D", (void*)Java_hep_aida_jni_CIFunction_gradient },
        { (char*)"providesGradient", (char*)"()Z", (void*)Java_hep_aida_jni_CIFunction_providesGradient },
        { (char*)"variableName", (char*)"(I)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_variableName },
        { (char*)"variableNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_variableNames },
        { (char*)"setParameters", (char*)"([D)V", (void*)Java_hep_aida_jni_CIFunction_setParameters },
        { (char*)"parameters", (char*)"()[D", (void*)Java_hep_aida_jni_CIFunction_parameters },
        { (char*)"numberOfParameters", (char*)"()I", (void*)Java_hep_aida_jni_CIFunction_numberOfParameters },
        { (char*)"parameterNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_parameterNames },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;D)V", (void*)Java_hep_aida_jni_CIFunction_setParameter },
        { (char*)"parameter", (char*)"(Ljava/lang/String;)D", (void*)Java_hep_aida_jni_CIFunction_parameter },
        { (char*)"indexOfParameter", (char*)"(Ljava/lang/String;)I", (void*)Java_hep_aida_jni_CIFunction_indexOfParameter },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIFunction_annotation },
        { (char*)"codeletString", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_codeletString },
    };
    LOADCLASS(classCIFunction, "hep/aida/jni/CIFunction", ctorCIFunction,
              crefCIFunction, methodsCIFunction, 1+18);

    JNINativeMethod methodsCIFunctionCatalog[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"add", (char*)"(Ljava/lang/String;Lhep/aida/IFunction;)Z", (void*)Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Lhep_aida_IFunction_2 },
        { (char*)"add", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIFunctionCatalog_add__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"list", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunctionCatalog_list },
        { (char*)"remove", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFunctionCatalog_remove },
        { (char*)"storeAll", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFunctionCatalog_storeAll },
        { (char*)"loadAll", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFunctionCatalog_loadAll },
    };
    LOADCLASS(classCIFunctionCatalog, "hep/aida/jni/CIFunctionCatalog", ctorCIFunctionCatalog,
              crefCIFunctionCatalog, methodsCIFunctionCatalog, 1+6);

    JNINativeMethod methodsCIFunctionFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"createFunctionByName", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;", (void*)Java_hep_aida_jni_CIFunctionFactory_createFunctionByName },
        { (char*)"createFunctionFromScript", (char*)"(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;", (void*)Java_hep_aida_jni_CIFunctionFactory_createFunctionFromScript__Ljava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createFunctionFromScript", (char*)"(Ljava/lang/String;ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/IFunction;", (void*)Java_hep_aida_jni_CIFunctionFactory_createFunctionFromScript__Ljava_lang_String_2ILjava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"cloneFunction", (char*)"(Ljava/lang/String;Lhep/aida/IFunction;)Lhep/aida/IFunction;", (void*)Java_hep_aida_jni_CIFunctionFactory_cloneFunction },
        { (char*)"catalog", (char*)"()Lhep/aida/IFunctionCatalog;", (void*)Java_hep_aida_jni_CIFunctionFactory_catalog },
    };
    LOADCLASS(classCIFunctionFactory, "hep/aida/jni/CIFunctionFactory", ctorCIFunctionFactory,
              crefCIFunctionFactory, methodsCIFunctionFactory, 1+5);

/* FIXME 3.2.4
    JNINativeMethod methodsCIHistogramFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"destroy", (char*)"(Lhep/aida/IBaseHistogram;)V", (void*)Java_hep_aida_jni_CIHistogramFactory_destroy },
        { (char*)"createCloud1D", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ICloud1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud1D__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createCloud1D", (char*)"(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/ICloud1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud1D__Ljava_lang_String_2Ljava_lang_String_2I },
        { (char*)"createCloud1D", (char*)"(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud1D__Ljava_lang_String_2Ljava_lang_String_2ILjava_lang_String_2 },
        { (char*)"createCloud1D", (char*)"(Ljava/lang/String;)Lhep/aida/ICloud1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud1D__Ljava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/ICloud1D;)Lhep/aida/ICloud1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_ICloud1D_2 },
        { (char*)"createCloud2D", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ICloud2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud2D__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createCloud2D", (char*)"(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/ICloud2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud2D__Ljava_lang_String_2Ljava_lang_String_2I },
        { (char*)"createCloud2D", (char*)"(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud2D__Ljava_lang_String_2Ljava_lang_String_2ILjava_lang_String_2 },
        { (char*)"createCloud2D", (char*)"(Ljava/lang/String;)Lhep/aida/ICloud2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud2D__Ljava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/ICloud2D;)Lhep/aida/ICloud2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_ICloud2D_2 },
        { (char*)"createCloud3D", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ICloud3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud3D__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createCloud3D", (char*)"(Ljava/lang/String;Ljava/lang/String;I)Lhep/aida/ICloud3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud3D__Ljava_lang_String_2Ljava_lang_String_2I },
        { (char*)"createCloud3D", (char*)"(Ljava/lang/String;Ljava/lang/String;ILjava/lang/String;)Lhep/aida/ICloud3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud3D__Ljava_lang_String_2Ljava_lang_String_2ILjava_lang_String_2 },
        { (char*)"createCloud3D", (char*)"(Ljava/lang/String;)Lhep/aida/ICloud3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCloud3D__Ljava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/ICloud3D;)Lhep/aida/ICloud3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_ICloud3D_2 },
        { (char*)"createHistogram1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDD)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram1D__Ljava_lang_String_2Ljava_lang_String_2IDD },
        { (char*)"createHistogram1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram1D__Ljava_lang_String_2Ljava_lang_String_2IDDLjava_lang_String_2 },
        { (char*)"createHistogram1D", (char*)"(Ljava/lang/String;IDD)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram1D__Ljava_lang_String_2IDD },
        { (char*)"createHistogram1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram1D__Ljava_lang_String_2Ljava_lang_String_2_3D },
        { (char*)"createHistogram1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram1D__Ljava_lang_String_2Ljava_lang_String_2_3DLjava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_IHistogram1D_2 },
        { (char*)"createHistogram2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDD)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDD },
        { (char*)"createHistogram2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDLjava_lang_String_2 },
        { (char*)"createHistogram2D", (char*)"(Ljava/lang/String;IDDIDD)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram2D__Ljava_lang_String_2IDDIDD },
        { (char*)"createHistogram2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3D },
        { (char*)"createHistogram2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3DLjava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_IHistogram2D_2 },
        { (char*)"createHistogram3D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDIDD)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram3D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDIDD },
        { (char*)"createHistogram3D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDIDDLjava/lang/String;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram3D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDIDDLjava_lang_String_2 },
        { (char*)"createHistogram3D", (char*)"(Ljava/lang/String;IDDIDDIDD)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram3D__Ljava_lang_String_2IDDIDDIDD },
        { (char*)"createHistogram3D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[D)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram3D__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3D },
        { (char*)"createHistogram3D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D[DLjava/lang/String;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createHistogram3D__Ljava_lang_String_2Ljava_lang_String_2_3D_3D_3DLjava_lang_String_2 },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_IHistogram3D_2 },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDD)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2IDD },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDLjava/lang/String;)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2IDDLjava_lang_String_2 },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDDD)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2IDDDD },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDDDLjava/lang/String;)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2IDDDDLjava_lang_String_2 },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2_3D },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[DLjava/lang/String;)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2_3DLjava_lang_String_2 },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[DDD)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2_3DDD },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;Ljava/lang/String;[DDDLjava/lang/String;)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2Ljava_lang_String_2_3DDDLjava_lang_String_2 },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;IDD)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2IDD },
        { (char*)"createProfile1D", (char*)"(Ljava/lang/String;IDDDD)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile1D__Ljava_lang_String_2IDDDD },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IProfile1D;)Lhep/aida/IProfile1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_IProfile1D_2 },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDD)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDD },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDLjava/lang/String;)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDLjava_lang_String_2 },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDDD)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDDD },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;IDDIDDDDLjava/lang/String;)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2IDDIDDDDLjava_lang_String_2 },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[D)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3D },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[DLjava/lang/String;)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3DLjava_lang_String_2 },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[DDD)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3DDD },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;Ljava/lang/String;[D[DDDLjava/lang/String;)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2Ljava_lang_String_2_3D_3DDDLjava_lang_String_2 },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;IDDIDD)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2IDDIDD },
        { (char*)"createProfile2D", (char*)"(Ljava/lang/String;IDDIDDDD)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createProfile2D__Ljava_lang_String_2IDDIDDDD },
        { (char*)"createCopy", (char*)"(Ljava/lang/String;Lhep/aida/IProfile2D;)Lhep/aida/IProfile2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_createCopy__Ljava_lang_String_2Lhep_aida_IProfile2D_2 },
        { (char*)"add", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_add__Ljava_lang_String_2Lhep_aida_IHistogram1D_2Lhep_aida_IHistogram1D_2 },
        { (char*)"subtract", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_subtract__Ljava_lang_String_2Lhep_aida_IHistogram1D_2Lhep_aida_IHistogram1D_2 },
        { (char*)"multiply", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_multiply__Ljava_lang_String_2Lhep_aida_IHistogram1D_2Lhep_aida_IHistogram1D_2 },
        { (char*)"divide", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram1D;Lhep/aida/IHistogram1D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_divide__Ljava_lang_String_2Lhep_aida_IHistogram1D_2Lhep_aida_IHistogram1D_2 },
        { (char*)"add", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_add__Ljava_lang_String_2Lhep_aida_IHistogram2D_2Lhep_aida_IHistogram2D_2 },
        { (char*)"subtract", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_subtract__Ljava_lang_String_2Lhep_aida_IHistogram2D_2Lhep_aida_IHistogram2D_2 },
        { (char*)"multiply", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_multiply__Ljava_lang_String_2Lhep_aida_IHistogram2D_2Lhep_aida_IHistogram2D_2 },
        { (char*)"divide", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_divide__Ljava_lang_String_2Lhep_aida_IHistogram2D_2Lhep_aida_IHistogram2D_2 },
        { (char*)"add", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_add__Ljava_lang_String_2Lhep_aida_IHistogram3D_2Lhep_aida_IHistogram3D_2 },
        { (char*)"subtract", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_subtract__Ljava_lang_String_2Lhep_aida_IHistogram3D_2Lhep_aida_IHistogram3D_2 },
        { (char*)"multiply", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_multiply__Ljava_lang_String_2Lhep_aida_IHistogram3D_2Lhep_aida_IHistogram3D_2 },
        { (char*)"divide", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram3D;", (void*)Java_hep_aida_jni_CIHistogramFactory_divide__Ljava_lang_String_2Lhep_aida_IHistogram3D_2Lhep_aida_IHistogram3D_2 },
        { (char*)"projectionX", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_projectionX },
        { (char*)"projectionY", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_projectionY },
        { (char*)"sliceX", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceX__Ljava_lang_String_2Lhep_aida_IHistogram2D_2I },
        { (char*)"sliceY", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;I)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceY__Ljava_lang_String_2Lhep_aida_IHistogram2D_2I },
        { (char*)"sliceX", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceX__Ljava_lang_String_2Lhep_aida_IHistogram2D_2II },
        { (char*)"sliceY", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram2D;II)Lhep/aida/IHistogram1D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceY__Ljava_lang_String_2Lhep_aida_IHistogram2D_2II },
        { (char*)"projectionXY", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_projectionXY },
        { (char*)"projectionXZ", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_projectionXZ },
        { (char*)"projectionYZ", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_projectionYZ },
        { (char*)"sliceXY", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceXY },
        { (char*)"sliceXZ", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceXZ },
        { (char*)"sliceYZ", (char*)"(Ljava/lang/String;Lhep/aida/IHistogram3D;II)Lhep/aida/IHistogram2D;", (void*)Java_hep_aida_jni_CIHistogramFactory_sliceYZ },
    };
    LOADCLASS(classCIHistogramFactory, "hep/aida/jni/CIHistogramFactory", ctorCIHistogramFactory,      
              crefCIHistogramFactory, methodsCIHistogramFactory, 1+80);
*/
    JNINativeMethod methodsCIHistogram1D[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"allEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_allEntries },
        { (char*)"extraEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_extraEntries },
        { (char*)"equivalentBinEntries", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_equivalentBinEntries },
        { (char*)"sumBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumBinHeights },
        { (char*)"sumAllBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumAllBinHeights },
        { (char*)"sumExtraBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumExtraBinHeights },
        { (char*)"minBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_minBinHeight },
        { (char*)"maxBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_maxBinHeight },
        { (char*)"scale", (char*)"(D)V", (void*)Java_hep_aida_jni_CIHistogram_scale },

        { (char*)"fill", (char*)"(D)V", (void*)Java_hep_aida_jni_CIHistogram1D_fill__D },
        { (char*)"fill", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIHistogram1D_fill__DD },
        { (char*)"binMean", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram1D_binMean },
        { (char*)"binEntries", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram1D_binEntries },
        { (char*)"binHeight", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram1D_binHeight },
        { (char*)"binError", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram1D_binError },
        { (char*)"mean", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram1D_mean },
        { (char*)"rms", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram1D_rms },
        { (char*)"axis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram1D_axis },
        { (char*)"coordToIndex", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram1D_coordToIndex },
        { (char*)"add", (char*)"(Lhep/aida/IHistogram1D;)V", (void*)Java_hep_aida_jni_CIHistogram1D_add }
    };
    LOADCLASS(classCIHistogram1D, "hep/aida/jni/CIHistogram1D", ctorCIHistogram1D,      
              crefCIHistogram1D, methodsCIHistogram1D, 1+6+9+11);

    JNINativeMethod methodsCIHistogram2D[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"allEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_allEntries },
        { (char*)"extraEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_extraEntries },
        { (char*)"equivalentBinEntries", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_equivalentBinEntries },
        { (char*)"sumBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumBinHeights },
        { (char*)"sumAllBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumAllBinHeights },
        { (char*)"sumExtraBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumExtraBinHeights },
        { (char*)"minBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_minBinHeight },
        { (char*)"maxBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_maxBinHeight },
        { (char*)"scale", (char*)"(D)V", (void*)Java_hep_aida_jni_CIHistogram_scale },

        { (char*)"fill", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIHistogram2D_fill__DD },
        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CIHistogram2D_fill__DDD },
        { (char*)"binMeanX", (char*)"(II)D", (void*)Java_hep_aida_jni_CIHistogram2D_binMeanX },
        { (char*)"binMeanY", (char*)"(II)D", (void*)Java_hep_aida_jni_CIHistogram2D_binMeanY },
        { (char*)"binEntries", (char*)"(II)I", (void*)Java_hep_aida_jni_CIHistogram2D_binEntries },
        { (char*)"binEntriesX", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram2D_binEntriesX },
        { (char*)"binEntriesY", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram2D_binEntriesY },
        { (char*)"binHeight", (char*)"(II)D", (void*)Java_hep_aida_jni_CIHistogram2D_binHeight },
        { (char*)"binHeightX", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram2D_binHeightX },
        { (char*)"binHeightY", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram2D_binHeightY },
        { (char*)"binError", (char*)"(II)D", (void*)Java_hep_aida_jni_CIHistogram2D_binError },
        { (char*)"meanX", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram2D_meanX },
        { (char*)"meanY", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram2D_meanY },
        { (char*)"rmsX", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram2D_rmsX },
        { (char*)"rmsY", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram2D_rmsY },
        { (char*)"xAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram2D_xAxis },
        { (char*)"yAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram2D_yAxis },
        { (char*)"coordToIndexX", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram2D_coordToIndexX },
        { (char*)"coordToIndexY", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram2D_coordToIndexY },
        { (char*)"add", (char*)"(Lhep/aida/IHistogram2D;)V", (void*)Java_hep_aida_jni_CIHistogram2D_add },
    };
    LOADCLASS(classCIHistogram2D, "hep/aida/jni/CIHistogram2D", ctorCIHistogram2D,      
              crefCIHistogram2D, methodsCIHistogram2D, 1+6+9+20);

    JNINativeMethod methodsCIHistogram3D[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"allEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_allEntries },
        { (char*)"extraEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIHistogram_extraEntries },
        { (char*)"equivalentBinEntries", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_equivalentBinEntries },
        { (char*)"sumBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumBinHeights },
        { (char*)"sumAllBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumAllBinHeights },
        { (char*)"sumExtraBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_sumExtraBinHeights },
        { (char*)"minBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_minBinHeight },
        { (char*)"maxBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram_maxBinHeight },
        { (char*)"scale", (char*)"(D)V", (void*)Java_hep_aida_jni_CIHistogram_scale },

        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CIHistogram3D_fill__DDD },
        { (char*)"fill", (char*)"(DDDD)V", (void*)Java_hep_aida_jni_CIHistogram3D_fill__DDDD },
        { (char*)"binMeanX", (char*)"(III)D", (void*)Java_hep_aida_jni_CIHistogram3D_binMeanX },
        { (char*)"binMeanY", (char*)"(III)D", (void*)Java_hep_aida_jni_CIHistogram3D_binMeanY },
        { (char*)"binMeanZ", (char*)"(III)D", (void*)Java_hep_aida_jni_CIHistogram3D_binMeanZ },
        { (char*)"binEntries", (char*)"(III)I", (void*)Java_hep_aida_jni_CIHistogram3D_binEntries },
        { (char*)"binEntriesX", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram3D_binEntriesX },
        { (char*)"binEntriesY", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram3D_binEntriesY },
        { (char*)"binEntriesZ", (char*)"(I)I", (void*)Java_hep_aida_jni_CIHistogram3D_binEntriesZ },
        { (char*)"binHeight", (char*)"(III)D", (void*)Java_hep_aida_jni_CIHistogram3D_binHeight },
        { (char*)"binHeightX", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram3D_binHeightX },
        { (char*)"binHeightY", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram3D_binHeightY },
        { (char*)"binHeightZ", (char*)"(I)D", (void*)Java_hep_aida_jni_CIHistogram3D_binHeightZ },
        { (char*)"binError", (char*)"(III)D", (void*)Java_hep_aida_jni_CIHistogram3D_binError },
        { (char*)"meanX", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_meanX },
        { (char*)"meanY", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_meanY },
        { (char*)"meanZ", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_meanZ },
        { (char*)"rmsX", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_rmsX },
        { (char*)"rmsY", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_rmsY },
        { (char*)"rmsZ", (char*)"()D", (void*)Java_hep_aida_jni_CIHistogram3D_rmsZ },
        { (char*)"xAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram3D_xAxis },
        { (char*)"yAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram3D_yAxis },
        { (char*)"zAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIHistogram3D_zAxis },
        { (char*)"coordToIndexX", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram3D_coordToIndexX },
        { (char*)"coordToIndexY", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram3D_coordToIndexY },
        { (char*)"coordToIndexZ", (char*)"(D)I", (void*)Java_hep_aida_jni_CIHistogram3D_coordToIndexZ },
        { (char*)"add", (char*)"(Lhep/aida/IHistogram3D;)V", (void*)Java_hep_aida_jni_CIHistogram3D_add },
    };
    LOADCLASS(classCIHistogram3D, "hep/aida/jni/CIHistogram3D", ctorCIHistogram3D,     
              crefCIHistogram3D, methodsCIHistogram3D, 1+6+9+27);

    JNINativeMethod methodsCIInfo[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"clear", (char*)"()V", (void*)Java_hep_aida_jni_CIInfo_clear },
        { (char*)"addText", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIInfo_addText },
        { (char*)"addLegend", (char*)"(Lhep/aida/IMarkerStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_IMarkerStyle_2Ljava_lang_String_2 },
        { (char*)"addLegend", (char*)"(Lhep/aida/ILineStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_ILineStyle_2Ljava_lang_String_2 },
        { (char*)"addLegend", (char*)"(Lhep/aida/IFillStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIInfo_addLegend__Lhep_aida_IFillStyle_2Ljava_lang_String_2 },
    };
    LOADCLASS(classCIInfo, "hep/aida/jni/CIInfo", ctorCIInfo,        
              crefCIInfo, methodsCIInfo, 1+5);

    JNINativeMethod methodsCIInfoStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"textStyle", (char*)"()Lhep/aida/ITextStyle;", (void*)Java_hep_aida_jni_CIInfoStyle_textStyle },
        { (char*)"setTextStyle", (char*)"(Lhep/aida/ITextStyle;)Z", (void*)Java_hep_aida_jni_CIInfoStyle_setTextStyle },
    };
    LOADCLASS(classCIInfoStyle, "hep/aida/jni/CIInfoStyle", ctorCIInfoStyle,        
              crefCIInfoStyle, methodsCIInfoStyle, 1+6+2);

    JNINativeMethod methodsCILineStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"availableColors", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_availableColors },
        { (char*)"color", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_color },
        { (char*)"opacity", (char*)"()D", (void*)Java_hep_aida_jni_CIBrushStyle_opacity },
        { (char*)"setColor", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setColor },
        { (char*)"setOpacity", (char*)"(D)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setOpacity },

        { (char*)"availableLineTypes", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CILineStyle_availableLineTypes },
        { (char*)"lineType", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CILineStyle_lineType },
        { (char*)"thickness", (char*)"()I", (void*)Java_hep_aida_jni_CILineStyle_thickness },
        { (char*)"setLineType", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CILineStyle_setLineType },
        { (char*)"setThickness", (char*)"(I)Z", (void*)Java_hep_aida_jni_CILineStyle_setThickness },
    };
    LOADCLASS(classCILineStyle, "hep/aida/jni/CILineStyle", ctorCILineStyle,
              crefCILineStyle, methodsCILineStyle, 1+6+5+5);

    JNINativeMethod methodsCIMarkerStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"availableColors", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_availableColors },
        { (char*)"color", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_color },
        { (char*)"opacity", (char*)"()D", (void*)Java_hep_aida_jni_CIBrushStyle_opacity },
        { (char*)"setColor", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setColor },
        { (char*)"setOpacity", (char*)"(D)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setOpacity },

        { (char*)"availableShapes", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIMarkerStyle_availableShapes },
        { (char*)"shape", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIMarkerStyle_shape },
        { (char*)"setShape", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIMarkerStyle_setShape },
    };
    LOADCLASS(classCIMarkerStyle, "hep/aida/jni/CIMarkerStyle", ctorCIMarkerStyle,
              crefCIMarkerStyle, methodsCIMarkerStyle, 1+6+5+3);

    JNINativeMethod methodsCIManagedObject[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"name", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIManagedObject_name },
//        { (char*)"type", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIManagedObject_type },
    };
    LOADCLASS(classCIManagedObject, "hep/aida/jni/CIManagedObject", ctorCIManagedObject,    
              crefCIManagedObject, methodsCIManagedObject, 1+1);

    JNINativeMethod methodsCIMeasurement[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"value", (char*)"()D", (void*)Java_hep_aida_jni_CIMeasurement_value },
        { (char*)"errorPlus", (char*)"()D", (void*)Java_hep_aida_jni_CIMeasurement_errorPlus },
        { (char*)"errorMinus", (char*)"()D", (void*)Java_hep_aida_jni_CIMeasurement_errorMinus },
        { (char*)"setValue", (char*)"(D)V", (void*)Java_hep_aida_jni_CIMeasurement_setValue },
        { (char*)"setErrorPlus", (char*)"(D)V", (void*)Java_hep_aida_jni_CIMeasurement_setErrorPlus },
        { (char*)"setErrorMinus", (char*)"(D)V", (void*)Java_hep_aida_jni_CIMeasurement_setErrorMinus },
    };
    LOADCLASS(classCIMeasurement, "hep/aida/jni/CIMeasurement", ctorCIMeasurement,    
              crefCIMeasurement, methodsCIMeasurement, 1+6);

    JNINativeMethod methodsCIModelFunction[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIFunction_setTitle },
        { (char*)"value", (char*)"([D)D", (void*)Java_hep_aida_jni_CIFunction_value },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIFunction_dimension },
        { (char*)"isEqual", (char*)"(Lhep/aida/IFunction;)Z", (void*)Java_hep_aida_jni_CIFunction_isEqual },
        { (char*)"gradient", (char*)"([D)[D", (void*)Java_hep_aida_jni_CIFunction_gradient },
        { (char*)"providesGradient", (char*)"()Z", (void*)Java_hep_aida_jni_CIFunction_providesGradient },
        { (char*)"variableName", (char*)"(I)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_variableName },
        { (char*)"variableNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_variableNames },
        { (char*)"setParameters", (char*)"([D)V", (void*)Java_hep_aida_jni_CIFunction_setParameters },
        { (char*)"parameters", (char*)"()[D", (void*)Java_hep_aida_jni_CIFunction_parameters },
        { (char*)"numberOfParameters", (char*)"()I", (void*)Java_hep_aida_jni_CIFunction_numberOfParameters },
        { (char*)"parameterNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_parameterNames },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;D)V", (void*)Java_hep_aida_jni_CIFunction_setParameter },
        { (char*)"parameter", (char*)"(Ljava/lang/String;)D", (void*)Java_hep_aida_jni_CIFunction_parameter },
        { (char*)"indexOfParameter", (char*)"(Ljava/lang/String;)I", (void*)Java_hep_aida_jni_CIFunction_indexOfParameter },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIFunction_annotation },
        { (char*)"codeletString", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIFunction_codeletString },

        { (char*)"providesNormalization", (char*)"()Z", (void*)Java_hep_aida_jni_CIModelFunction_providesNormalization },
        { (char*)"normalize", (char*)"(Z)V", (void*)Java_hep_aida_jni_CIModelFunction_normalize },
        { (char*)"isNormalized", (char*)"()Z", (void*)Java_hep_aida_jni_CIModelFunction_isNormalized },
        { (char*)"parameterGradient", (char*)"([D)[D", (void*)Java_hep_aida_jni_CIModelFunction_parameterGradient },
        { (char*)"providesParameterGradient", (char*)"()Z", (void*)Java_hep_aida_jni_CIModelFunction_providesParameterGradient },
        { (char*)"normalizationRange", (char*)"(I)Lhep/aida/IRangeSet;", (void*)Java_hep_aida_jni_CIModelFunction_normalizationRange },
        { (char*)"includeNormalizationAll", (char*)"()V", (void*)Java_hep_aida_jni_CIModelFunction_includeNormalizationAll },
        { (char*)"excludeNormalizationAll", (char*)"()V", (void*)Java_hep_aida_jni_CIModelFunction_excludeNormalizationAll },
    };
    LOADCLASS(classCIModelFunction, "hep/aida/jni/CIModelFunction", ctorCIModelFunction,
              crefCIModelFunction, methodsCIModelFunction, 1+18+8);

    JNINativeMethod methodsCIPlotter[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"createRegion", (char*)"()Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_createRegion__ },
        { (char*)"createRegion", (char*)"(D)Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_createRegion__D },
        { (char*)"createRegion", (char*)"(DD)Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_createRegion__DD },
        { (char*)"createRegion", (char*)"(DDD)Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_createRegion__DDD },
        { (char*)"createRegion", (char*)"(DDDD)Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_createRegion__DDDD },
        { (char*)"createRegions", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_createRegions__ },
        { (char*)"createRegions", (char*)"(I)V", (void*)Java_hep_aida_jni_CIPlotter_createRegions__I },
        { (char*)"createRegions", (char*)"(II)V", (void*)Java_hep_aida_jni_CIPlotter_createRegions__II },
        { (char*)"createRegions", (char*)"(III)V", (void*)Java_hep_aida_jni_CIPlotter_createRegions__III },
        { (char*)"currentRegion", (char*)"()Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_currentRegion },
        { (char*)"currentRegionNumber", (char*)"()I", (void*)Java_hep_aida_jni_CIPlotter_currentRegionNumber },
        { (char*)"numberOfRegions", (char*)"()I", (void*)Java_hep_aida_jni_CIPlotter_numberOfRegions },
        { (char*)"setCurrentRegionNumber", (char*)"(I)V", (void*)Java_hep_aida_jni_CIPlotter_setCurrentRegionNumber },
        { (char*)"next", (char*)"()Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_next },
        { (char*)"region", (char*)"(I)Lhep/aida/IPlotterRegion;", (void*)Java_hep_aida_jni_CIPlotter_region },
        { (char*)"destroyRegions", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_destroyRegions },
        { (char*)"clearRegions", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_clearRegions },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotter_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotter_parameterValue },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotter_availableParameterOptions },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotter_availableParameters },
        { (char*)"show", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_show },
        { (char*)"refresh", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_refresh },
        { (char*)"hide", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_hide },
        { (char*)"interact", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotter_interact },
        { (char*)"writeToFile", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2 },
        { (char*)"writeToFile", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotter_writeToFile__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotter_setTitle },
        { (char*)"titleStyle", (char*)"()Lhep/aida/ITitleStyle;", (void*)Java_hep_aida_jni_CIPlotter_titleStyle },
        { (char*)"setTitleStyle", (char*)"(Lhep/aida/ITitleStyle;)V", (void*)Java_hep_aida_jni_CIPlotter_setTitleStyle },
    };
    LOADCLASS(classCIPlotter, "hep/aida/jni/CIPlotter", ctorCIPlotter,    
              crefCIPlotter, methodsCIPlotter, 1+31);

    JNINativeMethod methodsCIPlotterFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"create", (char*)"()Lhep/aida/IPlotter;", (void*)Java_hep_aida_jni_CIPlotterFactory_create__ },
        { (char*)"create", (char*)"(Ljava/lang/String;)Lhep/aida/IPlotter;", (void*)Java_hep_aida_jni_CIPlotterFactory_create__Ljava_lang_String_2 },
        { (char*)"createMarkerStyle", (char*)"()Lhep/aida/IMarkerStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createMarkerStyle },
        { (char*)"createTextStyle", (char*)"()Lhep/aida/ITextStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createTextStyle },
        { (char*)"createLineStyle", (char*)"()Lhep/aida/ILineStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createLineStyle },
        { (char*)"createFillStyle", (char*)"()Lhep/aida/IFillStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createFillStyle },
        { (char*)"createDataStyle", (char*)"()Lhep/aida/IDataStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createDataStyle },
        { (char*)"createAxisStyle", (char*)"()Lhep/aida/IAxisStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createAxisStyle },
        { (char*)"createTitleStyle", (char*)"()Lhep/aida/ITitleStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createTitleStyle },
        { (char*)"createPlotterStyle", (char*)"()Lhep/aida/IPlotterStyle;", (void*)Java_hep_aida_jni_CIPlotterFactory_createPlotterStyle },
    };
    LOADCLASS(classCIPlotterFactory, "hep/aida/jni/CIPlotterFactory", ctorCIPlotterFactory,    
              crefCIPlotterFactory, methodsCIPlotterFactory, 1+10);

    JNINativeMethod methodsCIPlotterLayout[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotterLayout_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;D)Z", (void*)Java_hep_aida_jni_CIPlotterLayout_setParameter },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)D", (void*)Java_hep_aida_jni_CIPlotterLayout_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotterLayout_availableParameters },
    };
    LOADCLASS(classCIPlotterLayout, "hep/aida/jni/CIPlotterLayout", ctorCIPlotterLayout,    
              crefCIPlotterLayout, methodsCIPlotterLayout, 1+4);

    JNINativeMethod methodsCIPlotterRegion[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"plot", (char*)"(Lhep/aida/IBaseHistogram;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IBaseHistogram;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Ljava_lang_String_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Lhep_aida_IPlotterStyle_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IBaseHistogram;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IBaseHistogram_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IFunction;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IFunction;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Ljava_lang_String_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Lhep_aida_IPlotterStyle_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IFunction;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IFunction_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IDataPointSet;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IDataPointSet;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Ljava_lang_String_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Lhep_aida_IPlotterStyle_2 },
        { (char*)"plot", (char*)"(Lhep/aida/IDataPointSet;Lhep/aida/IPlotterStyle;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_plot__Lhep_aida_IDataPointSet_2Lhep_aida_IPlotterStyle_2Ljava_lang_String_2 },
        { (char*)"remove", (char*)"(Lhep/aida/IBaseHistogram;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IBaseHistogram_2 },
        { (char*)"remove", (char*)"(Lhep/aida/IFunction;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IFunction_2 },
        { (char*)"remove", (char*)"(Lhep/aida/IDataPointSet;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_remove__Lhep_aida_IDataPointSet_2 },
        { (char*)"clear", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotterRegion_clear },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotterRegion_parameterValue },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotterRegion_availableParameterOptions },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIPlotterRegion_availableParameters },
        { (char*)"style", (char*)"()Lhep/aida/IPlotterStyle;", (void*)Java_hep_aida_jni_CIPlotterRegion_style },
        { (char*)"setStyle", (char*)"(Lhep/aida/IPlotterStyle;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setStyle },
        { (char*)"applyStyle", (char*)"(Lhep/aida/IPlotterStyle;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_applyStyle },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setTitle },
        { (char*)"setXLimits", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotterRegion_setXLimits__ },
        { (char*)"setXLimits", (char*)"(D)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setXLimits__D },
        { (char*)"setXLimits", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setXLimits__DD },
        { (char*)"setYLimits", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotterRegion_setYLimits__ },
        { (char*)"setYLimits", (char*)"(D)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setYLimits__D },
        { (char*)"setYLimits", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setYLimits__DD },
        { (char*)"setZLimits", (char*)"()V", (void*)Java_hep_aida_jni_CIPlotterRegion_setZLimits__ },
        { (char*)"setZLimits", (char*)"(D)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setZLimits__D },
        { (char*)"setZLimits", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setZLimits__DD },
        { (char*)"layout", (char*)"()Lhep/aida/IPlotterLayout;", (void*)Java_hep_aida_jni_CIPlotterRegion_layout },
        { (char*)"setLayout", (char*)"(Lhep/aida/IPlotterLayout;)V", (void*)Java_hep_aida_jni_CIPlotterRegion_setLayout },
        { (char*)"info", (char*)"()Lhep/aida/IInfo;", (void*)Java_hep_aida_jni_CIPlotterRegion_info },
    };
    LOADCLASS(classCIPlotterRegion, "hep/aida/jni/CIPlotterRegion", ctorCIPlotterRegion,    
              crefCIPlotterRegion, methodsCIPlotterRegion, 1+37);

    JNINativeMethod methodsCIPlotterStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"dataStyle", (char*)"()Lhep/aida/IDataStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_dataStyle },
        { (char*)"xAxisStyle", (char*)"()Lhep/aida/IAxisStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_xAxisStyle },
        { (char*)"yAxisStyle", (char*)"()Lhep/aida/IAxisStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_yAxisStyle },
        { (char*)"zAxisStyle", (char*)"()Lhep/aida/IAxisStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_zAxisStyle },
        { (char*)"titleStyle", (char*)"()Lhep/aida/ITitleStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_titleStyle },
        { (char*)"infoStyle", (char*)"()Lhep/aida/IInfoStyle;", (void*)Java_hep_aida_jni_CIPlotterStyle_infoStyle },
        { (char*)"setDataStyle", (char*)"(Lhep/aida/IDataStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setDataStyle },
        { (char*)"setAxisStyleX", (char*)"(Lhep/aida/IAxisStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setAxisStyleX },
        { (char*)"setAxisStyleY", (char*)"(Lhep/aida/IAxisStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setAxisStyleY },
        { (char*)"setAxisStyleZ", (char*)"(Lhep/aida/IAxisStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setAxisStyleZ },
        { (char*)"setTitleStyle", (char*)"(Lhep/aida/ITitleStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setTitleStyle },
        { (char*)"setInfoStyle", (char*)"(Lhep/aida/IInfoStyle;)Z", (void*)Java_hep_aida_jni_CIPlotterStyle_setInfoStyle },
    };
    LOADCLASS(classCIPlotterStyle,  "hep/aida/jni/CIPlotterStyle", ctorCIPlotterStyle,     
              crefCIPlotterStyle, methodsCIPlotterStyle, 1+6+12);

    JNINativeMethod methodsCIProfile1D[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"allEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIProfile_allEntries },
        { (char*)"extraEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIProfile_extraEntries },
        { (char*)"sumBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumBinHeights },
        { (char*)"sumAllBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumAllBinHeights },
        { (char*)"sumExtraBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumExtraBinHeights },
        { (char*)"minBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_minBinHeight },
        { (char*)"maxBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_maxBinHeight },

        { (char*)"fill", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIProfile1D_fill__DD },
        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CIProfile1D_fill__DDD },
        { (char*)"binMean", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile1D_binMean },
        { (char*)"binEntries", (char*)"(I)I", (void*)Java_hep_aida_jni_CIProfile1D_binEntries },
        { (char*)"binHeight", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile1D_binHeight },
        { (char*)"binError", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile1D_binError },
        { (char*)"binRms", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile1D_binRms },
        { (char*)"mean", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile1D_mean },
        { (char*)"rms", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile1D_rms },
        { (char*)"axis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIProfile1D_axis },
        { (char*)"coordToIndex", (char*)"(D)I", (void*)Java_hep_aida_jni_CIProfile1D_coordToIndex },
        { (char*)"add", (char*)"(Lhep/aida/IProfile1D;)V", (void*)Java_hep_aida_jni_CIProfile1D_add },
    };
    LOADCLASS(classCIProfile1D, "hep/aida/jni/CIProfile1D", ctorCIProfile1D,        
              crefCIProfile1D, methodsCIProfile1D, 1+6+7+12);

    JNINativeMethod methodsCIProfile2D[] = {
        { (char*)"finalize",   (char*)"(J)V",                                     (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseHistogram_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CIBaseHistogram_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CIBaseHistogram_annotation },
        { (char*)"dimension", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_dimension },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseHistogram_reset },
        { (char*)"entries", (char*)"()I", (void*)Java_hep_aida_jni_CIBaseHistogram_entries },

        { (char*)"allEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIProfile_allEntries },
        { (char*)"extraEntries", (char*)"()I", (void*)Java_hep_aida_jni_CIProfile_extraEntries },
        { (char*)"sumBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumBinHeights },
        { (char*)"sumAllBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumAllBinHeights },
        { (char*)"sumExtraBinHeights", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_sumExtraBinHeights },
        { (char*)"minBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_minBinHeight },
        { (char*)"maxBinHeight", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile_maxBinHeight },

        { (char*)"fill", (char*)"(DDD)V", (void*)Java_hep_aida_jni_CIProfile2D_fill__DDD },
        { (char*)"fill", (char*)"(DDDD)V", (void*)Java_hep_aida_jni_CIProfile2D_fill__DDDD },
        { (char*)"binMeanX", (char*)"(II)D", (void*)Java_hep_aida_jni_CIProfile2D_binMeanX },
        { (char*)"binMeanY", (char*)"(II)D", (void*)Java_hep_aida_jni_CIProfile2D_binMeanY },
        { (char*)"binEntries", (char*)"(II)I", (void*)Java_hep_aida_jni_CIProfile2D_binEntries },
        { (char*)"binEntriesX", (char*)"(I)I", (void*)Java_hep_aida_jni_CIProfile2D_binEntriesX },
        { (char*)"binEntriesY", (char*)"(I)I", (void*)Java_hep_aida_jni_CIProfile2D_binEntriesY },
        { (char*)"binHeight", (char*)"(II)D", (void*)Java_hep_aida_jni_CIProfile2D_binHeight },
        { (char*)"binHeightX", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile2D_binHeightX },
        { (char*)"binHeightY", (char*)"(I)D", (void*)Java_hep_aida_jni_CIProfile2D_binHeightY },
        { (char*)"binError", (char*)"(II)D", (void*)Java_hep_aida_jni_CIProfile2D_binError },
        { (char*)"binRms", (char*)"(II)D", (void*)Java_hep_aida_jni_CIProfile2D_binRms },
        { (char*)"meanX", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile2D_meanX },
        { (char*)"meanY", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile2D_meanY },
        { (char*)"rmsX", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile2D_rmsX },
        { (char*)"rmsY", (char*)"()D", (void*)Java_hep_aida_jni_CIProfile2D_rmsY },
        { (char*)"xAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIProfile2D_xAxis },
        { (char*)"yAxis", (char*)"()Lhep/aida/IAxis;", (void*)Java_hep_aida_jni_CIProfile2D_yAxis },
        { (char*)"coordToIndexX", (char*)"(D)I", (void*)Java_hep_aida_jni_CIProfile2D_coordToIndexX },
        { (char*)"coordToIndexY", (char*)"(D)I", (void*)Java_hep_aida_jni_CIProfile2D_coordToIndexY },
        { (char*)"add", (char*)"(Lhep/aida/IProfile2D;)V", (void*)Java_hep_aida_jni_CIProfile2D_add },
    };
    LOADCLASS(classCIProfile2D, "hep/aida/jni/CIProfile2D", ctorCIProfile2D,
              crefCIProfile2D, methodsCIProfile2D, 1+6+7+21);

    JNINativeMethod methodsCIRangeSet[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"lowerBounds", (char*)"()[D", (void*)Java_hep_aida_jni_CIRangeSet_lowerBounds },
        { (char*)"upperBounds", (char*)"()[D", (void*)Java_hep_aida_jni_CIRangeSet_upperBounds },
        { (char*)"include", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIRangeSet_include },
        { (char*)"exclude", (char*)"(DD)V", (void*)Java_hep_aida_jni_CIRangeSet_exclude },
        { (char*)"includeAll", (char*)"()V", (void*)Java_hep_aida_jni_CIRangeSet_includeAll },
        { (char*)"excludeAll", (char*)"()V", (void*)Java_hep_aida_jni_CIRangeSet_excludeAll },
        { (char*)"isInRange", (char*)"(D)Z", (void*)Java_hep_aida_jni_CIRangeSet_isInRange },
        { (char*)"size", (char*)"()I", (void*)Java_hep_aida_jni_CIRangeSet_size },
        { (char*)"PLUS_INF", (char*)"()D", (void*)Java_hep_aida_jni_CIRangeSet_PLUS_1INF },
        { (char*)"MINUS_INF", (char*)"()D", (void*)Java_hep_aida_jni_CIRangeSet_MINUS_1INF },
    };
    LOADCLASS(classCIRangeSet, "hep/aida/jni/CIRangeSet", ctorCIRangeSet,
              crefCIRangeSet, methodsCIRangeSet, 1+10);

    JNINativeMethod methodsCITextStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"availableColors", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_availableColors },
        { (char*)"color", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBrushStyle_color },
        { (char*)"opacity", (char*)"()D", (void*)Java_hep_aida_jni_CIBrushStyle_opacity },
        { (char*)"setColor", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setColor },
        { (char*)"setOpacity", (char*)"(D)Z", (void*)Java_hep_aida_jni_CIBrushStyle_setOpacity },

        { (char*)"availableFonts", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITextStyle_availableFonts },
        { (char*)"fontSize", (char*)"()D", (void*)Java_hep_aida_jni_CITextStyle_fontSize },
        { (char*)"setFontSize", (char*)"(D)Z", (void*)Java_hep_aida_jni_CITextStyle_setFontSize },
        { (char*)"font", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CITextStyle_font },
        { (char*)"setFont", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CITextStyle_setFont },
        { (char*)"isBold", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_isBold },
        { (char*)"isItalic", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_isItalic },
        { (char*)"isUnderlined", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_isUnderlined },
        { (char*)"setBold", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_setBold__ },
        { (char*)"setBold", (char*)"(Z)Z", (void*)Java_hep_aida_jni_CITextStyle_setBold__Z },
        { (char*)"setItalic", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_setItalic__ },
        { (char*)"setItalic", (char*)"(Z)Z", (void*)Java_hep_aida_jni_CITextStyle_setItalic__Z },
        { (char*)"setUnderlined", (char*)"()Z", (void*)Java_hep_aida_jni_CITextStyle_setUnderlined__ },
        { (char*)"setUnderlined", (char*)"(Z)Z", (void*)Java_hep_aida_jni_CITextStyle_setUnderlined__Z },
    };
    LOADCLASS(classCITextStyle, "hep/aida/jni/CITextStyle", ctorCITextStyle,        
              crefCITextStyle, methodsCITextStyle, 1+6+5+14);

    JNINativeMethod methodsCITitleStyle[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CIBaseStyle_reset },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2 },
        { (char*)"setParameter", (char*)"(Ljava/lang/String;Ljava/lang/String;)Z", (void*)Java_hep_aida_jni_CIBaseStyle_setParameter__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"parameterValue", (char*)"(Ljava/lang/String;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_parameterValue },
        { (char*)"availableParameters", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameters },
        { (char*)"availableParameterOptions", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CIBaseStyle_availableParameterOptions },

        { (char*)"textStyle", (char*)"()Lhep/aida/ITextStyle;", (void*)Java_hep_aida_jni_CITitleStyle_textStyle },
        { (char*)"setTextStyle", (char*)"(Lhep/aida/ITextStyle;)Z", (void*)Java_hep_aida_jni_CITitleStyle_setTextStyle },
    };
    LOADCLASS(classCITitleStyle, "hep/aida/jni/CITitleStyle", ctorCITitleStyle,       
              crefCITitleStyle, methodsCITitleStyle, 1+6+2);

    JNINativeMethod methodsCITree[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"storeName", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_storeName },
        { (char*)"find", (char*)"(Ljava/lang/String;)Lhep/aida/IManagedObject;", (void*)Java_hep_aida_jni_CITree_find },
        { (char*)"findTree", (char*)"(Ljava/lang/String;)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITree_findTree },
        { (char*)"cd", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_cd },
        { (char*)"pwd", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_pwd },
        { (char*)"ls", (char*)"()V", (void*)Java_hep_aida_jni_CITree_ls__ },
        { (char*)"ls", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2 },
        { (char*)"ls", (char*)"(Ljava/lang/String;Z)V", (void*)Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2Z },
        { (char*)"ls", (char*)"(Ljava/lang/String;ZLjava/io/OutputStream;)V", (void*)Java_hep_aida_jni_CITree_ls__Ljava_lang_String_2ZLjava_io_OutputStream_2 },
        { (char*)"listObjectNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectNames__ },
        { (char*)"listObjectNames", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectNames__Ljava_lang_String_2 },
        { (char*)"listObjectNames", (char*)"(Ljava/lang/String;Z)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectNames__Ljava_lang_String_2Z },
        { (char*)"listObjectTypes", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectTypes__ },
        { (char*)"listObjectTypes", (char*)"(Ljava/lang/String;)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectTypes__Ljava_lang_String_2 },
        { (char*)"listObjectTypes", (char*)"(Ljava/lang/String;Z)[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_listObjectTypes__Ljava_lang_String_2Z },
        { (char*)"mkdir", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_mkdir },
        { (char*)"mkdirs", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_mkdirs },
        { (char*)"rmdir", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_rmdir },
        { (char*)"rm", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_rm },
        { (char*)"findPath", (char*)"(Lhep/aida/IManagedObject;)Ljava/lang/String;", (void*)Java_hep_aida_jni_CITree_findPath },
        { (char*)"mv", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_mv },
        { (char*)"commit", (char*)"()V", (void*)Java_hep_aida_jni_CITree_commit },
        { (char*)"setOverwrite", (char*)"()V", (void*)Java_hep_aida_jni_CITree_setOverwrite__ },
        { (char*)"setOverwrite", (char*)"(Z)V", (void*)Java_hep_aida_jni_CITree_setOverwrite__Z },
        { (char*)"cp", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_cp__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"cp", (char*)"(Ljava/lang/String;Ljava/lang/String;Z)V", (void*)Java_hep_aida_jni_CITree_cp__Ljava_lang_String_2Ljava_lang_String_2Z },
        { (char*)"symlink", (char*)"(Ljava/lang/String;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_symlink },
        { (char*)"mount", (char*)"(Ljava/lang/String;Lhep/aida/ITree;Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_mount },
        { (char*)"unmount", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITree_unmount },
        { (char*)"close", (char*)"()V", (void*)Java_hep_aida_jni_CITree_close },
//        { (char*)"isReadOnly", (char*)"()Z", (void*)Java_hep_aida_jni_CITree_isReadOnly },
    };
    LOADCLASS(classCITree, "hep/aida/jni/CITree", ctorCITree,             
              crefCITree, methodsCITree, 1+30);

    JNINativeMethod methodsCITreeFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"create", (char*)"()Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__ },
        { (char*)"create", (char*)"(Ljava/lang/String;)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;Z)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2Z },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;ZZ)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2ZZ },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;ZZLjava/lang/String;)Lhep/aida/ITree;", (void*)Java_hep_aida_jni_CITreeFactory_create__Ljava_lang_String_2Ljava_lang_String_2ZZLjava_lang_String_2 },
    };
    LOADCLASS(classCITreeFactory, "hep/aida/jni/CITreeFactory", ctorCITreeFactory,             
              crefCITreeFactory, methodsCITreeFactory, 1+6);

    JNINativeMethod methodsCITuple[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"title", (char*)"()Ljava/lang/String;", (void*)Java_hep_aida_jni_CITuple_title },
        { (char*)"setTitle", (char*)"(Ljava/lang/String;)V", (void*)Java_hep_aida_jni_CITuple_setTitle },
        { (char*)"annotation", (char*)"()Lhep/aida/IAnnotation;", (void*)Java_hep_aida_jni_CITuple_annotation },
        { (char*)"fill", (char*)"(ID)V", (void*)Java_hep_aida_jni_CITuple_fill__ID },
        { (char*)"fill", (char*)"(IF)V", (void*)Java_hep_aida_jni_CITuple_fill__IF },
        { (char*)"fill", (char*)"(II)V", (void*)Java_hep_aida_jni_CITuple_fill__II },
        { (char*)"fill", (char*)"(IS)V", (void*)Java_hep_aida_jni_CITuple_fill__IS },
        { (char*)"fill", (char*)"(IJ)V", (void*)Java_hep_aida_jni_CITuple_fill__IJ },
        { (char*)"fill", (char*)"(IC)V", (void*)Java_hep_aida_jni_CITuple_fill__IC },
        { (char*)"fill", (char*)"(IB)V", (void*)Java_hep_aida_jni_CITuple_fill__IB },
        { (char*)"fill", (char*)"(IZ)V", (void*)Java_hep_aida_jni_CITuple_fill__IZ },
        { (char*)"fill", (char*)"(ILjava/lang/String;)V", (void*)Java_hep_aida_jni_CITuple_fill__ILjava_lang_String_2 },
        { (char*)"fill", (char*)"(ILjava/lang/Object;)V", (void*)Java_hep_aida_jni_CITuple_fill__ILjava_lang_Object_2 },
        { (char*)"fill", (char*)"([D)V", (void*)Java_hep_aida_jni_CITuple_fill___3D },
        { (char*)"fill", (char*)"([F)V", (void*)Java_hep_aida_jni_CITuple_fill___3F },
        { (char*)"addRow", (char*)"()V", (void*)Java_hep_aida_jni_CITuple_addRow },
        { (char*)"resetRow", (char*)"()V", (void*)Java_hep_aida_jni_CITuple_resetRow },
        { (char*)"reset", (char*)"()V", (void*)Java_hep_aida_jni_CITuple_reset },
        { (char*)"rows", (char*)"()I", (void*)Java_hep_aida_jni_CITuple_rows },
        { (char*)"start", (char*)"()V", (void*)Java_hep_aida_jni_CITuple_start },
        { (char*)"skip", (char*)"(I)V", (void*)Java_hep_aida_jni_CITuple_skip },
        { (char*)"next", (char*)"()Z", (void*)Java_hep_aida_jni_CITuple_next },
        { (char*)"setRow", (char*)"(I)V", (void*)Java_hep_aida_jni_CITuple_setRow },
        { (char*)"findColumn", (char*)"(Ljava/lang/String;)I", (void*)Java_hep_aida_jni_CITuple_findColumn },
        { (char*)"getDouble", (char*)"(I)D", (void*)Java_hep_aida_jni_CITuple_getDouble },
        { (char*)"getFloat", (char*)"(I)F", (void*)Java_hep_aida_jni_CITuple_getFloat },
        { (char*)"getInt", (char*)"(I)I", (void*)Java_hep_aida_jni_CITuple_getInt },
        { (char*)"getShort", (char*)"(I)S", (void*)Java_hep_aida_jni_CITuple_getShort },
        { (char*)"getLong", (char*)"(I)J", (void*)Java_hep_aida_jni_CITuple_getLong },
        { (char*)"getChar", (char*)"(I)C", (void*)Java_hep_aida_jni_CITuple_getChar },
        { (char*)"getByte", (char*)"(I)B", (void*)Java_hep_aida_jni_CITuple_getByte },
        { (char*)"getBoolean", (char*)"(I)Z", (void*)Java_hep_aida_jni_CITuple_getBoolean },
        { (char*)"getString", (char*)"(I)Ljava/lang/String;", (void*)Java_hep_aida_jni_CITuple_getString },
        { (char*)"getObject", (char*)"(I)Ljava/lang/Object;", (void*)Java_hep_aida_jni_CITuple_getObject },
        { (char*)"getTuple", (char*)"(I)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITuple_getTuple },
        { (char*)"columns", (char*)"()I", (void*)Java_hep_aida_jni_CITuple_columns },
        { (char*)"columnName", (char*)"(I)Ljava/lang/String;", (void*)Java_hep_aida_jni_CITuple_columnName },
        { (char*)"columnNames", (char*)"()[Ljava/lang/String;", (void*)Java_hep_aida_jni_CITuple_columnNames },
        { (char*)"columnType", (char*)"(I)Ljava/lang/Class;", (void*)Java_hep_aida_jni_CITuple_columnType },
        { (char*)"columnTypes", (char*)"()[Ljava/lang/Class;", (void*)Java_hep_aida_jni_CITuple_columnTypes },
        { (char*)"columnMin", (char*)"(I)D", (void*)Java_hep_aida_jni_CITuple_columnMin },
        { (char*)"columnMax", (char*)"(I)D", (void*)Java_hep_aida_jni_CITuple_columnMax },
        { (char*)"columnMean", (char*)"(I)D", (void*)Java_hep_aida_jni_CITuple_columnMean },
        { (char*)"columnRms", (char*)"(I)D", (void*)Java_hep_aida_jni_CITuple_columnRms },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IHistogram3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IHistogram3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud1D;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud1D_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/ICloud3D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_ICloud3D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile1D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile1D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2 },
        { (char*)"project", (char*)"(Lhep/aida/IProfile2D;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IEvaluator;Lhep/aida/IFilter;Lhep/aida/IEvaluator;)V", (void*)Java_hep_aida_jni_CITuple_project__Lhep_aida_IProfile2D_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IEvaluator_2Lhep_aida_IFilter_2Lhep_aida_IEvaluator_2 },
    };
    LOADCLASS(classCITuple, "hep/aida/jni/CITuple", ctorCITuple,
              crefCITuple, methodsCITuple, 1+76);

    JNINativeMethod methodsCITupleFactory[] = {
        { (char*)"finalize", (char*)"(J)V", (void*)Java_hep_aida_jni_CProxy_finalize },

        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2_3Ljava_lang_Class_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Class;Ljava/lang/String;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2_3Ljava_lang_Class_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"create", (char*)"(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_create__Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2Ljava_lang_String_2 },
        { (char*)"createChained", (char*)"(Ljava/lang/String;Ljava/lang/String;[Lhep/aida/ITuple;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_createChained__Ljava_lang_String_2Ljava_lang_String_2_3Lhep_aida_ITuple_2 },
        { (char*)"createChained", (char*)"(Ljava/lang/String;Ljava/lang/String;[Ljava/lang/String;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_createChained__Ljava_lang_String_2Ljava_lang_String_2_3Ljava_lang_String_2 },
        { (char*)"createFiltered", (char*)"(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_createFiltered__Ljava_lang_String_2Lhep_aida_ITuple_2Lhep_aida_IFilter_2 },
        { (char*)"createFiltered", (char*)"(Ljava/lang/String;Lhep/aida/ITuple;Lhep/aida/IFilter;[Ljava/lang/String;)Lhep/aida/ITuple;", (void*)Java_hep_aida_jni_CITupleFactory_createFiltered__Ljava_lang_String_2Lhep_aida_ITuple_2Lhep_aida_IFilter_2_3Ljava_lang_String_2 },
        { (char*)"createFilter", (char*)"(Ljava/lang/String;)Lhep/aida/IFilter;", (void*)Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2 },
        { (char*)"createFilter", (char*)"(Ljava/lang/String;I)Lhep/aida/IFilter;", (void*)Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2I },
        { (char*)"createFilter", (char*)"(Ljava/lang/String;II)Lhep/aida/IFilter;", (void*)Java_hep_aida_jni_CITupleFactory_createFilter__Ljava_lang_String_2II },
        { (char*)"createEvaluator", (char*)"(Ljava/lang/String;)Lhep/aida/IEvaluator;", (void*)Java_hep_aida_jni_CITupleFactory_createEvaluator },
    };
    LOADCLASS(classCITupleFactory, "hep/aida/jni/CITupleFactory", ctorCITupleFactory,
              crefCITupleFactory, methodsCITupleFactory, 1+12);
}

JNIEXPORT ProxyFactory::~ProxyFactory() {
}

JNIEXPORT IAnnotation* ProxyFactory::createIAnnotation(JNIEnv *env, jobject object) const {
    RETURNCREF(IAnnotation, classCIAnnotation, crefCIAnnotation, object);
    return new JIAnnotation(env, object, *this);
}   

JNIEXPORT IAxis* ProxyFactory::createIAxis(JNIEnv *env, jobject object) const {
    RETURNCREF(IAxis, classCIAxis, crefCIAxis, object);
    return new JIAxis(env, object, *this);
}
    
JNIEXPORT IAxisStyle* ProxyFactory::createIAxisStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IAxisStyle, classCIAxisStyle, crefCIAxisStyle, object);
    return new JIAxisStyle(env, object, *this);
}   

JNIEXPORT IBaseHistogram* ProxyFactory::createIBaseHistogram(JNIEnv *env, jobject object) const {
    RETURNCREF(IBaseHistogram, classCIBaseHistogram, crefCIBaseHistogram, object);

    if (cloud1Dclass == NULL) {
    // load also managed objects
        FINDCLASS(cloud1Dclass,      "hep/aida/ICloud1D");
        FINDCLASS(cloud2Dclass,      "hep/aida/ICloud2D");
        FINDCLASS(cloud3Dclass,      "hep/aida/ICloud3D");
        FINDCLASS(dataPointSetClass, "hep/aida/IDataPointSet");
        FINDCLASS(functionClass,     "hep/aida/IFunction");
        FINDCLASS(modelFunctionClass,"hep/aida/IModelFunction");
        FINDCLASS(histogram1Dclass,  "hep/aida/IHistogram1D");
        FINDCLASS(histogram2Dclass,  "hep/aida/IHistogram2D");
        FINDCLASS(histogram3Dclass,  "hep/aida/IHistogram3D");
        FINDCLASS(profile1Dclass,    "hep/aida/IProfile1D");
        FINDCLASS(profile2Dclass,    "hep/aida/IProfile2D");    
        FINDCLASS(tupleClass,        "hep/aida/ITuple");
    }

    if (env->IsInstanceOf(object, histogram1Dclass) == JNI_TRUE) {
        return new JIHistogram1D(env, object, *this);
    } else if (env->IsInstanceOf(object, histogram2Dclass) == JNI_TRUE) {
        return new JIHistogram2D(env, object, *this);
    } else if (env->IsInstanceOf(object, histogram3Dclass) == JNI_TRUE) {
        return new JIHistogram3D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud1Dclass) == JNI_TRUE) {
        return new JICloud1D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud2Dclass) == JNI_TRUE) {
        return new JICloud2D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud3Dclass) == JNI_TRUE) {
        return new JICloud3D(env, object, *this);
    } else if (env->IsInstanceOf(object, profile1Dclass) == JNI_TRUE) {
        return new JIProfile1D(env, object, *this);
    } else if (env->IsInstanceOf(object, profile2Dclass) == JNI_TRUE) {
        return new JIProfile2D(env, object, *this);
    } else {
        cerr << "ProxyFactory found IBaseHistogram of unassociated class." << endl;
        return NULL;
    }
}

JNIEXPORT ICloud1D* ProxyFactory::createICloud1D(JNIEnv *env, jobject object) const {
    RETURNCREF(ICloud1D, classCICloud1D, crefCICloud1D, object);
    return new JICloud1D(env, object, *this);
}   

JNIEXPORT ICloud2D* ProxyFactory::createICloud2D(JNIEnv *env, jobject object) const {
    RETURNCREF(ICloud2D, classCICloud2D, crefCICloud2D, object);
    return new JICloud2D(env, object, *this);
}   

JNIEXPORT ICloud3D* ProxyFactory::createICloud3D(JNIEnv *env, jobject object) const {
    RETURNCREF(ICloud3D, classCICloud3D, crefCICloud3D, object);
    return new JICloud3D(env, object, *this);
}   

JNIEXPORT IDataPoint* ProxyFactory::createIDataPoint(JNIEnv *env, jobject object) const {
    RETURNCREF(IDataPoint, classCIDataPoint, crefCIDataPoint, object);
    return new JIDataPoint(env, object, *this);
}   

JNIEXPORT IDataPointSet* ProxyFactory::createIDataPointSet(JNIEnv *env, jobject object) const {
    RETURNCREF(IDataPointSet, classCIDataPointSet, crefCIDataPointSet, object);
    return new JIDataPointSet(env, object, *this);
}   

JNIEXPORT IDataPointSetFactory* ProxyFactory::createIDataPointSetFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(IDataPointSetFactory, classCIDataPointSetFactory, crefCIDataPointSetFactory, object);
    return new JIDataPointSetFactory(env, object, *this);
}   

JNIEXPORT IDataStyle* ProxyFactory::createIDataStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IDataStyle, classCIDataStyle, crefCIDataStyle, object);
    return new JIDataStyle(env, object, *this);
}   

JNIEXPORT IEvaluator* ProxyFactory::createIEvaluator(JNIEnv *env, jobject object) const {
    RETURNCREF(IEvaluator, classCIEvaluator, crefCIEvaluator, object);
    return new JIEvaluator(env, object, *this);
}   

JNIEXPORT IFillStyle* ProxyFactory::createIFillStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IFillStyle, classCIFillStyle, crefCIFillStyle, object);
    return new JIFillStyle(env, object, *this);
}   

JNIEXPORT IFilter* ProxyFactory::createIFilter(JNIEnv *env, jobject object) const {
    RETURNCREF(IFilter, classCIFilter, crefCIFilter, object);
    return new JIFilter(env, object, *this);
}   

JNIEXPORT IFitFactory* ProxyFactory::createIFitFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(IFitFactory, classCIFitFactory, crefCIFitFactory, object);
    return new JIFitFactory(env, object, *this);
}   

JNIEXPORT IFitData* ProxyFactory::createIFitData(JNIEnv *env, jobject object) const {
    RETURNCREF(IFitData, classCIFitData, crefCIFitData, object);
    return new JIFitData(env, object, *this);
}   

JNIEXPORT IFitParameterSettings* ProxyFactory::createIFitParameterSettings(JNIEnv *env, jobject object) const {
    RETURNCREF(IFitParameterSettings, classCIFitParameterSettings, crefCIFitParameterSettings, object);
    return new JIFitParameterSettings(env, object, *this);
}   

JNIEXPORT IFitResult* ProxyFactory::createIFitResult(JNIEnv *env, jobject object) const {
    RETURNCREF(IFitResult, classCIFitResult, crefCIFitResult, object);
    return new JIFitResult(env, object, *this);
}   

JNIEXPORT IFitter* ProxyFactory::createIFitter(JNIEnv *env, jobject object) const {
    RETURNCREF(IFitter, classCIFitter, crefCIFitter, object);
    return new JIFitter(env, object, *this);
}   

JNIEXPORT IFunction* ProxyFactory::createIFunction(JNIEnv *env, jobject object) const {
    RETURNCREF(IFunction, classCIFunction, crefCIFunction, object);
    FINDCLASS(modelFunctionClass, "hep/aida/IModelFunction");
    if (env->IsInstanceOf(object, modelFunctionClass)) {
        return createIModelFunction(env, object);
    }    
    return new JIFunction(env, object, *this);
}   

JNIEXPORT IFunctionCatalog* ProxyFactory::createIFunctionCatalog(JNIEnv *env, jobject object) const {
    RETURNCREF(IFunctionCatalog, classCIFunctionCatalog, crefCIFunctionCatalog, object);
    return new JIFunctionCatalog(env, object, *this);
}   

JNIEXPORT IFunctionFactory* ProxyFactory::createIFunctionFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(IFunctionFactory, classCIFunctionFactory, crefCIFunctionFactory, object);
    return new JIFunctionFactory(env, object, *this);
}   

JNIEXPORT IHistogramFactory* ProxyFactory::createIHistogramFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(IHistogramFactory, classCIHistogramFactory, crefCIHistogramFactory, object);
    return new JIHistogramFactory(env, object, *this);
}   

JNIEXPORT IHistogram1D* ProxyFactory::createIHistogram1D(JNIEnv *env, jobject object) const {
    RETURNCREF(IHistogram1D, classCIHistogram1D, crefCIHistogram1D, object);
    return new JIHistogram1D(env, object, *this);
}   

JNIEXPORT IHistogram2D* ProxyFactory::createIHistogram2D(JNIEnv *env, jobject object) const {
    RETURNCREF(IHistogram2D, classCIHistogram2D, crefCIHistogram2D, object);
    return new JIHistogram2D(env, object, *this);
}   

JNIEXPORT IHistogram3D* ProxyFactory::createIHistogram3D(JNIEnv *env, jobject object) const {
    RETURNCREF(IHistogram3D, classCIHistogram3D, crefCIHistogram3D, object);
    return new JIHistogram3D(env, object, *this);
}   

JNIEXPORT IInfo* ProxyFactory::createIInfo(JNIEnv *env, jobject object) const {
    RETURNCREF(IInfo, classCIInfo, crefCIInfo, object);
    return new JIInfo(env, object, *this);
}   

JNIEXPORT IInfoStyle* ProxyFactory::createIInfoStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IInfoStyle, classCIInfoStyle, crefCIInfoStyle, object);
    return new JIInfoStyle(env, object, *this);
}   

JNIEXPORT ILineStyle* ProxyFactory::createILineStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(ILineStyle, classCILineStyle, crefCILineStyle, object);
    return new JILineStyle(env, object, *this);
}   

JNIEXPORT IManagedObject* ProxyFactory::createIManagedObject(JNIEnv *env, jobject object) const {
    RETURNCREF(IManagedObject, classCIManagedObject, crefCIManagedObject, object);

    if (cloud1Dclass == NULL) {
        FINDCLASS(cloud1Dclass,      "hep/aida/ICloud1D");
        FINDCLASS(cloud2Dclass,      "hep/aida/ICloud2D");
        FINDCLASS(cloud3Dclass,      "hep/aida/ICloud3D");
        FINDCLASS(dataPointSetClass, "hep/aida/IDataPointSet");
        FINDCLASS(functionClass,     "hep/aida/IFunction");
        FINDCLASS(modelFunctionClass,"hep/aida/IModelFunction");
        FINDCLASS(histogram1Dclass,  "hep/aida/IHistogram1D");
        FINDCLASS(histogram2Dclass,  "hep/aida/IHistogram2D");
        FINDCLASS(histogram3Dclass,  "hep/aida/IHistogram3D");
        FINDCLASS(profile1Dclass,    "hep/aida/IProfile1D");
        FINDCLASS(profile2Dclass,    "hep/aida/IProfile2D");    
        FINDCLASS(tupleClass,        "hep/aida/ITuple");
    }

    if (env->IsInstanceOf(object, histogram1Dclass) == JNI_TRUE) {
        return new JIHistogram1D(env, object, *this);
    } else if (env->IsInstanceOf(object, histogram2Dclass) == JNI_TRUE) {
        return new JIHistogram2D(env, object, *this);
    } else if (env->IsInstanceOf(object, histogram3Dclass) == JNI_TRUE) {
        return new JIHistogram3D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud1Dclass) == JNI_TRUE) {
        return new JICloud1D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud2Dclass) == JNI_TRUE) {
        return new JICloud2D(env, object, *this);
    } else if (env->IsInstanceOf(object, cloud3Dclass) == JNI_TRUE) {
        return new JICloud3D(env, object, *this);
    } else if (env->IsInstanceOf(object, profile1Dclass) == JNI_TRUE) {
        return new JIProfile1D(env, object, *this);
    } else if (env->IsInstanceOf(object, profile2Dclass) == JNI_TRUE) {
        return new JIProfile2D(env, object, *this);
    } else if (env->IsInstanceOf(object, tupleClass) == JNI_TRUE) {
        return new JITuple(env, object, *this);
    } else if (env->IsInstanceOf(object, dataPointSetClass) == JNI_TRUE) {
        return new JIDataPointSet(env, object, *this);
    } else if (env->IsInstanceOf(object, modelFunctionClass) == JNI_TRUE) {
        return new JIModelFunction(env, object, *this);
    } else if (env->IsInstanceOf(object, functionClass) == JNI_TRUE) {
        return new JIFunction(env, object, *this);
    } else {
        cerr << "ProxyFactory found IManagedObject of unassociated class." << endl;
        return NULL;
    }
}

JNIEXPORT IMarkerStyle* ProxyFactory::createIMarkerStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IMarkerStyle, classCIMarkerStyle, crefCIMarkerStyle, object);
    return new JIMarkerStyle(env, object, *this);
}   

JNIEXPORT IMeasurement* ProxyFactory::createIMeasurement(JNIEnv *env, jobject object) const {
    RETURNCREF(IMeasurement, classCIMeasurement, crefCIMeasurement, object);
    return new JIMeasurement(env, object, *this);
}   

JNIEXPORT IModelFunction* ProxyFactory::createIModelFunction(JNIEnv *env, jobject object) const {
    RETURNCREF(IModelFunction, classCIModelFunction, crefCIModelFunction, object);
    return new JIModelFunction(env, object, *this);
}   

JNIEXPORT IPlotter* ProxyFactory::createIPlotter(JNIEnv *env, jobject object) const {
    RETURNCREF(IPlotter, classCIPlotter, crefCIPlotter, object);
    return new JIPlotter(env, object, *this);
}   

JNIEXPORT IPlotterFactory* ProxyFactory::createIPlotterFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(IPlotterFactory, classCIPlotterFactory, crefCIPlotterFactory, object);
    return new JIPlotterFactory(env, object, *this);
}   

JNIEXPORT IPlotterLayout* ProxyFactory::createIPlotterLayout(JNIEnv *env, jobject object) const {
    RETURNCREF(IPlotterLayout, classCIPlotterLayout, crefCIPlotterLayout, object);
    return new JIPlotterLayout(env, object, *this);
}   

JNIEXPORT IPlotterRegion* ProxyFactory::createIPlotterRegion(JNIEnv *env, jobject object) const {
    RETURNCREF(IPlotterRegion, classCIPlotterRegion, crefCIPlotterRegion, object);
    return new JIPlotterRegion(env, object, *this);
}   

JNIEXPORT IPlotterStyle* ProxyFactory::createIPlotterStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(IPlotterStyle, classCIPlotterStyle, crefCIPlotterStyle, object);
    return new JIPlotterStyle(env, object, *this);
}   

JNIEXPORT IProfile1D* ProxyFactory::createIProfile1D(JNIEnv *env, jobject object) const {
    RETURNCREF(IProfile1D, classCIProfile1D, crefCIProfile1D, object);
    return new JIProfile1D(env, object, *this);
}   

JNIEXPORT IProfile2D* ProxyFactory::createIProfile2D(JNIEnv *env, jobject object) const {
    RETURNCREF(IProfile2D, classCIProfile2D, crefCIProfile2D, object);
    return new JIProfile2D(env, object, *this);
}   

JNIEXPORT IRangeSet* ProxyFactory::createIRangeSet(JNIEnv *env, jobject object) const {
    RETURNCREF(IRangeSet, classCIRangeSet, crefCIRangeSet, object);
    return new JIRangeSet(env, object, *this);
}   

JNIEXPORT ITextStyle* ProxyFactory::createITextStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(ITextStyle, classCITextStyle, crefCITextStyle, object);
    return new JITextStyle(env, object, *this);
}   

JNIEXPORT ITitleStyle* ProxyFactory::createITitleStyle(JNIEnv *env, jobject object) const {
    RETURNCREF(ITitleStyle, classCITitleStyle, crefCITitleStyle, object);
    return new JITitleStyle(env, object, *this);
}   

JNIEXPORT ITree* ProxyFactory::createITree(JNIEnv *env, jobject object) const {
    RETURNCREF(ITree, classCITree, crefCITree, object);
    return new JITree(env, object, *this);
}   

JNIEXPORT ITreeFactory* ProxyFactory::createITreeFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(ITreeFactory, classCITreeFactory, crefCITreeFactory, object);
    return new JITreeFactory(env, object, *this);
}   

JNIEXPORT ITuple* ProxyFactory::createITuple(JNIEnv *env, jobject object) const {
    RETURNCREF(ITuple, classCITuple, crefCITuple, object);
    return new JITuple(env, object, *this);
}   

JNIEXPORT ITupleFactory* ProxyFactory::createITupleFactory(JNIEnv *env, jobject object) const {
    RETURNCREF(ITupleFactory, classCITupleFactory, crefCITupleFactory, object);
    return new JITupleFactory(env, object, *this);
}   






JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IAnnotation & obj) const {
    RETURNJREF(JIAnnotation, obj);
    RETURNCI(classCIAnnotation, ctorCIAnnotation, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IAxis & obj) const {
    RETURNJREF(JIAxis, obj);
    RETURNCI(classCIAxis, ctorCIAxis, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IAxisStyle & obj) const {
    RETURNJREF(JIAxisStyle, obj);
    RETURNCI(classCIAxisStyle, ctorCIAxisStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IBaseHistogram & obj) const {
    RETURNJREF(JIBaseHistogram, obj);
    RETURNCREATE(IHistogram, obj);
    RETURNCREATE(ICloud, obj);
    RETURNCREATE(IProfile, obj);
    return NULL;
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ICloud & obj) const {
    RETURNJREF(JICloud, obj);
    RETURNCREATE(ICloud1D, obj);
    RETURNCREATE(ICloud2D, obj);
    RETURNCREATE(ICloud3D, obj);
    return NULL;
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ICloud1D & obj) const {
    RETURNJREF(JICloud1D, obj);
    RETURNCI(classCICloud1D, ctorCICloud1D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ICloud2D & obj) const {
    RETURNJREF(JICloud2D, obj);
    RETURNCI(classCICloud2D, ctorCICloud2D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ICloud3D & obj) const {
    RETURNJREF(JICloud3D, obj);
    RETURNCI(classCICloud3D, ctorCICloud3D, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IDataPoint & obj) const {
    RETURNJREF(JIDataPoint, obj);
    RETURNCI(classCIDataPoint, ctorCIDataPoint, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IDataPointSet & obj) const {
    RETURNJREF(JIDataPointSet, obj);
    RETURNCI(classCIDataPointSet, ctorCIDataPointSet, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IDataPointSetFactory & obj) const {
    RETURNJREF(JIDataPointSetFactory, obj);
    RETURNCI(classCIDataPointSetFactory, ctorCIDataPointSetFactory, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IDataStyle & obj) const {
    RETURNJREF(JIDataStyle, obj);
    RETURNCI(classCIDataStyle, ctorCIDataStyle, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IEvaluator & obj) const {
    RETURNJREF(JIEvaluator, obj);
    RETURNCI(classCIEvaluator, ctorCIEvaluator, obj);
}
                
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFillStyle & obj) const {
    RETURNJREF(JIFillStyle, obj);
    RETURNCI(classCIFillStyle, ctorCIFillStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFilter & obj) const {
    RETURNJREF(JIFilter, obj);
    RETURNCI(classCIFilter, ctorCIFilter, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFitData & obj) const {
    RETURNJREF(JIFitData, obj);
    RETURNCI(classCIFitData, ctorCIFitData, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFitFactory & obj) const {
    RETURNJREF(JIFitFactory, obj);
    RETURNCI(classCIFitFactory, ctorCIFitFactory, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFitParameterSettings & obj) const {
    RETURNJREF(JIFitParameterSettings, obj);
    RETURNCI(classCIFitParameterSettings, ctorCIFitParameterSettings, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFitResult & obj) const {
    RETURNJREF(JIFitResult, obj);
    RETURNCI(classCIFitResult, ctorCIFitResult, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFitter & obj) const {
    RETURNJREF(JIFitter, obj);
    RETURNCI(classCIFitter, ctorCIFitter, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFunction & obj) const {
    RETURNCREATE(IModelFunction, obj);
    RETURNJREF(JIFunction, obj);
    RETURNCI(classCIFunction, ctorCIFunction, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFunctionCatalog & obj) const {
    RETURNJREF(JIFunctionCatalog, obj);
    RETURNCI(classCIFunctionCatalog, ctorCIFunctionCatalog, obj);
}
                
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IFunctionFactory & obj) const {
    RETURNJREF(JIFunctionFactory, obj);
    RETURNCI(classCIFunctionFactory, ctorCIFunctionFactory, obj);
}
                
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IHistogram & obj) const {
    RETURNJREF(JIHistogram, obj);
    RETURNCREATE(IHistogram1D, obj);
    RETURNCREATE(IHistogram2D, obj);
    RETURNCREATE(IHistogram3D, obj);
    return NULL;
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IHistogramFactory & obj) const {
    RETURNJREF(JIHistogramFactory, obj);
    RETURNCI(classCIHistogramFactory, ctorCIHistogramFactory, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IHistogram1D & obj) const {
    RETURNJREF(JIHistogram1D, obj);
    RETURNCI(classCIHistogram1D, ctorCIHistogram1D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IHistogram2D & obj) const {
    RETURNJREF(JIHistogram2D, obj);
    RETURNCI(classCIHistogram2D, ctorCIHistogram2D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IHistogram3D & obj) const {
    RETURNJREF(JIHistogram3D, obj);
    RETURNCI(classCIHistogram3D, ctorCIHistogram3D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IInfo & obj) const {
    RETURNJREF(JIInfo, obj);
    RETURNCI(classCIInfo, ctorCIInfo, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IInfoStyle & obj) const {
    RETURNJREF(JIInfoStyle, obj);
    RETURNCI(classCIInfoStyle, ctorCIInfoStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ILineStyle & obj) const {
    RETURNJREF(JILineStyle, obj);
    RETURNCI(classCILineStyle, ctorCILineStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IManagedObject & obj) const {
    RETURNCREATE(IHistogram1D, obj);
    RETURNCREATE(IHistogram2D, obj);
    RETURNCREATE(IHistogram3D, obj);
    RETURNCREATE(ICloud1D, obj);
    RETURNCREATE(ICloud2D, obj);
    RETURNCREATE(ICloud3D, obj);
    RETURNCREATE(IProfile1D, obj);
    RETURNCREATE(IProfile2D, obj);
    RETURNCREATE(ITuple, obj);
    RETURNCREATE(IDataPointSet, obj);
    RETURNCREATE(IModelFunction, obj);
    RETURNCREATE(IFunction, obj);
    return NULL;
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IMarkerStyle & obj) const {
    RETURNJREF(JIMarkerStyle, obj);
    RETURNCI(classCIMarkerStyle, ctorCIMarkerStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IMeasurement & obj) const {
    RETURNJREF(JIMeasurement, obj);
    RETURNCI(classCIMeasurement, ctorCIMeasurement, obj);
}
        
JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IModelFunction & obj) const {
    RETURNJREF(JIModelFunction, obj);
    RETURNCI(classCIModelFunction, ctorCIModelFunction, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IPlotter & obj) const {
    RETURNJREF(JIPlotter, obj);
    RETURNCI(classCIPlotter, ctorCIPlotter, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IPlotterFactory & obj) const {
    RETURNJREF(JIPlotterFactory, obj);
    RETURNCI(classCIPlotterFactory, ctorCIPlotterFactory, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IPlotterLayout & obj) const {
    RETURNJREF(JIPlotterLayout, obj);
    RETURNCI(classCIPlotterLayout, ctorCIPlotterLayout, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IPlotterRegion & obj) const {
    RETURNJREF(JIPlotterRegion, obj);
    RETURNCI(classCIPlotterRegion, ctorCIPlotterRegion, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IPlotterStyle & obj) const {
    RETURNJREF(JIPlotterStyle, obj);
    RETURNCI(classCIPlotterStyle, ctorCIPlotterStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IProfile & obj) const {
    RETURNJREF(JIProfile, obj);
    RETURNCREATE(IProfile1D, obj);
    RETURNCREATE(IProfile2D, obj);
    return NULL;
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IProfile1D & obj) const {
    RETURNJREF(JIProfile1D, obj);
    RETURNCI(classCIProfile1D, ctorCIProfile1D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IProfile2D & obj) const {
    RETURNJREF(JIProfile2D, obj);
    RETURNCI(classCIProfile2D, ctorCIProfile2D, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const IRangeSet & obj) const {
    RETURNJREF(JIRangeSet, obj);
    RETURNCI(classCIRangeSet, ctorCIRangeSet, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITextStyle & obj) const {
    RETURNJREF(JITextStyle, obj);
    RETURNCI(classCITextStyle, ctorCITextStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITitleStyle & obj) const {
    RETURNJREF(JITitleStyle, obj);
    RETURNCI(classCITitleStyle, ctorCITitleStyle, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITree & obj) const {
    RETURNJREF(JITree, obj);
    RETURNCI(classCITree, ctorCITree, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITreeFactory & obj) const {
    RETURNJREF(JITreeFactory, obj);
    RETURNCI(classCITreeFactory, ctorCITreeFactory, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITuple & obj) const {
    RETURNJREF(JITuple, obj);
    RETURNCI(classCITuple, ctorCITuple, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, ITuple & obj) const {
    RETURNJREF(JITuple, obj);
    RETURNCI(classCITuple, ctorCITuple, obj);
}

JNIEXPORT jobject ProxyFactory::create(JNIEnv *env, const ITupleFactory & obj) const {
    RETURNJREF(JITupleFactory, obj);
    RETURNCI(classCITupleFactory, ctorCITupleFactory, obj);
}


