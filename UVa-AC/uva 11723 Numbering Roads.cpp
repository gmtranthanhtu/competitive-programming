/*
  Name: UVa 11723 Numbering Roads
  Copyright: 
  Author: 3T
  Date: 11/05/10 09:30
  Description: no algorithm needed :D
*/
#include <stdio.h>
#include <stdlib.h>

#define INP "11723.INP"

int R,N,Case(1),result;
bool test;

int main () {
  // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d%d",&R,&N) && R){
           test = true;
           if(R <= N) result = 0;
           else if((float) R / N > 27) test = false;
           else if(R % N == 0) result = R / N - 1;
           else result = R / N;
           if(test) printf("Case %d: %d\n",Case,result);
           else printf("Case %d: impossible\n",Case);
           Case++;                    
           }
    
   // getchar();
    return 0;
    }
