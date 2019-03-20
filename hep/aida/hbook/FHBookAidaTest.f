*
* Example FORTRAN Program to use HBOOK-AIDA
*
* @author Mark Donszelmann
* @version $Id: FHBookAidaTest.f,v 1.1 2001/03/22 07:20:32 duns Exp $
*
           
*
* Create Histos
*
      WRITE( 6,*) 'HBOOK1'
      CALL HBOOK1(10,'EXAMPLE OF 1-DIM HISTOGRAM',100,1.,101.,0.)
      
*
* Fill 1D Histo
*  
      WRITE( 6,*) 'HFILLs'
      DO 10 I=1,100
          W=10*MOD(I,25)
          CALL HFILL(10,FLOAT(I)+0.5,0.,W)
   10 CONTINUE
       
      END