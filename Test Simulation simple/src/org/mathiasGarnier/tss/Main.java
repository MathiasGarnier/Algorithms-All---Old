package org.mathiasGarnier.tss;

import org.mathiasGarnier.tss.util.Limits2f;
import org.mathiasGarnier.tss.util.Map2f;
import org.mathiasGarnier.tss.util.Orthonormal2f;

public class Main {

    public static void main(String[] args) {

        Limits2f lim = new Limits2f(5d, 5d, 5d, 5d);
        Orthonormal2f orthonormal2f = new Orthonormal2f(3d, 5d, 3d, 5d, lim);

        Map2f map2f = new Map2f();

        map2f.generateMap2f(orthonormal2f);
    }
}
