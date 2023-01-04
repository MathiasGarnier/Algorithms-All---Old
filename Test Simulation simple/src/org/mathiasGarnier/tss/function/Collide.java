package org.mathiasGarnier.tss.function;

import org.mathiasGarnier.tss.population.Molecule;
import org.mathiasGarnier.tss.util.Orthonormal3f;
import org.mathiasGarnier.tss.util.Vector3f;

import java.util.Random;

/**
 * Created by Mathias Garnier on 13/12/2016.
 */

public class Collide {

    Random r = new Random();
    private double angle = r.nextInt(359); //Like before and after when the molecule hurt a surface.

    private Vector3f norme3f; //When molecule hurt a surface (in Orthonormal3f), the molecule undergoes a elastic choc.

    //make bounce(), isMoleculeHurtSurface, MAKE

    public boolean isMoleculeHurt2DSurface(Molecule molecule) {

        Orthonormal3f orthonormal3f = new Orthonormal3f(molecule.getX(), molecule.getY(), molecule.getZ());

        if ((molecule.getX() == orthonormal3f.getxSize()) || (molecule.getY() == orthonormal3f.getySize()) || (molecule.getZ() == orthonormal3f.getzSize())) {

            bounce2D(molecule);
            return true;
        }
        else return false;
    }

    public void bounce2D(Molecule molecule) {

        if (isMoleculeHurt2DSurface(molecule)) {

            this.angle = (Math.cos(this.angle) * 360);
            this.norme3f = new Vector3f(3.0d * molecule.getX(), 3.0d * molecule.getY(), 3.0d * molecule.getZ());
        }
    }
}
