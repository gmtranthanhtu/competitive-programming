#include <stdio.h>

int N, M[55], Sum, Ans, Avg, Case(1);

int main () {
    while(scanf("%d",&N) && N){
            Sum = 0;
            for(int i = 1; i <= N; i++){
                    scanf("%d",&M[i]);
                    Sum += M[i];
                    }           
            Avg = Sum / N;
            Ans = 0;
            for(int i = 1; i <= N; i++){
                    if(M[i] < Avg){
                            Ans = Ans + Avg - M[i];
                            }
                    }  
            printf("Set #%d\n",Case++);
            printf("The minimum number of moves is %d.\n\n",Ans);
            }
    return 0;
    }
