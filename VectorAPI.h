#ifndef VECTORAPI_H_INCLUDED
#define VECTORAPI_H_INCLUDED

/* @TODO Make 2D grid */

typedef struct      Vector Vector;

struct Vector {

    double                length;                           /* In centimeter.                                                   */
    char                  way[2];                           /* Example : sens[0] = 'A'; sens[1] = 'B'. So : vector(AB)  .       */
    char            direction[2];                           /* Name of the line example : direction AB #Huhu                    */
};

void    vectorSum           (Vector v1, Vector v2);
void    vectorSub           (Vector v1, Vector v2);
void    vectorMul           (Vector v1, Vector v2);
void    vectorDiv           (Vector v1, Vector v2);
void    vector2DDraw        (Vector v);                     /* @TODO Un jour x)                                                 */
void    vectors2DDraw       (Vector v, Vector v1);          /* @TODO Un jour x)                                                 */
void    vector3DDraw        (Vector v);                     /* @TODO Un jour x)                                                 */
void    vectorCompare       (Vector v1, Vector v2);
void    vectorClone         (Vector v, Vector copy);        /* Returns a clone of this vector                                   */
void    vectorContains      (Vector v);                     /* Return the contains of the vector                                */
void    vectorClear         (Vector v);                     /* Removes all of the elements from this vector.                    */
void    vectorInsertElement (Vector v, Vector element);     /* Inserts the specified element in this vector at the index        */
void    vectorRemoveElement (Vector v, Vector element);     /* Removes the element at the specified position in this Vector.    */
void    vectorSetElement    (Vector v, Vector element);     /* Set the element to this vector at the specified position         */
void    vectorExecuteAllFun (Vector v);                     /* Execute all function on the vector                               */

void    vectorCompare       (Vector v1, Vector v2) {

    if ( (v1.length == v2.length) && ( (v1.direction[0] == v2.direction[0]) && (v1.direction[1] == v2.direction[1]) ) && ( (v1.way[0] == v2.way[0]) && ( v1.way[1] == v2.way[1])))
        printf("Equals");
    /*
     * @TODO Ajouter pour si le quadrilatere ABCD est un parallelogramme (eventuellement aplati).
     * @TODO Ajouter pour si la translation qui transforme A en B est transforme aussi C en D.
     * Attention, trouver un moyen de résoudre le problème de concurrence de nom de A && C comme ci dessous (le problème réside du
     * fait que A et C sont au même endroit en 0:0 et qu'ils sont tout les deux le point de "départ" du vecteur v et du vecteur x) :
     * http://image.noelshack.com/fichiers/2016/30/1469631325-vectorproblem.png ^^'.
     * Résolu par Ben ^^' :
                    #include <iostream>
                    typedef struct Point
                    {
                        int x;
                        int y;
                        Point()
                        {
                            x = 0, y = 0;
                        }
                        Point(int x, int y)
                        {
                            this->x = x, this->y = y;
                        }
                        Point(const Point& p)
                        {
                            x = p.x, y = p.y;
                        }
                        void operator=(Point p)
                        {
                            x = p.x, y = p.y;
                        }
                        bool operator==(Point p)
                        {
                            return x == p.x && y == p.y;
                        }
                    } Point;
                    typedef struct Line
                    {
                        Point p;
                        Point q;
                        Line()
                        {
                            p = Point(0, 0), q = Point(0, 0);
                        }
                        Line(Point p, Point q)
                        {
                            this->p = p, this->q = q;
                        }
                        Line(const Line& l)
                        {
                            p = l.p, q = l.q;
                        }
                        void operator=(Line l)
                        {
                            p = l.p, q = l.q;
                        }
                        bool operator==(Line l)
                        {
                            return p == l.p && q == l.q;
                        }
                    } Line;
                    typedef struct Vector
                    {
                        Line direction;
                        Line magnitude;
                        Vector(Point p, Point q)
                        {
                            direction.p = p, direction.q = q, magnitude.p = p, magnitude.q = q;
                        }
                        bool operator==(Vector v)
                        {
                            return direction.p == v.direction.p && direction.q == v.direction.q && magnitude.p == v.magnitude.p && magnitude.q == v.magnitude.q;
                        }
                    } Vector;
                    int main(int argc, char* argv[])
                    {
                        Vector v1(Point(0, 0), Point(5, 5));
                        Vector v2(Point(0, 0), Point(5, 5));
                        if(v1 == v2)
                            std::cout << "v1 == v2";
                        return 0;
                    }
     * Ni vu ni connu les deux dernières lignes de français héhé x).
     */
    else
        printf("Different");
}

void    vectorSum           (Vector v1, Vector v2) {

    /* With use of the Chasles's relation. */
    Vector                                   temp;

    temp.length     =       v1.length + v2.length;
    /*
     * @TODO Chercher comment ajouter pour la direction && le sens.
     */
    printf("%lf", temp.length);
}

void    vectorSub           (Vector v1, Vector v2) {

    Vector                                      temp;

    temp.length     =       v1.length + (-v2.length);
    /*
     * @TODO Chercher comment ajouter pour la direction && le sens.
     */
    printf("%lf", temp.length);

}

void    vectorClone         (Vector v, Vector copy) {

    copy        =           v;

    printf("%lf", copy.length);
    printf("First Direction : %c - Second Direction : %c", copy.direction[0], copy.direction[1]);
    printf("First Way : %c - Second Way : %c", copy.way[0], copy.way[1]);
}

void    vectorClear         (Vector v) {

    v.direction[0]      =       '0';
    v.direction[1]      =       '0';
    v.way[0]            =       '0';
    v.way[1]            =       '0';
    v.length            =         0;
}

void    vector2DDraw        (Vector v) {

    /* Not required to define the way, it is defined implicitly */

    int                           i;

    printf("%c |", v.direction[0]);

    for (i = 0; i < v.length; i++)
        printf("-");

    printf("> %c ", v.direction[1]);
}

void    vectors2DDraw       (Vector v, Vector v1) {


    int                           i;
    int                          ii;

    printf("  %c |", v.direction[0]);

    for (i = 0; i < v.length; i++)
        printf("-");

    printf("> %c \n", v.direction[1]);

    printf("%c /", v1.direction[0]);            /* After the / will be used for 3d vector ! */

    for (ii = 0; ii < v.length - 1; ii++)
        printf("\n|");

    printf("\n>%c", v1.direction[1]);
}

void    vectorContains      (Vector v) {

    printf("%lf cm.\n", v.length);
    printf("First Direction : %c - Second Direction : %c\n", v.direction[0], v.direction[1]);
    printf("First Way : %c - Second Way : %c\n", v.way[0], v.way[1]);
}

#endif // VECTORAPI_H_INCLUDED
