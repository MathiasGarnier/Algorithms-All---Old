/*
 * Originally designed by Michael Pinn - http://www.openprocessing.org/sketch/198563
 * Modified by Mathias Garnier
 * Programming set and get exercice and modification of "star".
 */

ArrayList particles = new ArrayList();
 
float s = 100;
 
void setup() {
  
  size(640, 640);
  stroke(40, 75);
  
  for (int i = 720; i > -720; i--) {
    
    particles.add(new Particle(-50, i));
  }
 
  for (int i = 0; i < particles.size (); i++) {
    
    Particle p = (Particle) particles.get(i);
    p.p2 = (Particle) particles.get((int) random(particles.size() - 1));
  }
    
  background(225);
}
 
void draw() {
  
  fill(225, 75);
  rect(0, 0, width, height);
  translate(width / 2, height / 2);
  
  for (int i = 0; i < particles.size (); i++) {
    
    Particle p = (Particle) particles.get(i);
    p.draw();
  }
  
  if (frameCount % 10 == 0) print("FPS : " + frameRate + "\n");
}
 
class Particle {
  
  Particle p2;
  PVector loc;
 
  int index, y;
 
  Particle(int nY, int nIndex) {
    
    setLocation();
    this.setY(nY);
    this.setIndex(nIndex);
  }
 
  void draw() {
    
    float angle = cos(radians(index * 2 - frameCount * 3)) * 53;
    loc = new PVector(sin(radians(index))*(s+angle*2), sin(radians(index))*(s-angle*2));
    
    if (PVector.dist(loc, p2.loc) < s) {
      
      line(loc.x, loc.y, p2.loc.x, p2.loc.y);
    }
  }
  
  int getY(){
    
    return y;
  }
  
  int getIndex(){
    
    return index;
  }
  
  void setY(int nY){
    
    this.y = nY;
  }
  
  void setIndex(int nIndex){
    
    this.index = nIndex;
  }
  
  void setLocation() {
   
    loc = new PVector();
  }
}
