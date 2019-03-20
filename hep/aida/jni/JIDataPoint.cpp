
#include "FreeHepTypes.h"

#include <cstdlib>
#include <iostream>

#include "AIDA/IMeasurement.h"
#include "JIDataPoint.h"
#include "JIMeasurement.h"

#include "ProxyFactory.h"

#include "JNIUtil.hh"

using namespace AIDA;
using namespace JAIDA;


JNIEXPORT JIDataPoint::JIDataPoint(JNIEnv *jnienv, jobject object, const ProxyFactory & factory)
        : JProxy(jnienv, object, factory) {
    jclass cls = env->GetObjectClass(getRef());

    coordinateOICLhep_aida_IMeasurementEMethod = env->GetMethodID(cls, "coordinate", "(I)Lhep/aida/IMeasurement;");
    if (coordinateOICLhep_aida_IMeasurementEMethod == NULL) {
        std::cerr << "IDataPoint" << ": Could not find method: " << "coordinate" << "(I)Lhep/aida/IMeasurement;" << std::endl;
    }

    dimensionOCIMethod = env->GetMethodID(cls, "dimension", "()I");
    if (dimensionOCIMethod == NULL) {
        std::cerr << "IDataPoint" << ": Could not find method: " << "dimension" << "()I" << std::endl;
    }

}

JNIEXPORT JIDataPoint::~JIDataPoint() {
}

JNIEXPORT int JIDataPoint::dimension() const {
   jint r = env->CallIntMethod(ref, dimensionOCIMethod);
   JNIUtil::checkExceptions(env);
   return r;
}

JNIEXPORT IMeasurement * JIDataPoint::coordinate(int coord) {
   jobject obj = env->CallObjectMethod(ref, coordinateOICLhep_aida_IMeasurementEMethod, coord);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIMeasurement(env, obj);
}

JNIEXPORT const IMeasurement * JIDataPoint::coordinate(int coord) const {
   jobject obj = env->CallObjectMethod(ref, coordinateOICLhep_aida_IMeasurementEMethod, coord);
   if (JNIUtil::exceptions(env)) return NULL;
   else return factory->createIMeasurement(env, obj);
}
