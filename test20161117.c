#include <stdio.h>

void addto(int * inint){
  *inint=*inint+1;
}

int main(int argc, char const *argv[]) {
  int int1=1;
  printf("%d\n", int1);
  addto(&int1);
  printf("%d\n", int1);
  return 0;
}
