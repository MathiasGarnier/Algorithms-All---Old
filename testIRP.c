#include <stdio.h>
#include <stdbool.h>

int u1();
int v();
void provide_u1();
void provide_v();

typedef struct {
    int object;
    bool is_built;
} item;

#define IRP_OBJECT_NUMBER 100 // À calculer lorsque le programme est lu.

item IRPC99_STATUS[IRP_OBJECT_NUMBER];

int t() {
    
    int t1;
    t1 = u1() + v() + 4;
    
    item status_t1 = { .object = t1, .is_built = true};
    IRPC99_STATUS[0] = status_t1; // Chaque élement a son index !

    item status_t2 = { .object = 1000, .is_built = false };
    IRPC99_STATUS[1] = status_t2;

    return t1;
}

void build_t(int x, int y, int result) {

    result = x + y + 4;
}

void provide_t() {

    if (!(IRPC99_STATUS->is_built)) {

        provide_u1();
        provide_v();

        build_t(u1(), v(), t());
        IRPC99_STATUS->is_built = true;
    }
}

int u1() {
    return 10;
}

int v() {

    return 6;
}

void provide_u1() {

}

void provide_v() {

}

int main() {

    printf("%d\n", t());
    printf("%d, %d", IRPC99_STATUS[0].object, IRPC99_STATUS[0].is_built);
}
