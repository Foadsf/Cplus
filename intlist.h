#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
  size_t l; // length
  int *e;   // pointer to the first element of the listay in the memory
} intlist;


#include "intset.h"

#ifndef MEMALC
#define MEMALC

int *memalc(size_t inlength) { return (int *)malloc(sizeof(int) * inlength); }

void klintlist(intlist inlist) { free(inlist.e) }

#endif

#ifndef QSRT
#define QSRT

int compareint(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

void qsrtintlist(intlist *inlist) {
  qsort((*inlist).e, (*inlist).l, sizeof(int), compareint);
}

#endif

intlist initintlist() {
  intlist tmplist;
  tmplist.l = 0;
  tmplist.e = NULL;
  return tmplist;
}

intlist initintlistsize(size_t inint) {
  intlist tmplist;
  tmplist.l = inint;
  tmplist.e = memalc(inint);
  return tmplist;
}

int isinintlist(intlist inlist, int inint) {
  int tmpint = 0;
  for (size_t i = 0; i < inlist.l; i++)
    if (inint == inlist.e[i]) {
      tmpint = i + 1;
      break;
    };
  return tmpint;
}

int areqintlist(intlist inlist1, intlist inlist2) {
  int tmpint = 0;
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++) {
      if (inlist1.e[i] == inlist2.e[i]) {
        tmpint = 1;
      } else {
        return 0;
      }
    }
  }
  return tmpint;
}

int arsmintlist(intlist inlist1, intlist inlist2) {
  int tmpint = 0;
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++) {
      if (isinintlist(inlist1, inlist2.e[i])) {
        return 0;
      } else {
        tmpint = 1;
      }
    }
  }
  return tmpint;
}

void addtointlist(intlist *inlist, int inint) {
  int *tmpptr = memalc((*inlist).l + 1);
  // int *tmpptr = realloc((*inlist).e, (*inlist).l + 1);
  for (size_t i = 0; i < (*inlist).l; i++) {
    tmpptr[i] = (*inlist).e[i];
    // free((*inlist).e+i);
  };
  tmpptr[(*inlist).l] = inint;
  // free((*inlist).e);
  (*inlist).e = tmpptr;
  (*inlist).l++;
}

intlist dupintlist(intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inlist.e[i]);
  return tmplist;
}

intlist blkintlist(intlist inlist, size_t beg, size_t len) {
  intlist tmpintlist = initintlist();
  if ((beg + len) < inlist.l) {
    tmpintlist.l = len;
    tmpintlist.e = &inlist.e[beg];
  }
  return tmpintlist;
}

intlist nblkintlist(intlist inlist, size_t beg, size_t len) {
  intlist tmpintlist = initintlist();
  if ((beg + len) < inlist.l) {
    tmpintlist.l = len;
    tmpintlist.e = &inlist.e[beg];
  }
  return dupintlist(tmpintlist);
}

intlist naddtointlist(intlist inlist, int inint) {
  intlist tmplist = dupintlist(inlist);
  addtointlist(&tmplist, inint);
  return tmplist;
}

int insertintlist(intlist *inlist, int inint, size_t inpos) {
  int tmpint = 0;
  if (inpos < (*inlist).l) {
    int *tmpptr = memalc((*inlist).l + 1);
    // int *tmpptr = realloc((*inlist).e, (*inlist).l + 1);
    for (size_t i = 0; i < inpos; i++) {
      tmpptr[i] = (*inlist).e[i];
      // free((*inlist).e+i);
    };
    tmpptr[inpos] = inint;
    for (size_t i = inpos; i < (*inlist).l; i++) {
      tmpptr[i + 1] = (*inlist).e[i];
      // free((*inlist).e+i);
    };
    // free((*inlist).e);
    (*inlist).e = tmpptr;
    (*inlist).l++;
    tmpint = 1;
  };
  return tmpint;
}

intlist ninsertintlist(intlist inlist, int inint, size_t inpos) {
  intlist tmpintlist = dupintlist(inlist);
  insertintlist(&tmpintlist, inint, inpos);
  return tmpintlist;
}

