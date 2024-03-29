package hep.physics.jet;
//
// FixNumberOfJetsFinder.java
//
// JetFinder which uses another JetFinder to devide an event into
// a specified number of jets
//
// author : W.Walkowiak 03/08/01
// changed: w.w., 06/20/01  -- simplified with binary search
//          w.w., 06/21/02  -- added safety check including new Exception
//
import hep.physics.filter.Predicate;
import hep.physics.vec.HepLorentzVector;
import java.util.Collection;
import java.util.List;

/*
 * JetFinder which divides an event into a specified number of Jets
 * using another ycut based JetFinder
 *
 * @author  Wolfgang Walkowiak
 * @version $Id: FixNumberOfJetsFinder.java,v 1.2 2005/03/14 06:02:17 tonyj Exp $
 */
public class FixNumberOfJetsFinder implements JetFinder
{
   private AbstractJetFinder m_jetFinder = new JadeEJetFinder(0.01);
   private int       m_nReqJets          = 2;
   private double    m_ycut              = -1;
   private boolean   m_resultsValid      = false;
   
   /**
    * Default constructor, sets up JadeEJetFinder.
    */
   public FixNumberOfJetsFinder()
   {    }
   
   /**
    * Constructor specifying number of requested jets,
    * sets up JadeEJetFinder as default.
    * @param nJets number of jets to be formed
    */
   public FixNumberOfJetsFinder(int nJets)
   {
      setNJets(nJets);
   }
   
   /**
    * Constructor to specify a specfic JetFinder to use.
    * @param jetFinder JetFinder to use
    * @see   AbstractJetFinder
    */
   public FixNumberOfJetsFinder(AbstractJetFinder jetFinder)
   {
      setJetFinder(jetFinder);
   }
   
   /**
    * Constructor to specify rquested number of jets and
    * a specfic JetFinder to use.
    * @param nJets     number of jets to be formed
    * @param jetFinder JetFinder to use
    * @see   AbstractJetFinder
    */
   public FixNumberOfJetsFinder(int nJets, AbstractJetFinder jetFinder)
   {
      setJetFinder(jetFinder);
      setNJets(nJets);
   }
   
   /**
    * Specify the underlying JetFinder you want to use
    * @param jetFinder JetFinder to use
    * @see   AbstractJetFinder
    */
   protected void setJetFinder(AbstractJetFinder jetFinder)
   {
      if ( jetFinder == null)
         throw new IllegalArgumentException("FixNumberOfJetsFinder: "+
                 "no JetFinder defined!");
      this.m_jetFinder = jetFinder;
      m_resultsValid   = false;
   }
   
   /**
    * Set number of jets requested to be formed.
    * @param nJets number of jets to be formed
    */
   public void setNJets(int nJets)
   {
      if ( nJets != m_nReqJets ) m_resultsValid = false;
      this.m_nReqJets = nJets;
   }
   
   /**
    * Actual number jets formed.
    * Should be the same as the number of jets requested, unless
    * a problem occured.  (E.g. too little input objects.)
    * @return number of jets
    * @see    JetFinder#njets
    */
   public int njets()
   {
      if ( !m_resultsValid ) doFindJets();
      return m_jetFinder.njets();
   }
   
   /**
    * Resulting ycut value.
    * @return final ycut
    */
   public double getYCut()
   {
      if ( !m_resultsValid ) doFindJets();
      return m_ycut;
   }
   
   /**
    * Four vector of a specific jet.
    * @parameter index index of jet
    * @return    jet   Lorentz vector for the entire jet
    * @see       JetFinder#jet
    */
   public HepLorentzVector jet(int index)
   {
      if ( !m_resultsValid ) doFindJets();
      return m_jetFinder.jet(index);
   }
   
   /**
    * Particles in a specific jet.
    * @parameter index index of jet
    * @return    enumeration of particles
    * @see       JetFinder#particlesInJet
    */
   public List particlesInJet(int index)
   {
      if ( !m_resultsValid ) doFindJets();
      return m_jetFinder.particlesInJet(index);
   }
   
   /**
    * Number of particles in a specific jet.
    * @parameter index index of jet
    * @return    number of particles
    * @see       JetFinder#NParticlesPerJet
    */
   public int nParticlesPerJet(int index)
   {
      if ( !m_resultsValid ) doFindJets();
      return m_jetFinder.nParticlesPerJet(index);
   }
   
   /**
    * Jet with the fewest tracks
    * @return    index of jet with fewest tracks
    * @see       JetFinder#fewestTracks
    */
   public int fewestTracks()
   {
      if ( !m_resultsValid ) doFindJets();
      return m_jetFinder.fewestTracks();
   }
   
   /**
    * Give event information to JetFinder
    * @param     e Enumeration of Hep3Vectors or HepLorentzVectors
    * @see       JetFinder#setEvent(Enumeration)
    */
   public void setEvent(Collection data)
   {
      setEvent(data,null);
   }
   
   /**
    * Give event information to JetFinder
    * @param     e   Enumeration of Hep3Vectors or Hep4Vectors
    * @param     cut predicate to impose a cut on the particles in event
    * @see       JetFinder#setEvent(Enumeration, Predicate)
    */
   public void setEvent(Collection data, Predicate cut)
   {
      m_resultsValid = false;
      m_jetFinder.setEvent(data,cut);
   }
   
     /*
      * Does the subdivision of the event into jets.
      */
   private void doFindJets()
   {
      double ycut    =  0.5;
      int    njets   = -1;
      
      double yHigh  = 0.999999;
      double yLow   = 0.000001;
      
      while ( njets != m_nReqJets )
      {
         
         ycut  = 0.5*(yLow+yHigh);
         m_jetFinder.setYCut(ycut);
         njets = m_jetFinder.njets();
         
         if ( Math.abs(yHigh-yLow) < 1.e-10 ) throw new
                 FixNumberOfJetsFinder.NumJetsNotFoundException(
                 "JetFinder:  Can not find "+m_nReqJets+" !");
         
         if ( njets > m_nReqJets ) yLow  = ycut;
         if ( njets < m_nReqJets ) yHigh = ycut;
      }
      m_ycut         = ycut;
      m_resultsValid = true;
   }
   
   public static class NumJetsNotFoundException extends RuntimeException
   {
      public NumJetsNotFoundException(String s)
      {
         super(s);
      }
   }
}




