#
# Setup for Windows with cygwin and VC7
#
# Check HEPREP_HOME is set sensibly

if (! $?HEPREP_HOME) then
   echo "HEPREP_HOME has not been set"
   exit
endif

if (! -e "${HEPREP_HOME}/lib/WIN32-VC7/HEPREP.LIB") then
   echo "The HEPREP.LIB file seem to be missing, make sure HEPREP_HOME has been set properly"
   exit
endif

set ARCH=WIN32-VC7
set UPATH=`cygpath -u "${HEPREP_HOME}"`
set DPATH=`cygpath -d "${HEPREP_HOME}"`

setenv PATH "${UPATH}/bin/${ARCH}:${UPATH}/lib/${ARCH}:${PATH}"

setenv HEPREP_INCLUDES "-I${DPATH}/include"
setenv HEPREP_LIBS "/libpath:${DPATH}\lib\${ARCH} HEPREP.lib ZIPIOS.lib ZLIB.lib"
setenv HEPREP_VERSION "2.0.2"
