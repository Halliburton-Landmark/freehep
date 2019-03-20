#
# Makefile for the PSViewer
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.5 2004/01/13 18:55:40 duns Exp $
#

#
# User Configuration: Define targets
#
DEBUG = false

DVERSION= 1.1.0
DIRNAME = PSViewer-$(DVERSION)
DNAME = PSViewer-$(DVERSION)$(TAREXT)
DDIR  = ../../../LICENSE.txt
DDIR += ../../../LGPL.txt
DDIR += PSViewer.txt
DDIR += ../../../web/freehep/psviewer/ReleaseNotes-$(DVERSION).xhtml
DBIN  = ../../../package/PSViewer/bin
DLIB  = ../../../lib/freehep-psviewer.jar \
        ../../../lib/freehep-graphicsio-swf.jar \
        ../../../lib/freehep-graphicsio.jar \
        ../../../lib/freehep-graphics2d.jar \
        ../../../lib/freehep-base.jar
DEXAMPLES   = test/PStoSWF.java test/EmbeddedPSViewer.java

#
# No User Configuration below
#

include $(FREEHEP)/config/common.gmk
