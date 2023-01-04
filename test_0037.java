package fr.mathiasGarnier.swingTest;

import java.awt.Color;

import javax.swing.JFrame;

public class Windows extends JFrame{

	/**
	 * @author Yapix
	 */
	
	private static final long serialVersionUID = 127508451688950397L;
	
	public Windows(){
		this.setVisible(true);
		this.setSize(830, 470);
		this.setTitle("JFrame");
		this.setLocationRelativeTo(null);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setResizable(false);
		this.getContentPane().setBackground(Color.GRAY);
	}
}
//Yeahhhh x)
