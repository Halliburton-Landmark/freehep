
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "cfortran.h"

#include "JNIMacros.h"
#include "JNICUtil.h"

#include "JHBookAdvanced.h"
#include "JHBookExterns.h"

/**
 * HBOOK routines from Chapter 4
 *
 * WARNING: only a few call are implemented.
 *
 * @author Mark Donszelmann
 * @version $Id: JHBookAdvanced.c,v 1.3 2001/04/18 14:36:49 duns Exp $
 */

/* HBook Chapter 4 */
jmethodID hf1ID, hf2ID;

int jhbookAdvancedInitDone = 0;

/* FIXME: to be integrated into static loading */
void JHBookAdvancedInit() {
    if (jhbookAdvancedInitDone) return;
    
    JHBookInit();
    
    jhbookAdvancedInitDone = 1;
    
    /* HBOOK Chapter 4 */
    GETSTATICMETHOD(jhbookEnv, hf1ID,    jhbook, "hf1",    "(IFF)V" )
    GETSTATICMETHOD(jhbookEnv, hf2ID,    jhbook, "hf2",    "(IFFF)V" )
    
}

/* Chapter 4 */

FCALLSCSUB3(hf1, HF1, hf1, INT, FLOAT, FLOAT)                               
void hf1 (int id, float x, float weight) {
    JHBookAdvancedInit();
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hf1ID, id, x, weight);    
}

FCALLSCSUB4(hf2, HF2, hf2, INT, FLOAT, FLOAT, FLOAT)                               
void hf2 (int id, float x, float y, float weight) {
    JHBookAdvancedInit();
    (*jhbookEnv)->CallStaticVoidMethod(jhbookEnv, jhbook, hf2ID, id, x, y, weight);
}
