package fr.mathiasGarnier.swingTest;

import javax.swing.JFrame;

public class FirstGui {

	public static void main(String[] args){ //If you put Main instead of main, result = nil
		
		Abc obj = new Abc();
		obj.setVisible(true);
		}
}
class Abc extends JFrame{
	public Abc(){
		
	}
}
