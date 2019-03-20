/*
 * JASPlotterRegion.java
 *
 * Created on September 27, 2002, 2:21 PM
 */

package hep.aida.ref.plotter;
import hep.aida.*;
import hep.aida.IFillStyle;
import hep.aida.IInfo;
import hep.aida.ILineStyle;
import hep.aida.IMarkerStyle;
import hep.aida.IPlotterStyle;
import hep.aida.ref.AidaUtils;
import hep.aida.ref.function.BaseModelFunction;
import hep.aida.ref.function.RangeSet;
import hep.aida.ref.plotter.FPlotter;
import hep.aida.ref.plotter.Info;
import hep.aida.ref.plotter.StyleListener;
import hep.aida.ref.plotter.adapter.AIDAAdapter;
import hep.aida.ref.plotter.adapter.AIDACloudAdapter1D;
import hep.aida.ref.plotter.adapter.AIDADataPointSetAdapter;
import hep.aida.ref.plotter.adapter.AIDAHistogramAdapter1D;
import hep.aida.ref.plotter.adapter.AIDAProfileAdapter;
import hep.aida.ref.plotter.adapter.CanSetStyle;
import hep.aida.ref.plotter.adapter.CanSetData;
import jas.plot.MovableObject;
import java.awt.Component;
import java.awt.Point;
import java.awt.datatransfer.Clipboard;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.print.PrinterException;
import javax.swing.*;
import jas.hist.*;
import jas.hist.JASHist1DFunctionStyle;
import jas.hist.JASHist1DHistogramStyle;
import jas.hist.JASHistData;
import jas.hist.JASHistScatterPlotStyle;
import jas.hist.JASHistStyle;
import jas.hist.StatisticsBlock;
import jas.plot.EditableLabel;
import jas.plot.Legend;
import jas.plot.Title;
import java.util.*;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.util.ArrayList;
import java.util.List;
import org.freehep.application.Application;
import org.freehep.application.PrintHelper;
import org.freehep.application.studio.Studio;
import org.freehep.swing.ColorConverter;
import org.freehep.swing.popup.HasPopupItems;
import org.freehep.util.export.ExportDialog;
import org.freehep.util.export.VectorGraphicsTransferable;

/**
 * A dummy implementation of PlotterRegion
 * @author tonyj
 * @version $Id: PlotterRegion.java,v 1.65 2006/02/10 22:52:20 serbo Exp $
 */
public class PlotterRegion implements IPlotterRegion {
    
    private static final String[] emptyArray = new String[0];
    private JASHist plot;
    private JPanel panel;
    private ArrayList dataStyleList = new ArrayList();
    private ArrayList dataList = new ArrayList();
    private IPlotterStyle plotterStyle = new PlotterStyle();
    private IPlotterLayout plotterLayout = new PlotterLayout();
    private IInfo info = new Info();
    private List queue = new ArrayList();
    private String regionTitle = null;
    private Map optionsMap;
    
    String[] styleKeys = {"AxisLabel", "AxisScale", "AxisType"};
    String[] stylePars = {Style.AXIS_LABEL, Style.AXIS_SCALE, Style.AXIS_TYPE};
    
    public final int REPLACE = 0;
    public final int OVERLAY = 1;
    public final int ADD = 2;
    public final int STACK = 3;
    
    private int defaultMode = OVERLAY;
    
    private String[] parameters = {"xAxisLowerLimit", "xAxisUpperLimit", "yAxisLowerLimit", "yAxisUpperLimit"};
    
    private IPlotter plotter;
    
    public PlotterRegion(JPanel panel,IPlotter plotter) {
        this.panel = panel;
        panel.setLayout(new BorderLayout());
        panel.setOpaque(false);
        this.plotter = plotter;
    }
    
    public PlotterRegion(IPlotter plotter) {
        this(new JPanel(), plotter);
    }
    
    JPanel getPanel() {
        return panel;
    }
    
    public String[] availableParameterOptions(String str) {
        return emptyArray;
    }
    public String[] availableParameters() {
        return parameters;
    }
    
    public void setParameter(String str) {
    }
    
    public void setParameter(String str, String str1) {
    }
    
    public String parameterValue(String str) {
        if ( str.equals( parameters[0] ) )
            return String.valueOf( getPlot().getXAxis().getMin() );
        if ( str.equals( parameters[1] ) )
            return String.valueOf( getPlot().getXAxis().getMax() );
        if ( str.equals( parameters[2] ) )
            return String.valueOf( getPlot().getYAxis().getMin() );
        if ( str.equals( parameters[3] ) )
            return String.valueOf( getPlot().getYAxis().getMax() );
        
        return null;
    }
    
    public IPlotterStyle style() {
        return plotterStyle;
    }
    
    public void setStyle(IPlotterStyle style) {
        for ( int i = 0; i < dataStyleList.size(); i ++ )
            ( ( DataStyleEntry ) dataStyleList.get( i ) ).cleanUp();
        ((BaseStyle) style).setParent( ( (BaseStyle)plotterStyle ).parent() );
        this.plotterStyle = style;
        for ( int i = 0; i < dataStyleList.size(); i ++ )
            ( (BaseStyle) plotterStyle ).addStyleListener( ( DataStyleEntry ) dataStyleList.get( i ) );
    }
    
    public void applyStyle(IPlotterStyle style) {
        setStyle( style );
        for ( int i = 0; i < dataStyleList.size(); i++ )
            invokeOnSwingThread( (DataStyleEntry) dataStyleList.get( i ) );
    }
    
    public void setTitle(String title) {
        invokeOnSwingThread(new TitleChanged(title));
    }
    
    public String title() {
        return regionTitle;
    }
    
    public void setXLimits() throws java.lang.IllegalArgumentException {
        setXLimits(Double.NaN, Double.NaN);
    }
    
    public void setXLimits(double min) {
        setXLimits(min, Double.NaN);
    }
    
    public void setXLimits(double min, double max) throws java.lang.IllegalArgumentException {
        Runnable run = new LimitsChanged(LimitsChanged.XAXIS,min,max);
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            addToQueue( run );
        else
            invokeOnSwingThread(run);
    }
    
    public void setYLimits() throws java.lang.IllegalArgumentException {
        setYLimits(Double.NaN, Double.NaN);
    }
    
    public void setYLimits(double min) {
        setYLimits(min, Double.NaN);
    }
    
    public void setYLimits(double min, double max) throws java.lang.IllegalArgumentException {
        Runnable run = new LimitsChanged(LimitsChanged.YAXIS,min,max);
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            addToQueue( run );
        else
            invokeOnSwingThread(run);
    }
    
    public void setZLimits() throws java.lang.IllegalArgumentException {
        setZLimits(Double.NaN, Double.NaN);
    }
    
    public void setZLimits(double min) {
        setZLimits(min, Double.NaN);
    }
    
    public void setZLimits(double min, double max) throws java.lang.IllegalArgumentException {
        Runnable run = new LimitsChanged(LimitsChanged.ZAXIS,min,max);
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            addToQueue( run );
        else
            invokeOnSwingThread(run);
    }
    
