17/10/10 15:01
/*
  Name: UVa 11105 Semi-prime H-numbers
  Copyright: 
  Author: 3T
  Date: 17/10/10 15:02
  Description: modified Sieve of Eratosthenes, DP
*/

#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 250005
bool H[MAX];
bool Semi[MAX];
int Ans[MAX];
int N, R;

void Init(){
    //Generate H
    H[0] = false;
    for(int i = 1; i < MAX; i ++){
           // if((i - 1) % 4) H[i] = false;
           // else H[i] = true;
           H[i] = true;
            Semi[i] = false;
            Ans[i] = 0;
            }
    for(int i = 1; i < MAX; i ++){
            while(i < MAX && !H[i]) i ++;
            for(int j = 1; 4 * i * j + i + j < MAX; j ++){
                    H[4 * i * j + i + j] = false;
                    }
            }
    //generate Semi
    for(int i = 1; i < MAX; i ++){
            if(!H[i]) continue;
            for(int j = 1; 4 * i * j + i + j < MAX; j ++){
                    if(!H[j]) continue;
                    Semi[4 * i * j + i + j] = true;
                    Ans[4 * i * j + i + j] = 1;
                    }
            }
            
     Ans[0] = 0;
     for(int i = 1; i < MAX; i ++){
             Ans[i] = Ans[i] + Ans[i - 1];
             }

    }


int main () {
    //freopen("Tu.out", "w", stdout);
    Init();
    while(scanf("%d",&N) && N){
        R = (N - 1) / 4;
        printf("%d %d\n",N,Ans[R]);
        }

    return 0;
    }
