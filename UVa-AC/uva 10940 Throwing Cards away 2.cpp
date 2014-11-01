#include <stdio.h>
#include <math.h>

int N;

int Pow2(int a){
    if(a == 0) return 1;
    int R = 1;
    int i;
    for(i = 1; i <= a; i++) R *= 2;
    return R;
    }

int main (){
    while(scanf("%d",&N) && N){
         if(N == 1) {printf("1\n");continue;}
         double Log = log(N) / log(2);
         int LogI = (int) Log;
         if(LogI == Log){printf("%d\n",N);continue;}
         int Ans = (N - Pow2(LogI)) * 2;
         printf("%d\n",Ans);
                     
         }
    return 0;
    }
