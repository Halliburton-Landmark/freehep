/*
 * HistogramFactory.java
 *
 * Created on February 14, 2001, 1:09 PM
 */

package hep.aida.ref.histogram;
import hep.aida.*;
import hep.aida.ref.AidaUtils;
import hep.aida.ref.tree.*;

/**
 * @author The AIDA team @ SLAC.
 * @version $Id: HistogramFactory.java,v 1.14 2005/02/14 22:36:30 serbo Exp $
 */
public class HistogramFactory implements IHistogramFactory {
    
    private Tree tree;
    private final static int defaultMaxEntries=100000;
    private HistMath histMath;
    private final static char separatorChar = '/';
    
    private String nameInPath( String path ) {
        return AidaUtils.parseName(path);
        /*
        int index = path.lastIndexOf( separatorChar );
        if ( index == -1 )
            return path;
        return path.substring( index+1 );
         */
    }
    
    private String parentPath( String path ) {
        return AidaUtils.parseDirName(path);
        /*
        int index = path.lastIndexOf( separatorChar );
        if ( index == -1 )
            return null;
        return path.substring(0,index);
         */
    }
    
    /**
     * Create a new HistogramFactory.
     * This constructor is used by AnalysisFactory, the Master Factory.
     * @param tree the ITree where the histogram is added.
     */
    public HistogramFactory(ITree tree) {
        this((Tree)tree);
    }
    
    /**
     * Create a new HistogramFactory.
     * This constructor is used by AnalysisFactory, the Master Factory.
     * @param tree the Tree where the histogram is added.
     */
    public HistogramFactory(Tree tree) {
        this.tree = tree;
        histMath = new HistMath();
    }
    
    /**
     * Destroy an IBaseHistogram ogject.
     *
     */
    public void destroy(IBaseHistogram hist) throws IllegalArgumentException {
	if (tree != null) {
	    String path = tree.findPath((IManagedObject) hist);
	    tree.rm(path);
	}
    }
    
