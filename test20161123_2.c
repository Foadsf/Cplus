#include <stdio.h>
// #include <stdlib.h>

int main(int argc, char const *argv[]) {

  int ii;
  void *vv;

  ii = 276;
  vv = (int *)&ii;
  printf("%d\n", *(int *)vv);
  return 0;
}
