package org.mathiasGarnier.keyProject.object;

import org.mathiasGarnier.keyProject.enumeration.EnumPlace;
import org.mathiasGarnier.keyProject.utils.Utils;

public class Key implements Cloneable {

    private String keyOwner;
    private int actionRange; //Well if a door is to 3 actionRange, a key with 2 actionRange can't be open the door
    private EnumPlace keyFor; //Well the "house", the "garden"...
    
    public Key(String nKeyOwner, int nActionRange, EnumPlace nKeyFor) {
	
	this.setKeyOwner(nKeyOwner);
	this.setActionRange(nActionRange);
	this.setKeyFor(nKeyFor);
    }
    
    //For the actionRange : get a Random number, and test if the random number is > || < to know if actionRange is adequate ^^'. -> 2D
    
    /*
     * FUNCTION
     */
    
    /**
     * @param door a {@link Boolean} for the door state
     * @return a {@link Boolean} with the state of the dooor
     */
    public boolean isDoorOpen(EnumPlace door) {
	
	if (door.isEnumPlaceState()) return true;
	else return false;
    }
    
    /**
     * @param door an {@link EnumPlace} for the door state
     */
    public void openDoor(EnumPlace door) {
	
	if (!(door.isEnumPlaceState())) return;
		
	else door.setState(true);
    }
    
    /**
     * @param door an {@link EnumPlace} for the door state 
     * @return a {@link Boolean} true if door can be opened, false if door can't be opened
     */
    public boolean canOpen(EnumPlace door) {
	
	if (door.equals(getKeyFor())) return true;
	else return false;
    }
    
    /**
     * @return a {@link Boolean} true if door is reachable, false  if door isn't reachable
     */
    public boolean reachableDoor(){
	
	Utils u = new Utils();
	int nU = u.getRandomNumber(10); //CHANGE THIS LATER
	
	if (nU > getActionRange()) return false;
	else return true;
    }
    
    /*
     * GETTER AND SETTER
     */
    
    /**
     * @return the name
     */
    public String getKeyOwner() {
	
	return keyOwner;
    }

    /**
     * @param name the name to set
     */
    public void setKeyOwner(String name) {
	
	this.keyOwner = name;
    }

    /**
     * @return the actionRange
     */
    public int getActionRange() {
	
	return actionRange;
    }

    /**
     * @param actionRange the actionRange to set
     */
    public void setActionRange(int actionRange) {
	
	this.actionRange = actionRange;
    }

    /**
     * @return the keyFor
     */
    public EnumPlace getKeyFor() {
	
	return keyFor;
    }

    /**
     * @param keyFor the keyFor to set
     */
    public void setKeyFor(EnumPlace keyFor) {
	
	this.keyFor = keyFor;
    }
    
    /*
     * SUPER FUNCTION
     */
    
    /**
     * @param o the compare {@link Object}
     * @return a {@link Boolean} true if key object is equals to an o {@link Object}, false if any key object is different to an o {@link Object}
     */
    public boolean equals(Object o) {
	
	if(!(o instanceof Key)) return false;
	
	Key k = (Key) o;
	
	return keyOwner.equals(k.keyOwner) && actionRange == k.actionRange && keyFor.equals(k.keyFor);
    }
    
    /**
     * 
     * @param o the compare {@link Object}
     * @return a {@link Boolean} true if key {@link Object} is equals to an o {@link Object}, false if any Key {@link Object} is different to an o {@link Object}
     */
    public boolean equalsWithoutKeyFor(Object o) {
	
	if (!(o instanceof Key)) return false;
	
	Key k = (Key) o;
	
	return keyOwner.equals(k.keyOwner) && actionRange == k.actionRange;
    }
}