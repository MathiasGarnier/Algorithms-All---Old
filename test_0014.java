package fr.yapix.test;

import java.util.ArrayList;

import org.bukkit.Bukkit;
import org.bukkit.GameMode;
import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{

	ArrayList<Player> p_test_arrayList = new ArrayList<Player>();
	
	public void onJoin(PlayerJoinEvent e){
		
		Player p = e.getPlayer();
		Player p_Location = (Player) p.getLocation();
		Player p_Test = (Player) e.getPlayer().getEyeLocation().add((Location) p_Location);
		Player p_Location_Array[][][];
		
		int p_LocationX = p.getLocation().getBlockX();
		int p_LocationY = p.getLocation().getBlockY();
		int p_LocationZ = p.getLocation().getBlockZ();
		
		Location x = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), p_LocationX, p_LocationY, p_LocationZ);
		Location y = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), p_LocationX, p_LocationY, p_LocationZ);
		Location z = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), p_LocationX, p_LocationY, p_LocationZ);;
		
		if(p_Test.equals(p.getLocation().getWorld().getName().equals("SpigotDevWorldTest001")) 
				&& p_Test.getGameMode().equals(GameMode.ADVENTURE)){
			
			
		}
				
	}
}
