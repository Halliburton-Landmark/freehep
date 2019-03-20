setlocal
CPATH = "%PSVIEWER_HOME%/lib/freehep-psviewer.jar"
CPATH = "%CPATH%;%PSVIEWER_HOME%/lib/freehep-graphicsio.jar"
CPATH = "%CPATH%;%PSVIEWER_HOME%/lib/freehep-graphics2d.jar"
CPATH = "%CPATH%;%PSVIEWER_HOME%/lib/freehep-base.jar"
java -classpath "%CPATH" org.freehep.postscript.PSViewer %*
