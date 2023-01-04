package fr.mathiasGarnier.swingTest;


import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class FirstGui {

	public static void main(String[] args){
		
		Add obj = new Add();
	}
}
class Add extends JFrame implements ActionListener{
	
	JTextField jt, jt1;
	JLabel label;
	JButton button;
	
	public Add(){
		
		jt = new JTextField(20);
		add(jt);
		jt1 = new JTextField(20);
		add(jt1);
		
		label = new JLabel("");
		add(label);
		
		button = new JButton("Result");
		add(button);
		
		button.addActionListener(this);
		
		
		setLayout(new FlowLayout());
		setVisible(true);
		setSize(300, 300);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
	
		int first = Integer.parseInt(jt.getText()); 
		int second = Integer.parseInt(jt1.getText());

		int result = first + second;
		label.setText(result + "");
	}
}
