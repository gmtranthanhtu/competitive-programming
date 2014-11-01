/*
  Name: UVa 10611 Playboy Chimp
  Copyright: 
  Author: 3T
  Date: 13/11/10 16:35
  Description: DandC, binary search 
*/
#include <stdio.h>

#define MAX 50000

int N, Q, a, M[MAX + 5];

int findShorter(int m){
    int S, E, Median;
    S = 1; E = N;
    while(S <= E){
            if(S == E - 1){
                 if(M[E] < m) return M[E];
                 if(M[S] < m) return M[S];
                 else return 0;
                 }
           // printf("S: %d, E: %d\n", S, E);
            if(S == E){
                 if(M[S] < m) return M[S];
                 else return 0;
                 }
            Median = (S + E) / 2;
            if(M[Median] == m){
                         E = Median - 1;
                         continue;
                         }
            if(M[Median] > m){
                         E = Median - 1;
                         }
            else S = Median;
            }
    return 0;
    }
    
int findTaller(int m){
    int S, E, Median;
    S = 1; E = N;
    while(S <= E){
            if(S == E - 1){
                 if(M[S] > m) return M[S];
                 if(M[E] > m) return M[E];
                 else return 0;
                 }
           // printf("S: %d, E: %d\n", S, E);
            if(S == E){
                 if(M[S] > m) return M[S];
                 else return 0;
                 }
            Median = (S + E) / 2;
            if(M[Median] == m){
                         S = Median + 1;
                         continue;
                         }
            if(M[Median] > m){
                         E = Median;
                         }
            else S = Median + 1;
            }
    return 0;
    }

int main () {
  //  freopen("10611.INP", "r", stdin);
   // freopen("10611.OUT", "w", stdout);
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            scanf("%d",&M[i]);
            }
    scanf("%d",&Q);
    for(int i = 1; i <= Q; i++){
            scanf("%d",&a);
            //printf("a: %d\n",a);
            int Taller = findTaller(a);
            int Shorter = findShorter(a);
            if(!Shorter) printf("X ");
            else printf("%d ",Shorter);
            if(!Taller) printf("X\n");
            else printf("%d\n",Taller);
            }
    return 0;
    }
