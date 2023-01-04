package fr.yapix.test;

import java.util.ArrayList;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerMoveEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{

	ArrayList<Player> afk_p = new ArrayList();
			
	public void onEnable() {
		
		System.out.println(ChatColor.BLUE + "ON");
	}

	public void onDisable() {
		
		System.out.println(ChatColor.BLUE + "OFF");
	}
	
	public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {

		Player p = (Player) sender;
		
		if(label.equalsIgnoreCase("afk")){
			
			if(afk_p.contains(p)){
				
				afk_p.remove(p);
				Bukkit.broadcastMessage(ChatColor.AQUA + "[-] " + ChatColor.BLUE + p.getPlayer());
			} else {
				
				afk_p.add(p);
				Bukkit.broadcastMessage(ChatColor.AQUA + "[+] " + ChatColor.BLUE + p.getPlayer());
			}
			
		}
		return false;
	}
	
	public void onMove(PlayerMoveEvent e){
		
		Player p = e.getPlayer();
		
		if(afk_p.contains(p)){
			
			afk_p.remove(p);
			Bukkit.broadcastMessage(ChatColor.AQUA + "[-] " + ChatColor.BLUE + p.getPlayer());
		} else {
			
			return;
		}
	}
}
