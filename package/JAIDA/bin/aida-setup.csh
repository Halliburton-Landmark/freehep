#
# Setup for Unix (Linux, Solaris, MacOS X, Windows-Cygwin) using csh
#

# Check JAIDA_HOME is set sensibly

if (! $?JAIDA_HOME) then
   echo "JAIDA_HOME has not been set"
   exit
endif


# Unix or Cygwin

switch(`uname`)
case CYGWIN*:
    set CLASSPATHSEP=';'
    set UJAIDA_HOME=`cygpath -u ${JAIDA_HOME}`
    set MJAIDA_HOME=`cygpath -m ${JAIDA_HOME}`
    breaksw
default:
    set CLASSPATHSEP=':'
    set UJAIDA_HOME="${JAIDA_HOME}"
    set MJAIDA_HOME="${JAIDA_HOME}"
    breaksw
endsw

if (! -e "${UJAIDA_HOME}/lib/aida.jar") then
   echo "The AIDA.jar files seem to be missing, make sure JAIDA_HOME has been set properly"
   exit
endif

set JAIDAJARS="aida aida-dev bcel freehep-base freehep-hep jas-plotter jel openide-lookup optimizers"

if (! $?CLASSPATH) then
   setenv CLASSPATH ""
endif

foreach jar (${JAIDAJARS})
   setenv CLASSPATH "${MJAIDA_HOME}/lib/${jar}.jar${CLASSPATHSEP}${CLASSPATH}"
end

end:

