package hep.physics.event.generator;

import hep.physics.event.BaseEvent;
import java.util.List;

/**
 * EventHeader for an event generator. Provides the output of the
 * generator.
 * @author Gary Bower
 * @version $Id: GeneratorEvent.java,v 1.1 2005/03/14 06:02:16 tonyj Exp $
 */

public class GeneratorEvent extends BaseEvent implements MCEvent
{
   public GeneratorEvent(int run, int event)
   {
      super(run,event);
   }
   public List getMCParticles()
   {
      return (List) get(MCEvent.MC_PARTICLES);
   }   
}

