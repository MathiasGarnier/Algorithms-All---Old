package fr.mathiasGarnier.FastDev.Main;

import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);
	
	public static void main(String[] args) {
	
		String rep;
		
		System.out.println("Bonjour, que souhaitez vous faire ? - (soyez global, merci de ne pas utiliser de majuscule et d'accent)");
		rep = sc.nextLine();

		if(rep.contains("programme")){
			System.out.println("Quel type de programme ?");
			rep = sc.nextLine();
				if(rep.contains("ia") || rep.contains("artificielle") || rep.contains("genie")){
					
				}
		} else if (rep.contains("minecraft")){
			System.out.println("Basé sur quelle api ?");
			rep = sc.nextLine();
			if (rep.contains("sponge") || rep.contains("bukkit") || rep.contains("spigot") || rep.contains("bungee")){
				System.out.println("d");
			}
		} //else if(){
			
		}
	}

//}
