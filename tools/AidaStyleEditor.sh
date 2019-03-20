#!/bin/sh

CP=$FREEHEP/lib/aida.jar:$FREEHEP/lib/aida-dev.jar:$FREEHEP/lib/freehep-hep.jar:$FREEHEP/lib/freehep-base.jar:$FREEHEP/lib/jas-plotter.jar:$FREEHEP/lib/l2fprod-common-all.jar 

java -classpath $CP hep.aida.ref.plotter.styleEditor.AidaStyleEditor

