package fr.mathiasGarnier.apprentissage;

import java.util.Date;
import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	
	Date d = new Date();
	Random r = new Random();
	Scanner sc = new Scanner(System.in);
	
	long rR = r.nextInt(1000);
	
	try {
	    
	    long time = (long) (d.getTime() / rR * Math.PI);
	    
	    System.out.println("Secret string : ");
	    String str = sc.nextLine();
		
	    long length = (long) str.length();
		
	    long fResult = time / rR + length;
		
	    System.out.println("Original >> " + str);
		
	    System.out.println("Encrypt >> " + fResult);
	    
	} catch (ArithmeticException e) {
	    
	    System.out.println("Division par zéro impossible");
	}
    }
}
