#
# Setup for Windows with cygwin and g++
#
# Check AIDAJNI_HOME is set sensibly

if (! $?AIDAJNI_HOME) then
   echo "AIDAJNI_HOME has not been set"
   exit
endif

if (! -e "${AIDAJNI_HOME}/lib/WIN32-g++/libAIDAJNI.a") then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   exit
endif

if (! $?JDK_HOME) then
   echo "JDK_HOME has not been set, make sure it is set to the Java Runtime (JRE/JDK) directory"
   exit
endif

if (! -e "${JDK_HOME}/jre/bin/client/jvm.dll") then
   echo "The jvm.dll file seem to be missing, make sure JDK_HOME has been set properly"
   exit
endif

set ARCH=WIN32-g++
set UPATH=`cygpath -u "${AIDAJNI_HOME}"`
set DPATH=`cygpath -d "${AIDAJNI_HOME}"`
set UJPATH=`cygpath -u "${JDK_HOME}"`
set DJPATH=`cygpath -d "${JDK_HOME}"`

setenv PATH "${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}:${UJPATH}/jre/bin/client"
if (! $?CLASSPATH) then
   setenv CLASSPATH ""
endif
setenv CLASSPATH "${DPATH}/lib/freehep-aidajni.jar;${CLASSPATH}"

setenv AIDAJNI_INCLUDES "-I${UPATH}/include"
setenv AIDAJNI_LIBS "-L${UPATH}/lib/$ARCH -lAIDAJNI -lFHJNI -ljvm"
setenv AIDAJNI_VERSION "3.2.5"
