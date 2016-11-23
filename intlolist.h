#ifndef INTLOLIST_H
#define INTLOLIST_H

#include "intlist.h"

typedef struct Intlolist {
  int l;
  struct Intlolist *cl;
} intlolist;

#endif
