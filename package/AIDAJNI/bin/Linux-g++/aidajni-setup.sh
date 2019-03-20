#
# Setup for Linux using sh
#
# Check AIDAJNI_HOME is set sensibly

if ! test -e "${AIDAJNI_HOME}/lib/Linux-g++/libAIDAJNI.a"
then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   return
fi

if ! test -e "${JDK_HOME}/jre/lib/i386/client/libjvm.so"
then
   echo "The libjvm.so file seem to be missing, make sure JDK_HOME has been set properly"
   return
fi

export PATH="${AIDAJNI_HOME}/bin/Linux-g++:${PATH}"
export CLASSPATH="${AIDAJNI_HOME}/lib/freehep-aidajni.jar:${CLASSPATH}"

export LD_LIBRARY_PATH="${AIDAJNI_HOME}/lib/Linux-g++:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${JDK_HOME}/jre/lib/i386/client:${LD_LIBRARY_PATH}"
export LD_LIBRARY_PATH="${JDK_HOME}/jre/lib/i386:${LD_LIBRARY_PATH}"

export AIDAJNI_INCLUDES=-I${AIDAJNI_HOME}/include
export AIDAJNI_LIBS="-L${AIDAJNI_HOME}/lib/Linux-g++ -lAIDAJNI -lFHJNI -L${JDK_HOME}/jre/lib/i386/client -ljvm"
export AIDAJNI_VERSION="3.2.5"