    /**
     * Create a Cloud1D, and unbinned 1-dimensional Histogram.
     * @param path The path of the Cloud1D.
     * @param title The title of the Cloud1D.
     * @param nMax The maximum number of entries after which the Cloud1D will convert to an Histogram1D.
     *             If nMax = -1 then the Cloud1D will not convert automatically to an Histogram1D.
     * @param options The options for creating a Cloud1D.
     *
     */
    public ICloud1D createCloud1D(String path, String title, int nMax, String options) {
        Cloud1D result= new Cloud1D(nameInPath(path),title,nMax,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
    
    public ICloud1D createCloud1D(String path, String title, int nMax) {
        return createCloud1D(path, title, nMax, "");
    }
    
    public ICloud1D createCloud1D(String path, String title) {
        return createCloud1D(path, title, defaultMaxEntries);
    }
    
    public ICloud1D createCloud1D(String pathAndTitle) {
        return createCloud1D(pathAndTitle, nameInPath(pathAndTitle));
    }
    
    public ICloud1D createCopy( String path, ICloud1D cloud) {
        Cloud1D oldCloud = (Cloud1D) cloud;
        Cloud1D newCloud = new Cloud1D(nameInPath(path), oldCloud.title(), oldCloud.maxEntries(), oldCloud.getOptions() );
        if ( oldCloud.isConverted() ) 
            newCloud.setHistogram( copy( nameInPath(path), oldCloud.histogram() ) );
        else 
            for ( int i = 0; i < oldCloud.entries(); i++ )
                newCloud.fill( oldCloud.value(i), oldCloud.weight(i) );
        newCloud.setLowerEdge( oldCloud.lowerEdge() );
        newCloud.setUpperEdge( oldCloud.upperEdge() );
        if (tree != null) tree.addFromFactory(parentPath(path),newCloud);
        return newCloud;
    }
    
    /**
     * Create a Cloud2D, and unbinned 2-dimensional Histogram.
     * @param path The path of the Cloud2D.
     * @param title The title of the Cloud2D.
     * @param nMax The maximum number of entries after which the Cloud2D will convert to an Histogram2D.
     *             If nMax = -1 then the Cloud2D will not convert automatically to an Histogram2D.
     * @param options The options for creating a Cloud2D.
     *
     */
    public ICloud2D createCloud2D(String path, String title, int nMax, String options) {
        Cloud2D result= new Cloud2D(nameInPath(path),title,nMax,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
    
    public ICloud2D createCloud2D(String path, String title, int nMax) {
        return createCloud2D(path, title, nMax, "");
    }
    
    public ICloud2D createCloud2D(String path, String title) {
        return createCloud2D(path, title, defaultMaxEntries);
    }
    
    public ICloud2D createCloud2D(String pathAndTitle) {
        return createCloud2D(pathAndTitle, nameInPath(pathAndTitle));
    }
    
    public ICloud2D createCopy( String path, ICloud2D cloud) {
        Cloud2D oldCloud = (Cloud2D) cloud;
        Cloud2D newCloud = new Cloud2D(nameInPath(path), oldCloud.title(), oldCloud.maxEntries(), oldCloud.getOptions() );
        if ( oldCloud.isConverted() ) 
            newCloud.setHistogram( copy( nameInPath(path), oldCloud.histogram() ) );
        else 
            for ( int i = 0; i < oldCloud.entries(); i++ )
                newCloud.fill( oldCloud.valueX(i), oldCloud.valueY(i), oldCloud.weight(i) );
        newCloud.setLowerEdgeX( oldCloud.lowerEdgeX() );
        newCloud.setUpperEdgeX( oldCloud.upperEdgeX() );
        newCloud.setLowerEdgeY( oldCloud.lowerEdgeY() );
        newCloud.setUpperEdgeY( oldCloud.upperEdgeY() );
        if (tree != null) tree.addFromFactory( parentPath(path),newCloud);
        return newCloud;
    }
    
    /**
     * Create a Cloud3D, and unbinned 3-dimensional Histogram.
     * @param path The path of the Cloud3D.
     * @param title The title of the Cloud3D.
     * @param nMax The maximum number of entries after which the Cloud3D will convert to an Histogram3D.
     *             If nMax = -1 then the Cloud3D will not convert automatically to an Histogram3D.
     * @param options The options for creating a Cloud3D.
     *
     */
    public ICloud3D createCloud3D(String path, String title, int nMax, String options) {
        Cloud3D result= new Cloud3D(nameInPath(path),title,nMax,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
    
    public ICloud3D createCloud3D(String path, String title, int nMax) {
        return createCloud3D(path, title, nMax, "");
    }
    
    public ICloud3D createCloud3D(String path, String title) {
        return createCloud3D(path, title, defaultMaxEntries);
    }
    
    public ICloud3D createCloud3D(String pathAndTitle) {
        return createCloud3D(pathAndTitle, nameInPath(pathAndTitle));
    }
        
    public ICloud3D createCopy( String path, ICloud3D cloud) {
        Cloud3D oldCloud = (Cloud3D) cloud;
        Cloud3D newCloud = new Cloud3D(nameInPath(path), oldCloud.title(), oldCloud.maxEntries(), oldCloud.getOptions() );
        if ( oldCloud.isConverted() ) 
            newCloud.setHistogram( copy( nameInPath(path), oldCloud.histogram() ) );
        else 
            for ( int i = 0; i < oldCloud.entries(); i++ )
                newCloud.fill( oldCloud.valueX(i), oldCloud.valueY(i), oldCloud.valueZ(i), oldCloud.weight(i) );
        newCloud.setLowerEdgeX( oldCloud.lowerEdgeX() );
        newCloud.setUpperEdgeX( oldCloud.upperEdgeX() );
        newCloud.setLowerEdgeY( oldCloud.lowerEdgeY() );
        newCloud.setUpperEdgeY( oldCloud.upperEdgeY() );
        newCloud.setLowerEdgeZ( oldCloud.lowerEdgeZ() );
        newCloud.setUpperEdgeZ( oldCloud.upperEdgeZ() );
        if (tree != null) tree.addFromFactory( parentPath(path),newCloud);
        return newCloud;
    }

    /**
     * Create a IHistogram1D.
     *
     */
    private IAxis copy( IAxis axis ) {
        if ( axis instanceof FixedAxis )
            return new FixedAxis( axis.bins(), axis.lowerEdge(),  axis.upperEdge() );
        else {
            double[] edges = new double[ axis.bins() + 1 ];
            edges[0] = axis.binLowerEdge(0);
            for ( int i = 0; i < axis.bins(); i ++ )
                edges[i+1] = axis.binUpperEdge(i);
            return new VariableAxis( edges );
        }
    }
    
    public IHistogram1D createHistogram1D(String path, String title, int nBins, double lowerEdge, double upperEdge, String options) {
        IAxis axis = new FixedAxis(nBins,lowerEdge,upperEdge);
        Histogram1D result = new Histogram1D(nameInPath(path),title,axis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
        
    public IHistogram1D createHistogram1D(String path, String title, int nBins, double lowerEdge, double upperEdge) {
        return createHistogram1D(path, title, nBins, lowerEdge, upperEdge, "");
    }
    
    public IHistogram1D createHistogram1D(String pathAndTitle, int nBins, double lowerEdge, double upperEdge) {
        return createHistogram1D(pathAndTitle, nameInPath(pathAndTitle), nBins, lowerEdge, upperEdge);
    }
    
    public IHistogram1D createHistogram1D(String path, String title, double[] binEdges, String options) {
        IAxis axis = new VariableAxis(binEdges);
        Histogram1D result = new Histogram1D(nameInPath(path),title,axis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
    
    public IHistogram1D createHistogram1D(String path, String title, double[] binEdges) {
        return createHistogram1D(path,title,binEdges,"");
    }
    
    public IHistogram1D createCopy(String path, IHistogram1D hist) {
        Histogram1D newHist = copy(nameInPath(path),hist);
        if (tree != null) tree.addFromFactory( parentPath(path),newHist);
        return newHist;
    }
        
    private Histogram1D copy(String name, IHistogram1D hist) {
        Histogram1D oldHist = (Histogram1D) hist;
        IAxis axis = oldHist.axis();
        Histogram1D newHist = new Histogram1D(name, oldHist.title(), copy( axis ), oldHist.options() );

        int bins = axis.bins()+2;
        
        double[] heights = new double[bins];
        double[] errors  = new double[bins];
        double[] means   = new double[bins];
        double[] rmss    = new double[bins];
        int[]    entries = new int   [bins];
        
        for(int i=IAxis.UNDERFLOW_BIN; i<bins-2;i++) {
            int bin = oldHist.mapBinNumber(i,axis);
            heights[bin] = oldHist.binHeight(i);
            errors [bin] = oldHist.binError(i);
            entries[bin] = oldHist.binEntries(i);
            means  [bin] = oldHist.binMean(i);
            rmss   [bin] = oldHist.binRms(i);
        }
        newHist.setContents(heights,errors,entries,means,rmss);
        newHist.setMean( oldHist.mean() );
        newHist.setRms( oldHist.rms() );
        newHist.setNEntries( oldHist.allEntries() );
        newHist.setFillable( oldHist.isFillable() );
        return newHist;
    }
    
    /**
     * Create a IHistogram2D.
     *
     */
    public IHistogram2D createHistogram2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, String options) {
        IAxis xAxis = new FixedAxis(nBinsX, lowerEdgeX, upperEdgeX);
        IAxis yAxis = new FixedAxis(nBinsY, lowerEdgeY, upperEdgeY);
        Histogram2D result = new Histogram2D(nameInPath(path),title,xAxis,yAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
       
    public IHistogram2D createHistogram2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
        return createHistogram2D(path, title, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY,"");
    }
    
    public IHistogram2D createHistogram2D(String pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
        return createHistogram2D(pathAndTitle, nameInPath(pathAndTitle), nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY);
    }
        
    public IHistogram2D createHistogram2D(String path, String title, double[] binEdgesX, double[] binEdgesY, String options) {
        IAxis xAxis = new VariableAxis(binEdgesX);
        IAxis yAxis = new VariableAxis(binEdgesY);
        Histogram2D result = new Histogram2D(nameInPath(path),title,xAxis,yAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }

    public IHistogram2D createHistogram2D(String path, String title, double[] binEdgesX, double[] binEdgesY) {
        return createHistogram2D(path,title,binEdgesX,binEdgesY,"");
    }
    
    public IHistogram2D createCopy(String path, IHistogram2D hist) {
        Histogram2D newHist = copy(nameInPath(path),hist);
        if (tree != null) tree.addFromFactory( parentPath(path),newHist);
        return newHist;
    }

    private Histogram2D copy(String name, IHistogram2D hist) {
        Histogram2D oldHist = (Histogram2D) hist;
        IAxis xAxis = oldHist.xAxis();
        IAxis yAxis = oldHist.yAxis();
        Histogram2D newHist = new Histogram2D(name, oldHist.title(), copy( xAxis ), copy( yAxis ), oldHist.options() );

        int xBins = xAxis.bins()+2;
        int yBins = yAxis.bins()+2;
        
        double[][] heights = new double[xBins][yBins];
        double[][] errors  = new double[xBins][yBins];
        double[][] meanXs  = new double[xBins][yBins];
        double[][] rmsXs   = new double[xBins][yBins];
        double[][] meanYs  = new double[xBins][yBins];
        double[][] rmsYs   = new double[xBins][yBins];
        int[][]    entries = new int   [xBins][yBins];
        
        for(int i=IAxis.UNDERFLOW_BIN; i<xBins-2;i++) {
            for(int j=IAxis.UNDERFLOW_BIN; j<yBins-2;j++) {
                int xbin = oldHist.mapBinNumber(i,xAxis);
                int ybin = oldHist.mapBinNumber(j,yAxis);
                heights[xbin][ybin] = oldHist.binHeight(i,j);
                errors [xbin][ybin] = oldHist.binError(i,j);
                entries[xbin][ybin] = oldHist.binEntries(i,j);
                meanXs [xbin][ybin] = oldHist.binMeanX(i,j);
                rmsXs  [xbin][ybin] = oldHist.binRmsX(i,j);
                meanYs [xbin][ybin] = oldHist.binMeanY(i,j);
                rmsYs  [xbin][ybin] = oldHist.binRmsY(i,j);
            }
        }
        newHist.setContents(heights,errors,entries,meanXs,rmsXs,meanYs,rmsYs);
        newHist.setMeanX( oldHist.meanX() );
        newHist.setRmsX( oldHist.rmsX() );
        newHist.setMeanY( oldHist.meanY() );
        newHist.setRmsY( oldHist.rmsY() );
        newHist.setNEntries( oldHist.allEntries() );
        newHist.setFillable( oldHist.isFillable() );
        return newHist;
    }

    /**
     * Create a IHistogram3D.
     *
     */
    public IHistogram3D createHistogram3D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ, String options) {
        IAxis xAxis = new FixedAxis(nBinsX, lowerEdgeX, upperEdgeX);
        IAxis yAxis = new FixedAxis(nBinsY, lowerEdgeY, upperEdgeY);
        IAxis zAxis = new FixedAxis(nBinsZ, lowerEdgeZ, upperEdgeZ);
        Histogram3D result = new Histogram3D(nameInPath(path),title,xAxis,yAxis,zAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
    
    public IHistogram3D createHistogram3D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) {
        return createHistogram3D(path, title, nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, nBinsZ, lowerEdgeZ, upperEdgeZ, "");
    }
    
    public IHistogram3D createHistogram3D(String pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, int nBinsZ, double lowerEdgeZ, double upperEdgeZ) {
        return createHistogram3D(pathAndTitle, nameInPath(pathAndTitle), nBinsX, lowerEdgeX, upperEdgeX, nBinsY, lowerEdgeY, upperEdgeY, nBinsZ, lowerEdgeZ, upperEdgeZ, "");
    }
        
    public IHistogram3D createHistogram3D(String path, String title, double[] binEdgesX, double[] binEdgesY, double[] binEdgesZ, String options) {
        IAxis xAxis = new VariableAxis(binEdgesX);
        IAxis yAxis = new VariableAxis(binEdgesY);
        IAxis zAxis = new VariableAxis(binEdgesZ);
        Histogram3D result = new Histogram3D(nameInPath(path),title,xAxis,yAxis,zAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }
        
    public IHistogram3D createHistogram3D(String path, String title, double[] binEdgesX, double[] binEdgesY, double[] binEdgesZ) {
        return createHistogram3D(path,title,binEdgesX,binEdgesY,binEdgesZ,"");
    }
    
    public IHistogram3D createCopy(String path, IHistogram3D hist) {
        Histogram3D newHist = copy(nameInPath(path),hist);
        if (tree != null) tree.addFromFactory( parentPath(path),newHist);
        return newHist;
    }

    private Histogram3D copy(String name, IHistogram3D hist) {
        Histogram3D oldHist = (Histogram3D) hist;
        IAxis xAxis = oldHist.xAxis();
        IAxis yAxis = oldHist.yAxis();
        IAxis zAxis = oldHist.zAxis();
        Histogram3D newHist = new Histogram3D(name, oldHist.title(), copy( xAxis ), copy( yAxis ), copy( zAxis ), oldHist.options() );

        int xBins = xAxis.bins()+2;
        int yBins = yAxis.bins()+2;
        int zBins = zAxis.bins()+2;
        
        double[][][] heights = new double[xBins][yBins][zBins];
        double[][][] errors  = new double[xBins][yBins][zBins];
        double[][][] meanXs  = new double[xBins][yBins][zBins];
        double[][][] rmsXs   = new double[xBins][yBins][zBins];
        double[][][] meanYs  = new double[xBins][yBins][zBins];
        double[][][] rmsYs   = new double[xBins][yBins][zBins];
        double[][][] meanZs  = new double[xBins][yBins][zBins];
        double[][][] rmsZs   = new double[xBins][yBins][zBins];
        int[][][]    entries = new int   [xBins][yBins][zBins];
        
        for(int i=IAxis.UNDERFLOW_BIN; i<xBins-2;i++) {
            for(int j=IAxis.UNDERFLOW_BIN; j<yBins-2;j++) {
                for(int k=IAxis.UNDERFLOW_BIN; k<zBins-2;k++) {
                    int xbin = oldHist.mapBinNumber(i,xAxis);
                    int ybin = oldHist.mapBinNumber(j,yAxis);
                    int zbin = oldHist.mapBinNumber(k,zAxis);
                    heights[xbin][ybin][zbin] = oldHist.binHeight(i,j,k);
                    errors [xbin][ybin][zbin] = oldHist.binError(i,j,k);
                    entries[xbin][ybin][zbin] = oldHist.binEntries(i,j,k);
                    meanXs [xbin][ybin][zbin] = oldHist.binMeanX(i,j,k);
                    rmsXs  [xbin][ybin][zbin] = oldHist.binRmsX(i,j,k);
                    meanYs [xbin][ybin][zbin] = oldHist.binMeanY(i,j,k);
                    rmsYs  [xbin][ybin][zbin] = oldHist.binRmsY(i,j,k);
                    meanZs [xbin][ybin][zbin] = oldHist.binMeanZ(i,j,k);
                    rmsZs  [xbin][ybin][zbin] = oldHist.binRmsZ(i,j,k);
                }
            }
        }
        newHist.setContents(heights,errors,entries,meanXs,rmsXs,meanYs,rmsYs,meanZs,rmsZs);
        newHist.setMeanX( oldHist.meanX() );
        newHist.setRmsX( oldHist.rmsX() );
        newHist.setMeanY( oldHist.meanY() );
        newHist.setRmsY( oldHist.rmsY() );
        newHist.setMeanZ( oldHist.meanZ() );
        newHist.setRmsZ( oldHist.rmsZ() );
        newHist.setNEntries( oldHist.allEntries() );
        newHist.setFillable( oldHist.isFillable() );
        return newHist;
    }

    /**
     * Create a IProfile1D.
     *
     */
    public IProfile1D createProfile1D(String path, String title, int nBins, double lowerEdge, double upperEdge, String options) {
        IAxis axis = new FixedAxis(nBins,lowerEdge,upperEdge);
        Profile1D result = new Profile1D(nameInPath(path),title,axis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }

    public IProfile1D createProfile1D(String path, String title, int nBins, double lowerEdge, double upperEdge) {
        return createProfile1D(path, title, nBins, lowerEdge, upperEdge, "");
    }

    public IProfile1D createProfile1D(String path, String title, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue, String options) {
        // lowerValue and upperValue currently ignored
        return createProfile1D(path, title, nBins, lowerEdge, upperEdge, "");
    }

    public IProfile1D createProfile1D(String path, String title, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue) {
        // lowerValue and upperValue currently ignored
        return createProfile1D(path, title, nBins, lowerEdge, upperEdge, "");
    }

    public IProfile1D createProfile1D(String pathAndTitle, int nBins, double lowerEdge, double upperEdge) {
        return createProfile1D(pathAndTitle, nameInPath(pathAndTitle), nBins, lowerEdge, upperEdge, "");
    }

    public IProfile1D createProfile1D(String pathAndTitle, int nBins, double lowerEdge, double upperEdge, double lowerValue, double upperValue) {
        // lowerValue and upperValue currently ignored
        return createProfile1D(pathAndTitle, nameInPath(pathAndTitle), nBins, lowerEdge, upperEdge, "");
    }

    public IProfile1D createProfile1D(String path, String title, double[] binEdges, String options) {
        IAxis axis = new VariableAxis(binEdges);
        Profile1D result = new Profile1D(nameInPath(path),title,axis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }

    public IProfile1D createProfile1D(String path, String title, double[] binEdges) {
        return createProfile1D(path,title,binEdges,"");
    }
    
    public IProfile1D createProfile1D(String path, String title, double[] binEdges, double lowerValue, double upperValue, String options) {
        // lowerValue and upperValue currently ignored
        return createProfile1D(path,title,binEdges,"");
    }

    public IProfile1D createProfile1D(String path, String title, double[] binEdges, double lowerValue, double upperValue) {
        return createProfile1D(path,title,binEdges,lowerValue,upperValue,"");
    }
    
    public IProfile1D createCopy(String path, IProfile1D profile) {
        Profile1D oldProfile = (Profile1D) profile;
        Profile1D newProfile = new Profile1D( nameInPath(path), oldProfile.title(), copy( oldProfile.axis() ), oldProfile.options() );
        newProfile.setHistogram( copy(nameInPath(path), oldProfile.histogram() ) );
        if (tree != null) tree.addFromFactory( parentPath(path),newProfile);
        return newProfile;
    }
    
    /**
     * Create a IProfile2D.
     *
     */
    public IProfile2D createProfile2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, String options) {
        IAxis xAxis = new FixedAxis(nBinsX, lowerEdgeX, upperEdgeX);
        IAxis yAxis = new FixedAxis(nBinsY, lowerEdgeY, upperEdgeY);
        Profile2D result = new Profile2D(nameInPath(path),title,xAxis,yAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }

    public IProfile2D createProfile2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
        return createProfile2D(path,title,nBinsX,lowerEdgeX,upperEdgeX,nBinsY,lowerEdgeY,upperEdgeY,"");
    }

    public IProfile2D createProfile2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue, String options) {
        // lowerValue and upperValue currently ignored
        return createProfile2D(path,title,nBinsX,lowerEdgeX,upperEdgeX,nBinsY,lowerEdgeY,upperEdgeY,"");
    }

    public IProfile2D createProfile2D(String path, String title, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue) {
        // lowerValue and upperValue currently ignored
        return createProfile2D(path,title,nBinsX,lowerEdgeX,upperEdgeX,nBinsY,lowerEdgeY,upperEdgeY,"");
    }

    public IProfile2D createProfile2D(String pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY) {
        return createProfile2D(pathAndTitle,nameInPath(pathAndTitle),nBinsX,lowerEdgeX,upperEdgeX,nBinsY,lowerEdgeY,upperEdgeY,"");
    }

    public IProfile2D createProfile2D(String pathAndTitle, int nBinsX, double lowerEdgeX, double upperEdgeX, int nBinsY, double lowerEdgeY, double upperEdgeY, double lowerValue, double upperValue) {
        // lowerValue and upperValue currently ignored
        return createProfile2D(pathAndTitle,nameInPath(pathAndTitle),nBinsX,lowerEdgeX,upperEdgeX,nBinsY,lowerEdgeY,upperEdgeY,"");
    }

    public IProfile2D createProfile2D(String path, String title, double[] binEdgesX, double[] binEdgesY, String options) {
        IAxis xAxis = new VariableAxis(binEdgesX);
        IAxis yAxis = new VariableAxis(binEdgesY);
        Profile2D result = new Profile2D(nameInPath(path),title,xAxis,yAxis,options);
        if (tree != null) tree.addFromFactory(parentPath(path),result);
        return result;
    }

    public IProfile2D createProfile2D(String path, String title, double[] binEdgesX, double[] binEdgesY) {
        return createProfile2D(path,title,binEdgesX,binEdgesY,"");
    }
    
    public IProfile2D createProfile2D(String path, String title, double[] binEdgesX, double[] binEdgesY, double lowerValue, double upperValue, String options) {
        // lowerValue and upperValue currently ignored
        return createProfile2D(path,title,binEdgesX,binEdgesY,"");
    }

    public IProfile2D createProfile2D(String path, String title, double[] binEdgesX, double[] binEdgesY, double lowerValue, double upperValue) {
        return createProfile2D(path,title,binEdgesX,binEdgesY,lowerValue,upperValue,"");
    }
        
    public IProfile2D createCopy(String path, IProfile2D profile) {
        Profile2D oldProfile = (Profile2D) profile;
        Profile2D newProfile = new Profile2D( nameInPath(path), oldProfile.title(), copy( oldProfile.xAxis() ), copy( oldProfile.yAxis() ), oldProfile.options() );
        newProfile.setHistogram( copy(nameInPath(path), oldProfile.histogram() ) );
        if (tree != null) tree.addFromFactory( parentPath(path),newProfile);
        return newProfile;
    }

    /**
     * IHistogram operations
     *
     */
    
    /**
     * Adds two 1D Histogram
     *
     * @return a+b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram1D add(String path, IHistogram1D a, IHistogram1D b) throws IllegalArgumentException {
        IHistogram1D result = histMath.add(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Subtracts two 1D Histogram
     *
     * @return a-b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram1D subtract(String path, IHistogram1D a, IHistogram1D b) throws IllegalArgumentException {
        IHistogram1D result = histMath.sub(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Multiplies two 1D Histogram
     *
     * @return a*b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram1D multiply(String path, IHistogram1D a, IHistogram1D b) throws IllegalArgumentException {
        IHistogram1D result = histMath.mul(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Divides two 1D Histogram
     *
     * @return a/b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram1D divide(String path, IHistogram1D a, IHistogram1D b) throws IllegalArgumentException {
        IHistogram1D result = histMath.div(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Adds two 2D Histogram
     *
     * @return a+b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram2D add(String path, IHistogram2D a, IHistogram2D b) throws IllegalArgumentException {
        IHistogram2D result = histMath.add(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Subtracts two 2D Histogram
     *
     * @return a-b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram2D subtract(String path, IHistogram2D a, IHistogram2D b) throws IllegalArgumentException {
        IHistogram2D result = histMath.sub(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Multiplies two 2D Histogram
     *
     * @return a*b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram2D multiply(String path, IHistogram2D a, IHistogram2D b) throws IllegalArgumentException {
        IHistogram2D result = histMath.mul(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Divides two 2D Histogram
     *
     * @return a/b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram2D divide(String path, IHistogram2D a, IHistogram2D b) throws IllegalArgumentException {
        IHistogram2D result = histMath.div(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
        
    /**
     * Adds two 3D Histogram
     *
     * @return a+b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram3D add(String path, IHistogram3D a, IHistogram3D b) throws IllegalArgumentException {
        IHistogram3D result = histMath.add(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Subtracts two 3D Histogram
     *
     * @return a-b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram3D subtract(String path, IHistogram3D a, IHistogram3D b) throws IllegalArgumentException {
        IHistogram3D result = histMath.sub(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Multiplies two 3D Histogram
     *
     * @return a*b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram3D multiply(String path, IHistogram3D a, IHistogram3D b) throws IllegalArgumentException {
        IHistogram3D result = histMath.mul(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Divides two 3D Histogram
     *
     * @return a/b
     * @throws IllegalArgumentException if histogram binnings are incompatible
     */
    public IHistogram3D divide(String path, IHistogram3D a, IHistogram3D b) throws IllegalArgumentException {
        IHistogram3D result = histMath.div(nameInPath(path), a, b);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a projection from a 2D histogram parallel to the X axis.
     * Equivalent to <tt>sliceX(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     */
    public IHistogram1D projectionX(String path, IHistogram2D h) {
        IHistogram1D result = histMath.sliceX(h, nameInPath(path), IAxis.UNDERFLOW_BIN, IAxis.OVERFLOW_BIN);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a projection from a 2D histogram parallel to the Y axis.
     * Equivalent to <tt>sliceY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     */
    public IHistogram1D projectionY(String path, IHistogram2D h) {
        IHistogram1D result = histMath.sliceY(h, nameInPath(path), IAxis.UNDERFLOW_BIN, IAxis.OVERFLOW_BIN);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Slice parallel to the Y axis from a 2D histogram at bin indexY and one bin wide.
     * Equivalent to <tt>sliceX(indexY,indexY)</tt>.
     */
    public IHistogram1D sliceX(String path, IHistogram2D h, int indexY) {
        IHistogram1D result = histMath.sliceX(h, nameInPath(path),indexY, indexY);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Slice parallel to the X axis from a 2D histogram at bin indexX and one bin wide.
     * Equivalent to <tt>sliceY(indexX,indexX)</tt>.
     */
    public IHistogram1D sliceY(String path, IHistogram2D h, int indexX) {
        IHistogram1D result = histMath.sliceY(h, nameInPath(path),indexX, indexX);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }

    /**
     * Create a slice parallel to the X axis from a 2D histogram,
     * between "indexY1" and "indexY2" (inclusive).
     * The returned IHistogram1D represents an instantaneous snapshot of the
     * histogram at the time the slice was created.
     */
    public IHistogram1D sliceX(String path, IHistogram2D h, int indexY1, int indexY2) {
        //Check the order of the indexes
        IHistogram1D result = histMath.sliceX(h, nameInPath(path),indexY1, indexY2);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a slice parallel to the Y axis from a 2D histogram,
     * between "indexX1" and "indexX2" (inclusive).
     * The returned IHistogram1D represents an instantaneous snapshot of the
     * histogram at the time the slice was created.
     */
    public IHistogram1D sliceY(String path, IHistogram2D h, int indexX1, int indexX2) {
        IHistogram1D result = histMath.sliceY(h, nameInPath(path),indexX1, indexX2);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a projection parallel to the X axis from a 3D histogram.
     * Equivalent to <tt>sliceXY(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     */
    public IHistogram2D projectionXY(String path, IHistogram3D h) {
        IHistogram2D result = histMath.sliceXY(h, nameInPath(path),IAxis.UNDERFLOW_BIN, IAxis.OVERFLOW_BIN);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a projection parallel to the Z axis from a 3D histogram.
     * Equivalent to <tt>sliceXZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     */
    public IHistogram2D projectionXZ(String path, IHistogram3D h) {
        IHistogram2D result = histMath.sliceXZ(h, nameInPath(path),IAxis.UNDERFLOW_BIN, IAxis.OVERFLOW_BIN);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }

    /**
     * Create a projection parallel to the Y axis from a 3D histogram.
     * Equivalent to <tt>sliceYZ(UNDERFLOW_BIN,OVERFLOW_BIN)</tt>.
     */
    public IHistogram2D projectionYZ(String path, IHistogram3D h) {
        IHistogram2D result = histMath.sliceYZ(h, nameInPath(path),IAxis.UNDERFLOW_BIN, IAxis.OVERFLOW_BIN);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a slice perpendicular to the Z axis from a 3D histogram,
     * between "indexZ1" and "indexZ2" (inclusive).
     * The returned IHistogram2D represents an instantaneous snapshot of the
     * histogram at the time the slice was created.
     * The X axis of the returned histogram corresponds to the X axis of this histogram.
     * The Y axis of the returned histogram corresponds to the Y axis of this histogram.
     */
    public IHistogram2D sliceXY(String path, IHistogram3D h, int indexZ1, int indexZ2) {
        IHistogram2D result = histMath.sliceXY(h, nameInPath(path),indexZ1, indexZ2);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
    /**
     * Create a slice perpendicular to the Y axis from a 3D histogram,
     * between "indexY1" and "indexY2" (inclusive).
     * The returned IHistogram2D represents an instantaneous snapshot of the
     * histogram at the time the slice was created.
     * The X axis of the returned histogram corresponds to the X axis of this histogram.
     * The Y axis of the returned histogram corresponds to the Z axis of this histogram.
     */
    public IHistogram2D sliceXZ(String path, IHistogram3D h, int indexY1, int indexY2) {
        IHistogram2D result = histMath.sliceXZ(h, nameInPath(path),indexY1, indexY2);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    /**
     * Create a slice perpendicular to the X axis from a 3D histogram,
     * between "indexX1" and "indexX2" (inclusive).
     * The returned IHistogram2D represents an instantaneous snapshot of the
     * histogram at the time the slice was created.
     * The X axis of the returned histogram corresponds to the Y axis of this histogram.
     * The Y axis of the returned histogram corresponds to the Z axis of this histogram.
     */
    public IHistogram2D sliceYZ(String path, IHistogram3D h, int indexX1, int indexX2) {
        IHistogram2D result = histMath.sliceYZ(h, nameInPath(path),indexX1, indexX2);
        if (tree != null && result instanceof IManagedObject) tree.addFromFactory( parentPath(path),(IManagedObject) result);
        return result;
    }
    
}
