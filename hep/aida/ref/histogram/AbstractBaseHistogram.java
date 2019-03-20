package hep.aida.ref.histogram;

/**
 * Implementation of IBaseHistogram.
 *
 * @author The AIDA Team at SLAC.
 *
 */
import java.util.ArrayList;
import java.util.Map;
import java.util.Iterator;

import hep.aida.*;
import hep.aida.ref.*;

public abstract class AbstractBaseHistogram extends ManagedObject implements IBaseHistogram {
    
    private int dimension;
    private IAnnotation annotation;
    
    // Allowed keys that can be set in the annotation from options
    static String[] styleKeys = {"xaxislabel", "xaxisscale", "xaxistype", "yaxislabel", "yaxisscale", "yaxistype"};
    
    /**
     * Creates a new instance of BaseHistogram.
     * @param name The name of the BaseHistogram. See ManagedObject for details.
     * @param title The title of the BaseHistogram.
     * @param dimension The dimension of the BaseHistogram.
     *
     */
    public AbstractBaseHistogram(String name, String title, int dimension) {
        this(name, title, dimension, null);
    }
    public AbstractBaseHistogram(String name, String title, int dimension, String options) {
        super(name);
        this.dimension = dimension;
        annotation = new Annotation();
        annotation.addItem(Annotation.titleKey,title,true);
        setOptions(options);
    }
    
    private void setOptions(String options) {
        if (options == null || options.trim().equals("")) return;
        String[] arr = AidaUtils.parseString(options);
        if (arr == null || arr.length == 0) return;
        ArrayList list = new ArrayList();
        for (int i=0; i<arr.length; i++) {
            String tmp = arr[i];
            if (tmp.length() > 11 && tmp.substring(0, 11).equalsIgnoreCase("annotation.")) {
                String key = tmp.substring(11);
                int index = key.indexOf("=");
                if (index > 0) key = key.substring(0, index);
                list.add(key);
            }
        }
        Map optionMap = AidaUtils.parseOptions( options );
        Iterator it = optionMap.keySet().iterator();
        while (it.hasNext()) {
            String key = (String) it.next();
            for (int i=0; i<list.size(); i++) {
                if (key.equals((String) list.get(i))) {
                    String val = (String) optionMap.get(key);
                    if (val != null) annotation.addItem(key, val, true);
                }
            }
        }
    }
    
    
    /**
     * Get the histogram title.
     * @return the Histogram title.
     *
     */
    public String title() {
        String title =  annotation.value(Annotation.titleKey);
        if ( title == null )
            title = "";
        return title;
    }
    
    /**
     * Set the histogram title.
     * @param title The title.
     *
     */
    public void setTitle(String title) {
        if ( title == null )
            title = "";
        annotation.setValue(Annotation.titleKey,title);
        if (isValid) fireStateChanged();
    }
    
    /**
     * Get the IAnnotation associated with the histogram.
     * @return The IAnnotation.
     *
     */
    public IAnnotation annotation() {
        return annotation;
    }
    
    public void setAnnotation( IAnnotation annotation ) {
        this.annotation = annotation;
    }
    
    /**
     * Get the dimension of the histogram.
     *
     */
    public int dimension() {
        return dimension;
    }
    
    /**
     * Reset the histogram; as if just created.
     *
     */
    public void reset() {
        annotation.reset();
    }
    
    /**
     * Number of in-range entries in the histogram.
     * @return The number of in-range entries.
     *
     */
    abstract public int entries();
    
    /**
     * Number of entries whose coordinate or weight is NaN. Such entries
     * are counted as allEntries but don't contribute to the statistics.
     * @return The number of entries whose value or weight is NaN.
     *
     */
    abstract public int nanEntries();
    
}
