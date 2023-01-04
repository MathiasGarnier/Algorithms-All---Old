package fr.yapix.test;

import org.bukkit.ChatColor;
import org.bukkit.Statistic;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
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
		
		if(label.equalsIgnoreCase("commandetroplonguelel")){
			p.sendMessage(ChatColor.AQUA + "Tu es mort -> " + ChatColor.BLUE + p.getStatistic(Statistic.DEATHS) + " fois");
		}
		return false;
	}
}
