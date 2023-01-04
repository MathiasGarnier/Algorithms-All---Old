package org.mathiasGarnier.tss.util;

/**
 * Created by Mathias Garnier on 13/12/2016.
 */

public class Limits2f {

    //Determined limits of Orthonormal Map2f.

    private double xSize = 0d;
    private double mXSize = 0d;
    private double ySize = 0d;
    private double mYSize = 0d;

    public Limits2f(double _xSize, double _mXSize, double _ySize, double _mYSize) {

        this.xSize = _xSize;
        this.mXSize = _mXSize;

        this.ySize = _ySize;
        this.mYSize = _mYSize;
    }

    public double getmYSize() {

        return mYSize;
    }

    public void setmYSize(double mYSize) {

        this.mYSize = mYSize;
    }

    public double getySize() {

        return ySize;
    }

    public void setySize(double ySize) {

        this.ySize = ySize;
    }

    public double getmXSize() {

        return mXSize;
    }

    public void setmXSize(double mXSize) {

        this.mXSize = mXSize;
    }

    public double getxSize() {

        return xSize;
    }

    public void setxSize(double xSize) {

        this.xSize = xSize;
    }
}
