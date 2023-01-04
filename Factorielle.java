package fr.mathiasGarnier.prologin;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		/*
		 * Il s'agit d'écrire un programme qui calcule la factorielle d'un entier et indique à l'écran le résultat. 
		 */
		
		Scanner sc = new Scanner(System.in);
		int n = 0;
		
		n = sc.nextInt();
		
		int resultat = 1;
		for (int i = 1; i <= n; i++){
			resultat *= i;
			System.out.println(resultat);
		}

	}

}
