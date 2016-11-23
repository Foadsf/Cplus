#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pa = malloc(10 * sizeof(int)); // allocate an array of 10 int
  if (pa) {
    printf("%zu bytes allocated at %p. Storing ints: ", 10 * sizeof(int), pa);
    for (int n = 0; n < 10; ++n)
      printf("%d ", pa[n] = n);
    printf("\n");
  }

  int *pb =
      realloc(pa, 100 * sizeof(int)); // reallocate array to a smaller size
  if (pb) {
    printf("%zu bytes allocated at %p, first 100 ints are: ", 100 * sizeof(int),
           pb);
    for (int n = 0; n < 100; ++n) {
      pb[n] = pa[n] + 1;
      printf("%d ", pb[n]);
    }
    // show the array
    printf("\n");
    for (int n = 0; n < 10; ++n)
      printf("%d ", pa[n]);
    printf("\n");
    for (int n = 0; n < 100; ++n)
      printf("%d ", pb[n]); // show the array
    printf("\n");

    // free(pb);
    // free(pa);
    // pa = pb;
    for (int n = 0; n < 10; ++n)
      printf("%d ", pa[n]); // show the array
    printf("\n");
    for (int n = 0; n < 100; ++n)
      printf("%d ", pb[n]); // show the array
    printf("\n");
  } else { // if realloc failed, the original pointer needs to be freed
    free(pa);
  }
}
