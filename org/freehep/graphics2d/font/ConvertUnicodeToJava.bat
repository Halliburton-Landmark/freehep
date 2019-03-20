REM
REM Converts all unicode.txt files into their Java tables
REM
REM Author M.Donszelmann

setlocal
set CLASSPATH=%FREEHEP%
java org.freehep.graphics2d.font.CharTableConverter expert.unicode.txt
java org.freehep.graphics2d.font.CharTableConverter symbol.unicode.txt
java org.freehep.graphics2d.font.CharTableConverter zapfdingbats.unicode.txt
java org.freehep.graphics2d.font.CharTableConverter latin.unicode.txt ISO
java org.freehep.graphics2d.font.CharTableConverter latin.unicode.txt MAC
java org.freehep.graphics2d.font.CharTableConverter latin.unicode.txt WIN
java org.freehep.graphics2d.font.CharTableConverter latin.unicode.txt PDF
java org.freehep.graphics2d.font.CharTableConverter latin.unicode.txt STD
