package fr.yapix.AnotherCrew.WaitingRoom;

import org.bukkit.Bukkit;
import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.event.Listener;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Main extends JavaPlugin implements Listener{

		@Override
		public void onEnable() {
			Bukkit.getServer().getPluginManager().registerEvents(this, this);
		}
		
		public void onJoin(PlayerJoinEvent e){
			
			Player p = e.getPlayer();
			
			double x = p.getLocation().getX();
			double y = p.getLocation().getY();
			double z = p.getLocation().getZ();
			Location hub = new Location(Bukkit.getWorld("world"), x, y, z);
			
			p.teleport(hub);
		}
}
