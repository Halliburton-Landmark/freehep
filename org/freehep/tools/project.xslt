<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
	<xsl:template match="/">
		<html>
		   <head>
		   <title>Project Status</title>
                   <LINK REL="stylesheet" TYPE="text/css" HREF="stylesheet.css" TITLE="Style"/>
		   </head>
		  <body>
				<xsl:for-each select="PROJECT"><h1>Status: Project <xsl:value-of select="@NAME"/></h1>
                                 <h4>Version: <xsl:value-of select="@VERSION"/></h4>
                                 <table border="1" cellpadding="3" cellspacing="0" width="100%">
                                 <tr bgcolor="#CCCCFF" class="TableHeadingColor">
                                                <th>Jar File</th>
                                                <th>Package </th>
                                                <th>Description</th>
                                                <th>Status</th>
                                  </tr>

					<xsl:for-each select="JAR">
						<xsl:for-each select="PACKAGE">
                                                <tr>
                                                <xsl:if test="position()=1">
                                                  <xsl:element name="th">
			                              <xsl:attribute name="rowspan"><xsl:value-of select="last()"/></xsl:attribute>
			                              <xsl:attribute name="valign">top</xsl:attribute>
                                                      <xsl:value-of select="../@NAME"/>.jar
                                                </xsl:element>
                                                </xsl:if>
								<td valign="top">
								<xsl:element name="a">
								<xsl:attribute name="href"><xsl:value-of select="translate(@NAME,'.','/')"/>/package-summary.html</xsl:attribute>
									<xsl:value-of select="@NAME"/>
							      </xsl:element>
								</td>
								<td valign="top">
									<xsl:value-of select="DESCRIPTION" disable-output-escaping="yes"/>
								</td>
								<td valign="top">
									<xsl:value-of select="STATUS" disable-output-escaping="yes"/>
								</td>
							</tr>
						</xsl:for-each>
					</xsl:for-each>
					</table>
				</xsl:for-each>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
