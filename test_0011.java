package org.yapix.Rya.Main;

import java.util.Scanner;

public class Pythagore {

	@SuppressWarnings("resource")
	public static void main(String[] args) {

		double hypothenuse, coteOposePlusPetit, coteOposePlusGrand;
		Scanner sc = new Scanner(System.in);
		
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
	}

}
