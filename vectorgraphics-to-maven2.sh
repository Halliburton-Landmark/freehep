#!/bin/sh
URL="scpexe://svn.freehep.org/nfs/slac/g/jas/maven2"
VERSION=1.2.3

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphics2d \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphics2d.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-cgm \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-cgm.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-emf \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-emf.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-gif \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-gif.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-java \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-java.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-pdf \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-pdf.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-ps \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-ps.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-svg \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-svg.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-swf \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-swf.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-latex \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-latex.jar

mvn deploy:deploy-file \
    -DgeneratePom \
    -DuniqueVersion=false \
    -Durl=${URL} \
    -DrepositoryId=freehep-maven-deploy \
    -DgroupId=org.freehep \
    -DartifactId=freehep-graphicsio-ppm \
    -Dversion=${VERSION} \
    -Dpackaging=jar \
    -Dfile=lib/freehep-graphicsio-ppm.jar
 
