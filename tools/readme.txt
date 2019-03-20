Libraries used when compiling FREEHEP

This directory contains all libraries needed when you COMPILE freehep. Libraries also
used for running should go in the lib directory.


Each library specfies name, version number, description, their origin and use(rs)

(alphabetical)

ant.jar, ant-nodeps.jar, ant-junit.jar
    1.6.0
    Jakarta-ANT: Make for Java
    http://ant.apache.org/
    infrastructure

freehep-buildtools.jar:
    checked out with freehep
    Extensions to Ant and other tools for freehep's building process
    part of freehep

jace.jar, Regexp.jar
    1.1beta3
    JNI made easy
    http://reyelts.dyndns.org:8080/jace/release/docs/index.html
    aidjni, heprepjni

javacc.jar:
    3.2
    Java Parser Generator, tool to generate java lexers and parsers from grammar descriptions
    https://javacc.dev.java.net/
    jaco and aid

j3daudio.jar, j3dcore.jar, j3dutils.jar, vecmath.jar:
    1.3.1 OpenGL (Windows version)
    Java3D, only used here to compile the library. The user of FreeHep needs a platform dependent version of Java3D
    http://www.javasoft.com/products/java-media/3D
    j3d packages

jnlp.jar
    1.2
    Java Web Start library
    http://java.sun.com/products/javawebstart/download-jnlp.html
    application framework

junit.jar
    3.8.1
    Java Unit Testing
    http://www.junit.org/
    infrastructure
