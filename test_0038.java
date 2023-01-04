package fr.mathiasGarnier.swingTest;

import java.awt.Graphics;

import javax.swing.JPanel;

public class Pannel extends JPanel{

	/**
	 * @author Yapix 
	 */
	
	private static final long serialVersionUID = -6302633729025338221L;

		public void paintComponent(Graphics graph){
			System.out.println("Start");
			graph.fillOval(20, 20, 75, 75);
			graph.draw3DRect(20, 20, 75, 75, false);
			graph.drawOval(50, 50, 150, 150);
		}
}
