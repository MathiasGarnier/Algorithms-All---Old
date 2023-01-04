package org.mathiasGarnier.keyProject.utils;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Utils {

    /**
     * @param max The maximum can get the {@link Random} number
     * @return A {@link Random} number between 1 and max
     */
    public int getRandomNumber(int max) {
	
	Random r = new Random();
	
	return r.nextInt(max) + 1;
    }
    
    public void writeFile(String file, String content) {
	try {
	    
	    FileWriter fw = new FileWriter(file, true);
	    
	    fw.write(content);
	    
	    fw.close();
	    
	} catch (IOException e) {
	    
	    System.out.println("Error in " + file + ".");
	}
    }
    
    public void writeFile(String file, int content) {
	
	try {
	    
	    FileWriter fw = new FileWriter(file);
	    BufferedWriter bw = new BufferedWriter(fw);
	    
	    bw.write(content);
	    
	    bw.flush();
	    
	    bw.close();
	    
	} catch (IOException e) {
	    
	    System.out.println("Error in " + file + ".");
	}
    }
    
    public void readFile(String file) {
	
	
	try {
	    
	    FileReader fr = new FileReader(file);
	    BufferedReader br = new BufferedReader(fr);
	    
	    String line;
	    
	    while ((line = br.readLine()) != null) {
		
		System.out.println(line);
	    }
	    
	    fr.close();
	} catch (IOException e) {
	    
	    System.out.println("Error in " + file + ".");
	}
    }
    
    public void refreshFile(String file) {

	try {
	    
	    FileOutputStream fos = new FileOutputStream(file);
	    
	    fos.close();
	
	} catch (IOException e) {
	    
	    System.out.println("File not found.");
	}
    }
}
