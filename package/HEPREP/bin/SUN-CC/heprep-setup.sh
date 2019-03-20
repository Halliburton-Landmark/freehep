#
# Setup for Solaris using sh
#
# Check HEPREP_HOME is set sensibly

if ! test -e "${HEPREP_HOME}/lib/SUN-CC/libHEPREP.a"
then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   return
fi

export PATH="${HEPREP_HOME}/bin/SUN-CC:${PATH}"

export LD_LIBRARY_PATH="${HEPREP_HOME}/lib/SUN-CC:${LD_LIBRARY_PATH}"

export HEPREP_INCLUDES=-I${HEPREP_HOME}/include
export HEPREP_LIBS="-L${HEPREP_HOME}/lib/SUN-CC -lHEPREP -lZIPIOS -lZLIB"
export HEPREP_VERSION="2.0.2"
