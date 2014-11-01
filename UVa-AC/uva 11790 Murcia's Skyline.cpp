/*
  Name: UVa 11790 Murcia's Skyline
  Copyright: 
  Author: 3T
  Date: 17/05/10 16:45
  Description: DP, LIS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define Max 10001
#define INP "11790.INP"

int n,N,MaxInc,MaxDec,jmax,H[Max],W[Max],temp[Max];

int FindMaxIncreasing(){
    memset(temp,0,sizeof(temp));
    H[N + 1] = 1000;
    ///test
//    printf("Test: ");
//    for(int i = 0; i <= N + 1; i++){
//            printf("%d ",H[i]);
//            }
//    printf("\n");
    //
    for(int i = 1; i <= N + 1; i++){
            jmax = 0;
            for(int j = i - 1; j >= 0; j--){
                    if(H[j] < H[i] && temp[j] > temp[jmax]) jmax = j;
                    }
            temp[i] = temp[jmax] + W[i];
            }
    return temp[N + 1];
    }
    
int FindMaxDecreasing(){
    memset(temp,0,sizeof(temp));
    H[0] = 1000;
    H[N + 1] = 0;

    ///test
//    printf("Test: ");
//    for(int i = 0; i <= N + 1; i++){
//            printf("%d ",H[i]);
//            }
//    printf("\n");
    //
    for(int i = 1; i <= N + 1; i++){
            jmax = 0;
            for(int j = i - 1; j >= 0; j--){
                    if(H[j] > H[i] && temp[j] > temp[jmax]) jmax = j;
                    }
            temp[i] = temp[jmax] + W[i];
            }
    return temp[N + 1];
    }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&n);
    for(int i = 1; i <= n; i++){
            fscanf(f,"%d",&N);
            memset(H,0,sizeof(H));
            memset(W,0,sizeof(W));
            for(int j = 1; j <= N; j++){
                    fscanf(f,"%d",&H[j]);
                    }
            for(int j = 1; j <= N; j++){
                    fscanf(f,"%d",&W[j]);
                    }
            MaxInc = FindMaxIncreasing();        
            //test
//            printf("INC: %d\n",MaxInc);
            MaxDec = FindMaxDecreasing();
 //           printf("INC: %d\n",MaxDec);
            if(MaxDec > MaxInc) printf("Case %d. Decreasing (%d). Increasing (%d).\n",i,MaxDec,MaxInc);
            else printf("Case %d. Increasing (%d). Decreasing (%d).\n",i,MaxInc,MaxDec);
            }
    
  //  getchar();
    return 0;
    }
