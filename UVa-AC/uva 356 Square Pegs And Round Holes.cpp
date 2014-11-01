/*
  Name: UVa 356 Square Pegs And Round Holes
  Copyright: 
  Author: 3T
  Date: 01/08/10 19:43
  Description: Geometry
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n,Case(0),Contain,Complete;

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%d",&n) == 1){
           Contain = Complete = 0;
           double R = n - 0.5;
           for(int i = 1; i <= n; i++){
                   for(int j = 1; j <= n; j++){
                           if(hypot(i,j) < R) Complete++;
                           else if(hypot(i - 1, j - 1) < R) Contain++;
                           }
                   }
           if(Case) printf("\n");
           Case++;
           printf("In the case n = %d, %d cells contain segments of the circle.\n",n,Contain * 4);  
           printf("There are %d cells completely contained in the circle.\n",Complete * 4);             
           }
    return 0;
    }
