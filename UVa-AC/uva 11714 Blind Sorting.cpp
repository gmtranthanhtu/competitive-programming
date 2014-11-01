/*
  Name: UVa 11714 Blind Sorting
  Copyright: 
  Author: 3T
  Date: 11/05/10 00:46
  Description: K.O scheduling :D
*/
#include <stdio.h>
#include <math.h>

#define INP "11714.INP"

int main () {
    //FILE *f = fopen (INP,"r");
    FILE *f = stdin;
    unsigned int n,result;
    
      while(fscanf(f,"%ud",&n)==1){
       result = n - 1 + (unsigned int)log2(n - 1);
       printf("%u\n",result);                  
        }
    //getchar();
    return 0;
    }
