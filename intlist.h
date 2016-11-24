/*
general description about the file and librarry
*/

/*
to do:
1. the library is not memory safe/efficient. some parts of memory which are not
used never get freed. maybe I can use realloc to make it better for that reason
branch memsafe is made
*/

// Include guards
#ifndef INTLIST_H
#define INTLIST_H

#include <stdio.h>
#include <stdlib.h>

/*
one of the biggest issues with C is that it treats arrays as pointer and the
size of the arrays can not be passed to the functions easily. for that reason we
define a new type which includes the size
*/

typedef struct {
  size_t l; // length
  int *e;   // pointer to the first element of the list in memory
} intlist;

#include "intset.h"

#ifndef MEMALC
#define MEMALC

// allocates a bulck of memory given an integer
int *memalc(size_t inlength) { return (int *)malloc(sizeof(int) * inlength); }

// can be used to free the declared intlists
void klintlist(intlist inlist) { free(inlist.e) }

#endif

// initialise a empty list
intlist initintlist() {
  intlist tmplist;
  tmplist.l = 0;
  tmplist.e = NULL;
  return tmplist;
}

// initialise a list given an integer as the length
intlist initintlistsize(size_t inint) {
  intlist tmplist;
  tmplist.l = inint;
  tmplist.e = memalc(inint);
  return tmplist;
}

// checks if the given integer inint is in the inlist. the output is zero if it
// does not exxist, otherwise the position of the init will be given. please
// notice that the position is 1 if it is the element 0 of the array
int isinintlist(intlist inlist, int inint) {
  int tmpint = 0;
  for (size_t i = 0; i < inlist.l; i++)
    if (inint == inlist.e[i]) {
      tmpint = i + 1;
      break;
    };
  return tmpint;
}

// checks if two given lists are exactly equal
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

// checks if all the elements of the two lists are same. the location may varry
// though
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

// this function takes a pointer to an intlist and adds the given integer inint
// to the end
void addtointlist(intlist *inlist, int inint) {
  int *tmpptr = memalc((*inlist).l + 1);
  // trying to use realloc it failed got to branch memsafe
  // int *tmpptr = realloc((*inlist).e, (*inlist).l + 1);
  for (size_t i = 0; i < (*inlist).l; i++) {
    tmpptr[i] = (*inlist).e[i];
    // free((*inlist).e+i); // going for memory managment and eficiency faled
    // --> branch memsafe
  };
  tmpptr[(*inlist).l] = inint;
  // free((*inlist).e); // going for memory managment and eficiency faled -->
  // branch memsafe
  (*inlist).e = tmpptr;
  (*inlist).l++;
}

// because itnlist is actually a pointer if you use intlist2=intlist1 and then
// change intlist1, intlist2 will also change automatically. you need to
// duplicate inlist1 using this function. in terms of efficiency it is a
// horrible function though!
intlist dupintlist(intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inlist.e[i]);
  return tmplist;
}

// creats an intlist pointing towards the block of memory starting from beg with
// the length of len
intlist blkintlist(intlist inlist, size_t beg, size_t len) {
  intlist tmpintlist = initintlist();
  if ((beg + len) < inlist.l) {
    tmpintlist.l = len;
    tmpintlist.e = &inlist.e[beg];
  }
  return tmpintlist;
}

// creats an intlist equivalent the block of memory starting from beg with the
// length of len
intlist nblkintlist(intlist inlist, size_t beg, size_t len) {
  intlist tmpintlist = initintlist();
  if ((beg + len) < inlist.l) {
    tmpintlist.l = len;
    tmpintlist.e = &inlist.e[beg];
  }
  return dupintlist(tmpintlist);
}

// creats a new intlist wihc has the given intger added to the given inlist,
// general rull when there is an n int he begining of a function it always
// creats a new intlist
intlist naddtointlist(intlist *inlist, int inint) {
  intlist tmplist = dupintlist(*inlist);
  addtointlist(&tmplist, inint);
  return tmplist;
}

// place the given inint int the inpose block of the given inlist
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

// creates a new intlist based on the insertintlist function
intlist ninsertintlist(intlist *inlist, int inint, size_t inpos) {
  intlist tmpintlist = dupintlist(*inlist);
  insertintlist(&tmpintlist, inint, inpos);
  return tmpintlist;
}

// looks for all instances of the inint and removes them from the given inlist
int rmfrmintlist(intlist *inlist, int inint) {
  int tmpint = 0;
  while (isinintlist(*inlist, inint)) {
    int tmppos = isinintlist(*inlist, inint) - 1;
    // free((*inlist).e+tmppos);
    int *tmpptr = memalc((*inlist).l - 1);
    // int *tmpptr = realloc((*inlist).e, (*inlist).l - 1);
    for (int i = 0; i < tmppos; i++) {
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

//
intlist nrmfrmintlist(intlist *inlist, int inint) {
  intlist tmplist = dupintlist(*inlist);
  rmfrmintlist(&tmplist, inint);
  return tmplist;
}

// removes the element which is the position inint
int rmelmintlist(intlist *inlist, size_t inint) {
  int tmpint = 0;
  if (inint < (*inlist).l) {
    int tmppos = inint;
    // free((*inlist).e+tmppos);
    int *tmpptr = memalc((*inlist).l - 1);
    // int *tmpptr = realloc((*inlist).e, (*inlist).l - 1);
    for (int i = 0; i < tmppos; i++) {
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

intlist nrmelmintlist(intlist *inlist, size_t inint) {
  intlist tmplist = dupintlist(*inlist);
  rmelmintlist(&tmplist, inint);
  return tmplist;
}

// append lists toghethe
intlist appendintlists(intlist *inintlist1, intlist *inintlist2) {
  intlist tmplist = dupintlist(*inintlist1);
  for (size_t i = 0; i < (*inintlist2).l; i++)
    addtointlist(&tmplist, (*inintlist2).e[i]);
  return tmplist;
}

// adds an integer to all elements of the intlist
intlist intpluslist(int inint, intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inint + inlist.e[i]);
  return tmplist;
}

// mulitplies all the elements of the intlist with the given integer
intlist intmultlist(int inint, intlist inlist) {
  intlist tmplist = initintlist();
  for (size_t i = 0; i < inlist.l; i++)
    addtointlist(&tmplist, inint * inlist.e[i]);
  return tmplist;
}

// adds two intlists with the same size toghether
intlist listpluslist(intlist inlist1, intlist inlist2) {
  intlist tmplist = initintlist();
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++)
      addtointlist(&tmplist, inlist1.e[i] + inlist2.e[i]);
  };
  return tmplist;
}

// multiplies the elements of the two intlists with equal size
intlist listmultlist(intlist inlist1, intlist inlist2) {
  intlist tmplist = initintlist();
  if (inlist1.l == inlist2.l) {
    for (size_t i = 0; i < inlist1.l; i++)
      addtointlist(&tmplist, inlist1.e[i] * inlist2.e[i]);
  };
  return tmplist;
}

// converts an intset to an intlist
intlist intsettointlist(intset inset) {
  intlist tmpintlist = initintlist();
  for (size_t i = 0; i < inset.l; i++)
    addtointlist(&tmpintlist, inset.e[i]);
  return tmpintlist;
}

// adds all the elements of the intlist
int sumintlist(intlist inlist) {
  int tmpint = 0;
  for (size_t i = 0; i < inlist.l; i++)
    tmpint = tmpint + inlist.e[i];
  return tmpint;
}

// multiplies all the elements of the intlist
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

// prints a given intlist on the eterminal
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
