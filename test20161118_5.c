#include "intlist.h"

int main(int argc, char const *argv[]) {

  intlist tmplist1;

  addtointlist(&tmplist1, 4);

  addtointlist(&tmplist1, 4);

  addtointlist(&tmplist1, 5);
  addtointlist(&tmplist1, 6);
  addtointlist(&tmplist1, 8);
  addtointlist(&tmplist1, 23);
  addtointlist(&tmplist1, 11);
  printintlist(tmplist1);

  intlist tmplist2;

  addtointlist(&tmplist2, 3);
  printintlist(tmplist2);
  addtointlist(&tmplist2, 12);

  addtointlist(&tmplist2, 8);
  addtointlist(&tmplist2, 98);
  addtointlist(&tmplist2, 24);
  addtointlist(&tmplist2, 32);
  addtointlist(&tmplist2, 1);
  printintlist(tmplist2);

  // rmfrmintlist(&tmplist1, 4);
  // rmelmintlist(&tmplist1, 4);
  // printintlist(tmplist1);

  printintlist(appendintlists(&tmplist1, &tmplist2));
  printintlist(intpluslist(10, tmplist1));
  printintlist(intmultlist(10, tmplist1));
  printintlist(listpluslist(tmplist2, tmplist1));
  printintlist(listmultlist(tmplist2, tmplist1));
  insertintlist(&tmplist1, 41, 3);
  printintlist(tmplist1);

  return 0;
}
