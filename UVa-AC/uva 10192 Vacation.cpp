/*
  Name: UVa 10192 Vacation
  Copyright: 
  Author: 3T
  Date: 04/12/10 00:23
  Description: LCS
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

int Ans, lena, lenb, Case(0), DP[110][110];
char a[110], b[110];

void LCS(){
     if(lena == 0 || lenb == 0){
             Ans = 0;
             return;
             }
     DP[0][0] = 0;
     for(int i = 1; i <= lena; i++){
             for(int j = 1; j <= lenb; j++){
                     if(a[i - 1] == b[j - 1]){
                            DP[i][j] = DP[i - 1][j - 1] + 1;
                            }
                     else{
                          DP[i][j] = max(DP[i][j - 1], DP[i - 1][j]);
                          }
                     }
             }
     Ans = DP[lena][lenb];
     }

int main (){
    while(1){
             gets(a);
             if(a[0] == '#') break;
             gets(b);
             lena = strlen(a); lenb = strlen(b);
             LCS();
             Case++;
             printf("Case #%d: you can visit at most %d cities.\n",Case,Ans);
             }
    return 0;
    }
