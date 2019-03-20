#ifndef JHBOOK_TUPLE
#define JHBOOK_TUPLE

/* JHBookTuple.c: HBOOK Chapter 3 */
extern void hbookn (int id, char *chtitl, int nvar, char *chrzpa, int nwbuff, char *chtags[]);
extern void hfn    (int id, float x[]);
extern void hproj1 (int id, int idn, int isel, void* fun, int ifrom, int ito, int ivarx);
extern void hproj2 (int id, int idn, int isel, void* fun, int ifrom, int ito, int ivarx, int ivary);
extern void hgiven (int id, char *chtitl, int *nvar, char *chtag[], float rlow[], float rhigh[]);
extern void hgn    (int id, int *idn, int idnevt, float x[], int *ierror);
extern void hgnpar (int id, char *chrout);
extern void hgnf   (int id, int *idn, int idnevt, float x[], int *ierror);

#endif

