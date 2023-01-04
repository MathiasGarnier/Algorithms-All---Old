package org.mathiasgarnier.wintime.sktranslate;

import java.util.HashMap;

import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.player.PlayerLevelChangeEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class OnLevelChange extends JavaPlugin{

	HashMap<Player, Integer> levelKey = new HashMap<Player, Integer>();
	
	@EventHandler
	public void onLevelChange(PlayerLevelChangeEvent event)
	{

		Player player = event.getPlayer();
		int level = player.getLevel();
		player.getLevel();
		
		for(int i = 0; i < ((level - (1 % level) % level + 1)); i++){
			levelKey.put(player, level + 1);
		}
	  
	}
}