    /**
     * Get the min limit of x.
     */
    public double xLimitMin() {
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            throw new RuntimeException("No plot available");
        return getPlot().getXAxis().getMin();
    }
    
    /**
     * Get the max limit of x.
     */
    public double xLimitMax() {
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            throw new RuntimeException("No plot available");
        return getPlot().getXAxis().getMax();
    }
    
    /**
     * Get the min limit of y.
     */
    public double yLimitMin() {
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            throw new RuntimeException("No plot available");
        return getPlot().getYAxis().getMin();
    }
    
    /**
     * Get the max limit of y.
     */
    public double yLimitMax() {
        if ( getPlot() == null || getPlot().getNumberOfDataSources() == 0 )
            throw new RuntimeException("No plot available");
        return getPlot().getYAxis().getMax();
    }
    
    /**
     * Get the min limit of z.
     */
    public double zLimitMin() {
        throw new UnsupportedOperationException();
    }
    
    /**
     * Get the max limit of z.
     */
    public double zLimitMax() {
        throw new UnsupportedOperationException();
    }
    
    
    
    private synchronized void addToQueue( Runnable run ) {
        if ( queue == null ) queue = new ArrayList();
        queue.add( run );
    }
    
    public IInfo info() {
        return info;
    }
    
    public void setInfo(IInfo info) {
        this.info = info;
    }
    
    public void clear() {
        invokeOnSwingThread(new ClearRegion());
    }
    
    public void plot(IPlottable plottable) throws IllegalArgumentException {
        invokeOnSwingThread(new AddRemove(true,this,plottable));
    }
    
    public void plot(IPlottable plottable, String options) throws IllegalArgumentException {
        invokeOnSwingThread(new AddRemove(true,this,plottable, null, options));
    }
    
    public void plot(IPlottable plottable, IPlotterStyle style) throws IllegalArgumentException {
        invokeOnSwingThread(new AddRemove(true,this,plottable,style));
    }
    
    public void plot(IPlottable plottable, IPlotterStyle style, String options) throws IllegalArgumentException {
        invokeOnSwingThread(new AddRemove(true,this,plottable,style, options));
    }
    
