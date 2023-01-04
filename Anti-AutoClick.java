package fr.yapix;

import org.bukkit.Bukkit;
import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerAnimationEvent;
import org.bukkit.event.player.PlayerAnimationType;
import org.bukkit.plugin.java.JavaPlugin;
import org.bukkit.scheduler.BukkitRunnable;

import net.md_5.bungee.api.ChatColor;

public class Main extends JavaPlugin implements Listener {

	@Override
	public void onEnable() {
		Bukkit.getPluginManager().registerEvents(this, this);
		Bukkit.broadcastMessage("Animation >> ON");

	}
	
	private static int count = 0;
	private static int test = 0;
	
	@EventHandler
	public void onPlayerClick(PlayerAnimationEvent e) {
		
		Player p = e.getPlayer();
		
		if (e.getAnimationType().equals(PlayerAnimationType.ARM_SWING)) {
			
			count++;
			p.sendMessage("" + count);
			
			long time = 20;
			new BukkitRunnable() {
				
				@Override
				public void run() {
					
					test += 1; //>= 20 == AUTO 

					if (test > time) {
						
						test = 0;
						count = 0;
						
						p.sendMessage(ChatColor.RED + "ATTENTION");
					}
				}
			}.runTaskLater(this, time); //Every seconds.
		}
		test = 0;
		count = 0;
	}
}
