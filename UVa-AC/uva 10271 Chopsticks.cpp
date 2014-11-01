/*
  Name: UVa 10271 Chopsticks
  Copyright: 
  Author: 3T
  Date: 01/06/10 16:57
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>

#define INP "10271.INP"
#define Max 5001

int T,K,N,i,j,k;
int L[Max],Sum[Max];
long Badness[Max];

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    for(i = 1; i <= T; i++){
          memset(L,0,sizeof(L));
          fscanf(f,"%d%d",&K,&N);
          K += 8;
          Sum[0] = 0;
          for(j = 1; j <= N; j++){
                fscanf(f,"%d",&L[j]);
                Sum[j] = 0;
                Badness[j] = (L[j] - L[j - 1]) * (L[j] - L[j - 1]);
                }
                
          for(j = 1; j <= K; j++){
                int loop = N - 3 * (K - j) - 1;
                  for(k = loop; k >= j * 2; k--){
                        Sum[k] = Sum[k - 2] + Badness[k];
                        }
                        ////test
//                printf("Take %d: \n",j);
//                for(int t = 0; t <= N; t++){
//                        printf("%d ",Sum[t]);
//                        }
//                printf("\n");
                  
                  for(k = (j * 2) + 1; k <= loop; k++){
                        if(Sum[k] > Sum[k - 1]){
                                 Sum[k] = Sum[k - 1];
                                 }
                        }
                        //test
//                printf("Take %d: \n",j);
//                for(int t = 0; t <= N; t++){
//                        printf("%d ",Sum[t]);
//                        }
//                printf("\n");
                
                  Sum[loop + 1] = Sum[loop];
                  }
          //test
//          for(j = 1; j <= N; j++){
//                printf("%d ",L[j]);
//                }
//          printf("\n");
          cout << Sum[N] << endl;
          }
//    getchar();
    return 0;
    }
