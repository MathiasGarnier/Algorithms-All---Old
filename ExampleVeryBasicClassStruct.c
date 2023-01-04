#include <stdio.h>

typedef struct Class {

  char* id;
} Class;

char* getClass(Class *c);

int main(int argc, char const *argv[]) {

  Class this;
  this.id = __FILE__;

  printf("%s\n", getClass(&this));
  return 0;
}

char* getClass(Class *c) {

  return c->id;
}
