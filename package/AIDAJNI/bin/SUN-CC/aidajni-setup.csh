#
# Setup for Solaris with csh
#
# Check AIDAJNI_HOME is set sensibly

if (! $?AIDAJNI_HOME) then
   echo "AIDAJNI_HOME has not been set"
   exit
endif

if (! -e "${AIDAJNI_HOME}/lib/SUN-CC/libAIDAJNI.a") then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   exit
endif

if (! $?JDK_HOME) then
   echo "JDK_HOME has not been set, make sure it is set to the Java Runtime (JRE/JDK) directory"
   exit
endif

if (! -e "${JDK_HOME}/jre/lib/sparc/client/libjvm.so") then
   echo "The libjvm.so file seem to be missing, make sure JDK_HOME has been set properly"
   exit
endif

setenv PATH "${AIDAJNI_HOME}/bin/SUN-CC:${PATH}"
if (! $?CLASSPATH) then
   setenv CLASSPATH ""
endif
setenv CLASSPATH "${AIDAJNI_HOME}/lib/freehep-aidajni.jar:${CLASSPATH}"

if (! $?LD_LIBRARY_PATH) then
   setenv LD_LIBRARY_PATH ""
endif
setenv LD_LIBRARY_PATH "${AIDAJNI_HOME}/lib/SUN-CC:${LD_LIBRARY_PATH}"

setenv AIDAJNI_INCLUDES -I${AIDAJNI_HOME}/include
setenv AIDAJNI_LIBS "-L${AIDAJNI_HOME}/lib/SUN-CC -lAIDAJNI -lFHJNI"
setenv AIDAJNI_VERSION "3.2.5"
