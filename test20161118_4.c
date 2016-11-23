//#include <stdio.h>
#include "vec3d.h"


int main(int argc, char const *argv[]) {

  vec3D tempvec3D1={1,2,3};
  vec3D tempvec3D2={4,5,6};
  printvec3D(tempvec3D1);
  printf("%f\n", dotprodvec3D(tempvec3D1, tempvec3D2));
  printvec3D(crossprodvec3D(tempvec3D1, tempvec3D2));
  printvec3D(scalvec3D(10,tempvec3D1));
  printf("%f\n", normvec3D(tempvec3D1));
  printvec3D(unitvec3D(tempvec3D1));
  printvec3D(scalvec3D(normvec3D(tempvec3D1), unitvec3D(tempvec3D1)));
  return 0;
}
