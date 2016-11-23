#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  int *tmparr = malloc(sizeof(int[2][2]));
  tmparr[0] = 1;
  printf("%d\n", tmparr[0]);
  return 0;
}
