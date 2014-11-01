/*
  Name: UVa 11151 Longest Palindrome
  Copyright: 
  Author: 3T
  Date: 27/09/10 08:47
  Description: DP
*/
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

    int T, len;
    char S[1010];
    int M[1010][1010];

int findDP(int s, int e){
    if(s > e) return 0;
    if(s == e) return 1;
    if(s < e && S[s] == S[e]){
         if(M[s][e] != -1) return M[s][e];
         else{
              M[s][e] = 2 + findDP(s + 1, e - 1);
              return M[s][e];
              }
         }
    if(s < e && S[s] != S[e]){
         if(M[s][e] != -1) return M[s][e];
         else{
              M[s][e] = max(findDP(s + 1, e), findDP(s, e - 1));
              return M[s][e];
              }
         }
    }

int main () {
    scanf("%d",&T);
    gets(S);
    for(int i = 1; i <= T; i++){
           // scanf("%s",&S);
            gets(S);
          //  printf("%s\n",S);
            len = strlen(S);
            if(len == 0) {printf("0\n");continue;}
            
            for(int j = 0; j < len; j++)
               for(int k = 0; k < len; k++)
                   M[j][k] = -1;
            printf("%d\n",findDP(0, len - 1));
            
            }
    
    return 0;
    }

