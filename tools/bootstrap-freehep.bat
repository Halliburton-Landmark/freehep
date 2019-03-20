setlocal
set CLASSPATH=.;tools\ant.jar;tools\ant-nodeps.jar;tools\ant-junit.jar;%JDK_HOME%\lib\tools.jar;%CLASSPATH%
set OPTIONS=-deprecation
javac %OPTIONS% %FREEHEP%\org\freehep\ant\*.java
javac %OPTIONS% %FREEHEP%\org\freehep\tools\doclet\tags\*.java
javac %OPTIONS% %FREEHEP%\org\freehep\tools\doclet\*.java
javac %OPTIONS% %FREEHEP%\org\freehep\util\io\IndentPrintWriter.java
javac %OPTIONS% %FREEHEP%\org\freehep\xml\util\XMLWriter.java
javac %OPTIONS% %FREEHEP%\org\freehep\xml\util\XMLCharacterProperties.java
javac %OPTIONS% %FREEHEP%\org\freehep\tools\GenerateStatus.java
javac %OPTIONS% %FREEHEP%\org\freehep\tools\TransformStatus.java
jar -cf %FREEHEP%\tools\freehep-buildtools.jar -C %FREEHEP% org\freehep\ant\*.class org\freehep\tools\doclet\*.class org\freehep\tools\doclet\tags\*.class org\freehep\tools\GenerateStatus*.class org\freehep\tools\TransformStatus*.class org\freehep\util\io\IndentPrintWriter.class org\freehep\xml\util\XMLWriter.class org\freehep\xml\util\XMLCharacterProperties.class org\freehep\tools\project.xslt
