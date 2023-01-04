package fr.mathiasGarnier.reApprentissage;

public class Main {

    public static void main(String[] args) {

        String s = new String("salut");
        printText(s);
    }

    private static void printText(String txt){

        for(int i = 0; i < txt.length(); i++){
            System.out.print(txt.charAt(i));
        }
    }
}
