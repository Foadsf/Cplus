#ifndef VEC2D_H
#define VEC2D_H


#ifndef STDIO_H
#define STDIO_H
#include <stdio.h>
#endif



#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

#ifndef MATH_H
#define MATH_H
#include <math.h>
#endif





typedef struct {
    float x,y;
}vec2D;

vec2D mkvec2D(float inx, float iny) {
    vec2D tempvec2D;
    //vec2D tempvec2D={inx,iny};
    tempvec2D.x=inx;
    tempvec2D.y=iny;
    return tempvec2D;
}

float dotprodvec2D(vec2D invec1, vec2D invec2){
    return invec1.x*invec2.x+invec1.y*invec2.y;
}

float normvec2D(vec2D invec){
    return sqrt(dotprodvec2D(invec,invec));
    //return sqrt(invec2D.x*invec2D.x+invec2D.y*invec2D.y+invec2D.z*invec2D.z);
}

vec2D scalvec2D(float inscal, vec2D invec2D){
    vec2D tempvec2D;
    tempvec2D.x=inscal*invec2D.x;
    tempvec2D.y=inscal*invec2D.y;
    return tempvec2D;
}

vec2D unitvec2D(vec2D invec2D){
    return scalvec2D((1/normvec2D(invec2D)),invec2D);
}

vec2D addvec2D(vec2D invec1, vec2D invec2){
    vec2D tmpvec;
    tmpvec.x=invec1.x+invec2.x;
    tmpvec.y=invec1.y+invec2.y;
    return tmpvec;
}


void printvec2D(vec2D invec){
  printf("<%f,%f,%f>\n", invec.x,invec.y);
}

float anglevec2D(vec2D invec1, vec2D invec2){
  return acos(dotprodvec2D(invec1, invec2)/(normvec2D(invec1)*normvec2D(invec2)));
}

//to do

//2. random generation a. given a size c. given a unit vector

//4. shadow of a vetor on the other


#endif
