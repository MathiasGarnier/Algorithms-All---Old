package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
    	ObjectJ o = new ObjectJ("ObjectJ");
    	ObjectJ o1 = new ObjectJ(ObjectJ.class.getName().toString());
    	
    	System.out.println(o.equals(o1));
	}
}
