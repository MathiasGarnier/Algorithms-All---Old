package org.mathiasGarnier.tss.util;

/**
 * Created by Mathias Garnier on 13/12/2016.
 */

public class Orthonormal2f {

    /* Point(0;0) -> Origine | (Abs, Ord) */
    private final short unity = 1;
    private final double origine[] = {0, 0};

    private double xSize = 0d;
    private double mXSize = 0d; // -xSize
    private double ySize = 0d;
    private double mYSize = 0d; // -ySize

    private Limits2f lim;

    /* CONSTRUCTOR */
    public Orthonormal2f(double _xSize, double _mXSize, double _ySize, double _mYSize, Limits2f _lim) {

        /* ABSCISSES */
        this.xSize = _xSize;
        this.mXSize = _mXSize;

        /* ORDONEES */
        this.ySize = _ySize;
        this.mYSize = _mYSize;

        /* LIMITS*/
        this.lim = _lim;

        Map2f map2f = new Map2f();
        map2f.generateMap2f(this);
    }

    /* GETTERS AND SETTERS */
    public short getUnity() {

        return unity;
    }

    public double[] getOrigine() {

        return origine;
    }

    public double getxSize() {

        return xSize;
    }

    public void setxSize(double xSize) {

        this.xSize = xSize;
    }

    public double getmXSize() {

        return mXSize;
    }

    public void setmXSize(double mXSize) {

        this.mXSize = mXSize;
    }

    public double getySize() {

        return ySize;
    }

    public void setySize(double ySize) {

        this.ySize = ySize;
    }

    public double getmYSize() {

        return mYSize;
    }

    public void setmYSize(double mYSize) {

        this.mYSize = mYSize;
    }

}
