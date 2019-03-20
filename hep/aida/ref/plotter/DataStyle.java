package hep.aida.ref.plotter;

import hep.aida.IPlotterStyle;
import hep.aida.ref.plotter.BaseStyle;

import hep.aida.IFillStyle;
import hep.aida.ILineStyle;
import hep.aida.IMarkerStyle;

import hep.aida.IDataStyle;

import hep.aida.ref.plotter.BaseStyle;

/**
 *
 * @author The AIDA team @ SLAC.
 *
 */
public class DataStyle extends BaseStyle implements IDataStyle {
    
    protected void initializeBaseStyle() {
        setMarkerStyle(new MarkerStyle());
        setLineStyle(new LineStyle());
        setFillStyle(new FillStyle());
        setErrorBarStyle(new LineStyle());
        setOutlineStyle(new LineStyle());

        addParameter( new StringStyleParameter("customOverlay", null) );
        addParameter( new StringStyleParameter(Style.DATA_MODEL, null) );

        String[] profileErrors = {"spread","errorOnMean"};
        addParameter( new StringStyleParameter("profileErrors",profileErrors[0], profileErrors) );

        addParameter( new BooleanStyleParameter( Style.SHOW_DATA_IN_STATISTICS_BOX, true) );
        addParameter( new BooleanStyleParameter( Style.SHOW_DATA_IN_LEGEND_BOX, true) );
        
        // set the defaults:
        ((BaseStyle)outlineStyle()).setParameterDefault(Style.IS_VISIBLE,"false");
        ((BaseStyle)markerStyle()).setParameterDefault(Style.IS_VISIBLE,"false");
        
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
        
        if ( parName.toLowerCase().equals("showhistogrambars") ) {
            System.err.println("Parameter showHistogramBars is deprecated. The following method has been invoked instead lineStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                lineStyle().setVisible( Boolean.valueOf(value).booleanValue() );
            return true;
        }

        if ( parName.toLowerCase().equals("fillhistogrambars") ) {
            System.err.println("Parameter fillHistogramBars is deprecated. The following method has been invoked instead fillStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                fillStyle().setVisible( Boolean.valueOf(value).booleanValue() );
            return true;
        }

        if ( parName.toLowerCase().equals("showdatapoints") ) {
            System.err.println("Parameter showDataPoints is deprecated. The following method has been invoked instead markerStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                markerStyle().setVisible( Boolean.valueOf(value).booleanValue() );
            return true;
        }

        if ( parName.toLowerCase().equals("connectdatapoints") ) {
            System.err.println("Parameter connectDataPoints is deprecated. The following method has been invoked instead outlineStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setVisible( Boolean.valueOf(value).booleanValue() );
            return true;
        }

        if ( parName.toLowerCase().equals("linebetweenpointscolor") ) {
            System.err.println("Parameter lineBetweenPointsColor is deprecated. The following method has been invoked instead outlineStyle().setColor(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setColor(value);
            return true;
        }

        if ( parName.toLowerCase().equals("linebetweenpointstype") ) {
            System.err.println("Parameter lineBetweenPointsType is deprecated. The following method has been invoked instead outlineStyle().setLineType(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setLineType(value);
            return true;
        }

        if ( parName.toLowerCase().equals("linebetweenpointsthickness") ) {
            System.err.println("Parameter lineBetweenPointsThickness is deprecated. The following method has been invoked instead outlineStyle().setThickness(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setThickness(Integer.parseInt(value));
            return true;
        }

        if ( parName.toLowerCase().equals("showerrorbars") ) {
            System.err.println("Parameter showErrorBars is deprecated. The following method has been invoked instead errorBarStyle().setVisible(...);. Please update your code.");
            if ( value != null )
                errorBarStyle().setVisible( Boolean.valueOf(value).booleanValue() );
            return true;
        }

        if ( parName.toLowerCase().equals("errorbarscolor") ) {
            System.err.println("Parameter errorBarsColor is deprecated. The following method has been invoked instead errorBarStyle().setColor(...);. Please update your code.");
            if ( value != null )
                errorBarStyle().setColor(value);
            return true;
        }

        if ( parName.toLowerCase().equals("errorbarslinetype") ) {
            System.err.println("Parameter errorBarsLineType is deprecated. The following method has been invoked instead errorBarStyle().setLineType(...);. Please update your code.");
            if ( value != null )
                errorBarStyle().setLineType(value);
            return true;
        }

        if ( parName.toLowerCase().equals("errorbarslinethickness") ) {
            System.err.println("Parameter errorBarsLineThickness is deprecated. The following method has been invoked instead errorBarStyle().setThickness(...);. Please update your code.");
            if ( value != null )
                errorBarStyle().setThickness(Integer.parseInt(value));
            return true;
        }

        if ( parName.toLowerCase().equals("functionlinecolor") ) {
            System.err.println("Parameter functionLineColor is deprecated. The following method has been invoked instead outlineStyle().setColor(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setColor(value);
            return true;
        }

        if ( parName.toLowerCase().equals("functionlinetype") ) {
            System.err.println("Parameter functionLineType is deprecated. The following method has been invoked instead outlineStyle().setLineType(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setLineType(value);
            return true;
        }

        if ( parName.toLowerCase().equals("functionlinethickness") ) {
            System.err.println("Parameter functionLineThickness is deprecated. The following method has been invoked instead outlineStyle().setThickness(...);. Please update your code.");
            if ( value != null )
                outlineStyle().setThickness(Integer.parseInt(value));
            return true;
        }

        if ( parName.toLowerCase().equals("showstatisticsbox") ) {
            System.err.println("Parameter showStatisticsBox is deprecated. The following method has been invoked instead showInStatisticsBox(...);. Please update your code.");
            if ( value != null )
                showInStatisticsBox(Boolean.valueOf(value).booleanValue());
            return true;
        }

        return false;
    }
    
    private String getIfObsolete(String parName) {
        
        if ( parName.toLowerCase().equals("showhistogrambars") ) {
            System.err.println("Parameter showHistogramBars is deprecated. The following method has been invoked instead lineStyle().isVisible();. Please update your code.");
            return String.valueOf(lineStyle().isVisible());
        }

        if ( parName.toLowerCase().equals("fillhistogrambars") ) {
            System.err.println("Parameter fillHistogramBars is deprecated. The following method has been invoked instead fillStyle().isVisible();. Please update your code.");
            return String.valueOf(fillStyle().isVisible());
        }

        if ( parName.toLowerCase().equals("showdatapoints") ) {
            System.err.println("Parameter showDataPoints is deprecated. The following method has been invoked instead markerStyle().isVisible();. Please update your code.");
            return String.valueOf(markerStyle().isVisible() );
        }

        if ( parName.toLowerCase().equals("connectdatapoints") ) {
            System.err.println("Parameter connectDataPoints is deprecated. The following method has been invoked instead outlineStyle().isVisible();. Please update your code.");
            return String.valueOf(outlineStyle().isVisible());
        }

        if ( parName.toLowerCase().equals("linebetweenpointscolor") ) {
            System.err.println("Parameter lineBetweenPointsColor is deprecated. The following method has been invoked instead outlineStyle().color();. Please update your code.");
            return outlineStyle().color();
        }

        if ( parName.toLowerCase().equals("linebetweenpointstype") ) {
            System.err.println("Parameter lineBetweenPointsType is deprecated. The following method has been invoked instead outlineStyle().lineType();. Please update your code.");
            return outlineStyle().lineType();
        }

        if ( parName.toLowerCase().equals("linebetweenpointsthickness") ) {
            System.err.println("Parameter lineBetweenPointsThickness is deprecated. The following method has been invoked instead outlineStyle().thickness();. Please update your code.");
            return String.valueOf(outlineStyle().thickness());
        }

        if ( parName.toLowerCase().equals("showerrorbars") ) {
            System.err.println("Parameter showErrorBars is deprecated. The following method has been invoked instead errorBarStyle().isVisible();. Please update your code.");
            return String.valueOf(errorBarStyle().isVisible() );
        }

        if ( parName.toLowerCase().equals("errorbarscolor") ) {
            System.err.println("Parameter errorBarsColor is deprecated. The following method has been invoked instead errorBarStyle().color();. Please update your code.");
            return errorBarStyle().color();
        }

        if ( parName.toLowerCase().equals("errorbarslinetype") ) {
            System.err.println("Parameter errorBarsLineType is deprecated. The following method has been invoked instead errorBarStyle().lineType();. Please update your code.");
            return errorBarStyle().lineType();
        }

        if ( parName.toLowerCase().equals("errorbarslinethickness") ) {
            System.err.println("Parameter errorBarsLineThickness is deprecated. The following method has been invoked instead errorBarStyle().thickness();. Please update your code.");
            return String.valueOf(errorBarStyle().thickness());
        }

        if ( parName.toLowerCase().equals("functionlinecolor") ) {
            System.err.println("Parameter functionLineColor is deprecated. The following method has been invoked instead outlineStyle().color();. Please update your code.");
            return outlineStyle().color();
        }

        if ( parName.toLowerCase().equals("functionlinetype") ) {
            System.err.println("Parameter functionLineType is deprecated. The following method has been invoked instead outlineStyle().lineType();. Please update your code.");
            return outlineStyle().lineType();
        }

        if ( parName.toLowerCase().equals("functionlinethickness") ) {
            System.err.println("Parameter functionLineThickness is deprecated. The following method has been invoked instead outlineStyle().thickness();. Please update your code.");
            return String.valueOf(outlineStyle().thickness());
        }

        if ( parName.toLowerCase().equals("showstatisticsbox") ) {
            System.err.println("Parameter showStatisticsBox is deprecated. The following method has been invoked instead isShownInStatisticsBox();. Please update your code.");
            return String.valueOf(isShownInStatisticsBox());
        }

        return super.parameterValue(parName);
    }
    
    public IFillStyle fillStyle() {
        return (IFillStyle) child(Style.DATA_FILL_STYLE);
    }
    
    public ILineStyle lineStyle() {
        return (ILineStyle) child(Style.DATA_LINE_STYLE);
    }
    
    public IMarkerStyle markerStyle() {
        return (IMarkerStyle) child(Style.DATA_MARKER_STYLE);
    }
    
    public ILineStyle errorBarStyle() {
        return (ILineStyle) child(Style.DATA_ERRORBAR_STYLE);
    }
    
    public ILineStyle outlineStyle() {
        return (ILineStyle) child(Style.DATA_OUTLINE_STYLE);
    }

    public boolean setFillStyle(IFillStyle fillStyle) {
        return addBaseStyle( fillStyle,  Style.DATA_FILL_STYLE );
    }
    
    public boolean setLineStyle(ILineStyle lineStyle) {
        return addBaseStyle( lineStyle, Style.DATA_LINE_STYLE );
    }
    
    public boolean setMarkerStyle(IMarkerStyle markerStyle) {
        return addBaseStyle( markerStyle, Style.DATA_MARKER_STYLE );
    }    

    public boolean setErrorBarStyle(ILineStyle errorBarStyle) {
        return addBaseStyle( errorBarStyle, Style.DATA_ERRORBAR_STYLE );
        
    }
    public boolean setOutlineStyle(ILineStyle outlineStyle) {
        return addBaseStyle( outlineStyle, Style.DATA_OUTLINE_STYLE );
    }

    /**
     * Set the model accorting to which the data is represented.
     *
     */
    public boolean setModel(String model) {
        return ( (StringStyleParameter) parameter(Style.DATA_MODEL) ).setValue(model);
    }
    
    public String model() {
        return ( (StringStyleParameter) deepestSetParameter(Style.DATA_MODEL) ).value();
    }

    /**
     * Set if this data is to be represented in the statistics box.
     *
     */
    public void showInStatisticsBox(boolean showInStatisticsBox) {
        ( (BooleanStyleParameter) parameter(Style.SHOW_DATA_IN_STATISTICS_BOX) ).setValue(showInStatisticsBox);
    }
    public boolean isShownInStatisticsBox() {
        return ( (BooleanStyleParameter) deepestSetParameter(Style.SHOW_DATA_IN_STATISTICS_BOX) ).value();
    }        


    /**
     * Set if this data is to be represented in the legend box.
     *
     */
    public void showInLegendBox(boolean showInLegendBox) {
        ( (BooleanStyleParameter) parameter(Style.SHOW_DATA_IN_LEGEND_BOX) ).setValue(showInLegendBox);
    }
    public boolean isShownInLegendBox() {
        return ( (BooleanStyleParameter) deepestSetParameter(Style.SHOW_DATA_IN_LEGEND_BOX) ).value();
    }    
}
