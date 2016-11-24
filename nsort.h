#ifndef NSORT_H
#define NSORT_H

#include "intlist.h"

// the compare function for the qsort
int compareint(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

// quick sort algorithm
void qsrtintlist(intlist *inlist) {
  qsort((*inlist).e, (*inlist).l, sizeof(int), compareint);
}

// shell sort function
// copied from here:
// https://www.tutorialspoint.com/data_structures_algorithms/shell_sort_program_in_c.htm

void ssrtintlist(intlist *inlist) {
  int inner, outer;
  int valueToInsert;
  int interval = 1;
  int elements = (*inlist).l;
  int i = 0;

  while (interval <= elements / 3) {
    interval = interval * 3 + 1;
  }
  while (interval > 0) {
    for (outer = interval; outer < elements; outer++) {
      valueToInsert = (*inlist).e[outer];
      inner = outer;

      while (inner > interval - 1 &&
             (*inlist).e[inner - interval] >= valueToInsert) {
        (*inlist).e[inner] = (*inlist).e[inner - interval];
        inner -= interval;
      }

      (*inlist).e[inner] = valueToInsert;
    }

    interval = (interval - 1) / 3;
    i++;
  }
}

// buble sort algorithm
// copied from here:
// http://www.programmingsimplified.com/c/source-code/c-program-bubble-sort
void bsrtintlist(intlist *inlist) {
  size_t c, d;
  int swap;
  for (c = 0; c < ((*inlist).l - 1); c++) {
    for (d = 0; d < (*inlist).l - c - 1; d++) {
      if ((*inlist).e[d] > (*inlist).e[d + 1]) /* For decreasing order use < */
      {
        swap = (*inlist).e[d];
        (*inlist).e[d] = (*inlist).e[d + 1];
        (*inlist).e[d + 1] = swap;
      }
    }
  }
}

// insertion sort algorithm
// copied from here:
// http://www.programmingsimplified.com/c/source-code/c-program-insertion-sort

void isrtintlist(intlist *inlist) {
  size_t c;
  int t, d;
  for (c = 1; c <= (*inlist).l - 1; c++) {
    d = c;

    while (d > 0 && (*inlist).e[d] < (*inlist).e[d - 1]) {
      t = (*inlist).e[d];
      (*inlist).e[d] = (*inlist).e[d - 1];
      (*inlist).e[d - 1] = t;

      d--;
    }
  }
}

void slsrtintlist(intlist *inlist) {
  int c, d, position, swap;
  int n = (*inlist).l;
  for (c = 0; c < (n - 1); c++) {
    position = c;

    for (d = c + 1; d < n; d++) {
      if ((*inlist).e[position] > (*inlist).e[d])
        position = d;
    }
    if (position != c) {
      swap = (*inlist).e[c];
      (*inlist).e[c] = (*inlist).e[position];
      (*inlist).e[position] = swap;
    }
  }
}

// mergesort
// copied from here: https://gist.github.com/mycodeschool/9678029

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(int *A, int *L, int leftCount, int *R, int rightCount) {
  int i, j, k;

  // i - to mark the index of left aubarray (L)
  // j - to mark the index of right sub-raay (R)
  // k - to mark the index of merged subarray (A)
  i = 0;
  j = 0;
  k = 0;

  while (i < leftCount && j < rightCount) {
    if (L[i] < R[j])
      A[k++] = L[i++];
    else
      A[k++] = R[j++];
  }
  while (i < leftCount)
    A[k++] = L[i++];
  while (j < rightCount)
    A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void MergeSort(int *A, int n) {
  int mid, i, *L, *R;
  if (n < 2)
    return; // base condition. If the array has less than two element, do
            // nothing.

  mid = n / 2; // find the mid index.

  // create left and right subarrays
  // mid elements (from index 0 till mid-1) should be part of left sub-array
  // and (n-mid) elements (from mid to n-1) will be part of right sub-array
  L = (int *)malloc(mid * sizeof(int));
  R = (int *)malloc((n - mid) * sizeof(int));

  for (i = 0; i < mid; i++)
    L[i] = A[i]; // creating left subarray
  for (i = mid; i < n; i++)
    R[i - mid] = A[i]; // creating right subarray

  MergeSort(L, mid);            // sorting the left subarray
  MergeSort(R, n - mid);        // sorting the right subarray
  Merge(A, L, mid, R, n - mid); // Merging L and R into A as sorted list.
  free(L);
  free(R);
}

void msrtintlist(intlist *inlist) { MergeSort((*inlist).e, (*inlist).l); }

// heap sorte
// copied from here: http://www.sanfoundry.com/c-program-heap-sort-algorithm/
void hsrtintlist(intlist *inlist) {
  int no, i, j, c, root, temp;
  no = (*inlist).l;
  for (i = 1; i < no; i++) {
    c = i;
    do {
      root = (c - 1) / 2;
      if ((*inlist).e[root] <
          (*inlist).e[c]) /* to create MAX (*inlist).e array */
      {
        temp = (*inlist).e[root];
        (*inlist).e[root] = (*inlist).e[c];
        (*inlist).e[c] = temp;
      }
      c = root;
    } while (c != 0);
  }
  for (j = no - 1; j >= 0; j--) {
    temp = (*inlist).e[0];
    (*inlist).e[0] =
        (*inlist).e[j]; /* swap max element with rightmost leaf element */
    (*inlist).e[j] = temp;
    root = 0;
    do {
      c = 2 * root + 1; /* left node of root element */
      if (((*inlist).e[c] < (*inlist).e[c + 1]) && c < j - 1)
        c++;
      if ((*inlist).e[root] < (*inlist).e[c] &&
          c < j) /* again rearrange to max (*inlist).e array */
      {
        temp = (*inlist).e[root];
        (*inlist).e[root] = (*inlist).e[c];
        (*inlist).e[c] = temp;
      }
      root = c;
    } while (c < j);
  }
}

// comb sort
// copied from here:
// https://en.wikibooks.org/wiki/Algorithm_Implementation/Sorting/Comb_sort#cite_note-1
void comb_sort(int *input, size_t size) {
  const float shrink = 1.3f;
  int swap;
  size_t i, gap = size;
  bool swapped = false;

  while ((gap > 1) || swapped) {
    if (gap > 1) {
      gap = (size_t)((float)gap / shrink);
    }

    swapped = false;

    for (i = 0; gap + i < size; ++i) {
      if (input[i] > input[i + gap]) {
        swap = input[i];
        input[i] = input[i + gap];
        input[i + gap] = swap;
        swapped = true;
      }
      if (input[i] == input[i + gap]) {
        swapped = true;
      }
    }
  }
}

void csrtintlist(intlist *inlist) { comb_sort((*inlist).e, (*inlist).l); }

#endif
