package fr.yapix.main;

import java.io.BufferedWriter;

import java.io.File;
import java.io.FileWriter;

import java.io.IOException;

import org.bukkit.Bukkit;

import org.bukkit.ChatColor;

import org.bukkit.entity.Player;

import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerAnimationEvent;
import org.bukkit.event.player.PlayerAnimationType;

import org.bukkit.plugin.java.JavaPlugin;

import org.bukkit.scheduler.BukkitRunnable;

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

					if (test > count) {
						
						test = 0;
						count = 0;
						
						try {

							String content = "Suspect : " + p.getName();

							File file = new File("C:/Users/Yapix/workspace/Minecraft/TimeLord/src/fr/yapix/main/log.txt");

							if (!(file.exists())) {
								file.createNewFile();
							}

							FileWriter fw = new FileWriter(file.getAbsoluteFile());
							BufferedWriter bw = new BufferedWriter(fw);
							
							bw.write(content);
							bw.newLine();
							bw.close();

							System.out.println("Yeahhhh");

						} catch (IOException e) {
						    
							e.printStackTrace();
						}
						
						p.sendMessage(ChatColor.RED + "ATTENTION");
					}
				}
			}.runTaskLater(this, time); //Every seconds.
		}
		test = 0;
		count = 0;
	}
}