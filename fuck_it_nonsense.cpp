Variable x, y, z, r; //Symbolic variable (such as Sage[...])

Structure surface = new Structure({ 
	pow(x, 2) + pow(y, 2) + pow(z, 2) <= pow(r, 2)
});

auto stated_quantum_position;
stated_quantum_position.domain(surface);
stated_quantum_position.wave_function(exp(norm(vectorize(x, y, z)) / a) / (sqrt(pi * pow(a, 3))), "phi"); //Wave function Hydrogen, denoted as "phi"
stated_quantum_position.there_is_an_electron({
	for_each(surface.dx, surface.dy, surface.dz : surface.domain()) {
		if(pow(abs("phi"), 2) == 1 && tri_dimensional_iter((0, 0, 0), "i j k", (r, r, r), assert(electron_at("i j k") == 1))) //tri_dimensional_iter : in a combinatorial way
		display("Electron there");
	}
});

//==========================
//Transformation + Intrication(using &: operator)
//==========================

Variable x, y, z, r, i, j, k, i_prime, j_prime, k_prime;
Structure surface = new Structure({ 
	pow(x, 2) + pow(y, 2) + pow(z, 2) <= pow(r, 2)
});

auto stated_quantum_position;
stated_quantum_position.domain(surface);
stated_quantum_position.wave_function(exp(norm(vectorize(i, j, k)) / a) / (sqrt(pi * pow(a, 3))), "phi"); //Wave function Hydrogen, denoted as "phi"
stated_quantum_position.there_is_an_electron({
	if (tri_dimensional_iter((0, 0, 0), "i j k", (r, r, r), pow(abs("phi"), 2))) display("Electron there"); {
		if (stated_quantum_position.state(i, j, k) &: stated_quantum_position.state(i_prime, j_prime, k_prime)) display("Particle is intricated."); //Admitting that i_prime, j_prime and k_prime : iter in a combinatorial way, different from i, j, k
	}
});
