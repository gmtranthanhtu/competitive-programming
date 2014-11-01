/*
  Name: UVa 10003 Cutting Sticks
  Copyright: 
  Author: 3T
  Date: 02/05/10 13:45
  Description: DP
*/
#include <stdio.h>
#include <algorithm>

#define INP "10003.txt"
#define MaxCut 51
#define BIG 500000

int l,n,i,j,k,m,t;
int C[MaxCut],M[MaxCut][MaxCut]; 

//M[i][j] la chi phi thap nhat cua stick con lai giua nhat cat i va j. 
//Mac dinh 2 dau la nhat cat C[0] = 0 va C[n+1] = l
//Muc tieu la tim chi phi thap nhat giua nhat cat 0 và n+1
//Co so lap bang: Voi M[i][j], tim nhat cat k (i < k < j) sao cho C[j] - C[i] + M[i][k] + M[k][j] nho nhat

int main () {
//    FILE *f = fopen(INP , "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&l) && l != 0){
         fscanf(f,"%d",&n);
         for(i = 1; i <= n; i++){
               fscanf(f,"%d",&C[i]);
               }
         int n2 = n + 1;
         C[0] = 0;
         C[n2] = l;
         for(i = 0; i <= n2; i++){
               for(j = 0; j <= n2; j++){
                     if(i >= j - 1) M[i][j] = 0;
                     else if( j == i + 2) M[i][j] = C[j] - C[i];
                     else M[i][j] = BIG;
                     }
               }  
         for(i = 3; i <= n2; i++){
               m = i;
               for(j = 0; j <= n2 - i; j++){
                     for(t = j + 1; t < m; t++){
                           int Sum = C[m] - C[j] + M[j][t] + M[t][m];
                           M[j][m] = std::min(M[j][m], Sum);
                           }
                     m++;
                     }
               }
         printf("The minimum cutting is %d.\n",M[0][n2]);                 
         }

    return 0;
    }
