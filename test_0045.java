package org.mathiasGarnier.mario;

import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class DeplacementClavier implements KeyListener {

	@Override
	public void keyPressed(KeyEvent e){
		if(e.getKeyCode() == KeyEvent.VK_RIGHT){
			Main.sc.setDeplaceX(1);
		} else if(e.getKeyCode() == KeyEvent.VK_LEFT){
			Main.sc.setDeplaceX(-1);
		}
	}

	@Override
	public void keyReleased(KeyEvent e){
		Main.sc.setDeplaceX(0);
	}

	@Override
	public void keyTyped(KeyEvent e){
		
	}
	

	
}
