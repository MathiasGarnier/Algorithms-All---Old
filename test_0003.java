package fr.yapix.test;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.EntityType;
import org.bukkit.entity.Player;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{
			
	public void onEnable() {
		
		System.out.println(ChatColor.BLUE + "ON");
	}

	public void onDisable() {
		
		System.out.println(ChatColor.BLUE + "OFF");
	}
	
	public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {

		Player p = (Player) sender;
		
		if(label.equalsIgnoreCase("yolo")){
			Bukkit.getWorld("World").spawnEntity(p.getLocation(), EntityType.BAT);
		}
			
		return false;
	}
}
