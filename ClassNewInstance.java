package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) throws ClassNotFoundException, InstantiationException, IllegalAccessException {
		
    	Class c1 = Class.forName("org.mathiasGarnier.Apprentissage.Main");
    	
    	System.out.println(c1.newInstance());
    	
    }
}
