call aid -directory hep/aida/jni -property config JNIHeaderGenerator ../aida/src/aid/*.aid
del hep\aida\jni\JIConstants.h
call aid -directory hep/aida/jni -property config JNICodeGenerator ../aida/src/aid/*.aid
del hep\aida\jni\JIConstants.cpp