    public void plot(IBaseHistogram iBaseHistogram) {
        invokeOnSwingThread(new AddRemove(true,this,iBaseHistogram));
    }
    public void plot(IBaseHistogram iBaseHistogram, IPlotterStyle style) {
        invokeOnSwingThread(new AddRemove(true,this,iBaseHistogram,style));
    }
    public void plot(IBaseHistogram iBaseHistogram, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iBaseHistogram, null, options));
    }
    public void plot(IBaseHistogram iBaseHistogram, IPlotterStyle style, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iBaseHistogram,style, options));
    }
    public void plot(IDataPointSet iDataPointSet) {
        invokeOnSwingThread(new AddRemove(true,this,iDataPointSet));
    }
    public void plot(IDataPointSet iDataPointSet, IPlotterStyle style) {
        invokeOnSwingThread(new AddRemove(true,this,iDataPointSet,style));
    }
    public void plot(IDataPointSet iDataPointSet, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iDataPointSet,null, options));
    }
    public void plot(IDataPointSet iDataPointSet, IPlotterStyle style, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iDataPointSet,style,options));
    }
    public void plot(IFunction iFunction) {
        invokeOnSwingThread(new AddRemove(true,this,iFunction));
    }
    public void plot(IFunction iFunction, IPlotterStyle style) {
        invokeOnSwingThread(new AddRemove(true,this,iFunction, style));
    }
    public void plot(IFunction iFunction, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iFunction,null,options));
    }
    public void plot(IFunction iFunction, IPlotterStyle style, String options) {
        invokeOnSwingThread(new AddRemove(true,this,iFunction, style,options));
    }
    public void remove(IDataPointSet iDataPointSet) {
        invokeOnSwingThread(new AddRemove(false,this,iDataPointSet));
    }
    
    public void remove(IFunction iFunction) {
        invokeOnSwingThread(new AddRemove(false,this,iFunction));
    }
    
    public void remove(IBaseHistogram iBaseHistogram) {
        invokeOnSwingThread(new AddRemove(false,this,iBaseHistogram));
    }
    
    public void remove(IPlottable plottable) throws IllegalArgumentException {
        invokeOnSwingThread(new AddRemove(false,this,plottable));
    }
    
    public void setPlot( JASHist plot ) {
        this.plot = plot;
    }
    
    public JASHist getPlot() {
        return plot;
    }
    
    public void setLayout(hep.aida.IPlotterLayout iPlotterLayout) {
        this.plotterLayout = iPlotterLayout;
    }
    
    public hep.aida.IPlotterLayout layout() {
        return plotterLayout;
    }
    
    public void add(Object thing, IPlotterStyle style, int mode) {
        add( thing, style, mode, thing, null );
    }
    
    public void add(Object thing, IPlotterStyle style, String options) {
        int mode = getMode(options);
        add( thing, style, mode, thing, options );
    }
    
    
    public void add(Object thing, IPlotterStyle style, int mode, String options) {
        add( thing, style, mode, thing, options );
    }
    
    public void add(Object thing, IPlotterStyle style, int mode, Object data) {
        add(thing, style, mode, data, null);
    }
    
    public void add(Object thing, IPlotterStyle style, int mode, Object data, String options) {
        if (mode != REPLACE && mode != OVERLAY) throw new UnsupportedOperationException();
        if (mode != OVERLAY && getPlot() != null && getPlot().getNumberOfDataSources() > 0 )
            removeAllObjectsFromRegion();
        
        if (getPlot() == null) createPlot();
        
        DataSource ds = null;
        String title = null;
        
        if ( thing instanceof IPlottable )
            throw new IllegalArgumentException("IPlottable objects are not supported yet");
        
        if ( thing instanceof DataSource )
            ds = (DataSource) thing;
        else {
            if      (thing instanceof IHistogram)
                ds = AIDAAdapter.create((IHistogram) thing);
            else if (thing instanceof ICloud)
                ds = AIDAAdapter.create((ICloud) thing);
            else if (thing instanceof IFunction)
                ds = AIDAAdapter.create((IFunction) thing);
            else if (thing instanceof IProfile)
                ds = AIDAAdapter.create((IProfile) thing);
            else if (thing instanceof IDataPointSet)
                ds = AIDAAdapter.create((IDataPointSet) thing);
            else
                throw new IllegalArgumentException("Cannot plot object "+thing);
        }
        
        // Apply the Plotter style to the region style
        if ( plotter != null)
            ((BaseStyle)plotterStyle).setParent((BaseStyle)plotter.style());
        
        
        // Create a clone of the style to be applied to this data
        if ( style == null || style == plotterStyle )
            style = new PlotterStyle();
        else
            style = new PlotterStyle( (PlotterStyle) style );
        
        style = applyDefaultStyles(data, style);
        
        // Has to be called only after "applyDefaultStyles"
        // As it needs correct setup of parent styles
        setDefaultsFromData(data, style);
        
        applyStyleBeforeAdding(style, ds);
        
        if ( style != null && style != plotterStyle ) handleLabels(style);
        
        JASHistData jasHistData = getPlot().addData(ds);
        
        String range = getRange(options);
        if ( range != null ) {
            RangeSet rangeSet = new RangeSet(range);
            jasHistData.setXBounds(rangeSet.lowerBounds()[0],rangeSet.upperBounds()[0]);
        }
        
        //Add here the listener to the style.
        DataStyleEntry dataStyleEntry = new DataStyleEntry(jasHistData, style, mode);
        ( (BaseStyle) plotterStyle ).addStyleListener(dataStyleEntry);
        
        //The lists with the data and the style applied to
        dataList.add(data);
        dataStyleList.add(dataStyleEntry);
        
        //Invoke here all the setLimits commands after the first data souce
        //has been added. This way we make sure the axis has been created
        if ( getPlot().getNumberOfDataSources() == 1 ) {
            if ( queue != null ) {
                Iterator iter;
                synchronized (this) {
                    iter = queue.iterator();
                    queue = null;
                }
                for (; iter.hasNext();) {
                    Runnable run = (Runnable) iter.next();
                    invokeOnSwingThread(run);
                }
            }
        }
        
        // The title has to be set before applying the styles!
        if ( regionTitle != null )
            getPlot().setTitle( regionTitle );
        
        if ( getPlot().getTitle() == null ) {
            getPlot().setTitle(ds.getTitle());
            regionTitle = ds.getTitle();
        }
        //        else {
        //            String newTitle = ds.getTitle();
        //            if ( mode == OVERLAY ) {
        //                String tmpTitle = getPlot().getTitle();
        //                if ( tmpTitle != null )
        //                    newTitle = tmpTitle+" - "+newTitle;
        //            }
        //            getPlot().setTitle(newTitle);
        //        }
        
        applyStyle(jasHistData, style);
        
        //boolean isShowing = getPlot().isShowing();
        //jasHistData.show(isShowing);
        jasHistData.show(true);
        
        applyStyleAfterShow(jasHistData, style);        
    }
    
    
    // This method checks if data has set any of the
    // following: axisScale, axisType, axisLabel, customOverlay
    public IPlotterStyle setDefaultsFromData(Object thing, IPlotterStyle style) {
        if ( style == null || style == plotterStyle ) style = new PlotterStyle();
        
        IAnnotation an = null;
        int dimension = 0;
        if ( thing instanceof IBaseHistogram) {
            an = (IAnnotation) ((IBaseHistogram) thing).annotation();
            dimension = ((IBaseHistogram) thing).dimension();
        } else if ( thing instanceof IDataPointSet) {
            an= (IAnnotation) ((IDataPointSet) thing).annotation();
            dimension = ((IDataPointSet) thing).dimension();
        } else {
            //            Nothing to do for IFunction and unknown types
            return style;
        }
        
        String prefix = "x";
        IAxisStyle xAxisStyle = style.xAxisStyle();
        int size = an.size();
        for (int k=0; k<size; k++) {
            String key = an.key(k);
            for (int i=0; i<styleKeys.length; i++) {
                if (key.equalsIgnoreCase((prefix + styleKeys[i]))) {
                    try {
                        String val = an.value(key);
                        if (val != null && !((BaseStyle) xAxisStyle).isParameterSet(stylePars[i])) xAxisStyle.setParameter(stylePars[i], val);
                    } catch (IllegalArgumentException e) {}
                }
            }
        }
        
        
        prefix = "y";
        IAxisStyle yAxisStyle = style.yAxisStyle();
        size = an.size();
        for (int k=0; k<size; k++) {
            String key = an.key(k);
            for (int i=0; i<styleKeys.length; i++) {
                if (key.equalsIgnoreCase((prefix + styleKeys[i]))) {
                    try {
                        String val = an.value(key);
                        if (val != null && !((BaseStyle) yAxisStyle).isParameterSet(stylePars[i])) yAxisStyle.setParameter(stylePars[i], val);
                    } catch (IllegalArgumentException e) {}
                }
            }
        }
        
        String overlayKey = "customOverlay";
        size = an.size();
        for (int k=0; k<size; k++) {
            String key = an.key(k);
            if (key.equalsIgnoreCase(overlayKey)) {
                try {
                    String val = an.value(key);
                    String oldVal = null;
                    if (((BaseStyle) style.dataStyle()).isParameterSet(overlayKey)) oldVal = style.dataStyle().parameterValue(overlayKey);
                    if (val != null && oldVal == null) style.dataStyle().setParameter(overlayKey, val);
                    break;
                } catch (IllegalArgumentException e) {}
            }
        }
        
        return style;
    }
    
    // Transferes x and y axis labels from the current plot to the newer style
    // before getPlot().addData(ds) erases them
    public void handleLabels(IPlotterStyle style) {
        // do X axis
        JASHistAxis xHistAxis = getPlot().getXAxis();
        String oldXLabel = xHistAxis.getLabel();
        
        IAxisStyle xAxisStyle = style.xAxisStyle();
        String xAxisLabel = xAxisStyle.label();
        boolean setXLabel = xAxisLabel != null && ((BaseStyle) xAxisStyle).isParameterSet(Style.AXIS_LABEL);
        if (!setXLabel && oldXLabel != null) xAxisStyle.setLabel(oldXLabel);
        
        // do Y axis
        JASHistAxis yHistAxis = getPlot().getYAxis();
        String oldYLabel = yHistAxis.getLabel();
        
        IAxisStyle yAxisStyle = style.yAxisStyle();
        String yAxisLabel = yAxisStyle.label();
        boolean setYLabel = yAxisLabel != null && ((BaseStyle) yAxisStyle).isParameterSet(Style.AXIS_LABEL);
        if (!setYLabel && oldYLabel != null) yAxisStyle.setLabel(oldYLabel);
    }
    
    public IPlotterStyle applyDefaultStyles( Object thing, IPlotterStyle style ) {
        
        //Set a style specific to a plot.
        // This is the default style for an IDataPointSet.
        // A more generic way of doing this is needed.
        IPlotterStyle defaultStyle = null;
        if ( thing instanceof IDataPointSet )
            defaultStyle = new DataPointSetPlotterStyle();
        else if ( thing instanceof IProfile )
            defaultStyle = new DataPointSetPlotterStyle();
        
        PlotterStyle parent = (PlotterStyle) plotterStyle;
        while( parent.parent() != null )
            parent = (PlotterStyle) parent.parent();
        parent.setParent(defaultStyle);
        ( (BaseStyle)style ).setParent( (BaseStyle)plotterStyle );
        return style;
    }
    
    public void applyStyleBeforeAdding(IPlotterStyle style, DataSource ds) {
        //This MUST not be moved from here. The axis type has to be set before adding the
        //data source to the jasHist
        String xAxisType = style.xAxisStyle().parameterValue("type");
        if ( xAxisType != null )
            if ( xAxisType.equalsIgnoreCase("date") ) {
            //It used to be that the line below did the trick for setting the axis type.
            //It is no longer the case. The axis type is now changed on the data source.
            // getPlot().getXAxis().setAxisType( 3 );
            if ( ds instanceof AIDADataPointSetAdapter )
                ( (AIDADataPointSetAdapter) ds ).setAxisType(3);
            if ( ds instanceof AIDACloudAdapter1D )
                ( (AIDACloudAdapter1D) ds ).setAxisType(3);
            if ( ds instanceof AIDAHistogramAdapter1D )
                ( (AIDAHistogramAdapter1D) ds ).setAxisType(3);
            }
        
        String yAxisType = style.yAxisStyle().parameterValue("type");
        if ( yAxisType != null )
            if ( yAxisType.equals("date") ) {
            //TODO
            //This needs to be fixed as above
            getPlot().getYAxis().setAxisType( 3 );
            }
        
    }
    
    public void applyStyleAfterShow(JASHistData jasHistData, IPlotterStyle style) {
        
        if ( getPlot().getShowLegend() > 0 ) {
            Legend legend = getPlot().getLegend();
            placeMovableObject((MovableObject)legend, style.legendBoxStyle().boxStyle());
        }
        
        if ( getPlot().getShowStatistics() ) {
            StatisticsBlock stat = getPlot().getStats();
            placeMovableObject((MovableObject)stat, style.statisticsBoxStyle().boxStyle());
        }
        
    }
    public void applyStyle(JASHistData jasHistData, IPlotterStyle style) {
        
        //Set the type of error for a profile plot
        DataSource ds = jasHistData.getDataSource();
        String profileErrors = style.dataStyle().parameterValue("profileErrors");
        if ( profileErrors != null && ds instanceof AIDAProfileAdapter ) {
            if ( profileErrors.equals("errorOnMean") || profileErrors.equals("1") )
                ( (AIDAProfileAdapter) ds ).setErrorMode( AIDAProfileAdapter.USE_ERROR_ON_MEAN );
            else if ( profileErrors.equals("spread") || profileErrors.equals("0") )
                ( (AIDAProfileAdapter) ds ).setErrorMode( AIDAProfileAdapter.USE_SPREAD );
        }
        
        // Style options for the plot region
        
        //****  LEGEND  ****//
        boolean showLegend = style.legendBoxStyle().isVisible();
        if ( showLegend )
            getPlot().setShowLegend(JASHist.LEGEND_AUTOMATIC);
        else
            getPlot().setShowLegend(JASHist.LEGEND_NEVER);
        
        if ( getPlot().getShowLegend() > 0 ) {
            Legend legend = getPlot().getLegend();
            if ( legend != null )
                legend.setFont( PlotterFontUtil.getFont( style.legendBoxStyle().textStyle() ) );
        }
        
        
        //****  STATISTICS BOX  ****//
        // Is the statistics box showing?
        getPlot().setShowStatistics( style.statisticsBoxStyle().isVisible() );
        
        if ( getPlot().getShowStatistics() ) {
            StatisticsBlock stat = getPlot().getStats();
            if ( stat != null )
                stat.setFont(  PlotterFontUtil.getFont( style.statisticsBoxStyle().textStyle() ) );
        }
        
        // Choose whether to show the data statistics
        jasHistData.setShowStatistics(style.dataStyle().isShownInStatisticsBox());
        
        //****** TITLE  *******//
        if ( getPlot().getTitleObject() != null )
            getPlot().getTitleObject().setVisible( style.titleStyle().isVisible() );
        
        Title titleObj = getPlot().getTitleObject();
        if ( titleObj != null ) {
            titleObj.setFont( PlotterFontUtil.getFont(style.titleStyle().textStyle()) );
            String colorStr = style.titleStyle().textStyle().color();
            if ( colorStr != null )
                try {
                    Color color = ColorConverter.get(colorStr);
                    color = getTransparentColor(color, style.titleStyle().textStyle().opacity());
                    titleObj.setForeground( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            // Should this be executed on the Swing thread?
            // This should also be done for legend and stat box?
            if ( titleObj.isShowing() )
                getPlot().setTitleObject(titleObj);
        }
        
        //********** BACKGROUND - FOREGROND - DATA AREA COLORS ********//
        String backgroundColor = style.regionBoxStyle().backgroundStyle().color();
        if ( backgroundColor != null )
            try {
                Color color = ColorConverter.get(backgroundColor);
                getPlot().setBackground( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        String foregroundColor = style.regionBoxStyle().foregroundStyle().color();
        if ( foregroundColor != null )
            try {
                Color color = ColorConverter.get(foregroundColor);
                getPlot().setForegroundColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        String dataAreaColor = style.dataBoxStyle().backgroundStyle().color();
        if ( dataAreaColor != null )
            try {
                Color color = ColorConverter.get(dataAreaColor);
                getPlot().setDataAreaColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        //********* DATA AREA BORDER TYPE ****************//
        String dataAreaBorderType = style.dataBoxStyle().borderStyle().borderType();
        if ( dataAreaBorderType != null ) {
            if ( dataAreaBorderType == "bevelIn" || dataAreaBorderType == "0" )
                getPlot().setDataAreaBorderType(1);
            else if ( dataAreaBorderType == "bevelOut" || dataAreaBorderType == "1" )
                getPlot().setDataAreaBorderType(2);
            else if ( dataAreaBorderType == "etched" || dataAreaBorderType == "2" )
                getPlot().setDataAreaBorderType(3);
            else if ( dataAreaBorderType == "line" || dataAreaBorderType == "3" )
                getPlot().setDataAreaBorderType(4);
            else if ( dataAreaBorderType == "shadow" || dataAreaBorderType == "4" )
                getPlot().setDataAreaBorderType(5);
            else
                getPlot().setDataAreaBorderType(0);
        }
        
        //************ X AXIS STYLE  *******************//
        JASHistAxis xAxis = getPlot().getXAxis();
        IAxisStyle xAxisStyle = style.xAxisStyle();
        
        String xAxisLabel = xAxisStyle.label();
        boolean setXLabel = xAxisLabel != null && ((BaseStyle) xAxisStyle).isParameterSet(Style.AXIS_LABEL);
        if (setXLabel) xAxis.setLabel( xAxisLabel );
        
        boolean xAllowZeroSuppression = Boolean.valueOf(xAxisStyle.parameterValue("allowZeroSuppression")).booleanValue();
        xAxis.setAllowSuppressedZero( xAllowZeroSuppression );
        
        EditableLabel xlabel = xAxis.getLabelObject();
        if ( xlabel != null ) {
            xlabel.setFont( PlotterFontUtil.getFont( xAxisStyle.labelStyle() ) );
            String xAxisLabelColor = xAxisStyle.labelStyle().color();
            if ( xAxisLabelColor != null )
                try {
                    Color color = ColorConverter.get(xAxisLabelColor);
                    color = getTransparentColor(color, xAxisStyle.labelStyle().opacity());
                    xlabel.setForeground( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            if ( xlabel.isShowing() )
                xAxis.setLabelObject( xlabel );
        }
        xAxis.setFont( PlotterFontUtil.getFont( xAxisStyle.tickLabelStyle() ) );
        
        String xAxisScale = xAxisStyle.scaling();
        if ( xAxisScale != null ) xAxis.setLogarithmic(xAxisScale.startsWith("log"));
        
        
        String xAxisTickLabelColor = xAxisStyle.tickLabelStyle().color();
        if ( xAxisTickLabelColor != null )
            try {
                Color color = ColorConverter.get(xAxisTickLabelColor);
                color = getTransparentColor(color, xAxisStyle.tickLabelStyle().opacity());
                xAxis.setAxisColor(color);
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        String xAxisLineColor = xAxisStyle.lineStyle().color();
        if ( xAxisLineColor != null )
            try {
                Color color = ColorConverter.get(xAxisLineColor);
                color = getTransparentColor(color, xAxisStyle.lineStyle().opacity());
                xAxis.setAxisColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        String xAxisTextColor = xAxisStyle.labelStyle().color();
        if ( xAxisTextColor != null )
            try {
                Color color = ColorConverter.get(xAxisTextColor);
                color = getTransparentColor(color, xAxisStyle.labelStyle().opacity());
                xAxis.setTextColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        //************ Y AXIS STYLE  *******************//
        JASHistAxis yAxis = getPlot().getYAxis();
        IAxisStyle yAxisStyle = style.yAxisStyle();
        
        String yAxisLabel = yAxisStyle.label();
        boolean setYLabel = yAxisLabel != null && ((BaseStyle) yAxisStyle).isParameterSet(Style.AXIS_LABEL);
        if (setYLabel) yAxis.setLabel( yAxisLabel );
        
        boolean yAllowZeroSuppression = Boolean.valueOf(yAxisStyle.parameterValue("allowZeroSuppression")).booleanValue();
        yAxis.setAllowSuppressedZero( yAllowZeroSuppression );
        
        EditableLabel ylabel = yAxis.getLabelObject();
        if ( ylabel != null ) {
            ylabel.setFont( PlotterFontUtil.getFont( yAxisStyle.labelStyle() ) );
            String yAxisLabelColor = yAxisStyle.labelStyle().color();
            if ( yAxisLabelColor != null )
                try {
                    Color color = ColorConverter.get(yAxisLabelColor);
                    color = getTransparentColor(color, yAxisStyle.labelStyle().opacity());
                    ylabel.setForeground( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            if ( ylabel.isShowing() )
                yAxis.setLabelObject( ylabel );
        }
        yAxis.setFont( PlotterFontUtil.getFont( yAxisStyle.tickLabelStyle() ) );
        
        String yAxisScale = yAxisStyle.scaling();
        if ( yAxisScale != null ) yAxis.setLogarithmic(yAxisScale.startsWith("log"));
        
        String yAxisTickLabelColor = yAxisStyle.tickLabelStyle().color();
        if ( yAxisTickLabelColor != null )
            try {
                Color color = ColorConverter.get(yAxisTickLabelColor);
                color = getTransparentColor(color, yAxisStyle.tickLabelStyle().opacity());
                yAxis.setAxisColor(color);
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        
        String yAxisLineColor = yAxisStyle.lineStyle().color();
        if ( yAxisLineColor != null )
            try {
                Color color = ColorConverter.get(yAxisLineColor);
                color = getTransparentColor(color, yAxisStyle.lineStyle().opacity());
                yAxis.setAxisColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        String yAxisTextColor = yAxisStyle.labelStyle().color();
        if ( yAxisTextColor != null )
            try {
                Color color = ColorConverter.get(yAxisTextColor);
                color = getTransparentColor(color, yAxisStyle.labelStyle().opacity());
                yAxis.setTextColor( color );
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        // Set position of Y Axis for this DataSource
        String yAxisValue = yAxisStyle.parameterValue("yAxis");
        if ( yAxisValue != null )
            try {
                int yAxisID = (yAxisValue.equalsIgnoreCase("Y1")) ? JASHistData.YAXIS_RIGHT : JASHistData.YAXIS_LEFT;
                jasHistData.setYAxis(yAxisID);
            } catch ( Exception cce ){
                throw new RuntimeException(cce);
            }
        
        
        
        JASHistStyle histStyle = jasHistData.getStyle();
        //************  FUNCTIONS  *************//
        if ( histStyle instanceof JASHist1DFunctionStyle ) {
            JASHist1DFunctionStyle fs = (JASHist1DFunctionStyle) histStyle;
            
            IDataStyle dataStyle = style.dataStyle();
            String functionLineColor = dataStyle.outlineStyle().color();
            if ( functionLineColor != null )
                try {
                    Color color = ColorConverter.get(functionLineColor);
                    fs.setLineColor(color);
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            fs.setLineStyle( lineType(dataStyle.outlineStyle().lineType()) );
            fs.setLineWidth( lineThickness(dataStyle.outlineStyle().thickness()) );
        }
        
        //************  CUSTOM OVERLAYS  *************//
        String overlayClass = style.dataStyle().parameterValue("customOverlay");
        if (overlayClass == null) {
            
        }
        CustomOverlay customOverlay = null;
        if ( overlayClass != null ) {
            try {
                Class coClass = Class.forName(overlayClass);
                customOverlay = (CustomOverlay) coClass.newInstance();
                if (customOverlay instanceof CanSetData) ((CanSetData) customOverlay).setData(jasHistData);
                histStyle.setCustomOverlay(customOverlay);
                //System.out.println("PlotterRegion.applyStyle  CustomOverlay:  customOverlay="+customOverlay);
                
            } catch ( Exception coe ){ coe.printStackTrace(); }
        }
        
        //************  1D HISTOGRAMS  *************//
        if ( histStyle instanceof JASHist1DHistogramStyle ) {
            JASHist1DHistogramStyle hs = (JASHist1DHistogramStyle) histStyle;
            
            if (customOverlay != null && customOverlay instanceof CanSetStyle)
                ((CanSetStyle) customOverlay).setStyle(hs);
            
            IDataStyle dataStyle = style.dataStyle();
            
            hs.setShowHistogramBars( dataStyle.lineStyle().isVisible() );
            
            hs.setHistogramFill( dataStyle.fillStyle().isVisible() );
            
            hs.setShowErrorBars( dataStyle.errorBarStyle().isVisible() );
            
            hs.setShowDataPoints( dataStyle.markerStyle().isVisible() );
            
            hs.setShowLinesBetweenPoints( dataStyle.outlineStyle().isVisible() );
            
            IFillStyle dataFillStyle = dataStyle.fillStyle();
            ILineStyle dataLineStyle = dataStyle.lineStyle();
            IMarkerStyle dataMarkerStyle = dataStyle.markerStyle();
            
            //By default the histogram's fill color, the contour of the histogram bar and
            //the line between the points are taken from the line color. If the fill color is set
            //and the histogram's bars are filled, the different color is used. Same for the
            //line between the points.
            
            // Set the line type
            String dataLineType = dataLineStyle.lineType();
            hs.setHistogramBarLineStyle( lineType(dataLineType) );
            hs.setHistogramBarLineWidth( lineThickness(dataLineStyle.thickness()) );
            
            String dataLineColor = dataLineStyle.color();
            if ( dataLineColor != null )
                try {
                    Color color = ColorConverter.get(dataLineColor);
                    color = getTransparentColor(color, dataLineStyle.opacity());
                    hs.setHistogramBarLineColor(color);
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            String dataFillColor = dataFillStyle.color();
            if ( dataFillColor != null && hs.getHistogramFill() )
                try {
                    Color color = ColorConverter.get(dataFillColor);
                    color = getTransparentColor(color, dataFillStyle.opacity());
                    hs.setHistogramBarColor( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            String dataLineBetweenPointsColor = dataStyle.outlineStyle().color();
            if ( dataLineBetweenPointsColor != null )
                try {
                    Color color = ColorConverter.get(dataLineBetweenPointsColor);
                    hs.setLineColor(color);
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            hs.setLinesBetweenPointsStyle( lineType(dataStyle.outlineStyle().lineType()) );
            hs.setLinesBetweenPointsWidth( lineThickness(dataStyle.outlineStyle().thickness()) );
            
            
            String dataMarkerShape = dataMarkerStyle.shape();
            if ( dataMarkerShape != null )
                hs.setDataPointStyle( markerShape( dataMarkerShape ) );
            
            hs.setDataPointSize( dataMarkerStyle.size() );
            
            // By default the error bars have the same color as the plot's line.
            String dataMarkerColor = dataMarkerStyle.color();
            if ( dataMarkerColor != null )
                try {
                    Color color = ColorConverter.get(dataMarkerColor);
                    color = getTransparentColor(color, dataMarkerStyle.opacity());
                    hs.setDataPointColor( color );
                    hs.setErrorBarColor( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            String errorBarsColor = dataStyle.errorBarStyle().color();
            if ( errorBarsColor != null )
                try {
                    Color color = ColorConverter.get(errorBarsColor);
                    hs.setErrorBarColor( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            // Set the error bars line type
            hs.setErrorBarStyle( lineType(dataStyle.errorBarStyle().lineType()) );
            hs.setErrorBarWidth( lineThickness(dataStyle.errorBarStyle().thickness()) );
            
        }
        
        //*********  2D HISTOGRAMS  ***************//
        if ( histStyle instanceof JASHistScatterPlotStyle ) {
            JASHistScatterPlotStyle sphs = (JASHistScatterPlotStyle) histStyle;
            
            IMarkerStyle dataMarkerStyle = style.dataStyle().markerStyle();
            String dataMarkerShape = dataMarkerStyle.shape();
            if ( dataMarkerShape != null )
                sphs.setDataPointStyle( markerShapeScatter(dataMarkerShape) );
            
            sphs.setDataPointSize( dataMarkerStyle.size() );
            
            String dataMarkerColor = dataMarkerStyle.color();
            if ( dataMarkerColor != null )
                try {
                    Color color = ColorConverter.get(dataMarkerColor);
                    color = getTransparentColor(color, dataMarkerStyle.opacity());
                    sphs.setDataPointColor( color );
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            sphs.setDisplayAsScatterPlot(Boolean.valueOf( style.parameterValue("showAsScatterPlot") ).booleanValue() );
        }
        
        boolean isBinned2D = false;
        
        if ( histStyle instanceof JASHist2DHistogramStyle )
            if ( histStyle instanceof JASHistScatterPlotStyle ) {
            if ( ( (JASHistScatterPlotStyle) histStyle ).getDisplayAsScatterPlot() )
                isBinned2D = true;
            } else
                isBinned2D = true;
        
        
        if ( isBinned2D ) {
            
            JASHist2DHistogramStyle hs = (JASHist2DHistogramStyle) histStyle;
            String hist2DStyle = style.parameterValue("hist2DStyle");
            if ( hist2DStyle != null ) {
                if ( hist2DStyle.equals( "box" ) || hist2DStyle.equals("0") )
                    hs.setHistStyle(0);
                else if ( hist2DStyle.equals( "ellipse" ) || hist2DStyle.equals("1") )
                    hs.setHistStyle(1);
                else if ( hist2DStyle.equals( "colorMap" ) || hist2DStyle.equals("2") )
                    hs.setHistStyle(2);
                else
                    hs.setHistStyle(0);
            }
            
            String colorMapScheme = style.dataStyle().fillStyle().parameterValue("colorMapScheme");
            if ( colorMapScheme != null ) {
                if ( colorMapScheme.equals("warm") || colorMapScheme.equals("0") )
                    hs.setColorMapScheme(hs.COLORMAP_WARM);
                else if ( colorMapScheme.equals("cool") || colorMapScheme.equals("1") )
                    hs.setColorMapScheme(hs.COLORMAP_COOL);
                else if ( colorMapScheme.equals("thermal") || colorMapScheme.equals("2") )
                    hs.setColorMapScheme(hs.COLORMAP_THERMAL);
                else if ( colorMapScheme.equals("rainbow") || colorMapScheme.equals("3") )
                    hs.setColorMapScheme(hs.COLORMAP_RAINBOW);
                else if ( colorMapScheme.equals("grayscale") || colorMapScheme.equals("4") )
                    hs.setColorMapScheme(hs.COLORMAP_GRAYSCALE);
                else if ( colorMapScheme.equals("userdefined") || colorMapScheme.equals("5") ) {
                    hs.setColorMapScheme(hs.COLORMAP_USERDEFINED);
                    String startColor = style.dataStyle().fillStyle().parameterValue("startColor");
                    String endColor = style.dataStyle().fillStyle().parameterValue("endColor");
                    try {
                        hs.setStartDataColor(startColor == null ? Color.WHITE : ColorConverter.get(startColor));
                    } catch (ColorConverter.ColorConversionException x) {
                        hs.setStartDataColor(Color.WHITE);
                    }
                    try {
                        hs.setEndDataColor(endColor == null ? Color.BLACK : ColorConverter.get(endColor));
                    } catch (ColorConverter.ColorConversionException x) {
                        hs.setStartDataColor(Color.BLACK);
                    }
                    
                } else
                    hs.setColorMapScheme(0);
            }
            
            String shapeColor = style.dataStyle().markerStyle().color();
            if ( shapeColor != null )
                try {
                    Color color = ColorConverter.get(shapeColor);
                    color = getTransparentColor(color, style.dataStyle().markerStyle().opacity());
                    hs.setShapeColor(color);
                } catch ( Exception cce ){
                    throw new RuntimeException(cce);
                }
            
            String logZ = style.zAxisStyle().scaling();
            if ( logZ != null )
                hs.setLogZ(logZ.toLowerCase().startsWith("log"));
        }
    }
    
    private Color getTransparentColor(Color c, double alpha) {
        if ( alpha == -1 || alpha < 0 || alpha > 1 )
            return c;
        int t = (int)(255*alpha);
        return new Color(c.getRed(),c.getGreen(), c.getBlue(), t);
    }
    
    private float lineThickness(String thickness) {
        return Float.parseFloat(thickness)/(float)2.;
    }
    
    private float lineThickness(int thickness) {
       return ((float)thickness)/(float)2.;
    }
    
    private int lineType(String lineType) {
        if ( lineType == null || lineType.equals("solid") || lineType.equals("0") )
            return JASHist1DHistogramStyle.SOLID;
        if ( lineType.equals("dotted") || lineType.equals("1") )
            return JASHist1DHistogramStyle.DOTTED;
        if ( lineType.equals("dashed") || lineType.equals("2") )
            return JASHist1DHistogramStyle.DASHED;
        if ( lineType.equals("dotdash") || lineType.equals("3") )
            return JASHist1DHistogramStyle.DOTDASH;
        else
            return JASHist1DHistogramStyle.SOLID;
    }
    
    private int markerShape( String markerShape ) {
        if ( markerShape.equals("dot") || markerShape.equals("0") )
            return 0;
        else if ( markerShape.equals("box") || markerShape.equals("1") )
            return 1;
        else if ( markerShape.equals("triangle") || markerShape.equals("2") )
            return 2;
        else if ( markerShape.equals("diamond") || markerShape.equals("3") )
            return 3;
        else if ( markerShape.equals("star") || markerShape.equals("4") )
            return 4;
        else if ( markerShape.equals("verticalLine") || markerShape.equals("5") )
            return 5;
        else if ( markerShape.equals("horizontalLine") || markerShape.equals("6") )
            return 6;
        else if ( markerShape.equals("cross") || markerShape.equals("7") )
            return 7;
        else if ( markerShape.equals("circle") || markerShape.equals("8") )
            return 8;
        else if ( markerShape.equals("square") || markerShape.equals("9") )
            return 9;
        else
            return 0;
    }
    
    private int markerShapeScatter( String markerShape ) {
        if ( markerShape.equals("box") || markerShape.equals("1") )
            return 0;
        else if ( markerShape.equals("triangle") || markerShape.equals("2") )
            return 1;
        else if ( markerShape.equals("diamond") || markerShape.equals("3") )
            return 2;
        else if ( markerShape.equals("star") || markerShape.equals("4") )
            return 3;
        else if ( markerShape.equals("verticalLine") || markerShape.equals("5") )
            return 4;
        else if ( markerShape.equals("horizontalLine") || markerShape.equals("6") )
            return 5;
        else if ( markerShape.equals("cross") || markerShape.equals("7") )
            return 6;
        else if ( markerShape.equals("square") || markerShape.equals("9") )
            return 7;
        else
            return 0;
    }
    
    void removeAllObjectsFromRegion() {
        //Fix to JAS-270 It used to be that nData = getPlot().getNumberOfDataSources(), but this
        //did not take into account the functions: getPlot().get1DFunctions()
        int nData = dataList.size();
        ArrayList tmpDataList = (ArrayList) dataList.clone();
        for ( int i = 0; i < nData; i++ )
            removeObj( tmpDataList.get(i), false );
        rebuild();
    }
    
    public void removeObjectFromRegion(Object thing) {
        removeObj(thing,true);
    }
    
    void removeObj(Object thing, boolean rebuild) {
        int thingIndex = dataList.indexOf(thing);
        DataStyleEntry dse = (DataStyleEntry) dataStyleList.get(thingIndex);
        dse.cleanUp();
        removeDataSourceFromRegion( (DataSource) dse.data().getDataSource() );
        dataList.remove(thingIndex);
        dataStyleList.remove(thingIndex);
        if ( rebuild && dataList.size() > 0 )
            rebuild();
    }
    
    public void removeDataSourceFromRegion( DataSource ds ) {
    }
    
    public void refresh() {
        rebuild();
    }
    
    private void rebuild() {
        invokeOnSwingThread( new RebuildRegion() );
    }
    
    public void clearRegion() {
        removeAllObjectsFromRegion();
        JASHist plot = getPlot();
        if (plot != null) {
            panel.remove(plot);
            plot.destroy();
            setPlot(null);
            regionTitle = null;
        }
        plotterStyle = new PlotterStyle();
    }
    
    private void createPlot() {
        plot = new JASHistPlot((DummyPlotter)plotter);
        plot.setShowStatistics(true);
        panel.add(plot,BorderLayout.CENTER);
        panel.revalidate();
    }
    
    private static void invokeOnSwingThread(Runnable run) {
        if (SwingUtilities.isEventDispatchThread()) run.run();
        else {
            try {
                SwingUtilities.invokeAndWait(run);
            } catch (java.lang.reflect.InvocationTargetException x) {
                x.printStackTrace();
            } catch (InterruptedException x) {
                x.printStackTrace();
            }
        }
    }
    
    
    public void addToRegion(Object thing, IPlotterStyle styleObj, String options) {
        add(thing,styleObj, options);
    }
    
    private String getRange(String options) {
        if ( options != null ) {
            Map optionsMap = AidaUtils.parseOptions( options );
            return (String) optionsMap.get("range");
        }
        return null;
    }
    
    public int getMode(String options) {
        if ( options == null )
            return defaultMode();
        Map optionsMap = AidaUtils.parseOptions( options );
        String mode = (String) optionsMap.get("mode");
        return modeConversion(mode);
    }
    
    private int modeConversion( String mode ) {
        if ( mode != null ) {
            if ( mode.equals("replace") )
                return REPLACE;
            else if ( mode.equals("overlay") )
                return OVERLAY;
            else if ( mode.equals("add") )
                return ADD;
            else if ( mode.equals("stack") )
                return STACK;
        }
        return defaultMode();
    }
    
    public void setDefaultMode( String value ) {
        defaultMode = modeConversion( value );
    }
    
    int defaultMode() {
        return defaultMode;
    }

    private void placeMovableObject(MovableObject movableObject, IBoxStyle boxStyle) {
        if ( ! Double.isNaN(boxStyle.x()) && ! Double.isNaN(boxStyle.y()) )
            movableObject.moveMovableObject((int) boxStyle.x(), (int) boxStyle.y());
        if ( ! Double.isNaN(boxStyle.width()) && ! Double.isNaN(boxStyle.height()) )
            movableObject.resizeMovableObject((int) boxStyle.width(), (int) boxStyle.height());
    }

    //******************************************//
    // Methods needed by the FPlotter interface //
    //******************************************//
    /*
    public void plot(Object data, int options) {
        plot(data,options,plotterStyle);
    }
     
    public void plot(Object data, int options, Object style) {
    }
     
    public void remove(Object data) {
    }
     
    public void clearPlotter() {
    }
     
    public java.awt.Component viewable() {
        return getPlot();
    }
     */
    
    //*****************************************//
    
    private static class AddRemove implements Runnable {
        private boolean add;
        private PlotterRegion region;
        private Object thing;
        private IPlotterStyle styleObj;
        private String options;
        
        AddRemove(boolean add, PlotterRegion region, Object thing) {
            this( add, region, thing, null);
        }
        AddRemove(boolean add, PlotterRegion region, Object thing, IPlotterStyle styleObj) {
            this(add, region, thing, styleObj, null);
        }
        AddRemove(boolean add, PlotterRegion region, Object thing, IPlotterStyle styleObj, String options) {
            this.add = add;
            this.region = region;
            this.thing = thing;
            this.styleObj = styleObj;
            this.options = options;
        }
        public void run() {
            if (add) region.addToRegion(thing, styleObj, options);
            else     region.removeObjectFromRegion(thing);
            region.panel.repaint();
        }
    }
    private class ClearRegion implements Runnable {
        public void run() {
            clearRegion();
        }
    }
    private class LimitsChanged implements Runnable {
        final static int XAXIS = 0;
        final static int YAXIS = 1;
        final static int ZAXIS = 2;
        private int axis;
        private double min;
        private double max;
        LimitsChanged(int axis, double min, double max) {
            this.axis = axis;
            this.min = min;
            this.max = max;
        }
        
        public void run() {
            if (getPlot() != null) {
                JASHistAxis plotAxis = null;
                if      (axis == XAXIS) plotAxis = getPlot().getXAxis();
                else if (axis == YAXIS) plotAxis = getPlot().getYAxis();
                //TODO: What about the Z axis?
                if (plotAxis != null) {
                    if (Double.isNaN(min) && Double.isNaN(max)) plotAxis.setRangeAutomatic(true);
                    else {
                        if (Double.isNaN(min)) min = plotAxis.getMin();
                        if (Double.isNaN(max)) max = plotAxis.getMax();
                        plotAxis.setRange(min,max);
                    }
                }
            }
        }
    }
    
    private class TitleChanged implements Runnable {
        
        TitleChanged(String title) {
            regionTitle = title;
        }
        public void run() {
            if (getPlot() == null) createPlot();
            getPlot().setTitle(regionTitle);
        }
    }
    
    private class RebuildRegion implements Runnable {
        
        public void run() {
            if (getPlot() != null) getPlot().removeAllData();
            
            //Create first a copy of the dataList and of the dataStyleList.
            ArrayList tmpDataList = (ArrayList) dataList.clone();
            ArrayList tmpDataStyleList = (ArrayList) dataStyleList.clone();
            dataList.clear();
            dataStyleList.clear();
            
            for ( int i = 0; i < tmpDataList.size(); i++ ) {
                Object dataObj = tmpDataList.get(i);
                DataStyleEntry dse = (DataStyleEntry) tmpDataStyleList.get(i);
                
                add( dse.data().getDataSource(), dse.style(), dse.mode(), tmpDataList.get(i) );
                
                dse.cleanUp();
            }
        }
    }
    
    
    private class DataStyleEntry implements StyleListener, Runnable {
        
        private JASHistData jasHistData;
        private IPlotterStyle style;
        private int mode;
        
        DataStyleEntry( JASHistData jasHistData , IPlotterStyle style, int mode ) {
            setData(jasHistData);
            setStyle(style);
            this.mode = mode;
        }
        
        IPlotterStyle style() {
            return style;
        }
        
        JASHistData data() {
            return jasHistData;
        }
        
        void setStyle( IPlotterStyle style ) {
            this.style = style;
        }
        
        void setData( JASHistData jasHistData ) {
            this.jasHistData = jasHistData;
        }
        
        int mode() {
            return mode;
        }
        
        void cleanUp() {
            ( (BaseStyle)plotterStyle ).removeStyleListener(this);
        }
        
        public void styleChanged(BaseStyle style) {
            if ( style != plotterStyle && plotterStyle != style.parent() )
                style.setParent( plotterStyle );
            invokeOnSwingThread(this);
        }
        
        public void run() {
            applyStyle(data(), style());
        }
    }
    
    
    private class JASHistPlot extends JASHist implements HasPopupItems, ActionListener {
        
        private DummyPlotter plotter;
        private Component parent;
        
        protected JASHistPlot(DummyPlotter plotter) {
            setShowStatistics(true);
            setBackground(java.awt.Color.white);
            setAllowPopupMenus(false);
            this.plotter = plotter;
            this.parent = (Component) SwingUtilities.getAncestorOfClass(Component.class,plotter.panel());
        }

        public void actionPerformed(ActionEvent actionEvent) {
            String command = actionEvent.getActionCommand();
            if (command.equals("saveRegion")) {
                ExportDialog dlg = new ExportDialog(null,true);
                dlg.showExportDialog(parent, "Save As...",  JASHistPlot.this, "plot");
            } else if (command.equals("copyRegion")) {
                Clipboard cb = JASHistPlot.this.getToolkit().getSystemClipboard();
                VectorGraphicsTransferable t = new VectorGraphicsTransferable(JASHistPlot.this);
                cb.setContents(t,t);
            } else if (command.equals("printRegion")) {
                Studio studio = (Studio) Application.getApplication();
                try {
                    PrintHelper ph = new PrintHelper(JASHistPlot.this, studio);
                    ph.print();
                } catch (PrinterException x) {
                    studio.error("Error printing plot",x);
                }
            }
            else if (command.equals("savePlotter")) {
                ExportDialog dlg = new ExportDialog(null,true);
                dlg.showExportDialog(parent, "Save As...",  plotter.panel(), "plotter");
            } else if (command.equals("copyPlotter")) {
                Clipboard cb = JASHistPlot.this.getToolkit().getSystemClipboard();
                VectorGraphicsTransferable t = new VectorGraphicsTransferable(plotter.panel());
                cb.setContents(t,t);
            } else if (command.equals("printPlotter")) {
                Studio studio = (Studio) Application.getApplication();
                try {
                    PrintHelper ph = new PrintHelper(plotter.panel(), studio);
                    ph.print();
                } catch (PrinterException x) {
                    studio.error("Error printing plot",x);
                }
            }
        }
        public JPopupMenu modifyPopupMenu(JPopupMenu menu,Component source,Point p) {
            
            for (Component c=source; c != null; c = c.getParent()) {
                if (c instanceof jas.plot.HasPopupItems) ((jas.plot.HasPopupItems) c).modifyPopupMenu(menu, source);
            }
            
            // Do some work on the menu!
            for (int i=0; i<menu.getComponentCount();i++) {
                Object item = menu.getComponent(i);
                if (item instanceof JMenuItem) {
                    JMenuItem mItem = (JMenuItem) item;
                    String name = mItem.getText();
                    //                if      (name.indexOf("function") >= 0) menu.remove(i--);
                    //                else if (name.equals("Fit"))            menu.remove(i--);
                    if (name.indexOf("Advanced") >= 0) menu.remove(i--);
                    else if (name.equals("Save Plot As...")) menu.remove(i--);
                    //                else if (name.equals("Save Plot As...")) menu.remove(i--);
                    else if (name.equals("Print")) menu.remove(i--);
                    else if (name.equals("Copy Plot to Clipboard...")) menu.remove(i--);
                }
            }
            
            menu.addSeparator();
            JMenuItem item = new JMenuItem("Copy Plot Region");
            item.setActionCommand("copyRegion");
            item.addActionListener(this);
            menu.add(item);
            item = new JMenuItem("Copy Plotter");
            item.setActionCommand("copyPlotter");
            item.addActionListener(this);
            menu.add(item);
            item = new JMenuItem("Save Plot Region As...");
            item.setActionCommand("saveRegion");
            item.addActionListener(this);
            menu.add(item);
            item = new JMenuItem("Save Plotter As...");
            item.setActionCommand("savePlotter");
            item.addActionListener(this);
            menu.add(item);
            /*
            item = new JMenuItem("Print Plot Region");
            item.setActionCommand("printRegion");
            item.addActionListener(this);
            menu.add(item);
            item = new JMenuItem("Print Plotter");
            item.setActionCommand("printPlotter");
            item.addActionListener(this);
            menu.add(item);
            */
            return menu;
        }
                
    }
}
