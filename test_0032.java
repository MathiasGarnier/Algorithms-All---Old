package org.mathiasGarnier.skypeJava.test;

import com.skype.Skype;
import com.skype.SkypeException;

public class SendChatMessage {
	
	public static void main(String[] args) throws SkypeException{
		
		Skype.setDebug(true);
		
		System.out.println(Skype.chat(Constants.NICKNAME).getId());
	}
 
}
