//Je tenais à préciser que ce n'était pas de moi ^^.
package org.mathiasGarnier.skypeJava.test;

import com.skype.ChatMessage;
import com.skype.ChatMessageAdapter;
import com.skype.Skype;
import com.skype.SkypeException;
import com.skype.User;

public class SendChatMessage {
	
	public static void main(String[] args) throws Exception {
		 
        System.out.println("Lancement...");
         
        Skype.setDaemon(false);
         
         
        Skype.addChatMessageListener(new ChatMessageAdapter() {
            public void chatMessageReceived(ChatMessage received)
                    throws SkypeException {
                if (received.getType().equals(ChatMessage.Type.SAID)) {
 
                    User sender = received.getSender();    
                     
                    System.out.println(sender.getId() + " dit :");
                    System.out.println(" " + received.getContent() );
                     
                    received.getSender().send(
                            "bllll");
                     
                    System.out.println(" - Envoie de la réponse automatique !");
                }
            }
        });
         
         
        System.out.println("Réponse automatique débuté !");
    }
 
} // Au lancement skype crash ^^.
