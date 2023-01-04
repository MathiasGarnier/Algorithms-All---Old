package org.mathiasGarnier.keyProject;		

import org.mathiasGarnier.keyProject.enumeration.EnumPlace;
import org.mathiasGarnier.keyProject.logger.Logger;
import org.mathiasGarnier.keyProject.object.Key;
		
public class Main {		
    
    public static void main(String[] args) {		
			
	//Key k = new Key("Maison", 5, EnumPlace.CAR_ENTRY);		
	Key c = new Key("Maison", 5, EnumPlace.ATTIC);		
	
	Logger l = new Logger();
	
	/*		
	 * System.out.println(k.equals(c));		
	 * System.out.println(k.equalsWithoutKeyFor(c));		
	 */		
	
	   
	//System.out.println(k.canOpen(EnumPlace.CAR_ENTRY));		
	//System.out.println(k.reachableDoor());
	c.canOpen(EnumPlace.ATTIC);
	
	l.log(c.canOpen(EnumPlace.ATTIC));
    }		
}
