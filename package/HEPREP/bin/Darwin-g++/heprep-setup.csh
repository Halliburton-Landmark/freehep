#
# Setup for Darwin with csh
#
# Check HEPREP_HOME is set sensibly

if (! $?HEPREP_HOME) then
   echo "HEPREP_HOME has not been set"
   exit
endif

if (! -e "${HEPREP_HOME}/lib/Darwin-g++/libHEPREP.a") then
   echo "The libHEPREP.a file seem to be missing, make sure HEPREP_HOME has been set properly"
   exit
endif

if (-e "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.csh") then
   source "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.csh"
   /bin/rm "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.csh" 
   /bin/rm "${HEPREP_HOME}/bin/Darwin-g++/HEPREP-install.sh" 
endif

if (! $?PATH) then
   setenv PATH ""
endif
setenv PATH "${HEPREP_HOME}/bin/Darwin-g++:${PATH}"

if (! $?DYLD_LIBRARY_PATH) then
   setenv DYLD_LIBRARY_PATH ""
endif
setenv DYLD_LIBRARY_PATH "${HEPREP_HOME}/lib/Darwin-g++:${DYLD_LIBRARY_PATH}"

setenv HEPREP_INCLUDES -I${HEPREP_HOME}/include
setenv HEPREP_LIBS "-L${HEPREP_HOME}/lib/Darwin-g++ -lHEPREP -lZIPIOS -lZLIB"
setenv HEPREP_VERSION "2.0.2"
