#
# Setup for Windows with cygwin and g++
#
# Check HEPREP_HOME is set sensibly

if ! test -e "${HEPREP_HOME}/lib/WIN32-g++/libHEPREP.a"
then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   return
fi

ARCH=WIN32-g++
UPATH=`cygpath -u "${HEPREP_HOME}"`
DPATH=`cygpath -d "${HEPREP_HOME}"`

export PATH="${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}"

export HEPREP_INCLUDES=-I${UPATH}/include
export HEPREP_LIBS="-L${UPATH}/lib/${ARCH} -lHEPREP -lZIPIOS -lZLIB"
export HEPREP_VERSION="2.0.2"
