package fr.yapix.test;


import org.bukkit.GameMode;
import org.bukkit.command.Command;
import org.bukkit.command.CommandSender;
import org.bukkit.entity.Player;
import org.bukkit.plugin.java.JavaPlugin;

public class Test extends JavaPlugin{
	
	@Override
	public boolean onCommand(CommandSender sender, Command command, String label, String[] args) {
		
		Player p = (Player) sender;

		if(label.equalsIgnoreCase("calc")){
			
			if(p.isFlying()  && !(p.isSneaking()) || !(p.isSprinting())){
				p.setAllowFlight(false);
				p.setGameMode(GameMode.SPECTATOR);
				p.setLevel(-1);
			}
		}
		
		return false;
	}
}
