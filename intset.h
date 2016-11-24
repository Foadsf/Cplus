#ifndef INTSET_H
#define INTSET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t l; // length
  int *e;   // pointer to the first element of the setay in the memory
} intset;

#include "intlist.h"

#ifndef MEMALC
#define MEMALC

int *memalc(size_t inlength) { return (int *)malloc(sizeof(int) * inlength); }

#endif

intset initintset() {
  intset tmpset;
  tmpset.l = 0;
  tmpset.e = NULL;
  return tmpset;
}

int isinintset(intset inset, int inint) {
  int tmpint = 0;
  for (size_t i = 0; i < inset.l; i++)
    if (inint == inset.e[i]) {
      tmpint = i + 1;
      break;
    };
  return tmpint;
}

int addtointset(intset *inset, int inint) {
  int tmpint = 0;
  if (!isinintset(*inset, inint)) {
    int *tmpptr = memalc((*inset).l + 1);
    for (size_t i = 0; i < (*inset).l; i++) {
      tmpptr[i] = (*inset).e[i];
      // free((*inset).e+i);
    };
    // free((*inset).e);
    tmpptr[(*inset).l] = inint;
    (*inset).e = tmpptr;
    (*inset).l++;
  };
  return tmpint;
}

int rmfrmintset(intset *inset, int inint) {
  int tmpint = 0;
  if (isinintset(*inset, inint)) {
    int tmppos = isinintset(*inset, inint) - 1;
    // free((*inset).e+tmppos);
    int *tmpptr = memalc((*inset).l - 1);
    for (int i = 0; i < tmppos; i++) {
      tmpptr[i] = (*inset).e[i];
      // free((*inset).e+i);
    };

    for (size_t i = tmppos + 1; i < (*inset).l; i++) {
      tmpptr[i - 1] = (*inset).e[i];
      // free((*inset).e+i);
    }

    // free((*inset).e);
    (*inset).e = tmpptr;
    (*inset).l--;
    tmpint = 1;
  };
  return tmpint;
}

intset unionintsets(intset inset1, intset inset2) {
  intset tmpset = inset1;
  for (size_t i = 0; i < inset2.l; i++)
    addtointset(&tmpset, inset2.e[i]);
  return tmpset;
}

intset diffintset(intset inset1, intset inset2) {
  intset tmpset = inset1;
  for (size_t i = 0; i < inset2.l; i++)
    rmfrmintset(&tmpset, inset2.e[i]);
  return tmpset;
}

intset extintset(intset *inset1, intset *inset2) {
  return unionintsets(diffintset(*inset1, *inset2),
                      diffintset(*inset2, *inset1));
}

intset intintset(intset *inset1, intset *inset2) {
  return diffintset(*inset1, diffintset(*inset1, *inset2));
}

intset intplusset(int inint, intset inset) {
  intset tmpset = initintset();
  for (size_t i = 0; i < inset.l; i++)
    addtointset(&tmpset, inint + inset.e[i]);
  return tmpset;
}

intset intmultset(int inint, intset inset) {
  intset tmpset = initintset();
  for (size_t i = 0; i < inset.l; i++)
    addtointset(&tmpset, inint * inset.e[i]);
  return tmpset;
}

intset setplusset(intset inset1, intset inset2) {
  intset tmpset = initintset();
  if (inset1.l == inset2.l) {
    for (size_t i = 0; i < inset1.l; i++)
      addtointset(&tmpset, inset1.e[i] + inset2.e[i]);
  };
  return tmpset;
}

intset setmultset(intset inset1, intset inset2) {
  intset tmpset = initintset();
  if (inset1.l == inset2.l) {
    for (size_t i = 0; i < inset1.l; i++)
      addtointset(&tmpset, inset1.e[i] * inset2.e[i]);
  };
  return tmpset;
}

intset intlisttointset(intlist inlist) {
  intset tmpintset = initintset();
  for (size_t i = 0; i < inlist.l; i++)
    addtointset(&tmpintset, inlist.e[i]);
  return tmpintset;
}

int sumintset(intset inset) {
  int tmpint = 0;
  for (size_t i = 0; i < inset.l; i++)
    tmpint = tmpint + inset.e[i];
  return tmpint;
}

int prodintset(intset inset) {
  int tmpint = 1;
  for (size_t i = 0; i < inset.l; i++)
    tmpint = tmpint * inset.e[i];
  return tmpint;
}

void printintset(intset inset) {
  printf("{");
  if (!(inset.l == 0)) {
    for (size_t i = 0; i < inset.l - 1; i++)
      printf("%d, ", inset.e[i]);
    printf("%d", inset.e[inset.l - 1]);
  };
  printf("}\n");
}

#endif
