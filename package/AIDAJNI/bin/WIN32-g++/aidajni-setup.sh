#
# Setup for Windows with cygwin and g++
#
# Check AIDAJNI_HOME is set sensibly

if ! test -e "${AIDAJNI_HOME}/lib/WIN32-g++/libAIDAJNI.a"
then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   return
fi

if ! test -e "${JDK_HOME}/jre/bin/client/jvm.dll" 
then
   echo "The jvm.dll file seem to be missing, make sure JDK_HOME has been set properly"
   return
fi

ARCH=WIN32-g++
UPATH=`cygpath -u "${AIDAJNI_HOME}"`
DPATH=`cygpath -d "${AIDAJNI_HOME}"`
UJPATH=`cygpath -u "${JDK_HOME}"`
DJPATH=`cygpath -d "${JDK_HOME}"`

export PATH="${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}:${UJPATH}/jre/bin/client"
export CLASSPATH="${DPATH}/lib/freehep-aidajni.jar;${CLASSPATH}"

export AIDAJNI_INCLUDES=-I${UPATH}/include
export AIDAJNI_LIBS="-L${UPATH}/lib/${ARCH} -lAIDAJNI -lFHJNI -ljvm"
export AIDAJNI_VERSION="3.2.5"
