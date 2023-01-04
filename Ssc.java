package org.mathiasGarnier.Apprentissage;

import java.util.Random;

public class Main {

    public static void main(String[] args) {
		
    	Random r = new Random();
    	
    	for (int i = 0; i < 100; i++) {
    		
    		int nR = r.nextInt(10);
    		
    		int ssc, t, c;
    		
    		ssc = nR;
    		t = ssc;
    		c = t;
    		
    		t += c;
    		ssc += t;
    		
    		System.out.println(ssc);
    	}
    }
}
