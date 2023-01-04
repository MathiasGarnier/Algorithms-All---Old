package org.yapix.Rya.Main;

import java.util.Scanner;

public class Main {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		System.out.println("Choix : \n"
				+ "\tPythagore,\n"
				+ "\tPuissance,\n"
				+ "\tAutre,\n"
				+ "\tIA\n");
		String choix = sc.next();
		
		if(choix.equals("Pythagore"))
		{
				double hypothenuse, coteOposePlusPetit, coteOposePlusGrand;			
				System.out.println("Petit rappel :"
						+ "\nOn rappelle que l’hypoténuse est le côté opposé à l\'angle droit et le côté ayant la plus grande longueur.\n"
						+ "Ce théorème sert à calculer la longueur d\'un côté connaissant les longueurs des deux autres lorsque l\'on sait que le triangle est rectangle.\n"
						+ "Longeur de l'hypothénuse :");
				hypothenuse = sc.nextInt();
				System.out.println("Entrez le plus petit des deux cotés opposés de l'hypothénuse.");
				coteOposePlusPetit = sc.nextInt();
				System.out.println("Entrez le dernier coté.");
				coteOposePlusGrand = sc.nextInt();
			
				if((hypothenuse * hypothenuse) == ((coteOposePlusPetit * coteOposePlusPetit) + (coteOposePlusGrand * coteOposePlusGrand))){
					System.out.println("C'est bien un triangle.");
				} else {
					System.out.println("Changes tes valeurs ce n'est pas un triangle rectangle.");
					return;
				}
			
				double carreHypothenuse = hypothenuse * hypothenuse;
				double carreCoteOpposePlusPetit = coteOposePlusPetit * coteOposePlusPetit;
				double carreCoteOposePlusGrand = coteOposePlusGrand * coteOposePlusGrand;
				double rC = carreCoteOpposePlusPetit + carreCoteOposePlusGrand;
				if(carreHypothenuse == carreCoteOpposePlusPetit + carreCoteOposePlusGrand){
				System.out.println("L'hypothenuse est : " +  Math.sqrt(rC) + " cm.");
				} else {
					return;
				}
		} else if(choix.equals("Puissance"))
			{
				System.out.println("Entrez un chiffre.");
				int chiffreC = sc.nextInt();
				System.out.println("Entrez par quel puissance voulez vous qu'il soit multiplié.");
				int chiffreP = sc.nextInt();
				System.out.println(chiffreC + " puissance " + chiffreP + " est égal à -> " + Math.pow(chiffreC, chiffreP) + " .");
			}
		else if(choix.equals("Autre")){
			System.out.println("A vous de créer votre Alghorithme !");
		} 
		else if(choix.equals("IA")){
			
		} else {
			System.out.println("Désolé, essayez un autre mot.");
		return;
	}
	}
}
