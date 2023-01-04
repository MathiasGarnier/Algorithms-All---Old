package fr.mathiasGarnier.apprentissage;

public class Angle {

    /*  HYPOTHENUSE
     * X-----------Y
     *  \         /
     *   \      / 
     *    \   /
     *      Z
     *      
     *      Z sera toujours l'angle droit (pour faciliter)
     *      
     *      MAL PRIS
     */
    
    /*
     * VARIABLE INITIALISATION
     */
    private static int x;
    private static int y;
    private static int z;
    
    /*
     * CONSTRUCTOR 
     */
    public Angle(int nX, int nY, int nZ) { 
	
	this.setX(nX);
	this.setY(nY);
	this.setZ(nZ);
    }
    
    public boolean isRectangle(Angle a) {
	
	if (a.getZ() == (Math.sqrt(a.getY()) + Math.sqrt(a.getZ()))) return true;
	else return false;
    }
    public void cos(Angle a) {
	
	int cosX = a.getZ() / a.getY();
	int cosY = a.getZ() / a.getX();
	
	System.out.println("Cosinus de l\'angle X >> " + cosX);
	System.out.println("Cosinus de l\'angle Y >> " + cosY);
    }
    public int cos(int cAdj, int hypo) {
	
	return cAdj / hypo;
    }
    
    public void sin(Angle a) {
	
	int sinX = a.getY() / a.getZ();
	int sinY = a.getX() / a.getZ();
	
	System.out.println("Cosinus de l\'angle X >> " + sinX);
	System.out.println("Cosinus de l\'angle Y >> " + sinY);
    }
    
    public int sin (int cOpp, int hypo) {
	
	return cOpp / hypo;
    }
    
    public void tan(Angle a) {
	
	int tanX = a.getY() / a.getX();
	int tanY = a.getY() / a.getX();
    }
    
    public int tan(int cOpp, int cAdj) {
	
	return cOpp / cAdj;
    }

    /*
     * GETTER AND SETTER
     */
    
    /**
     * @return the x
     */
    public int getX() {
	return x;
    }

    /**
     * @param x the x to set
     */
    private void setX(int x) {
	this.x = x;
    }

    /**
     * @return the y
     */
    public int getY() {
	return y;
    }

    /**
     * @param y the y to set
     */
    private void setY(int y) {
	this.y = y;
    }

    /**
     * @return the z
     */
    public int getZ() {
	return z;
    }

    /**
     * @param z the z to set
     */
    private void setZ(int z) {
	this.z = z;
    }
}
