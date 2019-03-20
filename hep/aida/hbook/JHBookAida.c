
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "cfortran.h"

#include "JNIMacros.h"
#include "JNICUtil.h"

/**
 * HBOOK-AIDA stub to call HBookAida.java
 *
 * WARNING: only a few call are implemented.
 *
 * @author Mark Donszelmann
 * @version $Id: JHBookAida.c,v 1.13 2001/04/18 14:36:49 duns Exp $
 */

JNIEnv *jhbookEnv;
JavaVM *jhbookJVM;       
jclass jhbookStringClass;

/* HBook */
jclass jhbook;

int jhbookInitDone = 0;

/* FIXME: to be integrated into static loading */
void JHBookInit() {
    int rc;
    
    if (jhbookInitDone) return;
    
    jhbookInitDone = 1;
    
    /* Start JVM */
    rc = JNICcreateJVM(&jhbookEnv, &jhbookJVM);
    if (rc < 0) {
        JNICfatal("JHBookAida: failed to create Java VM");
    }
    if (rc == 1) {
        JNICfatal("JHBookAida: CLASSPATH or JVM_CLASSPATH not set");
    }
    
    GETCLASS(jhbookEnv, jhbookStringClass, "java/lang/String")
    GETCLASS(jhbookEnv, jhbook, "hep/aida/hbook/HBook")
}

