#include <stdio.h>
#include <math.h>

int N, M[100], Mau, Tu;
double Ans;

int GCD(int a, int b){
    if(a % b) return GCD(b, a % b);
    return b;
    }

int main (){
    while(scanf("%d",&N) && N){
           for(int i = 1; i <= N; i++) scanf("%d",&M[i]);
           Mau = (N * (N - 1)) / 2;
           Tu = 0;
           for(int i = 1; i < N; i++){
                   for(int j = i + 1; j <= N; j++){
                           if(GCD(M[i], M[j]) == 1) Tu++;
                           }
                   }              
           if(Tu == 0){
                 printf("No estimate for this data set.\n");
                 continue;
                 }
           Ans = (double) Mau * 6.0 / (double) Tu;
           Ans = sqrt(Ans);
           printf("%.6lf\n",Ans);
           }
    return 0;
    }
