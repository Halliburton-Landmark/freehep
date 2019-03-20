package hep.aida.hbook;

import java.util.*;

import org.freehep.util.*;

import hep.aida.*;

/**
 * HBookAida.java
 *
 * WARNING: only a few call are implemented.
 *
 * @author Mark Donszelmann
 * @version $Id: HBook.java,v 1.1 2001/03/29 09:46:57 duns Exp $
 */

public class HBook {
    
    // Decided to put Histograms and NTuples in separate tables
    // to make checking easier.
    private static Map histoTable = new HashMap();
    private static Map tupleTable = new HashMap();
    private static IHistogramFactory histoFactory;
    private static ITupleFactory tupleFactory;
    
    static {
        histoFactory = (IHistogramFactory)Factory.loadFactory("hep.aida.IHistogramFactory", "aida.properties", "hep.aida.ref.HistogramFactory");
        tupleFactory = (ITupleFactory)Factory.loadFactory("hep.aida.ITupleFactory", "aida.properties", "hep.aida.ref.TupleFactory");
    }
    
    // static class
    private HBook() {
    }

//    
// Chapter 2
//
    
    public static void hbook1 (int id, String chtitl, int nx, float xmi, float xma, float vmx) {
        if (id == 0) {
            error("hbook1: id=0 is an illegal identifier");
            return;
        }
        
        Integer key = new Integer(id);

        if (nx == 0) nx = 100;
        
        if (histoTable.get(key) != null) {
            error("hbook1: Already existing histogram ("+id+") replaced");
        }
        
        IHistogram1D histo = histoFactory.create1D(key.toString(), chtitl, nx, xmi, xma); 
        histoTable.put(key, histo);
    }

    public static void hbook2 (int id, String chtitl, int nx, float xmi, float xma, 
                                               int ny, float ymi, float yma, float vmx) {
        if (id == 0) {
            error("hbook2: id=0 is an illegal identifier");
            return;
        }
        
        Integer key = new Integer(id);

        if (nx == 0) nx = 100;
        if (ny == 0) ny = 100;
        
        if (histoTable.get(key) != null) {
            error("hbook2: Already existing histogram ("+id+") replaced");
        }
        
        IHistogram2D histo = histoFactory.create2D(key.toString(), chtitl, nx, xmi, xma, ny, ymi, yma); 
        histoTable.put(key, histo);
    }
                                
    public static void hfill (int id, float x, float y, float weight) {
        if (id == 0) {
            error("hfill: id=0 is an illegal identifier");
            return;
        }
        Integer key = new Integer(id);
        
        Object histo = histoTable.get(key);    
        if (histo == null) {
            error("hfill: trying to fill an unbooked histogram ("+id+")");
            return;
        }
        
        if (histo instanceof IHistogram1D) {
            // FIXME: handle profile filling
            hf1((IHistogram1D)histo, x, weight);
        } else if (histo instanceof IHistogram2D) {
            // FIXME: handle profile filling
            hf2((IHistogram2D)histo, x, y, weight);           
        } else {
            error("hfill: ("+id+") is not a Histogram, but a "+histo.getClass());
            return;
        }
    }
    
    public static void histdo () {
        notImplemented("histdo");
    }

    public static void hprint (int id) {
        notImplemented("hprint");
    }

    public static void hcopy (int id1, int id2, String chtitl) {
        notImplemented("hcopy");
    }

    public static void hcopyr (int id1, int id2, String chtitl, 
                               int ibinx1, int ibinx2, int ibiny1, int ibiny2, String chopt) {
        notImplemented("hcopyr");
    }

    public static void hrenid (int oldid, int newid) {
        Integer oldkey = new Integer(oldid);
        // Works on both histograms and ntuples
        Object obj = histoTable.get(oldkey);
        if (obj != null) {
            histoTable.remove(oldkey);
            histoTable.put(new Integer(newid), obj);
            return;
        }   
        
        obj = tupleTable.get(oldkey);
        if (obj != null) {
            tupleTable.remove(oldkey);
            tupleTable.put(new Integer(newid), obj);
            return;
        } 
        
        error("rename of id not possible because it does not exist ("+oldid+")");
    }

