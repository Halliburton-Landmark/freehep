#
# Setup for Windows with cygwin and VC7
#
# Check HEPREP_HOME is set sensibly

if ! test -e "${HEPREP_HOME}/lib/WIN32-VC7/HEPREP.LIB"
then
   echo "The HEPREP.LIB file seem to be missing, make sure HEPREP_HOME has been set properly"
   return
fi

ARCH=WIN32-VC7
UPATH=`cygpath -u "${HEPREP_HOME}"`
DPATH=`cygpath -d "${HEPREP_HOME}"`

export PATH="${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}"

export HEPREP_INCLUDES=-I${DPATH}\\include
export HEPREP_LIBS="/libpath:${DPATH}\\lib\\${ARCH} HEPREP.lib ZIPIOS.lib ZLIB.lib"
export HEPREP_VERSION="2.0.2"
