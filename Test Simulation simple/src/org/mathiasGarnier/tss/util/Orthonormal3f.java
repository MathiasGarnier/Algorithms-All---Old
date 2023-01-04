package org.mathiasGarnier.tss.util;

/**
 * Created by Mathias Garnier on 13/12/2016.
 */

public class Orthonormal3f {

    /* Point(0;0; 0) -> Origine | (Abs, Ord, z) */
    private final short unity = 1;
    private final short origine[] = {0, 0, 0};

    private double xSize = 0d;
    private double mXSize = 0d; // -xSize
    private double ySize = 0d;
    private double mYSize = 0d; // -ySize

    private double zSize = 0d;
    private double mZSize = 0d;

    private Limits3f lim;

    /* CONSTRUCTOR */
    public Orthonormal3f(double _xSize, double _ySize, double _mZSize) {

        this.xSize = _xSize;
        this.ySize = _ySize;
        this.zSize = _mZSize;
    }

    public Orthonormal3f(double _xSize, double _mXSize, double _ySize, double _mYSize, double _zSize, double _mZSize, Limits3f _lim) {

        /* ABSCISSES */
        this.xSize = _xSize;
        this.mXSize = _mXSize;

        /* ORDONEES */
        this.ySize = _ySize;
        this.mYSize = _mYSize;

        /* SURFACE */
        this.zSize = _zSize;
        this.mZSize = _mZSize;

        /* LIMITS*/
        this.lim = _lim;
    }

    /* GETTERS AND SETTERS */
    public short getUnity() {

        return unity;
    }

    public short[] getOrigine() {

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

    public double getzSize() {

        return zSize;
    }

    public void setzSize(double zSize) {

        this.zSize = zSize;
    }
}

