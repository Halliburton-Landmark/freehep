
#include "FreeHepTypes.h"

#include "AIDA/IInfoStyle.h"
#include "AIDA/ITextStyle.h"

#include "ProxyFactory.h"

#include "CIInfoStyle.h"

using namespace std;
using namespace AIDA;
using namespace JAIDA;

/*
 * Class:     hep_aida_jni_CIInfoStyle
 * Method:    textStyle
 * Signature: ()Lhep/aida/ITextStyle;
 */
JNIEXPORT jobject JNICALL Java_hep_aida_jni_CIInfoStyle_textStyle
  (JNIEnv *env, jobject obj) {

	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfoStyle* cref = (IInfoStyle*)ProxyFactory::getCRef(crefID);

    ITextStyle& style = cref->textStyle();

    ProxyFactory* factory = ProxyFactory::getFactory();

    return factory->create(env, style);
}

/*
 * Class:     hep_aida_jni_CIInfoStyle
 * Method:    setTextStyle
 * Signature: (Lhep/aida/ITextStyle;)Z
 */
JNIEXPORT jboolean JNICALL Java_hep_aida_jni_CIInfoStyle_setTextStyle
  (JNIEnv *env, jobject obj, jobject jstyle) {

    ProxyFactory* factory = ProxyFactory::getFactory();

    ITextStyle* style = factory->createITextStyle(env, jstyle);
    
	jclass cls = env->GetObjectClass(obj);
	jfieldID crefField = env->GetFieldID(cls, "crefID", "J");
    jlong crefID = env->GetLongField(obj, crefField);
	IInfoStyle* cref = (IInfoStyle*)ProxyFactory::getCRef(crefID);

    return cref->setTextStyle(*style);
}

