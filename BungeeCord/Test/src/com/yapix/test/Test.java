package com.yapix.test;

import net.md_5.bungee.api.connection.ProxiedPlayer;
import net.md_5.bungee.api.event.ServerKickEvent;
import net.md_5.bungee.api.plugin.Listener;
import net.md_5.bungee.api.plugin.Plugin;
import net.md_5.bungee.event.EventHandler;

public class Test extends Plugin implements Listener{
	/*
	 * This plugin is for test ^^ :)
	 */
	public void onEnable(){
		
		this.getProxy().getPluginManager().registerListener(this, this);
		}
	
	@SuppressWarnings("unused")
	@EventHandler
	public void onServerKickEvent(ServerKickEvent e){
		
		ProxiedPlayer p = e.getPlayer(); //ProxiedPlayer = Player with Bukkit || Spigot ^^
		
	}
}
