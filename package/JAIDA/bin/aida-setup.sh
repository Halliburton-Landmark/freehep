#
# Setup for Unix (Linux, Solaris, MacOS X, Windows-Cygwin) using sh
#

# check for JAIDA_HOME
if test ! "${JAIDA_HOME:+x}"
then
    echo "JAIDA_HOME environment variable not set!"
    return
fi

# Unix or Cygwin

case `uname` in
CYGWIN*)
        CLASSPATHSEP=';'
        UJAIDA_HOME=`cygpath -u ${JAIDA_HOME}`
        MJAIDA_HOME=`cygpath -m ${JAIDA_HOME}`
        ;;
*)
        CLASSPATHSEP=':'
        UJAIDA_HOME="${JAIDA_HOME}"
        MJAIDA_HOME="${JAIDA_HOME}"
esac


# Check JAIDA_HOME is set sensibly

if ! test -e "${UJAIDA_HOME}/lib/aida.jar"
then
   echo "The AIDA.jar files seem to be missing, make sure JAIDA_HOME has been set properly"
   return
fi

JAIDAJARS="aida aida-dev bcel freehep-base freehep-hep jas-plotter jel openide-lookup optimizers"

for jar in ${JAIDAJARS}; do
  CLASSPATH="${MJAIDA_HOME}/lib/${jar}.jar${CLASSPATHSEP}${CLASSPATH}"
done
export CLASSPATH

