package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
	//JObject o = new JObject("Salut");
	//JObject o1 = new JObject("Yo");
	
	String txt = new String("La carte mère (en anglais motherboard) est LA pièce indispensable à un PC.");

	byte[] s = txt.getBytes();
	
	for (int i = 0; i < txt.length(); i++) System.out.println(s[i]);
	
    }
}
