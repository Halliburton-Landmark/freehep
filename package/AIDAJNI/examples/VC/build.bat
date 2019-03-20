REM
REM Build file for Visual C++ (Windows)
REM
cl /c /TP /GX %AIDAJNI_INCLUDES% ..\AidaTest.cc
link /out:AidaTest.exe AidaTest.obj %AIDAJNI_LIBS%

