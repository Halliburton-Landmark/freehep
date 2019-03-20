package hep.aida.ref.plotter;

import hep.aida.IAxisStyle;
import hep.aida.IBoxStyle;
import hep.aida.IDataStyle;
import hep.aida.IGridStyle;
import hep.aida.IInfoStyle;
import hep.aida.ILegendBoxStyle;
import hep.aida.IPlotterStyle;
import hep.aida.IStatisticsBoxStyle;
import hep.aida.ITitleStyle;
import hep.aida.ref.plotter.BaseStyle;

/**
 *
 * @author The AIDA team @ SLAC.
 *
 */
public class PlotterStyle extends BaseStyle implements IPlotterStyle {
    
    PlotterStyle() {
        super();
    }
    
    PlotterStyle( PlotterStyle style ) {
        super( style );
    }
    
    protected void initializeBaseStyle() {
        setDataStyle( new DataStyle() );
        setInfoStyle( new InfoStyle() );
        setTitleStyle( new TitleStyle() );
        setAxisStyleX( new AxisStyle() );
        setAxisStyleY( new AxisStyle() );
        setAxisStyleZ( new AxisStyle() );
        setLegendBoxStyle( new LegendBoxStyle() );
        setStatisticsBoxStyle( new StatisticsBoxStyle() );
        setGridStyle( new GridStyle() );
        setRegionBoxStyle( new BoxStyle() );
        setDataBoxStyle( new BoxStyle() );
                
        String[] hist2dStyle = {"box", "ellipse", "colorMap"};
        addParameter( new StringStyleParameter("hist2DStyle", null, hist2dStyle) );
        addParameter( new BooleanStyleParameter("showAsScatterPlot",true ) );
    }
    
    
    public boolean setParameter(String parName) {
        if ( setIfObsolete(parName,null) )
            return false;
        return super.setParameter(parName);
    }
    
    public boolean setParameter(String parName, String parValue) {
        if ( setIfObsolete(parName,parValue) )
            return false;
        return super.setParameter(parName, parValue);
    }
    
    public String parameterValue(String parameterName) {
        return getIfObsolete(parameterName);
    }    

