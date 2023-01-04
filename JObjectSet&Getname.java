package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
	JObject o = new JObject("Hey");
	
	System.out.println(o.getName());
	o.setName("Hey2");
	System.out.println(o.getName());
    }
}
