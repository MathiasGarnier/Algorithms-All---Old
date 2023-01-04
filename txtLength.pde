String txt = "";
int txtLength;

void setup() {
 
  txt += "Salut c\'est cool Regardes comme il fait beau dehors....";
  
  print("\"txt\" => " + txt);
  print("\nCombien y'a t'il de caractère dans \"txt\" ?\n");
  
  txtLength = txt.length();
  
  print("La longueur de \"txt\" est : " + txtLength + " caractères.");
}
