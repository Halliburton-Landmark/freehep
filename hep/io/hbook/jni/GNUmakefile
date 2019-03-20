#
# Makefile for the Aida library
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.10 2005/09/28 19:07:57 duns Exp $
#

ifneq ($(CERN_ROOT),)

#
# User Configuration: Define targets
#
OBJS = hbook fclose hnt_var2
DLLS = hbookAdapter
#
# On Solaris link with C++, otherwise sunmath.so is not referenced.
#
LINKNOCXX = true
LINKNOJAVA = true
LINKFORTRAN = true

DNAME = $(DLLS)-3.0.6-$(DST)$(TAREXT)
DDIR  = ../../../../LICENSE.txt
DDIR += ../../../../LGPL.txt
DINC =
DSLIB  = $(DST)/*$(DLLEXT) $(DST)/*$(LIBEXT)
endif   # CERN_ROOT

#
# No User Configuration below
#

include $(FREEHEP)/config/common.gmk
