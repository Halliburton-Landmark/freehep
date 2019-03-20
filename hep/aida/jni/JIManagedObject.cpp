
#include <cstdlib>
#include <iostream>
#include <string>

#include "JIManagedObject.h"

using namespace AIDA;
using namespace JAIDA;
using namespace std;


JNIEXPORT JIManagedObject::JIManagedObject(JNIEnv *jnienv, jobject object) :
    moEnv(jnienv),
    moRef(object) {
    jclass cls = moEnv->GetObjectClass(moRef);

    nameOCLjava_lang_StringEMethod = moEnv->GetMethodID(cls, "name", "()Ljava/lang/String;");
    if (nameOCLjava_lang_StringEMethod == NULL) {
        std::cerr << "IManagedObject" << ": Could not find method: " << "name" << "()Ljava/lang/String;" << std::endl;
    }

}

JNIEXPORT JIManagedObject::~JIManagedObject() {
}

JNIEXPORT std::string JIManagedObject::name() const {
    // Call to Java
    jstring jname = (jstring)moEnv->CallObjectMethod(moRef, nameOCLjava_lang_StringEMethod);
    // converting String to string
    jboolean isCopy;
    const char* utf = moEnv->GetStringUTFChars(jname, &isCopy);
    string nameString = utf;
    if (isCopy) moEnv->ReleaseStringUTFChars(jname, utf);
    return nameString;
}
