package fr.yapix.anothercrew.timelord.fonctions;

import org.bukkit.entity.Player;
import org.bukkit.event.EventHandler;
import org.bukkit.event.Listener;
import org.bukkit.event.block.BlockBreakEvent;
import org.bukkit.event.entity.EntityDamageEvent;
import org.bukkit.event.entity.EntityDamageEvent.DamageCause;

public class Fonctionnality implements Listener{

	@EventHandler
	public void noFallDamage(EntityDamageEvent e){
		
        if(e.getEntity() instanceof Player && e.getCause() == DamageCause.FALL){
            e.setCancelled(true);
        }
	}
	
    @EventHandler
    public void onBlockBreak(BlockBreakEvent event){
        event.setCancelled(true);
    }
}
