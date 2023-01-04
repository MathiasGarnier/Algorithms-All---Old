package fr.mathiasGarnier.testJeux.util;

public class Plateau {

	private static int[][] plateau = new int[12][12]; //Plus grand plateau possible : largeur = 12, longueur = 12;
	
	public Plateau(){
		Plateau p = new Plateau();
	}
	
	public static void get2DPlateau(int x, int y){
		for(int i = 0; i < x; i++){
			for (int ii = 0; ii < y; ii++){
				int nPlateau = plateau[i][ii];
			}
		}		
	}
}
