#
# Setup for Windows with cygwin and g++
#
# Check HEPREP_HOME is set sensibly

if (! $?HEPREP_HOME) then
   echo "HEPREP_HOME has not been set"
   exit
endif

if (! -e "${HEPREP_HOME}/lib/WIN32-g++/libHEPREP.a") then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   exit
endif

set ARCH=WIN32-g++
set UPATH=`cygpath -u "${HEPREP_HOME}"`
set DPATH=`cygpath -d "${HEPREP_HOME}"`

setenv PATH "${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}"

setenv HEPREP_INCLUDES "-I${UPATH}/include"
setenv HEPREP_LIBS "-L${UPATH}/lib/$ARCH -lHEPREP -lZIPIOS -lZLIB"
setenv HEPREP_VERSION "2.0.2"
