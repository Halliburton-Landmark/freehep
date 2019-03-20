
#include <stdlib.h>

#include "runs.h"

extern int main(int argc, const char* argv[]);


JNIEXPORT jint JNICALL Java_runs_main(JNIEnv *env, jobject jobj, jint jargc, jobjectArray jargv) {
    int i, rc;
    char **argv = calloc((unsigned int)jargc, sizeof(char*));
    jboolean *isCopy = calloc((unsigned int)jargc, sizeof(jboolean));
    jobject *jarg = calloc((unsigned int)jargc, sizeof(jobject));

    if ((argv == NULL) || (isCopy == NULL) || (jarg == NULL)) {
       printf("runs: Could not allocate memory for arguments\n");
       return 1;
    } 
    
    for (i=0; i<jargc; i++) {
       jarg[i] = (*env)->GetObjectArrayElement(env, jargv, i);
       argv[i]  = (char*)(*env)->GetStringUTFChars(env, jarg[i], &isCopy[i]);
    }    

    rc = main(jargc, argv);   
    
    for (i=0; i<jargc; i++) {
       if (isCopy[i]) (*env)->ReleaseStringUTFChars(env, jarg[i], argv[i]);
    }    

    free(argv);
    free(isCopy);
    free(jarg);

    return rc;
}

