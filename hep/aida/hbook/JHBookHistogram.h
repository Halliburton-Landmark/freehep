#ifndef JHBOOK_HISTOGRAM
#define JHBOOK_HISTOGRAM

/* JHBookHistogram.c: HBOOK Chapter 2 */
extern void hbook1 (int id, char* chtitl, int nx, float xmi, float xma, float vmx);
extern void hbook2 (int id, char* chtitl, 
                    int nx, float xmi, float xma, 
                    int ny, float ymi, float yma, float vmx);
extern void hfill  (int id, float x, float y, float weight);
extern void histdo ();
extern void hprint (int id);
extern void hcopy  (int id1, int id2, char* chtitl);
extern void hcopyr (int id1, int id2, char* chtitl, 
                    int ibinx1, int ibinx2, 
                    int ibiny1, int ibiny2, char *chopt);
extern void hrenid (int idold, int idnew);
extern void hreset (int id, char* chtitl);
extern void hdelet (int id);

#endif
