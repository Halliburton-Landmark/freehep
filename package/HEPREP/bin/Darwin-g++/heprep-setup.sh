#
# Setup for Darwin using sh
#
# Check HEPREP_HOME is set sensibly

if ! test -e "${HEPREP_HOME}/lib/Darwin-g++/libHEPREP.a"
then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   return
fi

if test -e "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.sh"
then
    source "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.sh"
    /bin/rm "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.sh"
    /bin/rm "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.csh"
fi

export PATH="${HEPREP_HOME}/bin/Darwin-g++:${PATH}"

export DYLD_LIBRARY_PATH="${HEPREP_HOME}/lib/Darwin-g++:${DYLD_LIBRARY_PATH}"

export HEPREP_INCLUDES=-I${HEPREP_HOME}/include
export HEPREP_LIBS="-L${HEPREP_HOME}/lib/Darwin-g++ -lHEPREP -lZIPIOS -lZLIB"
export HEPREP_VERSION="2.0.2"
