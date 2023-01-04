package org.mathiasGarnier.mario;

import javax.swing.JFrame;

public class Main {

	public static Scene sc;
	
	public static void main(String[] args) {
		
		//JFrame de l'application
		JFrame jf = new JFrame("Mario !!");
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setSize(720, 360);
		jf.setLocationRelativeTo(null);
		jf.setResizable(false);
		jf.setAlwaysOnTop(true);
		
		sc = new Scene();
		jf.setContentPane(sc);
		jf.setVisible(true);
	}

}
