package fr.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {

        addNum(5, 6, 7, 99, 775845);
    }

    public static int[] addNum(int ... args) {

        for (int i : args) {

            System.out.print(i + "\n");
        }
        return args;
    }
}
