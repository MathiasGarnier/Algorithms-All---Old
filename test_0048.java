package org.mathiasGarnier.skype_api_test;

import java.util.Scanner;

import com.skype.Skype;
import com.skype.SkypeException;

public class Main {

	public static void main(String[] args) throws SkypeException {
		
		Scanner sc = new Scanner(System.in);
		String ID = new String();
		
		System.out.println("Lancement en cour... Merci de bien vouloir patienter !\n");
		System.out.println("Version : " + Skype.LIBRARY_VERSION + "\nVersion de skype : " + Skype.getVersion() + "\n");
		
		Skype.setDaemon(false);
		Skype.setDebug(false);
		
		System.out.println("Choissisez un identifiant skype, sur lequel les tests seront fait !");
		ID = sc.nextLine();
				
		System.out.println("Voici ses attributs : "
				+ "\nNom : " + Skype.getUser(ID).getFullName()
				+ "\n Langue : " + Skype.getUser(ID).getLanguage()
				+ "\nSex : " + Skype.getUser(ID).getSex()
				+ "\nStatus : " + Skype.getUser(ID).getStatus());		

	}

}
