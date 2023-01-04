package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
	//JObject o = new JObject("Salut");
	//JObject o1 = new JObject("Yo");
	
	StringBuilder txt = new StringBuilder();

	txt.append("La carte mère (en anglais motherboard) est LA pièce indispensable à un PC.");
	
	for (int i = 0; i < txt.length(); i++) {
	    
	    StringBuilder strB = txt.replace(0 , txt.length(), "Salut");
	    
	    System.out.println(strB.toString());
	    System.out.println(txt);
	}
    }
}
