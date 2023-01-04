int deplacementX, deplacementY;
int x, y;

int w, z;

int score = 0;

void setup() {
  
 size(400, 400);
 background(0);
 
 x = 200;
 y = 200; 
 
 deplacementX = 6;
 deplacementY = -3; 
 
 w = 15;
 z = 60;
}


void draw() {
  
 clearGame();
 move();
 bounce();
 drawG();
}


void clearGame() {
  
  background(0);
}

void drawG() {
  
  smooth();
  fill(255);
  rect(w, z, 25, 85);
  fill(255);
  ellipse(x, y, 20, 20);
  line(200, 0, 200, 400);
}

void move() {
  
 x = x + deplacementX;
 y = y + deplacementY;
 
 z = (mouseY);
}

void bounce() {
 
 // si on est trop à droite et que le déplacement horizontal est positif
 if (x > width - 10 && deplacementX > 0) {
   
   deplacementX = -deplacementX; // inverser la valeur
   score++;
 }
 

 
 // si on est trop bas et le déplacement vertical est positif
 if (y > width - 10 && deplacementY > 0) {
   
   deplacementY = -deplacementY; // rendre négative la valeur
 }
 
 // si on est trop haut et le déplacement vertical est negatif
 if (y < 10 && deplacementY < 10) {
   
   deplacementY = abs(deplacementY); // rendre positive cette valeur
 }
 
 if (x < w + 35 && y > z && y < z + 85) {
   
   deplacementX = -deplacementX; // inverser la valeur
 }

 if (x < 10) {
   
  noLoop();
  
  textSize(32);
  text("GAME OVER", 120, 200);
  text("Score : " + (score - 1), 150, 150);
 }
}
