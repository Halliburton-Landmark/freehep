setlocal
set LIB=%FREEHEP%\lib
java -classpath "%LIB%\freehep-base.jar;%LIB%\freehep-tools.jar;%LIB%\velocity.jar;%LIB%\servlet.zip;%LIB%\commons-collections.jar;%LIB%\logkit.jar" org.freehep.tools.WebPage %*
