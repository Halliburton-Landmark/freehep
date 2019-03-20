@echo off
set AIDAJNI_HOME=%~dp0..\..
set PATH=%~dp0;%AIDAJNI_HOME%\lib\WIN32-VC;%JDK_HOME%\jre\bin\client;%PATH%
set CLASSPATH=%AIDAJNI_HOME%\lib\freehep-aidajni.jar;%CLASSPATH%
set AIDAJNI_INCLUDES=-I%AIDAJNI_HOME%\include
set AIDAJNI_LIBS=/libpath:%AIDAJNI_HOME%\lib\WIN32-VC AIDAJNI.lib FHJNI.lib /libpath:%JAVA_HOME%\lib jvm.lib
set AIDAJNI_VERSION="3.2.5"
