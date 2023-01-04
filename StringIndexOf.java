package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
	//JObject o = new JObject("Salut");
	//JObject o1 = new JObject("Yo");
	
	String txt = "La carte mère (en anglais motherboard) est LA pièce indispensable à un PC.";
	
	int index = txt.indexOf("a");
	
	while (index > 0) {
	    
	    System.out.println("Ohhh un e à l'index : " + index + ".");
	    index = txt.indexOf("e", index + 1);
	}
    }
}
