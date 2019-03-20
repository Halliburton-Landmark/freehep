#
# Makefile for the CERNLIBAdapter library
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.14 2005/09/28 19:07:56 duns Exp $
#

ifneq ($(CERN_ROOT),)

#
# User Configuration: Define targets
#
DEBUG = false

DVERSION = 3.0.6
UVERSION = 
DNAME    = CERNLIBAdapter-$(DVERSION)$(UVERSION)-$(DST)$(TAREXT)
DIRNAME = CERNLIBAdapter-$(DVERSION)
DDIR     = ../LICENSE.txt
DDIR    += ../LGPL.txt
DDIR    += CERNLIBAdapter.txt
DDIR    += ../web/freehep/cernlibadapter/ReleaseNotes-$(DVERSION).xhtml
DSLIB    = io/hbook/jni/$(DST)/*$(DLLEXT) $(wildcard io/hbook/jni/$(DST)/*$(LIBEXT)) \
           aida/ref/optimizer/minuit/jni/$(DST)/*$(DLLEXT) $(wildcard aida/ref/optimizer/minuit/jni/$(DST)/*$(LIBEXT)) \
           $(wildcard ../lib/$(DST)/DFORMD.DLL)

endif   # CERN_ROOT

#
# No User Configuration below
#

include $(FREEHEP)/config/common.gmk
