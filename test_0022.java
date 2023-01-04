package org.mathiasgarnier.wintime.sktranslate;

import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class OnJoin extends JavaPlugin {
	public void onJoin(PlayerJoinEvent event) {
	
		Player p = event.getPlayer();
		boolean isOnline = false;
		
		if(p.isOnline() == true) {
			isOnline = true;
		} else {
			isOnline = false;
		}
	}
}
