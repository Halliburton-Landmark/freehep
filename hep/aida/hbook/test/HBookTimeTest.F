      PROGRAM HTEST

      PARAMETER (NWPAW=300000)
      COMMON/PAWC/H(NWPAW)
*
*      CALL HLIMIT(NWPAW)
*      CALL TIMED(T1)
*      CALL HTITLE('EXAMPLE NO = 1')
*
*             Book 1-dim, scatter-plot and table
*
      CALL HBOOK1(10,'EXAMPLE OF 1-DIM HISTOGRAM',100,1.,101.,0.)
      CALL HBOOK2(20,'EXAMPLE OF SCATTER-PLOT',100,0.,1.,40,1.,41.,30.)
*      CALL HTABLE(30,'EXAMPLE OF TABLE',15,1.,16.,40,1.,41.,1000.)
*
*             Fill 1-dim histogram
*
*      WRITE( 6,*) 'Started'
      DO 10 I=1,100000
         W=10*MOD(I,25)
         CALL HFILL(10,FLOAT(I)+0.5,0.,W)
  10  CONTINUE
*
*             Fill scatter-plot
*
      X=-0.005
*      WRITE( 6,*) 'Continuing'
      DO 30 I=1,5000
         X=X+0.01
         DO 20 J=1,4000
            Y=J
            IW=MOD(I,25)*MOD(J,10)
            IWMAX=J-MOD(I,25)+10
            IF(IW.GT.IWMAX)IW=0
            CALL HFILL(20,X,Y,FLOAT(IW))
  20     CONTINUE
  30  CONTINUE
*
*             Fill table
*
*      DO 50 I=1,20
*         DO 40 J=1,40
*            CALL HFILL(30,FLOAT(I)+0.5,FLOAT(J)+0.5,FLOAT(I+J))
*  40     CONTINUE
*  50  CONTINUE
*
*             Print all histograms with an index
*
*      CALL HISTDO
*
*      CALL TIMED(T1)
*      WRITE( 6,*) 'TIME FOR EXAMPLE 1 =',T1,'  SECONDS'

      END
