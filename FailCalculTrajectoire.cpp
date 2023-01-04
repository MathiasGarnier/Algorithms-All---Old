#include <iostream>
#include <math.h>
#include <windows.h>

//Language converter C#->C++
//Ca marche pas x). C'est parfait :huhu: x).

#define PI 3.141592653589793238463

int main () {

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    double x0 = 0, y0 = 20;
    double angle = 80 * PI / 180;
    double v0 = 26;
    double vx0 = v0 * cos(angle), vy0 = -v0 * sin(angle);
    double g = 10;

    double x = x0, y = y0;
    double vx = vx0, vy = vy0;
    double dt = 0.1;

    do {

        if (0 <= y && y < rows * 10) {

            SetCursorPos(x, y);
            std::cout << "a" << std::endl;
        }

        vy += g * dt;
        x += vx * dt;
        y += vy * dt;

    } while (x < columns);
    return 0;
}
