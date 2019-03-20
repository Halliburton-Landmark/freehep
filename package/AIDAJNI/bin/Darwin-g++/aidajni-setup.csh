#
# Setup for Darwin with csh
#
# Check AIDAJNI_HOME is set sensibly

if (! $?AIDAJNI_HOME) then
   echo "AIDAJNI_HOME has not been set"
   exit
endif

if (! -e "${AIDAJNI_HOME}/lib/Darwin-g++/libAIDAJNI.a") then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   exit
endif

if (-e "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.csh") then
   source "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.csh"
   /bin/rm "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.csh" 
   /bin/rm "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.sh" 
endif

if (! $?PATH) then
   setenv PATH ""
endif
setenv PATH "${AIDAJNI_HOME}/bin/Darwin-g++:${PATH}"

if (! $?CLASSPATH) then
   setenv CLASSPATH ""
endif
setenv CLASSPATH "${AIDAJNI_HOME}/lib:${CLASSPATH}"
setenv CLASSPATH "${AIDAJNI_HOME}/lib/freehep-aidajni.jar:${CLASSPATH}"

if (! $?DYLD_LIBRARY_PATH) then
   setenv DYLD_LIBRARY_PATH ""
endif
setenv DYLD_LIBRARY_PATH "${AIDAJNI_HOME}/lib/Darwin-g++:${DYLD_LIBRARY_PATH}"

setenv AIDAJNI_INCLUDES -I${AIDAJNI_HOME}/include
setenv AIDAJNI_LIBS "-L${AIDAJNI_HOME}/lib/Darwin-g++ -lAIDAJNI -lFHJNI -framework JavaVM"
setenv AIDAJNI_VERSION "3.2.5"
