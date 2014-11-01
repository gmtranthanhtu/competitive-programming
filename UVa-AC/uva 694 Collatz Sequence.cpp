/*
  Name: UVa 694 Collatz Sequence
  Copyright: 
  Author: 3T
  Date: 04/09/10 03:14
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

long A, L,Case(1);

int countTerm(long A, long L){
     int R = 0;
     while(A <= L){
             if(A == 1){
                  R++;
                  break;
                  }
             else if(A % 2) A = A * 3 + 1;
             else A = A / 2;
             R++;
             }
     return R;
     }

int main () {
    FILE *f = stdin;
    while(fscanf(f,"%ld %ld",&A,&L) && A > 0){
          printf("Case %d: A = %ld, limit = %ld, number of terms = %d\n",Case,A,L,countTerm(A, L));            
          Case++;
          }
    
    return 0;
    }