    // FIXME: chtitle ignored
    public static void hreset (int id, String chtitl) {
        if (id == 0) {
            for (Iterator i=histoTable.keySet().iterator(); i.hasNext(); ) {
                Integer key = (Integer)i.next();
                hreset(key.intValue(), chtitl);
            }
        } else {
            Integer key = new Integer(id);
            IHistogram histo = (IHistogram)histoTable.get(key);
            histo.reset();
        }
    }

    public static void hdelet (int id) {
        if (id == 0) {
            histoTable.clear();
        } else {
            histoTable.remove(new Integer(id));
        }
    }

//
// Chapter 3
//
    public static void hbookn (int id, String chtitl, int nvar, String chrzpa, int nwbuff, String[] chtags) {
        if (id == 0) {
            error("hbookn: id=0 is an illegal identifier");
            return;
        }
        
        Integer key = new Integer(id);
        
        if (tupleTable.get(key) != null) {
            error("hbookn: Already existing Ntuple ("+id+") replaced");
        }
        
        Class[] columnTypes = new Class[chtags.length];
        for (int i=0; i<columnTypes.length; i++) {
            columnTypes[i] = float.class;
        }
        // FIXME: need a store!
        ITuple tuple = tupleFactory.create(key.toString(), chtitl, null, chtags, columnTypes, "");
        tupleTable.put(key, tuple);
    }
    
    public static void hfn (int id, float[] x) {
        if (id == 0) {
            error("hfn: id=0 is an illegal identifier");
            return;
        }
        Integer key = new Integer(id);
        
        Object tuple = tupleTable.get(key);    
        if (tuple == null) {
            error("hfn: trying to fill an unbooked Ntuple ("+id+")");
            return;
        }
        
        if (tuple instanceof ITuple) {
            ((ITuple)tuple).fill(x);
        } else {
            error("hfn: ("+id+") is not a Ntuple, but a "+tuple.getClass());
            return;
        }
    }
    
    public static void hproj1(int id, int idn, int isel, WeightFunction fun, int ifrom, int ito, int ivarx) {
        IHistogram1D histo = (IHistogram1D)histoTable.get(new Integer(id));
        if (histo == null) {
            error("Histogram with id ("+id+") was not booked.");
            return;
        }
        
        ITuple tuple = (ITuple)tupleTable.get(new Integer(idn));
        if (tuple == null) {
            error("NTuple with id ("+idn+") does not exist.");
            return;
        }
        
        tuple.start();
        if (ifrom > 1) {
            if (!tuple.skip(ifrom-1)) {
                error("NTuple contains "+tuple.rows()+", which is less than ifrom: "+ifrom);
                return;
            }
        }
        
        for (int i=ifrom; i <= ito; i++) {
            if (!tuple.next()) {
                error("NTuple contains "+tuple.rows()+", which is less than ito: "+ito);
                break;
            }
            float x = tuple.getFloat(ivarx-1);
            float weight = 1.0f;
            if (isel != 0) {
                weight = fun.weight(x, isel);
            }
             
            if (weight != 0) {   
                histo.fill(x, weight);
            }
        }
    }
    
