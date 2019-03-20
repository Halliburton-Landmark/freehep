#
# Makefile for the JAIDA library
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.13 2005/09/28 19:07:56 duns Exp $
#

#
# User Configuration: Define targets
# 
# DVERSION specifies the version and the directory in which the version is written.
# UVERSION specifies (with leading dot) the update number. 
# The directory is still DVERSION, as well as the release notes.
#
DEBUG = false

DVERSION= 3.3.0-beta-1
UVERSION=
DIRNAME = JAIDA-$(DVERSION)
DNAME = JAIDA-$(DVERSION)$(UVERSION)$(TAREXT)
DDIR  = ../../LICENSE.txt
DDIR += ../../LGPL.txt
DDIR += JAIDA.txt
DDIR += ../../web/freehep/jaida/v$(DVERSION)/ReleaseNotes.xhtml
DBIN  = ../../package/JAIDA/bin
DLIB  = ../../lib/aida.jar \
        ../../lib/aida-dev.jar \
        ../../lib/freehep-hep.jar \
        ../../lib/freehep-base.jar \
        ../../lib/openide-lookup.jar \
        ../../lib/bcel.jar \
        ../../lib/jel.jar \
        ../../lib/optimizers.jar \
        ../../lib/JMinuit.jar \
        ../../lib/jas-plotter.jar
DEXAMPLES   = ../../web/freehep/jaida/v$(DVERSION)/examples/*.java
DEXAMPLES  += ../../web/freehep/jaida/v$(DVERSION)/examples/*.py

#
# No User Configuration below
#

include $(FREEHEP)/config/common.gmk
