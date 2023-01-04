package org.mathiasGarnier.mario;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Image;

import javax.swing.ImageIcon;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Scene extends JPanel {

	private ImageIcon icoFond;
	
	private Image imgFond1;
	private Image imgFond2;
	
	private ImageIcon icoMario;
	private Image imgMario;
	
	private int xFond1;
	private int xFond2;
	
	private int deplaceX;
	
	public Scene(){
		super();
		
		this.xFond1 = -50;
		this.xFond2 = -50;
		
		this.deplaceX = 0;
		
		icoFond = new ImageIcon(getClass().getResource("/images/fondEcran.png"));
		this.imgFond1 = this.icoFond.getImage();
		
		this.imgFond2 = this.icoFond.getImage();

		
		icoMario = new ImageIcon(getClass().getResource("/images/marioMarcheDroite.png"));
		this.imgMario = this.icoMario.getImage();
		
		this.setFocusable(true);
		this.requestFocusInWindow();
		this.addKeyListener(new DeplacementClavier());
		
		Thread chronometreEcran = new Thread(new Chronometre());
		chronometreEcran.start();
	}
	
	
	
	public int getDeplaceX() {
		return deplaceX;
	}
	
	public void setDeplaceX(int deplaceX){
		this.deplaceX = deplaceX;
	}

	public void deplacementFond(){
		this.xFond1 = this.xFond1 - this.deplaceX;
		this.xFond2 = this.xFond2 - this.deplaceX;
		
		if(this.xFond1 == -400){
			this.xFond1 = 400;
		} else if(this.xFond2 == -400){
			this.xFond2 = 400;
		} else if(this.xFond1 == 400){
			this.xFond1 = -400;
		} else if(this.xFond2 == 400){
			this.xFond2 = -400;
		}
	}
	
	public void paintComponent(Graphics g){
		
		super.paintComponent(g);
		
		Graphics g2D = (Graphics2D) g;
		
		this.deplacementFond();
		
		g2D.drawImage(this.imgFond1, this.xFond1, 0, null);
		g2D.drawImage(this.imgFond2, this.xFond2, 0, null);
		g2D.drawImage(imgMario, 300, 245, null);
		
	}
}
