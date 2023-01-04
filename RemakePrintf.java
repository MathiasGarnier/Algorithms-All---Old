package fr.mathiasGarnier.Apprentissage;

public class Main {

    public static void main(String[] args) {

    	StringBuilder displayIt = new StringBuilder("Bonjour !");
	    remakePrintf('s', displayIt.append(" Comment vas tu ?"));

	    int life = 42;
	    remakePrintf('i', life);

	    int dontNo = 42;
	    remakePrintf('j', dontNo);

    }

    public static void remakePrintf(Character c, Object display) {

    	int type = 0;
    	/*
    	 * 0 -> undetermined
    	 * 1 -> StringBuilder
    	 * 2 -> Integer
    	 */

    if (c.equals('s') && display instanceof StringBuilder) type = 1;
    else if (c.equals('i') && display instanceof Integer) type = 2;
    else type = 0;

	    switch(type) {

		    case 0:

			    //TYPE(ERROR HANDLING)
			    System.out.print("Please try with an other first argument.\n");
			    System.out.print("\"" + c + "\" is not the right type for \"" + display + "\" (" + display.getClass() + ").");
			    break;

		    case 1:

		    	StringBuilder strDisplay = (StringBuilder) display;
		    	System.out.print(strDisplay + "\n");
		    	System.out.print("TYPE : StringBuilder\n");
		    	break;

		    case 2:

		    	int intDisplay = (int) display;
		    	System.out.print(intDisplay + "\n");
		    	System.out.print("TYPE : Integer\n");
		    	break;

		    default:
		    	break;
	    }

	    System.out.print("\n---------------------------\n");
    }
}
