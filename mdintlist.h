// #include <stdio.h>
// #include <stdlib.h>

#include <string.h>

#include "intlist.h"

// typedef struct {
//   int l;
//   int *e;
// } intlist;

typedef struct {
  intlist d;
  void *c;
} mdintlist;

void *tmpfunc(int inint) {
  void *tmpintptr = malloc(sizeof(int) * inint);
  return tmpintptr;
}

void *tmpfunc2(int inint) {
  void *tmpintptr = (void *)malloc(sizeof(void *) * inint);
  return tmpintptr;
}

mdintlist initmdintlist(intlist indim) {
  mdintlist tmpmdintlist;
  tmpmdintlist.d = indim;
  if (indim.l == 1) {
    tmpmdintlist.c = tmpfunc(indim.e[0]);
  } else {
    tmpmdintlist.c = tmpfunc2(indim.e[0]);
    for (int i = 0; i < indim.e[0]; i++) {
      // tmpmdintlist.c[i] = (initmdintlist(nrmfrmintlist(indim,
      // indim.e[0]))).c;

      // *((void *)tmpmdintlist.c + i) =
      //     (initmdintlist(nrmfrmintlist(indim, indim.e[0]))).c;

      // ((void *)tmpmdintlist.c)[i] =
      //     (initmdintlist(nrmfrmintlist(indim, indim.e[0]))).c;

      // ((char *)tmpmdintlist.c)[8 * i] =
      //     (void *)(initmdintlist(nrmfrmintlist(indim, indim.e[0]))).c;

      memcpy(((char *)tmpmdintlist.c)[8 * i],
             (initmdintlist(nrmfrmintlist(indim, indim.e[0]))).c, 8);
    }
  }
  return tmpmdintlist;
}

int main(int argc, char const *argv[]) {

  void *tmpintptr1 = tmpfunc(10);
  ((int *)tmpintptr1)[0] = 0;
  return 0;
}
