@echo off
set HEPREP_HOME=%~dp0..\..
set PATH=%~dp0;%HEPREP_HOME%\lib\WIN32-VC7;%PATH%
set HEPREP_INCLUDES=-I%HEPREP_HOME%\include
set HEPREP_LIBS=/libpath:%HEPREP_HOME%\lib\WIN32-VC7 HEPREP.lib ZIPIOS.lib ZLIB.lib
set HEPREP_VERSION="2.0.2"
