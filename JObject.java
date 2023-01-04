package org.mathiasGarnier.Apprentissage;

public class JObject {

    private String name;
    
    public JObject(String nName) {
	
	this.name = nName;
    }

    public String getName() {
	return name;
    }

    public void setName(String name) {
	this.name = name;
    }
    
    public boolean isEquals(JObject o2) {
	
	return (JObject.this == o2);
    }
}
