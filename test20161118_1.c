#include <stdio.h>
//#include<stdlib.h>

typedef struct {
  int v;  // value
  int *p; // pointer
} nint;

nint initnint() {
  nint tmpnint;
  tmpnint.p = &tmpnint.v;
  return tmpnint;
}

nint inttonint(int inint) {
  nint tmpnint = initnint();
  tmpnint.v = inint;
  // tmpnint.p=&tmpnint.v;
  return tmpnint;
}

int main(int argc, char const *argv[]) {

  nint tmpnint;
  printf("%d\n", tmpnint.v);
  printf("%p\n", tmpnint.p);

  nint tmpnint2 = initnint();
  printf("%d\n", tmpnint2.v);
  printf("%p\n", tmpnint2.p);

  nint tmpnint3 = inttonint(10);
  printf("%d\n", tmpnint3.v);
  printf("%p\n", tmpnint3.p);
  return 0;
}
