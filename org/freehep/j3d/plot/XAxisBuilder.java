package org.freehep.j3d.plot;
import javax.media.j3d.*;
import javax.vecmath.*;

/**
 * @author Joy Kyriakopulos (joyk@fnal.gov)
 * @version $Id: XAxisBuilder.java,v 1.1 2001/05/19 00:11:58 tonyj Exp $
 */
public class XAxisBuilder extends AxisBuilder
{
	public XAxisBuilder()
	{
	}
	public XAxisBuilder(String label, String[] tickLabels, double[] tickLocations)
	{
		setLabel(label);
		setTickLabels(tickLabels);
		setTickLocations(tickLocations);
	}
	public Node getNode()
	{
		Transform3D t3d = new Transform3D();
		t3d.set(1/scale,new Vector3f(-0.5f,-0.5f,0));
		TransformGroup tg = new TransformGroup(t3d);
		tg.addChild(super.getNode());
		return tg;		
	}
}
