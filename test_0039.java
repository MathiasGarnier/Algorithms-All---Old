package fr.mathiasGarnier.swingTest;

import java.awt.Graphics;

import javax.swing.JPanel;

public class Pannel extends JPanel{

	/**
	 * @author Yapix 
	 */
	
	private static final long serialVersionUID = -6302633729025338221L;

		public void paintComponent(Graphics graph){
		    int x1 = this.getWidth() / 4;
		    int y1 = this.getHeight() / 4; 
		    
		    graph.fillOval(x1, y1, this.getWidth() / 2, this.getHeight() / 2);
		    graph.drawLine(x1, y1, this.getWidth() / 2, this.getHeight() / 2);
		}
}
