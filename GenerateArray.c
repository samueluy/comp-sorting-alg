#include <stdio.h>
#include <stdlib.h>

void GenerateData(int A[], int n){
   int i;
   for(i=0;i<n;i++)
     A[i]=rand()%1000;   // random number till 1000
}

