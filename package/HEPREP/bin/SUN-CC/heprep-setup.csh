#
# Setup for Solaris with csh
#
# Check HEPREP_HOME is set sensibly

if (! $?HEPREP_HOME) then
   echo "HEPREP_HOME has not been set"
   exit
endif

if (! -e "${HEPREP_HOME}/lib/SUN-CC/libHEPREP.a") then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   exit
endif

setenv PATH "${HEPREP_HOME}/bin/SUN-CC:${PATH}"

if (! $?LD_LIBRARY_PATH) then
   setenv LD_LIBRARY_PATH ""
endif
setenv LD_LIBRARY_PATH "${HEPREP_HOME}/lib/SUN-CC:${LD_LIBRARY_PATH}"

setenv HEPREP_INCLUDES -I${HEPREP_HOME}/include
setenv HEPREP_LIBS "-L${HEPREP_HOME}/lib/SUN-CC -lHEPREP -lZIPIOS -lZLIB"
setenv HEPREP_VERSION "2.0.2"
