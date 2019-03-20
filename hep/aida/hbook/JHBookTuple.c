
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "cfortran.h"

#include "JNIMacros.h"
#include "JNICUtil.h"

#include "JHBookTuple.h"
#include "JHBookExterns.h"

/**
 * Routines from hbook chapter 3
 *
 * WARNING: only a few call are implemented.
 *
 * @author Mark Donszelmann
 * @version $Id: JHBookTuple.c,v 1.3 2001/04/18 14:36:49 duns Exp $
 */

/* HBook Chapter 3 */
jmethodID hbooknID, hfnID;
jmethodID getColumnsID, getTitleID;
jmethodID hproj1ID, hproj2ID;
jclass jhbookWeightFunctionClass;
jmethodID jhbookWeightFunctionID;
jmethodID hgivenID, hgnID, hgnparID, hgnfID;

int jhbookTupleInitDone = 0;

/* FIXME: to be integrated into static loading */
void JHBookTupleInit() {
    if (jhbookTupleInitDone) return;
    
    JHBookInit();
    
    jhbookTupleInitDone = 1;
    
    /* HBook Chapter 3 */	
    GETSTATICMETHOD(jhbookEnv, hbooknID, jhbook, "hbookn", "(ILjava/lang/String;ILjava/lang/String;I[Ljava/lang/String;)V" )
    GETSTATICMETHOD(jhbookEnv, hfnID,    jhbook, "hfn",    "(IF)V" )
    GETSTATICMETHOD(jhbookEnv, getColumnsID, jhbook, "getColumns", "(I)I" )
    GETSTATICMETHOD(jhbookEnv, getTitleID, jhbook, "getTitle", "(I)Ljava/lang/String;" )
    GETSTATICMETHOD(jhbookEnv, hproj1ID, jhbook, "hproj1", "(IIILhep/aida/hbook/WeightFunction;III)V" )
    GETSTATICMETHOD(jhbookEnv, hproj2ID, jhbook, "hproj2", "(IIILhep/aida/hbook/WeightFunction;IIII)V" )
    GETCLASS(jhbookEnv, jhbookWeightFunctionClass, "WeightFunction")
    GETMETHOD(jhbookEnv, jhbookWeightFunctionID, jhbookWeightFunctionClass, "<init>", "(J)V" )
    GETSTATICMETHOD(jhbookEnv, hgivenID, jhbook, "hgiven", "(I[Ljava/lang/String;[F[F)I" )
    GETSTATICMETHOD(jhbookEnv, hgnID,    jhbook, "hgn",    "(II[F)I" )
    GETSTATICMETHOD(jhbookEnv, hgnparID, jhbook, "hgnpar", "(ILjava/lang/String;)V" )
    GETSTATICMETHOD(jhbookEnv, hgnfID,   jhbook, "hgnf",   "(II[F)I" )

}

/* Chapter 3 */

#define hbookn_STRV_A6 NUM_ELEM_ARG(3)
FCALLSCSUB6(hbookn, HBOOKN, hbookn, INT, STRING, INT, STRING, INT, STRINGV)
void hbookn (int id, char* chtitl, int nvar, char* chrzpa, int nwbuff, char* chtags[]) {
    jstring jchtitl, jchrzpa, jtmp;
    int i;
    jobjectArray jchtags;
    JHBookTupleInit();
    NEWSTRING(jhbookEnv, jchtitl, chtitl);
    NEWSTRING(jhbookEnv, jchrzpa, chrzpa);
    NEWSTRINGARRAY(jhbookEnv, jchtags, nvar, jhbookStringClass, chtags, i, jtmp);
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hbooknID, id, jchtitl, nvar, jchrzpa, nwbuff, jchtags);
    DELSTRING(jhbookEnv, jchtitl);
    DELSTRING(jhbookEnv, jchrzpa);
    DELSTRINGARRAY(jhbookEnv, jchtags);
    JNICcheckExceptions(jhbookEnv);
}    

FCALLSCSUB2(hfn, HFN, hfn, INT, FLOATV)                               
void hfn (int id, float x[]) {
    jint n;
    jfloatArray jx;
    JHBookTupleInit();
    n = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, getColumnsID, id); 
    NEWFLOATARRAY(jhbookEnv, jx, n, x);
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hfnID, id, jx);
    DELFLOATARRAY(jhbookEnv, jx);
    JNICcheckExceptions(jhbookEnv);
}

/**
 * callback:  float fun(float* x, int* isel);
 */
FCALLSCSUB7(hproj1, HPROJ1, hproj1, INT, INT, INT, ROUTINE, INT, INT, INT)
void hproj1 (int id, int idn, int isel, void* fun, int ifrom, int ito, int ivarx) {
    jobject jfun;
    JHBookTupleInit();
    jfun = (*jhbookEnv)->NewObject(jhbookEnv, jhbookWeightFunctionClass, 
                                   jhbookWeightFunctionID, (long)fun);
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hproj1ID, id, idn, isel, jfun, ifrom, ito, ivarx);
    JNICcheckExceptions(jhbookEnv);
}

