REM
REM Build file for Visual C++ (Windows)
REM
cl /c /TP /GX /MD %HEPREP_INCLUDES% ..\HepRepExample.cpp
link /out:HepRepExample.exe HepRepExample.obj %HEPREP_LIBS%

cl /c /TP /GX /MD %HEPREP_INCLUDES% ..\MultiWriteTest.cpp
link /out:MultiWriteTest.exe MultiWriteTest.obj %HEPREP_LIBS%
