#ifndef GVTYPE_H
#define GVTYPE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum Types {
  Int,   // int
  usInt, // unsigned int
  Char,  // char
  Float, // float
  Size_t // seze_t
} types;

typedef struct Gvtype {
  types t; // type of the variable
  void *c; // content of the variable
} gvtype;

gvtype initvar(types intype) {
  gvtype tmpgvtype;
  tmpgvtype.t = intype;
  switch (intype) {
  case Int: {
    tmpgvtype.c = (int *)malloc(sizeof(int));
    break;
  }
  case Char: {
    tmpgvtype.c = (char *)malloc(sizeof(char));
    break;
  }

  default: { tmpgvtype.c = (void *)malloc(sizeof(void)); }
  };
  return tmpgvtype;
}

gvtype initint(int inint) {
  gvtype tmpvar = initvar(Int);
  *((int *)tmpvar.c) = inint;
  return tmpvar;
}

int gvtoint(gvtype ingvtype) {
  int tmpint;
  if (ingvtype.t == Int) {
    tmpint = *((int *)ingvtype.c);
  };
  return tmpint;
}

gvtype dupvar(gvtype invar) {
  gvtype tmpvar = initvar(invar.t);
  // gvtype tmpvar;
  // tmpvar.t = invar.t;
  switch (invar.t) {
  case Int: {
    int tmpint = *((int *)invar.c);
    // tmpvar.c = &tmpint;
    *((int *)tmpvar.c) = tmpint;
    break;
  }
  };
  return tmpvar;
}

// void printgvt

#endif
