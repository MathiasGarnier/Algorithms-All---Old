package fr.mathiasGarnier.swingTest;

import java.awt.Color;
import java.awt.GradientPaint;
import java.awt.Graphics;
import java.awt.Graphics2D;

import javax.swing.JPanel;

public class Pannel extends JPanel{

	/**
	 * @author Yapix 
	 */
	
	private static final long serialVersionUID = -6302633729025338221L;

		public void paintComponent(Graphics graph){
			Graphics2D g2d = (Graphics2D) graph;         
		    GradientPaint gp = new GradientPaint((float) Math.PI, (float) Math.E, Color.CYAN, (float) Math.pow(Math.PI, Math.PI), (float) Math.pow(-(Math.PI), Math.PI), Color.GRAY, true);                
		    g2d.setPaint(gp);
		    g2d.fillRect(0, 0, this.getWidth(), this.getHeight()); 
		}
}
//Black renderer x)
