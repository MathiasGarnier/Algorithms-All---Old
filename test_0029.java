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
	JButton add, min, mul, div, mod;
	
	public Add(){
		
		jt = new JTextField(12);
		add(jt);
		jt1 = new JTextField(12);
		add(jt1);
		label = new JLabel("");
		add(label);
		add = new JButton("+");
		add(add);
		min = new JButton("-");
		add(min);
		mul = new JButton("*");
		add(mul);
		div = new JButton("/");
		add(div);
		mod = new JButton("%");
		add(mod);
		
		add.addActionListener(this);
		min.addActionListener(this);
		mul.addActionListener(this);
		div.addActionListener(this);
		mod.addActionListener(this);
		
		setLayout(new FlowLayout());
		setVisible(true);
		setSize(720, 360);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
	
		int first = Integer.parseInt(jt.getText()); 
		int second = Integer.parseInt(jt1.getText());
		
		if(e.getSource() == add){
			int result = first + second;
			label.setText(result + "");
		} else if(e.getSource() == min){
			int result = first - second;
			label.setText(result + "");
		} else if(e.getSource() == mul){
			int result = first * second;
			label.setText(result + "");
		} else if (e.getSource() == div){
			int result = first / second;
			label.setText(result + "");
		} else{
			int result = first % second;
			label.setText(result + "");
		}
	}
}
