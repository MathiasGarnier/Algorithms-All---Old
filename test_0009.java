package fr.perso.yapix.jct.main;

import java.util.Scanner;

public class JCT {

	
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);

		String s = "";
		
		System.out.println("\t\t\tWelcome to JCT\n"
				+ "\t\t\tMade by Yapix.");
		s = sc.nextLine();
		
		if(s.equals("print")){
			System.out.println("Write your text !");
			s = sc.nextLine();
			System.out.println(s);
			
		}
	}

}
