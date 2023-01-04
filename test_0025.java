package fr.mathiasGarnier.swingTest;

import javax.swing.JFrame;
import javax.swing.JLabel;

public class FirstGui {

	public static void main(String[] args){
		
		Abc obj = new Abc();
	}
}
class Abc extends JFrame{
	public Abc(){
		
		JLabel label = new JLabel("Hello");
		add(label);
		setVisible(true);
		setSize(300, 300);
	}
}
//Yeahhhhh xD
