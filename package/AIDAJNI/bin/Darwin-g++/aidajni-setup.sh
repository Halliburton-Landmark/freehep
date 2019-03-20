#
# Setup for Darwin using sh
#
# Check AIDAJNI_HOME is set sensibly

if ! test -e "${AIDAJNI_HOME}/lib/Darwin-g++/libAIDAJNI.a"
then
   echo "The libAIDAJNI.a file seem to be missing, make sure AIDAJNI_HOME has been set properly"
   return
fi

if test -e "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.sh"
then
    source "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.sh"
    /bin/rm "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.sh"
    /bin/rm "${AIDAJNI_HOME}/bin/Darwin-g++/aidajni-install.csh"
fi

export PATH="${AIDAJNI_HOME}/bin/Darwin-g++:${PATH}"
export CLASSPATH="${AIDAJNI_HOME}/lib:${CLASSPATH}"
export CLASSPATH="${AIDAJNI_HOME}/lib/freehep-aidajni.jar:${CLASSPATH}"

export DYLD_LIBRARY_PATH="${AIDAJNI_HOME}/lib/Darwin-g++:${DYLD_LIBRARY_PATH}"

export AIDAJNI_INCLUDES=-I${AIDAJNI_HOME}/include
export AIDAJNI_LIBS="-L${AIDAJNI_HOME}/lib/Darwin-g++ -lAIDAJNI -lFHJNI -framework JavaVM"
export AIDAJNI_VERSION="3.2.5"
