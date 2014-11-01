/*
  Name: UVa 11495 Bubbles and Buckets
  Copyright: 
  Author: 3T
  Date: 17/07/10 01:28
  Description: Merge Sort
*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 100010
#define MAX2 50005
#define INP "11495.INP"
#define OUT "11495.OUT"

int B[MAX],L[MAX2],R[MAX2],N;

long long MergeSort(int S, int E){
     int m,n;
     long long Count = 0;
        if(S == E) {
             return Count;
             }
     if(S + 1 == E){
          if(B[S] > B[E]){
                  Count = 1;
                  swap(B[S],B[E]);
                  }
          return Count;
          }

     int p = (S + E) / 2;
     Count += MergeSort(S, p) + MergeSort(p + 1, E);     
     int LS = p - S + 1;
     int RS = E - p;
     for(int i = 1; i <= LS; i++) L[i] = B[S + i - 1];
     for(int i = 1; i <= RS; i++) R[i] = B[p + i];
     m = n = 1;
     while(m <= LS && n <= RS){
             if(L[m] > R[n]){
                     Count = Count + LS - m + 1;
                     n++;
                     }
             else m++;
             }

     L[LS + 1] = R[RS + 1] = INT_MAX; 
     for(int i = S, m = 1, n = 1; i <= E; i++){
             if(L[m] < R[n]){
                     B[i] = L[m];
                     m++;
                     }
             else{
                  B[i] = R[n];
                  n++;
                  }
             }         
     return Count;    
     }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
//    freopen(OUT, "w", stdout);
    while(fscanf(f,"%d",&N) == 1 && N){
         for(int i = 1; i <= N; i++){
                 fscanf(f,"%d",&B[i]);
                 }   
         
    if(MergeSort(1,N) % 2) printf("Marcelo\n");
    else printf("Carlos\n");
          }
   // fclose(stdout);
 //   getchar();
    return 0;
    }
