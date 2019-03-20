#
# Makefile for the C++ parts of the FreeHEP library
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.32 2005/05/25 22:24:29 duns Exp $
#

MODULES =

#
# General
#
MODULES += org/freehep/jni

#
# AIDA
#
MODULES += package/AIDAJNI/src/runs
MODULES += package/AIDAJNI/src/aida-config
MODULES += hep/aida/jni
MODULES += hep/aida/ref/optimizer/minuit/jni
#MODULES += org/freehep/aid/test/jni        # not yet ready (MD: 08/29/2002)
#MODULES += hep/aida/hbook                  # DISABLED until updated (MD: 08/23/2001)

#
# IO
#
MODULES += hep/io/hbook/jni

#
# Composite Modules
#
MODULES += hep
MODULES += hep/aida

#
# No User Configuration below
#

#
# Check for existence of modules
#
MODULES := $(wildcard $(MODULES))

#
# include definitions
#
include $(FREEHEP)/config/architecture.gmk

LIBDIR = lib/$(DST)
FULLLIB = $(LIBDIR)/$(LIBPRE)FREEHEP$(DEBUGSUFFIX)$(LIBEXT)
FULLDLL = $(LIBDIR)/$(LIBPRE)FREEHEP$(DEBUGSUFFIX)$(DLLEXT)

#
# Targets
#
.PHONY: all info clean veryclean copylib copydll copydist $(FULLLIB) $(FULLDLL)

all: $(addsuffix .all, $(MODULES)) $(LIBDIR) copylib copydll
#$(FULLDLL) $(FULLLIB)

info: $(addsuffix .info, $(MODULES))

dist: $(addsuffix .dist, $(MODULES)) copylib copydll copydist

clean: $(addsuffix .clean, $(MODULES))

veryclean: $(addsuffix .veryclean, $(MODULES))
	rm -f $(FULLLIB)
	rm -f $(FULLDLL)
	rm -f $(subst \,/,$(FREEHEP)/$(LIBDIR))/*.pdb

test: $(addsuffix .test, $(MODULES))

#
# Rules for full library
#
$(LIBDIR):
	-mkdir $(FREEHEP)/$(LIBDIR)
	@-echo

$(FULLLIB):
	$(LIB) $(LIBFLAGS) $(LIBTARGET)$@ $(addsuffix /$(DST)/*$(OBJEXT), $(MODULES))
	-cp $(addsuffix /$(DST)/*.pdb, $(MODULES)) $(subst \,/,$(FREEHEP)/$(LIBDIR))
	@-echo

$(FULLDLL):
	$(LINK) $(LINKFLAGS) $(DLLFLAGS) $(addsuffix /$(DST)/*$(OBJEXT), $(MODULES)) $(subst \,/,$(LINKLIBS)) $(LINKTARGET)$@
	@-echo

copylib:
	-cp $(wildcard $(addsuffix /$(DST)/*$(LIBEXT), $(MODULES))) $(subst \,/,$(FREEHEP)/$(LIBDIR))
	@-echo

copydll:
	-cp $(wildcard $(addsuffix /$(DST)/*$(DLLEXT), $(MODULES))) $(subst \,/,$(FREEHEP)/$(LIBDIR))
	@-echo

copydist:
	-cp $(wildcard $(addsuffix /*$(TAREXT), $(MODULES))) .
	@-echo

#
# Rules for sub-makes
#
$(addsuffix .all, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

$(addsuffix .info, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

$(addsuffix .dist, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

$(addsuffix .clean, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

$(addsuffix .veryclean, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

$(addsuffix .test, $(MODULES)):
	$(MAKE) -C $(basename $@) $(subst .,,$(suffix $@))

	
