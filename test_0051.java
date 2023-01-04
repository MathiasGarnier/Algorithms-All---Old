package fr.mathiasGarnier.jSimpleCrypt.util;

public class Alphabet {

	private static final char[] alphabet = new char[25];
	private static final short maxValue = 25;
	
	public enum Letter {

		A ('a'), B ('b'), C ('c'), D ('d'), E ('e'), F ('f'), G ('g'), H ('h'),I ('i'), J ('j'), K ('k'), L ('l'), M ('m'), N ('n'), O ('o'), P ('p'), Q ('q'), R ('r'), S ('s'), T ('t'), U ('u'),	V ('v'), W ('w'), X ('x'), Y ('y'), Z ('z');
		   
		private char letter;

		Letter(char letter){
			this.letter = letter;
		}
		
		public char toChar(){
			return letter;
		}
	}
}
