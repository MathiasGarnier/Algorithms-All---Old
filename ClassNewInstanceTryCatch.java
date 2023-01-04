package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
    	Class<?> c1;
    	
	try {
	    
	    c1 = Class.forName("org.mathiasGarnier.Apprentissage.Main");
	    
	    try {
		
		System.out.println(c1.newInstance());
		
	    } catch (InstantiationException e) {

		e.printStackTrace();
		
	    } catch (IllegalAccessException e) {

		e.printStackTrace();
	    }
	} catch (ClassNotFoundException e) {

	    e.printStackTrace();
	}    	
    }
}
