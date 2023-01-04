package org.yapix.Rya.User;

import java.util.Scanner;

public class Main {

	@SuppressWarnings({ "resource", "unused" })
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
	
		User p = new User(getUserName("Yapix_"));
	}
	private static Object getUserName(Object userName) {
		return userName;
	}
	
}
