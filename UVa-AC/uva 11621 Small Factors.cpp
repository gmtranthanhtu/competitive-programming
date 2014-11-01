/*
  Name: UVa 11621 Small Factors
  Copyright: 
  Author: 3T
  Date: 27/05/10 13:34
  Description: use an array to store the set C23
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 2147483647
#define INP "11621.INP"

    long long A[2000];
    int loop,n;
    long long temp,m;
    
bool Mark(long long a){
     for(int p = loop - 1; p >= 1; p--){
             if(A[p] == a) return true;
             }
     return false;
     }   

void Sort(){
     int n = loop - 1;
     for(int j = n; j > 1; j--){
             for(int k = 1; k <= j - 1; k++){
                     if(A[k] > A[j]){
                             temp = A[k];
                             A[k] = A[j];
                             A[j] = temp;
                             }
                     }
             }
     }
    
int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    memset(A,0,sizeof(A));
    A[1] = 2;
    A[2] = 3;
    loop = 3;
    for(int i = 1; i < 2000; i++){
            if(A[i] == 0) break;
            if(A[i] % 2 == 0){
                    if(A[i] * 2 <= MAX && !Mark(A[i] * 2)) A[loop++] = A[i] * 2;
                    if(A[i] * 3 <= MAX && !Mark(A[i] * 3)) A[loop++] = A[i] * 3;
                    } 
            else{
                 if(A[i] * 3 <= MAX) A[loop++] = A[i] * 3;
                 }
            }
    n = loop - 1;
    Sort();
    while(fscanf(f,"%lld",&m) && m){
         if(m > A[n]) printf("2147483648\n");      
         else if(m == 1) printf("1\n");   
         else{
              for(int i = 1; i < loop; i++){
                      if(A[i] >= m){
                              printf("%lld\n",A[i]);
                              break;
                              }
                      }
              }          
         }
  //  getchar();
    return 0;
    }
