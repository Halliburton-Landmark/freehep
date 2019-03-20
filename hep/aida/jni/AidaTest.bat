setlocal
set PATH=.;%JDK_HOME%\jre\bin\client
set CLASSPATH=%FREEHEP%\lib\openide-lookup.jar;%FREEHEP%\lib\freehep-aidajni.jar;%FREEHEP%\lib\freehep-hep.jar;%FREEHEP%\lib\freehep-base.jar;%FREEHEP%\lib\aida.jar;%FREEHEP%\lib\aida-dev.jar;%CLASSPATH%
set JVM_ARGS=-Xmx256M
%FREEHEP%\hep\aida\jni\WIN32-VC\AidaTest.exe
