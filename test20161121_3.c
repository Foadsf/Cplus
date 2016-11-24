#include "mdintlist.h"
#include "nsort.h"

int main(int argc, char const *argv[]) {

  intlist tmplist1;
  tmplist1.l = 8;
  int intarr1[] = {1, 8, 3, 4, 7, 6, 5, 2};
  tmplist1.e = &intarr1[0];
  printintlist(tmplist1);

  intlist tmplist2;
  tmplist2.l = 3;
  int intarr2[] = {2, 2, 2};
  tmplist2.e = &intarr2[0];
  printintlist(tmplist2);

  printf("%d\n", prodintlist(tmplist2));

  intlist tmplist3;
  tmplist3.l = 3;
  int intarr3[] = {1, 1, 1};
  tmplist3.e = &intarr3[0];
  printintlist(tmplist3);

  mdintlist tmpmdil1 = initmdintlist(tmplist2);
  tmpmdil1.cl = tmplist1.e;
  // mdintlist tmpmdil2 = intlisttomdl(tmplist1, tmplist2);
  printf("%d\n", ppelmdil(tmplist3, tmplist2));
  printf("%zu,%zu,%zu\n", tmplist2.l, tmplist3.l, tmpmdil1.d.l);
  printf("%d\n", mdiltoint(tmpmdil1, tmplist3));

  qsrtintlist(&tmplist1);
  printintlist(tmplist1);

  return 0;
}
