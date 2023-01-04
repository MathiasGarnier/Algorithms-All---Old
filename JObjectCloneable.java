package org.mathiasGarnier.Apprentissage;

public class JObject implements Cloneable {

    private int name;
    
    public JObject(int nName) {
	
	this.name = nName;
    }

    public int getName() {
	return name;
    }

    public int setName(int string) {
	return this.name = string;
    }
    
    public String toString() {
	
	String resultat = super.toString();
	
	resultat += "\nNom de l'objet : \t" + getName();
	
	return resultat;
    }
    
    public Object cloneable() throws CloneNotSupportedException {
	
	return super.clone();
	
    }
    
    public boolean equals(Object o) {
	
	if (!(o instanceof JObject)) return false;
	
	JObject jo = (JObject) o;
	
	return this.getName() == jo.getName();
    }
}
