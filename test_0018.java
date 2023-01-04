package fr.yapix.test;

import java.net.MalformedURLException;
import java.net.URL;

import org.bukkit.Bukkit;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;

public class Test {
	
	public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
				
		if(label.equalsIgnoreCase("trier")){
			
			try {
		         
				URL mc_url = new URL("http://www.minecraft.com");
			         
			    Bukkit.broadcastMessage("Authority : " + mc_url.getAuthority());
			    Bukkit.broadcastMessage("Default port : " + mc_url.getDefaultPort());
			    Bukkit.broadcastMessage("Host : " + mc_url.getHost());
			    Bukkit.broadcastMessage("Port : " + mc_url.getPort());
			    Bukkit.broadcastMessage("Protocol : " + mc_url.getProtocol());
			         
			      } catch (MalformedURLException e) {
			         e.printStackTrace();
			      }
		}
		return false;
	}
}
