/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 64*1024*1024

int main()
{

int* arr = (void*) malloc(MAX*sizeof(int));
int t1, t2;

// Loop 1
clock_t tic1 = clock();
for (int i = 0; i < MAX; i++) arr[i] *= 3;
clock_t toc = clock();
t1 = toc-tic1;

// Loop 2
clock_t tic2 = clock();
for (int i = 0; i < MAX; i += 16) arr[i] *= 3;
clock_t toc2 = clock();
t2 = toc2-tic2;

printf("t1: %d t2:%d",  t1, t2);

}
