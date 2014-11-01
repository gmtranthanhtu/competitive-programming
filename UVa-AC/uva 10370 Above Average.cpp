#include <stdio.h>

int main () {
    int M[1005], N, P, a, Total;
    double Avg;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            scanf("%d",&P);
            Total = 0;
            for(int j = 1; j <= P; j++){
                    scanf("%d",&a);
                    M[j] = a;
                    Total += a;
                    }
            Avg = (double) Total / (double) P;
            Total = 0;
            for(int j = 1; j <= P; j++) if(M[j] > Avg) Total++;
            Avg = (double) Total / (double) P;
            printf("%.3lf%%\n",Avg * 100);
            }
    return 0;
    }
