package fr.mathiasGarnier.apprentissage;

public class Main {

    public static void main(String[] args) {

	class Foo {
	    
	    public int getInt(int n) {
		
		return n;
	    }
	}
	
	class Bar extends Foo {
	    
	}
	
	Bar b = new Bar();
	
	System.out.println(b.getInt(42));
    }

}
