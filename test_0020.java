package fr.yapix.test;

import java.util.ArrayList;

import org.bukkit.Bukkit;
import org.bukkit.GameMode;
import org.bukkit.Location;
import org.bukkit.entity.Player;
import org.bukkit.event.player.PlayerJoinEvent;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{

	ArrayList<Player> d6d071967ef2ef4052b350cda2c74203 = new ArrayList<Player>();
	
	public void onJoin(PlayerJoinEvent y1671797c52e15f763380b45e841ec32){
		
		int y0f3adf3175ff743d978e74349749d166 = 1;
		int y018026dcd924fa582bd6c7703fd83fc7 = Bukkit.getOnlinePlayers().size();
		int y49539156d2c8a8de87f7f597ce430ffe =  (int) ((Math.random() * y018026dcd924fa582bd6c7703fd83fc7) / y0f3adf3175ff743d978e74349749d166);
		
		Player y83878c91171338902e0fe0fb97a8c47a = y1671797c52e15f763380b45e841ec32.getPlayer();
		Player y14e4be7cd90d3ca24455f73644a21e44 = (Player) y83878c91171338902e0fe0fb97a8c47a.getLocation();
		Player y8587ec445b171ba3e287fc30b0f0c71d = (Player) y1671797c52e15f763380b45e841ec32.getPlayer().getEyeLocation().add((Location) y14e4be7cd90d3ca24455f73644a21e44);
		Player y899f2d1d680b79a028457370e7417ce[][][];
		
		int y96ecad5d3d979b30865a103a59c10047 = y83878c91171338902e0fe0fb97a8c47a.getLocation().getBlockX();
		int ycb17fdcaf80680bf4b3957f833647991 = y83878c91171338902e0fe0fb97a8c47a.getLocation().getBlockY();
		int yf5a70e8389739a1935c9a8ce52d1f4ed = y83878c91171338902e0fe0fb97a8c47a.getLocation().getBlockZ();
		
		Location y9dd4e461268c8034f5c8564e155c67a6 = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), y96ecad5d3d979b30865a103a59c10047, ycb17fdcaf80680bf4b3957f833647991, yf5a70e8389739a1935c9a8ce52d1f4ed);
		Location y415290769594460e2e485922904f345d = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), y96ecad5d3d979b30865a103a59c10047, ycb17fdcaf80680bf4b3957f833647991, yf5a70e8389739a1935c9a8ce52d1f4ed);
		Location yfbade9e36a3f36d3d676c1b808451dd7 = new Location(Bukkit.getWorld("SpigotDevWorldTest001"), y96ecad5d3d979b30865a103a59c10047, ycb17fdcaf80680bf4b3957f833647991, yf5a70e8389739a1935c9a8ce52d1f4ed);;
		
		if(y8587ec445b171ba3e287fc30b0f0c71d.equals(y83878c91171338902e0fe0fb97a8c47a.getLocation().getWorld().getName().equals("SpigotDevWorldTest001")) 
				&& y8587ec445b171ba3e287fc30b0f0c71d.getGameMode().equals(GameMode.ADVENTURE)){
			
			for (int i_0 = 0; i_0 < y49539156d2c8a8de87f7f597ce430ffe; i_0++){

				for (int i_1 = 0; i_1 < y49539156d2c8a8de87f7f597ce430ffe - 1; i_1++){
				}
			}
		}
				
	}
}
