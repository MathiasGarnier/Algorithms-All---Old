package fr.yapix.anothercrew.timelord;

import org.bukkit.Bukkit;
import org.bukkit.event.Listener;
import org.bukkit.plugin.java.JavaPlugin;

/*
 * @Author Mathias Garnier
 * @Description TimeLord est un plugin minecraft jouant avec le temps dont le but est d'être le premier à 25 kills !
 */

public class TimeLordMain extends JavaPlugin{

	@Override
	public void onEnable() {
		Bukkit.broadcastMessage("TimeLord >> ON");
		Bukkit.getPluginManager().registerEvents((Listener) this, this);

	}
	
	@Override
	public void onDisable() {
		Bukkit.broadcastMessage("TimeLord >> OFF");
	}
	
}
