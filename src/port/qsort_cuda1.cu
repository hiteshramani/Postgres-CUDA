extern "C"{
#include<stdio.h>
#include "qsort_cuda.h"
}

extern "C"{
const int N = 7;
void MyTestFunct()
{

 printf("Hello");
 
 char *ad;
 const int csize = N*sizeof(char);
 cudaMalloc( (void**)&ad, csize );

}
}