    public static void hproj2(int id, int idn, int isel, WeightFunction fun, int ifrom, int ito, int ivarx, int ivary) {
        IHistogram2D histo = (IHistogram2D)histoTable.get(new Integer(id));
        if (histo == null) {
            error("Histogram with id ("+id+") was not booked.");
            return;
        }
        
        ITuple tuple = (ITuple)tupleTable.get(new Integer(idn));
        if (tuple == null) {
            error("NTuple with id ("+idn+") does not exist.");
            return;
        }

        tuple.start();
        if (ifrom > 1) {
            if (!tuple.skip(ifrom-1)) {
                error("NTuple contains "+tuple.rows()+", which is less than ifrom: "+ifrom);
                return;
            }
        }
        
        for (int i=ifrom; i <= ito; i++) {
            if (!tuple.next()) {
                error("NTuple contains "+tuple.rows()+", which is less than ito: "+ito);
                break;
            }
            float x = tuple.getFloat(ivarx-1);
            float y = tuple.getFloat(ivary-1);
            float weight = 1.0f;
            if (isel != 0) {
                weight = fun.weight(x, y, isel);
            }
            
            if (weight != 0) { 
                histo.fill(x, y, weight);
            }
        }
    }
        
    public static String getTitle(int id) {
        if (id == 0) {
            error("getTitle: id=0 is an illegal identifier");
            return "";
        }
        
        Integer key = new Integer(id);
        
        ITuple tuple = (ITuple)tupleTable.get(key);    
        // FIXME: cannot return the title, since it is missing in ITuple interface
        return (tuple == null) ? "" : key.toString();        
    }

    public static int getColumns(int id) {
        if (id == 0) {
            error("getColumns: id=0 is an illegal identifier");
            return 0;
        }
        Integer key = new Integer(id);
        
        ITuple tuple = (ITuple)tupleTable.get(key);    
        return (tuple == null) ? 0 : tuple.columns();
    }
    
    public static int hgiven(int id, String[] chtag, float[] rlow, float[] rhigh) {
        if (id == 0) {
            error("hgiven: id=0 is an illegal identifier");
            return 0;
        }
        Integer key = new Integer(id);
        
        ITuple tuple = (ITuple)tupleTable.get(key);    
        if (tuple == null) return 0;
        
        for (int i=0; i<chtag.length; i++) {
            chtag[i] = tuple.columnName(i);
            rlow[i] = (float)tuple.columnMin(i);
            rhigh[i] = (float)tuple.columnMax(i);
        }
        return tuple.columns();
    }

    public static int hgn (int id, int idnevt, float[] x) {
        if (id == 0) {
            error("hgn: id=0 is an illegal identifier");
            return 1;
        }
        Integer key = new Integer(id);
        
        ITuple tuple = (ITuple)tupleTable.get(key);    
        if (tuple == null) return 1;
        
        tuple.start();
        if (idnevt > 1) {
            if (!tuple.skip(idnevt-1)) {
                error("NTuple contains "+tuple.rows()+", which is less than idnevt: "+idnevt);
                return 1;
            }
        }
        if (!tuple.next()) {
            error("NTuple contains "+tuple.rows()+", which is less than idnevt: "+idnevt);
            return 1;
        }
        
        if (x.length < tuple.columns()) {
            error("NTuple contains "+tuple.columns()+", which is larger than the size of array x: "+x.length);
            return 1;
        }
        
        for (int i=0; i<tuple.columns(); i++) {
            x[i] = tuple.getFloat(i);
        }
        
        return 0;
    }

    public static void hgnpar (int id, String chrout) {
        // ignored
    }

    public static int hgnf (int id, int idnevt, float[] x) {
        return hgn(id, idnevt, x);
    }
    
//
// Chapter 4
//    
    public static void hf1 (int id, float x, float weight) {
        hf1((IHistogram1D)histoTable.get(new Integer(id)), x, weight);
    }
    
    private static void hf1 (IHistogram1D histo, float x, float weight) {
        histo.fill(x, weight);
    }
            
    public static void hf2 (int id, float x, float y, float weight) {
        hf2((IHistogram2D)histoTable.get(new Integer(id)), x, y, weight);
    }
   
    private static void hf2 (IHistogram2D histo, float x, float y, float weight) {
        histo.fill(x, y, weight);
    }
   

//
// Private
//
    private static void notImplemented(String name) {
        error("function: "+name+"() is not implemented.");
    }

    private static void error(String msg) {
        System.err.println("HBookAida: "+msg);
    }
}

