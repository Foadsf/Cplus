#ifndef MDINTLIST_H
#define MDINTLIST_H

#include "intlist.h"

typedef struct Mdintlist {
  intlist d; // dimention
  // struct Mdintlist *cl; // chiled lists
  // void *cl;
  // int **cl;
  // intlist *cl;
  int *cl;
} mdintlist;

// int **malcintarr(intlist indim) {
//   int **tmpptr = (int **)malloc(sizeof(int *) * indim.e[0]);
//   if (indim.l == 2) {
//     for (size_t i = 0; i < indim.e[0]; i++) {
//       tmpptr[i] = (int *)malloc(sizeof(int) * indim.e[1]);
//     }
//   } else {
//     for (size_t i = 0; i < indim.e[0]; i++) {
//       tmpptr[i] = *malcintarr(nrmfrmintlist(indim, indim.e[0]));
//     }
//   }
//   return tmpptr;
// }

// void *malcintarr(intlist indim) {
//   if (indim.l == 1) {
//     int *tmpptr = (int *)malloc(sizeof(int) * indim.e[0]);
//   } else {
//     void **tmpptr = (void **)malloc(sizeof(void *) * indim.e[0]);
//     for (size_t i = 0; i < indim.e[0]; i++) {
//       tmpptr[i] = malcintarr(nrmfrmintlist(indim, indim.e[0]));
//     }
//   }
//   return tmpptr;
// }

int *malcintarr(intlist indim) {
  int *tmpptr = (int *)malloc(sizeof(int) * prodintlist(indim));
  return tmpptr;
}

mdintlist initmdintlist(intlist indim) {
  mdintlist tmpmdintlist;
  tmpmdintlist.d = indim;
  tmpmdintlist.cl = malcintarr(indim);
  // // tmpmdintlist.cl = (int *)malloc(sizeof(int) * prodintlist(indim));
  // tmpmdintlist.cl = malloc(sizeof(int *) * indim.e[0]);
  // if (indim.l == 1) {
  //   // tmpmdintlist.cl = (mdintlist *)malloc(sizeof(int) * indim.e[0]);
  //   // tmpmdintlist.cl = (int *)malloc(sizeof(int) * indim.e[0]);
  //   // tmpmdintlist.cl = memalc(indim.e[0]);
  //   tmpmdintlist.cl = (intlist *)malloc(sizeof(intlist) * indim.e[0]);
  // } else {
  //   // tmpmdintlist.cl = (mdintlist *)malloc(sizeof(int) * indim.e[0]);
  //   // tmpmdintlist.cl=(void *)malloc(sizeof(void)*indim.e[0])
  //   tmpmdintlist.cl = (mdintlist *)malloc(
  //       sizeof(initmdintlist(nrmfrmintlist(indim, indim.e[0]))) *
  //       indim.e[0]);
  //   // for (size_t i = 0; i < indim.e[0]; i++) {
  //   //   tmpmdintlist.cl[i] =
  //   &initmdintlist(nrmfrmintlist(indim,indim.e[0]));
  //   // }
  // }
  return tmpmdintlist;
}

// mdintlist intlisttomdl(intlist inlist, intlist indim) {
//   mdintlist tmpmdintlist;
//   if (prodintlist(indim) == inlist.l) {
//     tmpmdintlist = initmdintlist(indim);
//     if (indim.l == 1) {
//       for (size_t i = 0; i < indim.e[0]; i++) {
//         tmpmdintlist.cl[i] = &inlist.e[i];
//       }
//     } else {
//       for (size_t i = 0; i < indim.e[0]; i++) {
//         tmpmdintlist.cl[i] =
//             (intlisttomdl(blkintlist(inlist, i * (inlist.l / indim.e[0]),
//                                      inlist.l / indim.e[0]),
//                           nrmfrmintlist(indim, indim.e[0])))
//                 .cl;
//       }
//     }
//   };
//   return tmpmdintlist;
// }

int ppelmdil(intlist inlist1, intlist inlist2) {
  int tmpint = 0;
  if (inlist1.l == inlist2.l) {
    int tmpint2 = inlist1.l;
    for (int i; i < tmpint2; i++) {
      if (tmpint2 - 2 < i) {
        tmpint = (tmpint + inlist1.e[tmpint2 - 1 - i]);
      } else {
        tmpint =
            inlist2.e[tmpint2 - 2 - i] * (tmpint + inlist1.e[tmpint2 - 1 - i]);
      }
    }
  }
  return tmpint;
}

int mdiltoint(mdintlist inmdintlist, intlist elmpos) {
  int tmpint;
  // if (smallerthan(elmpos, inmdintlist.d)) {
  tmpint = inmdintlist.cl[ppelmdil(elmpos, inmdintlist.d)];
  // }
  return tmpint;
}

#endif
