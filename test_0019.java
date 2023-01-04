package fr.yapix.test;

import java.util.ArrayList;

import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{

	ArrayList<Player> p_test_arrayList = new ArrayList<Player>();
	
	public void onJoin(PlayerJoinEvent e){
		
		Player p = e.getPlayer();
		Player p_location = (Player) p.getLocation();
		Player p_test = (Player) e.getPlayer().getEyeLocation().add((Location) p_location);
		Player p_Array[][][];
	}
}
