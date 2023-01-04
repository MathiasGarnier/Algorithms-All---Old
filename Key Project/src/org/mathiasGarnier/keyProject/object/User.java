package org.mathiasGarnier.keyProject.object;

import org.mathiasGarnier.keyProject.utils.Utils;

/**
 * @deprecated 
 */

//@TODO REMAKE THIS LATER -> CREATE Account.java

public class User {

    private String username;
    private String password;
    
    private int id = 0; //1 for the first user...
    
    private final String fileUser = "C:/Users/Yapix/workspace/eclipse/Key Project/src/org/mathiasGarnier/keyProject/file/User.txt"; //Lolilol
    private final String fileId = "C:/Users/Yapix/workspace/eclipse/Key Project/src/org/mathiasGarnier/keyProject/file/Id.txt"; //Lolilol

    private String line = null;
    
    Utils u = new Utils();
    
    public User(String nUsername, String nPassword) {
	
	this.setUsername(nUsername);
	this.setUserPassword(nPassword);
    }
    
    public User() {
	
	//NULL
    }

    /*
     * FUNCTION
     */
    
    /**
     * @param username the username
     * @param password the password
     * @return a new {@link User}
     */
    public User registerUser(String username, String password) {
	
	User u = new User(username, password);
 
	return u;
    }
    
    public int incrementId() {
	
	u.writeFile(fileId, id);
	
	return id + 1;
    }
    
    /*
     * GETTER AND SETTER
     */
    
    /**
     * @return the username
     */
    public String getUsername() {
	
	u.readFile(fileUser);
	
	return username;
    }

    /**
     * @param username the username to set
     */
    private void setUsername(String username) {
	
	u.writeFile(fileUser, "[@USERNAME] >> " + username);

	this.username = username;
    }

    /**
     * @return the password
     */
    public String getUserPassword() {
	
	return password;
    }

    /**
     * @param password the password to set
     */
    private void setUserPassword(String password) {

	this.password = password;
    }
    
    /**
     * @return the id
     */
    public int getUserId() {
	
	return id;
    }

    /**
     * @param id the id to set
     */
    private void setUserId(int nId) {
	
	this.id = nId;
    }
    
    /**
     * @return the fileId
     */
    public String getFileId() {
	
	return fileId;
    }
    
    /**
     * @return the fileUser
     */
    public String getFileUser() {
	
	return fileUser;
    }
    /*
     * SUPER FUNCTION
     */
    
    public boolean equals(Object o) {
	
	if (!(o instanceof User)) return false;
	
	User u = (User) o;
	
	return username.equals(u.username) && password.equals(u.password);
    }
}
