package org.mathiasGarnier.Apprentissage;


public class Main {

    public static void main(String[] args) {
		
	JObject o = new JObject("Hey");
	JObject o1 = new JObject("Pluuuu");
	
	System.out.println(o.getName());
	
	o.setName("Hey2");
	
	System.out.println(o.getName());
	
	System.out.println(o.isEquals(o1));
    }
}
