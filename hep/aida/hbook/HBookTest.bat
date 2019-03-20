setlocal
set PATH=.;%JDK_HOME%\jre\bin\hotspot;%JDK_HOME%\jre\bin\classic
set CLASSPATH=%FREEHEP%\lib\freehep-hep.jar;%FREEHEP%\lib\freehep-base.jar;%FREEHEP%\lib\xerces.jar;%CLASSPATH%
set JVM_ARGS=-Xmx256M
WIN32-VC\CHBookAidaTest.exe