int rmfrmintlist(intlist *inlist, int inint) {
  int tmpint = 0;
  while (isinintlist(*inlist, inint)) {
    int tmppos = isinintlist(*inlist, inint) - 1;
    // free((*inlist).e+tmppos);
    int *tmpptr = memalc((*inlist).l - 1);
    // int *tmpptr = realloc((*inlist).e, (*inlist).l - 1);
    for (size_t i = 0; i < tmppos; i++) {
      tmpptr[i] = (*inlist).e[i];
      // free((*inlist).e+i);
    };

    for (size_t i = tmppos + 1; i < (*inlist).l; i++) {
      tmpptr[i - 1] = (*inlist).e[i];
      // free((*inlist).e+i);
    }

    // free((*inlist).e);
    (*inlist).e = tmpptr;
    (*inlist).l--;
    tmpint = 1;
  };
  return tmpint;
}

intlist nrmfrmintlist(intlist inlist, int inint) {
  intlist tmplist = dupintlist(inlist);
  rmfrmintlist(&tmplist, inint);
  return tmplist;
}

int rmelmintlist(intlist *inlist, size_t inint) {
  int tmpint = 0;
  if (inint < (*inlist).l) {
    int tmppos = inint;
    // free((*inlist).e+tmppos);
    int *tmpptr = memalc((*inlist).l - 1);
    // int *tmpptr = realloc((*inlist).e, (*inlist).l - 1);
    for (size_t i = 0; i < tmppos; i++) {
      tmpptr[i] = (*inlist).e[i];
      // free((*inlist).e+i);
    };

    for (size_t i = tmppos + 1; i < (*inlist).l; i++) {
      tmpptr[i - 1] = (*inlist).e[i];
      // free((*inlist).e+i);
    }

    // free((*inlist).e);
    (*inlist).e = tmpptr;
    (*inlist).l--;
    tmpint = 1;
  };
  return tmpint;
}

intlist nrmelmintlist(intlist inlist, size_t inint) {
  intlist tmplist = dupintlist(inlist);
  rmelmintlist(&tmplist, inint);
  return tmplist;
}

intlist appendintlists(intlist inintlist1, intlist inintlist2) {
  intlist tmplist = inintlist1;
  for (size_t i = 0; i < inintlist2.l; i++)
    addtointlist(&tmplist, inintlist2.e[i]);
  return tmplist;
}

intlist intpluslist(int inint, intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inint + inlist.e[i]);
  return tmplist;
}

intlist intmultlist(int inint, intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inint * inlist.e[i]);
  return tmplist;
}

intlist listpluslist(intlist inlist1, intlist inlist2) {
  intlist tmplist = initintlist();
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++)
      addtointlist(&tmplist, inlist1.e[i] + inlist2.e[i]);
  };
  return tmplist;
}

intlist listmultlist(intlist inlist1, intlist inlist2) {
  intlist tmplist = initintlist();
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++)
      addtointlist(&tmplist, inlist1.e[i] * inlist2.e[i]);
  };
  return tmplist;
}

intlist intsettointlist(intset inset) {
  intlist tmpintlist = initintlist();
  for (size_t i = 0; i < inset.l; i++)
    addtointlist(&tmpintlist, inset.e[i]);
  return tmpintlist;
}

int sumintlist(intlist inlist) {
  int tmpint = 0;
  for (size_t i = 0; i < inlist.l; i++)
    tmpint = tmpint + inlist.e[i];
  return tmpint;
}

int prodintlist(intlist inlist) {
  int tmpint;
  if (inlist.l == 0) {
    tmpint = 0;
  } else {
    tmpint = 1;
    for (size_t i = 0; i < inlist.l; i++)
      tmpint = tmpint * inlist.e[i];
  };
  return tmpint;
}

void printintlist(intlist inlist) {
  printf("[");
  if (!(inlist.l == 0)) {
    for (size_t i = 0; i < inlist.l - 1; i++)
      printf("%d, ", inlist.e[i]);
    printf("%d", inlist.e[inlist.l - 1]);
  };
  printf("]\n");
}

#endif
