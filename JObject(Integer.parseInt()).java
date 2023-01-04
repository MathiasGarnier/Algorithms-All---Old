package org.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {
		
	String content = "69";
	
	JObject o = new JObject(Integer.parseInt(content));
	JObject o1 = new JObject(Integer.parseInt(content) + 15);
	
	System.out.println(o.getName());
	
	
	System.out.println(o1.getName());
	
	System.out.println(o.isEquals(o1));
    }
}
