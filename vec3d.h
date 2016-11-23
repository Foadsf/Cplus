#ifndef VEC3D_H
#define VEC3D_H


// #ifndef STDIO_H
// #define STDIO_H
// #include <stdio.h>
// #endif
//
//
//
// #ifndef STDLIB_H
// #define STDLIB_H
// #include <stdlib.h>
// #endif
//
// #ifndef MATH_H
// #define MATH_H
// #include <math.h>
// #endif

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



typedef struct {
    float x,y,z;
}vec3D;

vec3D mkvec3D(float inx, float iny, float inz) {
    vec3D tempvec3D;
    //vec3D tempvec3D={inx,iny,inz};
    tempvec3D.x=inx;
    tempvec3D.y=iny;
    tempvec3D.z=inz;
    return tempvec3D;
}

float dotprodvec3D(vec3D invec1, vec3D invec2){
    return invec1.x*invec2.x+invec1.y*invec2.y+invec1.z*invec2.z;
}

float normvec3D(vec3D invec){
    return sqrt(dotprodvec3D(invec,invec));
    //return sqrt(invec3D.x*invec3D.x+invec3D.y*invec3D.y+invec3D.z*invec3D.z);
}

vec3D scalvec3D(float inscal, vec3D invec3D){
    vec3D tempvec3D;
    tempvec3D.x=inscal*invec3D.x;
    tempvec3D.y=inscal*invec3D.y;
    tempvec3D.z=inscal*invec3D.z;
    return tempvec3D;
}

vec3D unitvec3D(vec3D invec3D){
    return scalvec3D((1/normvec3D(invec3D)),invec3D);
}

vec3D addvec3D(vec3D invec1, vec3D invec2){
    vec3D tmpvec;
    tmpvec.x=invec1.x+invec2.x;
    tmpvec.y=invec1.y+invec2.y;
    tmpvec.z=invec1.z+invec2.z;
    return tmpvec;
}

vec3D crossprodvec3D(vec3D invec1, vec3D invec2){
  vec3D tmpvec;
  tmpvec.x=invec1.y*invec2.z-invec2.y*invec1.z;
  tmpvec.y=invec2.x*invec1.z-invec1.x*invec2.z;
  tmpvec.z=invec1.x*invec2.y-invec2.x*invec1.y;
  return tmpvec;
}

void printvec3D(vec3D invec){
  printf("<%f,%f,%f>\n", invec.x,invec.y,invec.z);
}

float anglevec3D(vec3D invec1, vec3D invec2){
  return acos(dotprodvec3D(invec1, invec2)/(normvec3D(invec1)*normvec3D(invec2)));
}

//to do

//2. random generation a. given a size c. given a unit vector

//4. shadow of a vetor on the other


#endif
