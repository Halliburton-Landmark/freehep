/*
 * This example demonstrate how to call HBOOK-AIDA from C
 *
 */

#include <stdlib.h>
#include "JHBookAida.h"

main()
{
	int hid=1;
	int i,j;
	float r;

	hbook1(hid," some random distribution",20000,-4.,4.,0.);

	for (i=0;i<100000;i++){
		for (j=0,r=0.;j<10;r += rand()/32768 -0.5 ,j++)  
		;
		hfill(hid,r,0.,1.);
	}
}
