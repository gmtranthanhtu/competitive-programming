#include <stdio.h>

int Case(1), M[50], N;

int main () {
    while(scanf("%d",&N) && N){
         for(int i = 1; i <= N; i++) scanf("%d",&M[i]);
         if(Case > 1) printf("\n");
         Case++;
         //print
         for(int i = 1; i <= N - 5; i++){
                 for(int j = i + 1; j <= N - 4; j++){
                         for(int k = j + 1; k <= N - 3; k++){
                                 for(int m = k + 1; m <= N - 2; m++){
                                         for(int n = m + 1; n <= N - 1; n++){
                                                 for(int t = n + 1; t <= N; t++){
                                         printf("%d %d %d %d %d %d\n",M[i],M[j],M[k],M[m],M[n],M[t]);
                                                         }
                                                 }
                                         }
                                 }
                         }
                 }                
         }
    
    return 0;
    }
