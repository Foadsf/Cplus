#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

  int *intarr1 = (int *)malloc(sizeof(int) * 3);
  intarr1[0] = 1;
  intarr1[1] = 2;
  intarr1[2] = 3;

  // int *intarr2 = (int *)malloc(sizeof(int) * 3);
  // intarr1[0] = 4;
  // intarr1[1] = 20;
  // intarr1[2] = 6;

  void *vdarr1 = malloc(sizeof(void *) * 5);

  memcpy(vdarr1, &intarr1, 8);
  // memcpy(vdarr1 + 8, &intarr2, 8);

  printf("%d\n", (*((int **)vdarr1))[0]);

  free(intarr1);
  // free(intarr2);
  free(vdarr1);
  return 0;
}
