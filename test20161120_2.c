#include <stdio.h>
#include <stdlib.h>

typedef struct Tmpstr {
  int i;
  struct Tmpstr *c;
  // void *c;
} tmpstr;

tmpstr inittmpstr(int inint) {
  tmpstr tmptmpstr;
  tmptmpstr.i = inint;
  tmptmpstr.c = (tmpstr *)malloc(sizeof(tmpstr));
  return tmptmpstr;
}

int main(int argc, char const *argv[]) {
  tmpstr tmptmpstr1 = inittmpstr(10);
  printf("%d\n", tmptmpstr1.i);
  printf("%p\n", tmptmpstr1.c);
  tmpstr tmptmpstr2;
  tmptmpstr2.i = 20;
  tmptmpstr1.c = &tmptmpstr2;
  printf("%d\n", (*tmptmpstr1.c).i);
  int tmpint = 30;
  tmptmpstr2.c = &tmpint;
  printf("%d\n", *tmptmpstr2.c);
  // printf("%p\n", *((int *)tmptmpstr2.c));
  return 0;
}
