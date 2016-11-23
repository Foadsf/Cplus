#include "intlist.h"
#include “clcom.h”

int main(int argc, char const *argv[]) {

  intlist tmplist1;
  tmplist1.l = 8;
  int intarr1[] = {1, 8, 3, 4, 7, 6, 5, 2};
  tmplist1.e = &intarr1[0];
  printintlist(tmplist1);

  intlist tmplist2;
  tmplist2.l = 8;
  int intarr2[] = {2, 2, 2, 3, 5, 7, 9, 21};
  tmplist2.e = &intarr2[0];
  printintlist(tmplist2);

  intlist tmplist3 = clplsintlist(tmplist1, tmplist2);
  printintlist(tmplist3);

  intlist tmplist4 = clmltintlist(tmplist1, tmplist2);
  printintlist(tmplist4);


  return 0;
}
