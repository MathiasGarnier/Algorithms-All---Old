package fr.mathiasGarnier.swingTest;


import java.awt.FlowLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;

public class FirstGui {

	public static void main(String[] args){
		
		Abc obj = new Abc();
	}
}
class Abc extends JFrame{
	public Abc(){
		
		JLabel t = new JLabel("Result");
		add(t);
		
		JButton first = new JButton("Search");
		add(first);
		
		setLayout(new FlowLayout());
		setVisible(true);
		setSize(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}
