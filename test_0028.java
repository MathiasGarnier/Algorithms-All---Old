
import java.io.File;
import java.util.Date;
import java.util.Scanner;

import javax.swing.JTree;

public class Start{

	static Scanner sc = new Scanner(System.in);
	static String username, password, cmd = new String();

	private File[] _roots;
	private JTree _dirs;
	
	public static void main(String[] args){
		
		System.out.println("Démarrage en cours ...\nCréation d\'une nouvelle session...\nEntrez votre nom d\'utilsateur (par défaut c\'est \"you\"):");
		username = sc.nextLine();
		if(username.equals("you")){
			System.out.println("Entrez votre mot de passe (par défaux il est null)");
			password = sc.nextLine();
			if(password.equals("")){
				System.out.println("Finission en cours....\nConnexion en cours...\nVous voilà connecté !");
				
				
				System.out.println("Listes des commandes possibles :");
				System.out.println("time : Affiche l\'heure.\necho \"texte\": Afficher du texte.\ntree : Affiche l\'arborescence.\n");
				
				
				for(int i = 0; i < 42; i++){
					cmd = sc.nextLine();
					
						if(cmd.equals("time")){
							Date date = new Date();
							System.out.println(date);
						}
						
						if(cmd.equals("echo")){
							String str0 = new String();
							System.out.println("Saisissez un texte :");
							str0 = sc.nextLine();
							System.out.println(str0);
						}
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
