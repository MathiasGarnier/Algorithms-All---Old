package fr.mathiasGarnier.Apprentissage;

import java.util.Random;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        Character c = '\0';

        Character array[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

        Random r = new Random();
        final Character specialChar = array[r.nextInt(array.length)]; /* select RANDOM_NUMBER->(ARRAY of CHARACTER) */

        int count = 0;

        do {

            System.out.print("Arriverez vous a trouver le caractère (essaie numéro " + count + ")?\n");
            c = sc.nextLine().charAt(0);

            if (c.equals(specialChar)) {

                System.out.print("Bien joué !");
                System.exit(0);
            } count++;
        } while (c != specialChar);
    }
}
