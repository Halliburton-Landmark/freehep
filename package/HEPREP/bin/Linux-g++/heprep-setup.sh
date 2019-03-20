#
# Setup for Linux using sh
#
# Check HEPREP_HOME is set sensibly

if ! test -e "${HEPREP_HOME}/lib/Linux-g++/libHEPREP.a"
then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   return
fi

export PATH="${HEPREP_HOME}/bin/Linux-g++:${PATH}"

export LD_LIBRARY_PATH="${HEPREP_HOME}/lib/Linux-g++:${LD_LIBRARY_PATH}"

export HEPREP_INCLUDES=-I${HEPREP_HOME}/include
export HEPREP_LIBS="-L${HEPREP_HOME}/lib/Linux-g++ -lHEPREP -lZIPIOS -lZLIB"
export HEPREP_VERSION="2.0.2"
