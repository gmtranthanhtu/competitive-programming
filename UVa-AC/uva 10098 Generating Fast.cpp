/*
  Name: UVa 10098 Generating Fast
  Copyright: 
  Author: 3T
  Date: 17/11/10 00:11
  Description: string, next_permutation
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int T;
char S[50];

int main () {
    scanf("%d",&T);
    scanf(" ");
    for(int i = 1; i <= T; i++){
            gets(S);
            int len = strlen(S);
            sort(S, S + len);
              do {
               cout << S << endl;
               } while ( next_permutation (S, S + len ) );
            printf("\n");
            }
    
    return 0;
    }
