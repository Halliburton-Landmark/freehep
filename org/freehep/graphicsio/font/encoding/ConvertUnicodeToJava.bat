REM
REM Converts all unicode.txt files into their Java tables
REM
REM Author M.Donszelmann

setlocal
set CLASSPATH=%FREEHEP%
java org.freehep.graphicsio.font.encoding.CharTableConverter expert.unicode.txt
java org.freehep.graphicsio.font.encoding.CharTableConverter symbol.unicode.txt
java org.freehep.graphicsio.font.encoding.CharTableConverter zapfdingbats.unicode.txt
java org.freehep.graphicsio.font.encoding.CharTableConverter latin.unicode.txt ISO
java org.freehep.graphicsio.font.encoding.CharTableConverter latin.unicode.txt MAC
java org.freehep.graphicsio.font.encoding.CharTableConverter latin.unicode.txt WIN
java org.freehep.graphicsio.font.encoding.CharTableConverter latin.unicode.txt PDF
java org.freehep.graphicsio.font.encoding.CharTableConverter latin.unicode.txt STD
