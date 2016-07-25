//Y'a aucun langage précis utiliser c'est juste pour donner une idée ^^'.

struct Isle : public boolean { //J'suis pas sur qu'on puisse faire le public boolean, mais c'est pour que tu comprennes ^^'.

  double        xF;
  double        xS;  
  double        yF;
  double        yS;
  double        z;
  Player        p;
  
  Player : Isle getLocation(); //Extends de Isle.
  Isle          addStruct(); 
};

Isle addStruct() {

  Vector<Isle> v;
  v.push_back(Isle.xF);
  v.push_back(Isle.xS);
  v.push_back(Isle.yF);
  v.push_back(Isle.yS);
  v.push_back(Isle.z);

  return v; Dans une sorte de file configurator
}

Player : Isle getLocation() {

  //La fonction donnant la location du joueur.
}

Isle isPlayerOnIsle(Vector<Isle> allIsle) {

  if(Isle::p::getLocation == addStruct) return true;
  else return false;
}

int main() {

  while(true) {

  if(isPlayerOnIsle){
    //d;bazdjzebf
   }

  }
}
