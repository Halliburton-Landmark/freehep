@SETLOCAL
@SET ANT_HOME=%FREEHEP%\tools
@java -cp "%FREEHEP%\tools\freehep-buildtools.jar;%FREEHEP%\tools\junit.jar;%ANT_HOME%\ant.jar;%ANT_HOME%\ant-nodeps.jar;%ANT_HOME%\ant-junit.jar;%JDK_HOME%\lib\tools.jar" -Dant.home="%ANT_HOME%" %ANT_OPTS% org.apache.tools.ant.Main %*
