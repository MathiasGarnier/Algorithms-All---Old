package org.mathiasGarnier.keyProject.enumeration;

public enum EnumPlace {
    
    //By default all door are closed.
    
    //NAME ("alias", doorState)
    CAR_ENTRY ("car_entry", false),
    ENTRY ("entry", false),
    HOUSE ("house", false),
    LIVING_ROOM ("living_room", false),
    BEDROOM ("bedroom", false),
    KITCHEN ("kitchen", false),
    DINING_ROOM ("dining_room", false),
    BATHROOM ("bathroom", false),
    ATTIC ("attic", false),
    GARDEN ("garden", false);
    
    private String name = "";
    private boolean state = false; //Close or Open
    
    EnumPlace(String nName, boolean nState) {
	
	this.setName(nName);
	this.setState(nState);
    }

    /**
     * @return the name
     */
    public String getName() {
	
	return name;
    }

    /**
     * @param name the name to set
     */
    public void setName(String name) {
	
	this.name = name;
    }

    /**
     * @return the state
     */
    public boolean isEnumPlaceState() {
	
	return state;
    }

    /**
     * @param state the state to set
     */
    public void setState(boolean state) {
	
	this.state = state;
    }
    
}
