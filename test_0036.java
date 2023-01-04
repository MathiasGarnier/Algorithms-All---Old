package fr.mathiasGarnier.swingTest;

import javax.swing.JFrame;

public class FirstGui {

	public static void main(String[] args){
	
		JFrame windows = new JFrame();
		
		windows.setVisible(true);
		windows.setSize(360, 360);
		windows.setTitle("JFrame");
		windows.setLocationRelativeTo(null);
		windows.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
