
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "cfortran.h"

#include "JNIMacros.h"
#include "JNICUtil.h"

#include "JHBookHistogram.h"
#include "JHBookExterns.h"

/**
 * HBook routines from chapter 2
 *
 * WARNING: only a few call are implemented.
 *
 * @author Mark Donszelmann
 * @version $Id: JHBookHistogram.c,v 1.2 2001/04/18 14:36:49 duns Exp $
 */

/* HBook Chapter 2 */
jmethodID hbook1ID, hbook2ID, hfillID;
jmethodID histdoID, hprintID, hcopyID, hcopyrID, hrenidID, hresetID, hdeletID;

int jhbookHistogramInitDone = 0;

/* FIXME: to be integrated into static loading */
void JHBookHistogramInit() {
    if (jhbookHistogramInitDone) return;
    
    JHBookInit();
    
    jhbookHistogramInitDone = 1;
    
    /* HBook Chapter 2 */	
	GETSTATICMETHOD(jhbookEnv, hbook1ID, jhbook, "hbook1", "(ILjava/lang/String;IFFF)V" )
    GETSTATICMETHOD(jhbookEnv, hbook2ID, jhbook, "hbook2", "(ILjava/lang/String;IFFIFFF)V" )
    GETSTATICMETHOD(jhbookEnv, hfillID,  jhbook, "hfill",  "(IFFF)V" )
    GETSTATICMETHOD(jhbookEnv, histdoID, jhbook, "histdo", "()V" )
    GETSTATICMETHOD(jhbookEnv, hprintID, jhbook, "hprint", "(I)V" )
    GETSTATICMETHOD(jhbookEnv, hcopyID,  jhbook, "hcopy",  "(IILjava/lang/String;)V" )
    GETSTATICMETHOD(jhbookEnv, hcopyrID, jhbook, "hcopyr", "(IILjava/lang/String;IIIILjava/lang/String;)V" )
    GETSTATICMETHOD(jhbookEnv, hrenidID, jhbook, "hrenid", "(II)V" )
    GETSTATICMETHOD(jhbookEnv, hresetID, jhbook, "hreset", "(ILjava/lang/String;)V" )
    GETSTATICMETHOD(jhbookEnv, hdeletID, jhbook, "hdelet", "(I)V" )
}

/* Chapter 2 */

FCALLSCSUB6(hbook1, HBOOK1, hbook1, INT, STRING, INT, FLOAT, FLOAT, FLOAT)
void hbook1 (int id, char* chtitl, int nx, float xmi, float xma, float vmx) {
    jstring jchtitl;
    JHBookHistogramInit();    
    NEWSTRING(jhbookEnv, jchtitl, chtitl)
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hbook1ID, id, jchtitl, nx, xmi, xma, vmx);
    DELSTRING(jhbookEnv, jchtitl)
    JNICcheckExceptions(jhbookEnv);
}

FCALLSCSUB9(hbook2, HBOOK2, hbook2, INT, STRING, INT, FLOAT, FLOAT, INT, FLOAT, FLOAT, FLOAT)
void hbook2 (int id, char* chtitl, int nx, float xmi, float xma, 
                                   int ny, float ymi, float yma, float vmx) {
    jstring jchtitl;    
    JHBookHistogramInit();
    NEWSTRING(jhbookEnv, jchtitl, chtitl)
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hbook2ID, id, jchtitl, nx, xmi, xma, 
                                                                    ny, xmi, xma, vmx);
    DELSTRING(jhbookEnv, jchtitl)
    JNICcheckExceptions(jhbookEnv);
}


FCALLSCSUB4(hfill, HFILL, hfill, INT, FLOAT, FLOAT, FLOAT)                               
void hfill (int id, float x, float y, float weight) {
    JHBookHistogramInit();
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hfillID, id, x, y, weight);
    JNICcheckExceptions(jhbookEnv);
}


FCALLSCSUB0(histdo, HISTDO, histdo)                               
void histdo () {
    JHBookHistogramInit();
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, histdoID);
    JNICcheckExceptions(jhbookEnv);
}


FCALLSCSUB1(hprint, HPRINT, hprint, INT)                               
void hprint (int id) {
    JHBookHistogramInit();
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hprintID, id);
    JNICcheckExceptions(jhbookEnv);
}    

FCALLSCSUB3(hcopy, HCOPY, hcopy, INT, INT, STRING)
void hcopy (int id1, int id2, char* chtitl) {
    jstring jchtitl;
    JHBookHistogramInit();
    NEWSTRING(jhbookEnv, jchtitl, chtitl)
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hcopyID, id1, id2, jchtitl);
    DELSTRING(jhbookEnv, jchtitl)
    JNICcheckExceptions(jhbookEnv);
}    

FCALLSCSUB8(hcopyr, HCOPYR, hcopyr, INT, INT, STRING, INT, INT, INT, INT, STRING)
void hcopyr (int id1, int id2, char* chtitl, 
                    int ibinx1, int ibinx2, 
                    int ibiny1, int ibiny2, char *chopt) {
    jstring jchtitl, jchopt;
    JHBookHistogramInit();
    NEWSTRING(jhbookEnv, jchtitl, chtitl)
    NEWSTRING(jhbookEnv, jchopt, chopt)
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hcopyrID, id1, id2, jchtitl,
                                 ibinx1, ibinx2, ibiny1, ibiny2, jchopt);
    DELSTRING(jhbookEnv, jchtitl)
    DELSTRING(jhbookEnv, jchopt)
    JNICcheckExceptions(jhbookEnv);
}
                    
FCALLSCSUB2(hrenid, HRENID, hrenid, INT, INT)
void hrenid (int idold, int idnew) {
    JHBookHistogramInit();    
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hrenidID, idold, idnew);
    JNICcheckExceptions(jhbookEnv);
}    

FCALLSCSUB2(hreset, HRESET, hreset, INT, STRING)                               
void hreset (int id, char* chtitl) {
    jstring jchtitl;    
    JHBookHistogramInit();
    NEWSTRING(jhbookEnv, jchtitl, chtitl)
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hresetID, id, jchtitl);
    DELSTRING(jhbookEnv, jchtitl)
    JNICcheckExceptions(jhbookEnv);
}    

FCALLSCSUB1(hdelet, HDELET, hdelet, INT)                               
void hdelet (int id) {
    JHBookHistogramInit();    
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hdeletID, id);
    JNICcheckExceptions(jhbookEnv);
}
