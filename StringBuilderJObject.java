package org.mathiasGarnier.Apprentissage;


public class Main {

    public static void main(String[] args) {
		
	JObject o = new JObject("Hey");
	JObject o1 = new JObject("Yo");
	
	StringBuilder strB = new StringBuilder();
	
	strB.append(o).append(" ").append(o1);

	System.out.println(strB.toString());
    }
}
