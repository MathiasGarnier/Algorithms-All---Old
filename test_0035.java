package org.mathiasGarnier.prototype_os;

import java.text.DateFormatSymbols;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;

public class Start{
	
	private static final int UNIVERSLIFEANDTHEREST = 42;
	static Scanner sc = new Scanner(System.in); 
	static String password, username, cmd;
	static String cmd_all[] = { "time", "cmdp"};
	
	public static void main(String[] args){
		
		System.out.println("Démarrage en cours ...\nCréation d\'une nouvelle session...\nEntrez votre nom d\'utilsateur (par défaut c\'est \"you\"):");
		username = sc.nextLine();
		if(username.equals("you")){
			System.out.println("Entrez votre mot de passe (par défaux il est null)");
			password = sc.nextLine();
			if(password.equals("")){
				System.out.println("Finission en cours....\nConnexion en cours...\nVous voilà connecté !");
				
				//Et c'est parti parti !! #RipJulienLepers
				
				System.out.println("Liste des commandes possibles :\n"
						+ "time : Affiche la date.\n"
						+ "cmdp : Change ton mot de passe (pour cette session).\n"
						+ "exit : Arreter le programme.\n"
						+ "");
				
				for(int i = 0; i < UNIVERSLIFEANDTHEREST; i++){
				cmd = sc.nextLine();
				
					if(cmd.equals("time")){
						Date time = new Date();
						DateFormatSymbols dfs = new DateFormatSymbols();
						String[] week = new String[] { "", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi",	"Samedi", "Dimanche" };
						dfs.setShortWeekdays(week);
						SimpleDateFormat dateFormat = new SimpleDateFormat( "EEE dd MMM yyyy HH:mm:ss", dfs);
						System.out.println(dateFormat.format(time));
					} else if(cmd.equals("cmdp")){
						System.out.println("Entrez l\'ancien mot de passe :");
						password = sc.nextLine();
							if(password.equals("")){
								System.out.println("Nouveaux mot de passe :");
								String newPassword = sc.nextLine();
								String temp = password;
								password = newPassword;
								newPassword = temp;
								System.out.println("Votre mot de passe a était changé !" + temp);
							} else {
								for(int i1 = 0; i1 < 4; i1++){
								System.out.println("Réessayez !");
								password = sc.nextLine();
									if (i1 == 4){
										System.out.println("Trop de tentative !\nVeuillez réessayez plus tard !");
									}
								}
							}
					}
				} if(UNIVERSLIFEANDTHEREST == 42){
					System.out.println("Plus assez de mémoire ! Veuillez redémarrez !");
				}
			} else if(!password.equals("")){
				for(int i = 0; i < 4; i++){
					System.out.println("Réessayez !");
					password = sc.nextLine();
					if (i == 4){
						System.out.println("Trop de tentative !\nVeuillez réessayer plus tard !");
					}
				}
			} else{
				System.out.println("Erreur !\nVeuillez réessayer plus tard !");
			}
		} else if (!username.equals("you")){
			for (int i = 0; i < 4; i++){
				System.out.println("Réessayez !");
				username = sc.nextLine();
				if (i ==  4){
					System.out.println("Trop de tentative !\nVeuillez réessayer plus tard !");
				}
			}
		} else{
			System.out.println("Erreur !\nVeuillez réessayer plus tard !");
		}
	}
}
