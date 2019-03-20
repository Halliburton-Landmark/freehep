package hep.io.stdhep;

import hep.io.mcfio.*;

import hep.io.xdr.*;

import java.io.IOException;


/**
 * A begin run record
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: StdhepBeginRun.java,v 1.3 2003/09/16 23:11:54 tonyj Exp $
 */
public class StdhepBeginRun extends StdhepRunRecord
{
   public StdhepBeginRun(int nevtreq, int nevtgen, int nevtwrt, float stdecom, float stdxsec, double stdseed1, double stdseed2)
   {
      super(MCFIO_STDHEPBEG, nevtreq, nevtgen, nevtwrt, stdecom, stdxsec, stdseed1, stdseed2);
   }

   StdhepBeginRun()
   {
      super(MCFIO_STDHEPBEG);
   }

   public String toString()
   {
      return "Begin run";
   }
}
