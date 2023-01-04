String txt = "";
String upperCase = "";
String lowerCase = "";

int txtLength;

void setup() {
 
  txt += "Salut c\'est cool Regardes comme il fait beau dehors....";
  
  upperCase = txt.toUpperCase();
  lowerCase = txt.toLowerCase();
  
  print(upperCase + "\n" + lowerCase);
}
