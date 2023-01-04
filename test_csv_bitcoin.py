import csv

from PyQt5 import QtWidgets
from pyqtgraph import PlotWidget, plot
from PyQt5.QtGui import QColor, QPen
import pyqtgraph as pg
import sys  # We need sys so that we can pass argv to QApplication
import os

filename = "btc.csv"


x = [i for i in range(2, 4539)]
y = []

with open(filename, 'r') as csvfile:
    next(csvfile)
    for elmt in csv.reader(csvfile):

        if elmt[68] == "":
            y.append(float(0))
        else:
            y.append(float(elmt[68]))


xN = [i for i in range(2, 4538)]
dydx = []
for i in range(len(y) - 1):
    dydx.append((y[i + 1] - y[i])/(x[i + 1] - x[i]))

class MainWindow(QtWidgets.QMainWindow):

    def __init__(self, *args, **kwargs):
        super(MainWindow, self).__init__(*args, **kwargs)

        self.graphWidget = pg.PlotWidget()
        self.setCentralWidget(self.graphWidget)

        # plot data: x, y values
        self.graphWidget.setBackground('w')
        self.graphWidget.plot(x, y, pen=QPen(QColor(0, 0, 0)))
        self.graphWidget.plot(xN, dydx, pen=QPen(QColor(0, 0, 255)))




def main():
    app = QtWidgets.QApplication(sys.argv)
    main = MainWindow()
    main.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
