#include "gvtype.h"

int main(int argc, char const *argv[]) {

  // gvtype tmpvar1 = initvar(Int);
  // int tmpint1 = 10;
  // tmpvar1.c = &tmpint1;
  //*tmpvar1.c = 10;
  //*((int *)tmpvar1.c) = 10;
  gvtype tmpvar1 = initint(10);
  gvtype tmpvar2 = tmpvar1;
  gvtype tmpvar3 = dupvar(tmpvar1);
  // printf("%d\n", *((int *)tmpvar1.c));
  printf("%d\n", gvtoint(tmpvar1));
  printf("%d\n", gvtoint(tmpvar2));
  printf("%d\n", gvtoint(tmpvar3));
  *((int *)tmpvar1.c) = 20;
  printf("%d\n", gvtoint(tmpvar1));
  printf("%d\n", gvtoint(tmpvar2));
  printf("%d\n", gvtoint(tmpvar3));
  return 0;
}
