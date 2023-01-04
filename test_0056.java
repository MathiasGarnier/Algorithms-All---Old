package org.yapix.math_sphere;

import java.util.Scanner;

public class Base {
	
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		String n = new String();
		
		System.out.println("Entrez un nombre :");
		n = sc.nextLine();
		
		for(int i = 0; i < n.length(); i++){
			int x = i;
			System.out.println(i);
			int nx = (x * n.length());
			System.out.println(nx);
		}
	}

}
