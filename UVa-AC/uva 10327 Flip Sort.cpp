/*
  Name: UVa 10327 Flip Sort
  Copyright: 
  Author: 3T
  Date: 27/10/10 21:18
  Description: bubble sort
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int N;
int M[1003];

int Flip(){
    int R = 0;
    for(int i = 1; i < N; i++)
       for(int j = N; j >= i + 1; j--){
               if(M[j] < M[j - 1]){
                       R++;
                       swap(M[j],M[j - 1]);
                       }
               }
    return R;
    }

int main () {
    while(scanf("%d",&N) != EOF){
                         for(int i = 1; i <= N; i++) scanf("%d",&M[i]);
                         int R = Flip();
                         printf("Minimum exchange operations : %d\n",R);
                         }
    return 0;
    }
