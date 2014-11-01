#include <stdio.h>

int N, F[100];

void Init(){
     F[0] = 1;
     F[1] = 1;
     for(int i = 2; i <= 50; i++) F[i] = F[i - 1] + F[i - 2];
     }

int main (){
    Init();
    while(scanf("%d",&N) && N) printf("%d\n",F[N]);
    return 0;
    }
