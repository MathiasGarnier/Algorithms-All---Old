package org.mathiasGarnier.keyProject.object;

public class Account {

    private String lastName;
    private String firstName;

    private String username;
    private String password;
    
    private int age;
    
    private Map x;
    private Map y;
    private Map z;
    private Map t; //TIME
    
    private boolean engaged;
    
    private Evolution level;
    
    private Id id;
    
    /* WARNING -> id is compulsory in every constructor. */
    
    public Account(String nLastName, String nFirstName, Id nId, String nUsername, String nPassword, int nAge, Map nX, Map nY, Map nZ, Map nT, boolean nEngaged, Evolution nLevel) {
	
	this.setLastName(nLastName);
	this.setFirstName(nFirstName);
	this.setId(nId);
	this.setUsername(nUsername);
	this.setPassword(nPassword);
	this.setAge(nAge);
	this.setX(nX);
	this.setY(nY);
	this.setZ(nZ);
	this.setT(nT);
	this.setEngaged(nEngaged);
	this.setLevel(nLevel);
    }
    
    public Account(Id nId) {
	
	this.setId(nId);
    }
    
    public Account(String nLastName, String nFirstName, Id nId) {
	
	this.setLastName(nLastName);
	this.setFirstName(nFirstName);
	this.setId(nId);
    }
    
    public Account(String nLastName, String nFirstName, Id nId, String nUsername, String nPassword) {
	
	this.setLastName(nLastName);
	this.setFirstName(nFirstName);
	this.setId(nId);
	this.setUsername(nUsername);
	this.setPassword(nPassword);
    }
    
    public Account(int nAge, Map nX, Map nY, Map nZ, Map nT, Id nId) {
	
	this.setAge(nAge);
	this.setX(nX);
	this.setY(nY);
	this.setZ(nZ);
	this.setT(nT);
	this.setId(nId);
    }

    /**
     * @return the lastName
     */
    public String getLastName() {
	
	return lastName;
    }

    /**
     * @param lastName the lastName to set
     */
    private void setLastName(String lastName) {
	
	this.lastName = lastName;
    }

    /**
     * @return the firstName
     */
    public String getFirstName() {
	
	return firstName;
    }

    /**
     * @param firstName the firstName to set
     */
    private void setFirstName(String firstName) {
	
	this.firstName = firstName;
    }

    /**
     * @return the id
     */
    public Id getId() {
	
	return id;
    }

    /**
     * @param id the id to set
     */
    private void setId(Id id) {
	
	this.id = id;
    }

    /**
     * @return the username
     */
    public String getUsername() {
	
	return username;
    }

    /**
     * @param username the username to set
     */
    private void setUsername(String username) {
	
	this.username = username;
    }

    /**
     * @return the password
     */
    public String getPassword() {
	
	return password;
    }

    /**
     * @param password the password to set
     */
    private void setPassword(String password) {
	
	this.password = password;
    }

    /**
     * @return the age
     */
    public int getAge() {
	
	return age;
    }

    /**
     * @param age the age to set
     */
    private void setAge(int age) {
	
	this.age = age;
    }

    /**
     * @return the x
     */
    public Map getX() {
	
	return x;
    }

    /**
     * @param x the x to set
     */
    private void setX(Map x) {
	
	this.x = x;
    }

    /**
     * @return the y
     */
    public Map getY() {
	
	return y;
    }

    /**
     * @param y the y to set
     */
    private void setY(Map y) {
	
	this.y = y;
    }

    /**
     * @return the z
     */
    public Map getZ() {
	
	return z;
    }

    /**
     * @param z the z to set
     */
    private void setZ(Map z) {
	
	this.z = z;
    }

    /**
     * @return the t
     */
    public Map getT() {
	
	return t;
    }

    /**
     * @param t the t to set
     */
    private void setT(Map t) {
	
	this.t = t;
    }

    /**
     * @return the isEngaged
     */
    public boolean isEngaged() {
	return engaged;
    }

    /**
     * @param isEngaged the isEngaged to set
     */
    private void setEngaged(boolean isEngaged) {
	
	this.engaged = isEngaged;
    }

    /**
     * @return the level
     */
    public Evolution getLevel() {
	
	return level;
    }

    /**
     * @param level the level to set
     */
    private void setLevel(Evolution level) {
	
	this.level = level;
    }
}
