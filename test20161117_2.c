#include <stdio.h>

typedef struct{
  int a;
  int b;
}dint;

void addto(dint * indint){
  (*indint).a=(*indint).a+1;
}

int main(int argc, char const *argv[]) {
  dint dint1;
  dint1.a=1;
  dint1.b=0;
  printf("%d\n", dint1.a);
  addto(&dint1);
  printf("%d\n", dint1.a);
  return 0;
}
