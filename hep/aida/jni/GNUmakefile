#
# Makefile for the Aida JNI library
#
# Author: Mark Donszelmann
# Version: $Id: GNUmakefile,v 1.51 2006/04/07 21:20:02 duns Exp $
#
# DVERSION specifies the version and the directory in which the version is written.
# UVERSION specifies (with leading dot) the update number. 
# The directory is still DVERSION, as well as the release notes.
#

#DEBUG = 1

#
# User Configuration: Define targets
#
INCLUDEDIRS = $(FREEHEP)/hep/aida/include $(FREEHEP)/org/freehep/aid/include $(FREEHEP)/org/freehep/jni
INCLUDELIBS = FHJNI
LIBDIRS = $(FREEHEP)/org/freehep/jni
OBJS = $(patsubst %.cpp, %, $(wildcard *.cpp))
LIBS = AIDAJNI
DLLS = AIDAJNI
EXE = AidaTest
TEST = AidaTest

DVERSION= 3.2.5
UVERSION= 
DIRNAME = $(DLLS)-$(DVERSION)
DNAME   = $(DLLS)-$(DVERSION)$(UVERSION)-$(DST)$(TAREXT)
DDIR    = ../../../LICENSE.txt
DDIR   += ../../../LGPL.txt
DDIR   += AIDAJNI.txt
DDIR   += ../../../web/freehep/aidajni/ReleaseNotes-$(DVERSION).xhtml
DSBIN   = ../../../package/AIDAJNI/bin/$(DST)/*
DSBIN  += ../../../package/AIDAJNI/src/aida-config/$(DST)/aida-config$(EXEEXT)
DINC    = ../include/AIDA
DLIB    = ../../../lib/freehep-aidajni.jar
DLIB   += ../../../package/AIDAJNI/src/runs/runs.class
DSLIB   = $(DST)/*$(DLLEXT) $(DST)/*$(LIBEXT)
DSLIB  += ../../../org/freehep/jni/$(DST)/*$(DLLEXT)
DSLIB  += ../../../org/freehep/jni/$(DST)/*$(LIBEXT)
DSLIB  += ../../../package/AIDAJNI/src/runs/$(DST)/runs$(OBJEXT)
ifeq ($(findstring Windows_, $(OS)), Windows_)
ifeq ($(COMPILER), g++)
DSLIB  += ../../../lib/WIN32-g++/libjvm.dll.a
endif
endif
DEXAMPLES  = AidaTest.cc
DEXAMPLES += ../../../package/AIDAJNI/examples/*

#
# No User Configuration below
#

include $(FREEHEP)/config/common.gmk
