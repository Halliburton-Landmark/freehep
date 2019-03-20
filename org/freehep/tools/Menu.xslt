<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance">
   <xsl:param name="baseURL" select="''"/>
   <xsl:param name="selected" select="''"/>
   <xsl:param name="isOffline" select="''"/>
   <xsl:param name="showFullMenu" select="''"/>
   <xsl:output method="html"/>
   <xsl:template match="/MenuList">
   <html>
   <head>
   <title>Test</title>
   <link rel="stylesheet" type="text/css" href="WebPage.css"/>
   </head>
   <body>

      <div class="menu">
      <ul>
      <xsl:for-each select="Menu[count(MenuItem[@href and (@enabled!=true())])!=0]">
         <li>
	        <span class="head">
	        <xsl:value-of select="translate(@name,' ','&#160;')"/>
	        </span>
         <ul>
	     <xsl:for-each select="MenuItem[@enabled!=true()]">
	        <xsl:if test="@href">
    	        <xsl:element name="li">
                 <xsl:element name="a">
                   <xsl:attribute name="href">
                      <xsl:if test="not(starts-with(@href,'/')) and not(contains(@href,'//'))">
                        <xsl:value-of select="$baseURL"/>
                      </xsl:if>
                      <xsl:value-of select="@href"/>
                   </xsl:attribute>
                   <xsl:element name="span">
    	              <xsl:if test="@href=$selected"><xsl:attribute name="class">sel</xsl:attribute></xsl:if>
    	              <xsl:value-of select="translate(@name,' ','&#160;')"/>
    	           </xsl:element>
	             </xsl:element>
                </xsl:element>
	        </xsl:if>
	        <xsl:if test="not(@href) and (false())">
	            <xsl:element name="li">
                 <xsl:element name="span">
    	            <xsl:value-of select="translate(@name,' ','&#160;')"/>
    	         </xsl:element>
                </xsl:element>
	        </xsl:if>
         </xsl:for-each>
      </ul>
      </li>
      </xsl:for-each>
  </ul>
  </div>
  </body>
  </html>
  </xsl:template>
</xsl:stylesheet>

