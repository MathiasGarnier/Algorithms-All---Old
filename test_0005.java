package fr.yapix.test;


import java.util.ArrayList;
import java.util.HashMap;

import org.bukkit.Bukkit;
import org.bukkit.ChatColor;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.plugin.java.JavaPlugin;


public class Test extends JavaPlugin{

	/*
	 * Developpeur Mathias Garnier
	 * Description Cette classe sert simplement à trier tous les joueurs du serveurs dans deux teams de façon aléatoires ! 
	 */
	
	ArrayList<Player> player_ArrayList = new ArrayList<Player>();
	HashMap<Player, Integer> team_HashMap = new HashMap<Player, Integer>();
	
	int  minRandValue = 1;
	int maxRandValue = Bukkit.getOnlinePlayers().size();
	int x =  (int) ((Math.random() * maxRandValue) / minRandValue);
	//Prendre un nombre aléatoire entre 1 et le nombre de joueurs connectés.
	
	@Override
	public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
		
		Player p = (Player) sender;
		
		if(label.equalsIgnoreCase("trier")){
			
			
			if (p.getPlayer().equals(team_HashMap.containsKey(0))){
				Bukkit.broadcastMessage(ChatColor.GRAY + "[+] " + ChatColor.BLUE + p.getName() + ChatColor.GRAY + " est chez les bleus !");
			} else if (p.getPlayer().equals(team_HashMap.containsKey(1))){
				Bukkit.broadcastMessage(ChatColor.GRAY + "[+] " + ChatColor.RED + p.getName() + ChatColor.GRAY + " est chez les rouges !");
			} else{
				Bukkit.broadcastMessage(ChatColor.GRAY + "Ressayez !");
			}
			//A finir ;)
		}
		return false;
	}
}
