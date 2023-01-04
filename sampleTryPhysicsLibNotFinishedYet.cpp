#include <iostream>
#include <utility>
#include <vector>
#include <string>

class PhysicsObject {

    public:
        PhysicsObject() {}

        void setIdentifier(std::string nId) { identifier = nId; }
        std::string getIdentifier() { return identifier; }

        void setNewtonMass(int nNm) { newtonMass = nNm; }
        int getNewtonMass() { return newtonMass; }

        ~PhysicsObject() {}

    private:
        std::string identifier;
        int newtonMass;

};

class Map : public PhysicsObject {

    public:
        Map() {}

        void setX(int nX) { x = nX; }
        int getX() { return x; }

        void setY(int nY) { y = nY; }
        int getY() { return y; }

        void setZ(int nZ) { z = nZ; }
        int getZ() { return z; }

        void setT(int nT) { t = nT; }
        int getT() { return t; }

        Map constructMap() {

            std::pair<std::pair<std::vector<int>, std::vector<int>>, std::pair<std::vector<int>, std::vector<int>>> m;
        }

        ~Map() {}

    private:
        int x;
        int y;
        int z;
        int t;
};

int main() {

    Map m;
    m.setIdentifier("ola");
    std::cout << m.getIdentifier();

    return 0;
}