/**
 * callback:  float fun(float* x, float* y, int* isel);
 */
FCALLSCSUB8(hproj2, HPROJ2, hproj2, INT, INT, INT, ROUTINE, INT, INT, INT, INT)
void hproj2 (int id, int idn, int isel, void* fun, int ifrom, int ito, int ivarx, int ivary) {
    jobject jfun;
    JHBookTupleInit();
    jfun = (*jhbookEnv)->NewObject(jhbookEnv, jhbookWeightFunctionClass, 
                                   jhbookWeightFunctionID, (long)fun);
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hproj1ID, id, idn, isel, jfun, ifrom, ito, ivarx, ivary);
    JNICcheckExceptions(jhbookEnv);
}

#define hgiven_STRV_A4 NUM_ELEM_ARG(3)
FCALLSCSUB6(hgiven, HGIVEN, hgiven, INT, PSTRING, PINT, PSTRINGV, FLOATV, FLOATV)
void hgiven (int id, char *chtitl, int *nvar, char *chtag[], float rlow[], float rhigh[]) {
    jint n;
    int i;
    jobject jtmp;
    jstring jchtitl;
    jobjectArray jchtag;
    jfloatArray jrlow, jrhigh;
    jsize len;
    
    JHBookTupleInit();
    n = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, getColumnsID, id); 
    *nvar = n;
    
    jchtitl = (*jhbookEnv)->CallStaticObjectMethod(jhbookEnv, jhbook, getTitleID, id);
    len = (*jhbookEnv)->GetStringUTFLength(jhbookEnv, jchtitl);
    if (strlen(chtitl) < len) {
        len = strlen(chtitl);
    }
    (*jhbookEnv)->GetStringUTFRegion(jhbookEnv, jchtitl, 0, len, chtitl);
    
    NEWSTRINGARRAY(jhbookEnv, jchtag, n, jhbookStringClass, chtag, i, jtmp);
    NEWFLOATARRAY(jhbookEnv, jrlow, n, rlow);
    NEWFLOATARRAY(jhbookEnv, jrhigh, n, rhigh);
    (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, hgivenID, id, jchtag, jrlow, jrhigh);
    for (i=0; i<n; i++) {
        jtmp = (*jhbookEnv)->GetObjectArrayElement(jhbookEnv, jchtag, i);
        len = (*jhbookEnv)->GetStringUTFLength(jhbookEnv, jtmp);
        if (strlen(chtag[i]) < len) {
            len = strlen(chtag[i]);
        }
        (*jhbookEnv)->GetStringUTFRegion(jhbookEnv, jtmp, 0, len, chtag[i]);
        
        (*jhbookEnv)->GetFloatArrayRegion(jhbookEnv, jrlow, 0, n, rlow);
        (*jhbookEnv)->GetFloatArrayRegion(jhbookEnv, jrhigh, 0, n, rhigh);
    }

    DELSTRINGARRAY(jhbookEnv, jchtag);
    DELFLOATARRAY(jhbookEnv, jrlow);
    DELFLOATARRAY(jhbookEnv, jrhigh);
    JNICcheckExceptions(jhbookEnv);
}

FCALLSCSUB5(hgn, HGN, hgn, INT, PINT, INT, FLOATV, PINT)
void hgn    (int id, int *idn, int idnevt, float x[], int *ierror) {
    jint n;
    jfloatArray jx;
    JHBookTupleInit();
    n = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, getColumnsID, id); 
    NEWFLOATARRAY(jhbookEnv, jx, n, x);
    *ierror = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, hgnID, id, idnevt, jx);    
    (*jhbookEnv)->GetFloatArrayRegion(jhbookEnv, jx, 0, n, x);
    DELFLOATARRAY(jhbookEnv, jx);
    JNICcheckExceptions(jhbookEnv);
}

FCALLSCSUB2(hgnpar, HGNPAR, hgnpar, INT, STRING)
void hgnpar (int id, char *chrout) {
    jstring jchrout;
    JHBookTupleInit();
    NEWSTRING(jhbookEnv, jchrout, chrout);
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hgnparID, id, jchrout);    
    DELSTRING(jhbookEnv, jchrout);
    JNICcheckExceptions(jhbookEnv);
}

FCALLSCSUB5(hgnf, HGNF, hgnf, INT, PINT, INT, FLOATV, PINT)
void hgnf   (int id, int *idn, int idnevt, float x[], int *ierror) {
    jint n;
    jfloatArray jx;
    JHBookTupleInit();
    n = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, getColumnsID, id); 
    NEWFLOATARRAY(jhbookEnv, jx, n, x);
    *ierror = (*jhbookEnv)->CallStaticIntMethod(jhbookEnv, jhbook, hgnfID, id, idnevt, jx);    
    (*jhbookEnv)->GetFloatArrayRegion(jhbookEnv, jx, 0, n, x);
    DELFLOATARRAY(jhbookEnv, jx);
    JNICcheckExceptions(jhbookEnv);
}

