package org.freehep.j3d.plot;
import javax.media.j3d.*;
import javax.vecmath.*;

/**
 * @author Joy Kyriakopulos (joyk@fnal.gov)
 * @version $Id: YAxisBuilder.java,v 1.1 2001/05/19 00:11:58 tonyj Exp $
 */
public class YAxisBuilder extends AxisBuilder
{
	public YAxisBuilder()
	{
	}
	public YAxisBuilder(String label, String[] tickLabels, double[] tickLocations)
	{
		setLabel(label);
		setTickLabels(tickLabels);
		setTickLocations(tickLocations);
	}
	public Node getNode()
	{
		Transform3D t3d = new Transform3D();
		t3d.set(1/scale,new Vector3f(-0.5f,+0.5f,0));
		Transform3D rot = new Transform3D();
		rot.rotZ(-Math.PI/2);
		t3d.mul(rot);
		TransformGroup tg = new TransformGroup(t3d);
		tg.addChild(super.getNode());
		return tg;		
	}
}
