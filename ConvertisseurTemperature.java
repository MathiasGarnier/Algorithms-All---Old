package fr.mathiasGarnier.Apprentissage;


/**
 * Created by Yapix on 28/05/2016.
 */
 
public class ConvertisseurTemperatures {


    public void convertirTempérature(int temperature, char convertirEn) {
        switch (convertirEn) {
            case 'F':
                System.out.println("Celsius :");
                int Celsius = (temperature - 32) * 5 / 9;

                System.out.println(Celsius);
                break;

            case 'C':
                System.out.println("Farenheit :");

                int Farenheit = temperature * 9 / 5 + 32;

                System.out.println(Farenheit);
                break;

            default:

                break;
        }
    }
}




//Main class : 

package fr.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {

        ConvertisseurTemperatures cT = new ConvertisseurTemperatures();
        
        cT.convertirTempérature(22, 'C');
    }
}
