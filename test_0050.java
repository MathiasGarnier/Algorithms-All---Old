package org.mathiasGarnier.rien;

import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	
	private static int SECONDS_LEFT;
	private static int seconds = (int) ((Math.random() * 1000) - 1);
	private static String exit = new String();
	
	public static void main(String[] args) {
		
		System.out.println("Bienvenue sur le jeux de \"RIEN\", voilà c'est tout [@Yapix]!\n"
				+ "Tu te demandes quel est ton but ? Attendre jusqu'à la fin du compteur, pour pouvoir enfin monter dans l'ascenceur !\n");
		System.out.println("La voix de l'ascenceur >> Il vous reste " + seconds + " avant que l'ascenceur n'arrive ! Merci de bien vouloir attendre...");
		for (int i = seconds; i >= 0; i--){
			try {
				Thread.sleep (seconds);
			} 
		  catch (InterruptedException e) {
			  System.out.print("Erreur");
			  }
		System.out.print(i + "\n");
		
		if(i == 0){
			System.out.println("L'ascenseur est là !");

			}
		}
	}
}
