package hep.io.mcfio;


/**
 * Constants shared by various MCFIO classes.
 *
 * @author Tony Johnson (tonyj@slac.stanford.edu)
 * @version $Id: MCFIOConstants.java,v 1.3 2003/09/16 23:11:54 tonyj Exp $
 */
interface MCFIOConstants
{
   static final int MCF_XDR_F_TITLE_LENGTH = 255;
   static final int MCF_XDR_VERSION_LENGTH = 4;
   static final int MCF_DEFAULT_TABLE_SIZE = 100;
   static final int FILEHEADER = 1;
   static final int EVENTTABLE = 2;
   static final int EVENTHEADER = 4;
}
