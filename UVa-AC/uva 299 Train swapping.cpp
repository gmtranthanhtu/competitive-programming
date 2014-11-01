/*
  Name: UVa 299 Train Swapping
  Copyright: 
  Author: 3T 
  Date: 22/10/10 16:05
  Description: sort
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int T, L, M[60], R;

int Sort(){
    int Count = 0;
    for(int i = 1; i < L; i++){
            for(int j = L; j >= i + 1; j--){
                    if(M[j] < M[j - 1]){
                            swap(M[j], M[j - 1]);
                            Count++;
                            }
                    }
            }
    return Count;
    }

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d",&L);
            for(int j = 1; j <= L; j++){
                    scanf("%d",&M[j]);
                    }
            R = Sort();
            printf("Optimal train swapping takes %d swaps.\n",R);
            }
    
    
    return 0;
    }