    private boolean setIfObsolete(String parName, String value) {
        
        if ( parName.toLowerCase().equals("showstatisticsbox") ) {
            System.err.println("Parameter showStatisticsBox is deprecated. The following method has been invoked instead statisticsBoxStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                statisticsBoxStyle().setVisible(Boolean.valueOf(value).booleanValue());
            return true;
        }
        
        
        
        if ( parName.toLowerCase().equals("showlegend") ) {
            System.err.println("Parameter showLegend is deprecated. The following method has been invoked instead legendBoxStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                legendBoxStyle().setVisible(Boolean.valueOf(value).booleanValue());
            return true;
        }
        
        if ( parName.toLowerCase().equals("legendfont") ) {
            System.err.println("Parameter legendFont is deprecated. The following method has been invoked instead legendBoxStyle().textStyle().setFont(...);. Please update your code.");
            if ( value != null )
                legendBoxStyle().textStyle().setFont(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("legendfontsize") ) {
            System.err.println("Parameter legendFontSize is deprecated. The following method has been invoked instead legendBoxStyle().textStyle().setFontSize(...);. Please update your code.");
            if ( value != null )
                legendBoxStyle().textStyle().setFontSize(Double.parseDouble(value));
            return true;
        }
        
        if ( parName.toLowerCase().equals("legendfontstyle") ) {
            System.err.println("Parameter legendFontStyle is deprecated. A combination of the following methods have been invoked instead: legendBoxStyle().textStyle().setBold(...) legendBoxStyle().textStyle().setItalic(...). Please update your code.");
            
            if ( value != null ) {
                if ( value.equals("1") || value.equals("bold") ) {
                    legendBoxStyle().textStyle().setBold(true);
                    legendBoxStyle().textStyle().setItalic(false);
                } else if ( value.equals("2") || value.equals("italic") ) {
                    legendBoxStyle().textStyle().setBold(false);
                    legendBoxStyle().textStyle().setItalic(true);
                } else if ( value.equals("3") || value.equals("boldItalic") ) {
                    legendBoxStyle().textStyle().setBold(true);
                    legendBoxStyle().textStyle().setItalic(true);
                } else {
                    legendBoxStyle().textStyle().setBold(false);
                    legendBoxStyle().textStyle().setItalic(false);
                }
            }
            return true;
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfont") ) {
            System.err.println("Parameter statisticsBoxFont is deprecated. The following method has been invoked instead statisticsBoxStyle().textStyle().setFont(...);. Please update your code.");
            if ( value != null )
                statisticsBoxStyle().textStyle().setFont(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfontsize") ) {
            System.err.println("Parameter statisticsBoxFontSize is deprecated. The following method has been invoked instead statisticsBoxStyle().textStyle().setFontSize(...);. Please update your code.");
            if ( value != null )
                statisticsBoxStyle().textStyle().setFontSize(Double.parseDouble(value));
            return true;
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfontstyle") ) {
            System.err.println("Parameter statisticsBoxFontStyle is deprecated. A combination of the following methods have been invoked instead: statisticsBoxStyle().textStyle().setBold(...) statisticsBoxStyle().textStyle().setItalic(...). Please update your code.");
            
            if ( value != null ) {
                if ( value.equals("1") || value.equals("bold") ) {
                    statisticsBoxStyle().textStyle().setBold(true);
                    statisticsBoxStyle().textStyle().setItalic(false);
                } else if ( value.equals("2") || value.equals("italic") ) {
                    statisticsBoxStyle().textStyle().setBold(false);
                    statisticsBoxStyle().textStyle().setItalic(true);
                } else if ( value.equals("3") || value.equals("boldItalic") ) {
                    statisticsBoxStyle().textStyle().setBold(true);
                    statisticsBoxStyle().textStyle().setItalic(true);
                } else {
                    statisticsBoxStyle().textStyle().setBold(false);
                    statisticsBoxStyle().textStyle().setItalic(false);
                }
            }
            return true;
        }
        
        if ( parName.toLowerCase().equals("backgroundcolor") ) {
            System.err.println("Parameter backgroundColor is deprecated. The following method has been invoked instead regionBoxStyle().backgroundStyle().setColor(...);. Please update your code.");
            if ( value != null )
                regionBoxStyle().backgroundStyle().setColor(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("foregroundcolor") ) {
            System.err.println("Parameter foregroundColor is deprecated. The following method has been invoked instead regionBoxStyle().foregroundStyle().setColor(...);. Please update your code.");
            if ( value != null )
                regionBoxStyle().foregroundStyle().setColor(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("dataareacolor") ) {
            System.err.println("Parameter dataAreaColor is deprecated. The following method has been invoked instead dataBoxStyle().backgroundStyle().setColor(...);. Please update your code.");
            if ( value != null )
                dataBoxStyle().backgroundStyle().setColor(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("dataareabordertype") ) {
            System.err.println("Parameter dataAreaBorderType is deprecated. The following method has been invoked instead dataBoxStyle().borderStyle().setBorderType(...);. Please update your code.");
            if ( value != null )
                dataBoxStyle().borderStyle().setBorderType(value);
            return true;
        }
        
        if ( parName.toLowerCase().equals("showtitle") ) {
            System.err.println("Parameter showTitle is deprecated. The following method has been invoked instead titleStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                titleStyle().setVisible(Boolean.valueOf(value).booleanValue());
            return true;
        }
        
        return false;
    }
    
    private String getIfObsolete(String parName) {
        
        if ( parName.toLowerCase().equals("showstatisticsbox") ) {
            System.err.println("Parameter showStatisticsBox is deprecated. The following method has been invoked instead statisticsBoxStyle().isVisible();. Please update your code.");
            return String.valueOf(statisticsBoxStyle().isVisible());
        }
        
        if ( parName.toLowerCase().equals("showlegend") ) {
            System.err.println("Parameter showLegend is deprecated. The following method has been invoked instead legendBoxStyle().isVisible();. Please update your code.");
            return String.valueOf(legendBoxStyle().isVisible());
        }
        
        if ( parName.toLowerCase().equals("legendfont") ) {
            System.err.println("Parameter legendFont is deprecated. The following method has been invoked instead legendBoxStyle().textStyle().font();. Please update your code.");
            return legendBoxStyle().textStyle().font();
        }
        
        if ( parName.toLowerCase().equals("legendfontsize") ) {
            System.err.println("Parameter legendFontSize is deprecated. The following method has been invoked instead legendBoxStyle().textStyle().fontSize();. Please update your code.");
            return String.valueOf(legendBoxStyle().textStyle().fontSize());
        }
        
        if ( parName.toLowerCase().equals("legendfontstyle") ) {
            System.err.println("Parameter legendFontStyle is deprecated. A combination of the following methods have been invoked instead: legendBoxStyle().textStyle().isBold() legendBoxStyle().textStyle().isItalic(). Please update your code.");
            boolean isItalic = legendBoxStyle().textStyle().isItalic();
            boolean isBold = legendBoxStyle().textStyle().isBold();
            if ( isBold && ! isItalic )
                return "bold";
            if ( ! isBold && isItalic )
                return "italic";
            if ( isBold && isItalic )
                return "boldItalic";
            return "plain";
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfont") ) {
            System.err.println("Parameter statisticsBoxFont is deprecated. The following method has been invoked instead statisticsBoxStyle().textStyle().font();. Please update your code.");
            return statisticsBoxStyle().textStyle().font();
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfontsize") ) {
            System.err.println("Parameter statisticsBoxFontSize is deprecated. The following method has been invoked instead statisticsBoxStyle().textStyle().fontSize();. Please update your code.");
            return String.valueOf(statisticsBoxStyle().textStyle().fontSize());
        }
        
        if ( parName.toLowerCase().equals("statisticsboxfontstyle") ) {
            System.err.println("Parameter statisticsBoxFontStyle is deprecated. A combination of the following methods have been invoked instead: statisticsBoxStyle().textStyle().isBold() statisticsBoxStyle().textStyle().isItalic(). Please update your code.");
            boolean isItalic = statisticsBoxStyle().textStyle().isItalic();
            boolean isBold = statisticsBoxStyle().textStyle().isBold();
            if ( isBold && ! isItalic )
                return "bold";
            if ( ! isBold && isItalic )
                return "italic";
            if ( isBold && isItalic )
                return "boldItalic";
            return "plain";
        }
        
        if ( parName.toLowerCase().equals("backgroundcolor") ) {
            System.err.println("Parameter backgroundColor is deprecated. The following method has been invoked instead regionBoxStyle().backgroundStyle().color();. Please update your code.");
            return regionBoxStyle().backgroundStyle().color();
        }
        
        if ( parName.toLowerCase().equals("foregroundcolor") ) {
            System.err.println("Parameter foregroundColor is deprecated. The following method has been invoked instead regionBoxStyle().foregroundStyle().color();. Please update your code.");
            return regionBoxStyle().foregroundStyle().color();
        }
        
        if ( parName.toLowerCase().equals("dataareacolor") ) {
            System.err.println("Parameter dataAreaColor is deprecated. The following method has been invoked instead dataBoxStyle().backgroundStyle().color();. Please update your code.");
            return dataBoxStyle().backgroundStyle().color();
        }
        
        if ( parName.toLowerCase().equals("dataareabordertype") ) {
            System.err.println("Parameter dataAreaBorderType is deprecated. The following method has been invoked instead dataBoxStyle().borderStyle().borderType();. Please update your code.");
            return dataBoxStyle().borderStyle().borderType();
        }
        
        if ( parName.toLowerCase().equals("showtitle") ) {
            System.err.println("Parameter showTitle is deprecated. The following method has been invoked instead titleStyle().isVisible();. Please update your code.");
            return String.valueOf(titleStyle().isVisible());
        }
        
        return super.parameterValue(parName);
    }
    
    
    public IDataStyle dataStyle() {
        return (IDataStyle) child(Style.PLOTTER_DATA_STYLE);
    }
    
    /**
     * @deprecated
     */
    public IInfoStyle infoStyle() {
        return (IInfoStyle) child(Style.PLOTTER_INFO_STYLE);
    }
    
    public ITitleStyle titleStyle() {
        return (ITitleStyle) child(Style.PLOTTER_TITLE_STYLE);
    }
    
    public IAxisStyle xAxisStyle() {
        return (IAxisStyle) child(Style.PLOTTER_XAXIS_STYLE);
    }
    
    public IAxisStyle yAxisStyle() {
        return (IAxisStyle) child(Style.PLOTTER_YAXIS_STYLE);
    }
    
    public IAxisStyle zAxisStyle() {
        return (IAxisStyle) child(Style.PLOTTER_ZAXIS_STYLE);
    }
    
    public ILegendBoxStyle legendBoxStyle() {
        return (ILegendBoxStyle) child(Style.PLOTTER_LEGEND_BOX_STYLE);
    }
    
    public IStatisticsBoxStyle statisticsBoxStyle() {
        return (IStatisticsBoxStyle) child(Style.PLOTTER_STATISTICS_BOX_STYLE);
    }
    
    public IGridStyle gridStyle() {
        return (IGridStyle) child(Style.PLOTTER_GRID_STYLE);
    }
    
    public IBoxStyle regionBoxStyle() {
        return (IBoxStyle) child(Style.PLOTTER_REGION_BOX_STYLE);
    }
    
    public IBoxStyle dataBoxStyle() {
        return (IBoxStyle) child(Style.PLOTTER_DATA_BOX_STYLE);
    }
    
    public boolean setAxisStyleX(IAxisStyle xAxisStyle) {
        return addBaseStyle( xAxisStyle, Style.PLOTTER_XAXIS_STYLE );
    }
    
    public boolean setAxisStyleY(IAxisStyle yAxisStyle) {
        return addBaseStyle( yAxisStyle, Style.PLOTTER_YAXIS_STYLE );
    }
    
    public boolean setAxisStyleZ(IAxisStyle zAxisStyle) {
        return addBaseStyle( zAxisStyle, Style.PLOTTER_ZAXIS_STYLE );
    }
    
    public boolean setDataStyle(IDataStyle dataStyle) {
        return addBaseStyle( dataStyle, Style.PLOTTER_DATA_STYLE );
    }
    
    public boolean setInfoStyle(IInfoStyle infoStyle) {
        return addBaseStyle( infoStyle, Style.PLOTTER_INFO_STYLE );
    }
    
    public boolean setTitleStyle(ITitleStyle titleStyle) {
        return addBaseStyle( titleStyle, Style.PLOTTER_TITLE_STYLE );
    }
    
    public boolean setLegendBoxStyle(ILegendBoxStyle legendBoxStyle) {
        return addBaseStyle( legendBoxStyle, Style.PLOTTER_LEGEND_BOX_STYLE );
    }
    
    public boolean setStatisticsBoxStyle(IStatisticsBoxStyle statisticsBoxStyle) {
        return addBaseStyle( statisticsBoxStyle, Style.PLOTTER_STATISTICS_BOX_STYLE );
    }
    
    public boolean setGridStyle(IGridStyle gridStyle) {
        return addBaseStyle( gridStyle, Style.PLOTTER_GRID_STYLE );
    }
    
    public boolean setRegionBoxStyle(IBoxStyle regionBoxStyle) {
        return addBaseStyle( regionBoxStyle, Style.PLOTTER_REGION_BOX_STYLE );
    }
    
    public boolean setDataBoxStyle(IBoxStyle dataBoxStyle) {
        return addBaseStyle( dataBoxStyle, Style.PLOTTER_DATA_BOX_STYLE );
    }
    
}
