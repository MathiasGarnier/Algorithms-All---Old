package fr.yapix.test;

import org.bukkit.Bukkit;
import org.bukkit.Color;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerInteractEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin {
    
	private Player player;
	
	public void blockIsClicked(PlayerInteractEvent e, Player player){
		this.player = player;
		
		if(!(e.getClickedBlock().isLiquid())){
			Bukkit.broadcastMessage(Color.AQUA + "x : " + e.getClickedBlock().getX()
					+ "\ny :" + e.getClickedBlock().getY()
					+ "\nz : "+ e.getClickedBlock().getZ());
		} else {
			Bukkit.broadcastMessage(Color.BLUE + "Bhaaa un liquide");
		}
	}
		
}
