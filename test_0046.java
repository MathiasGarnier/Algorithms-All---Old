package org.mathiasGarnier.mario;

public class Chronometre implements Runnable {

	private final int ATTENTE = 3;
	
	@Override
	public void run(){
		
		while(true){
			Main.sc.repaint();
			
			try {
				Thread.sleep(ATTENTE);
			} catch (InterruptedException e) {}
		}
	}
}
