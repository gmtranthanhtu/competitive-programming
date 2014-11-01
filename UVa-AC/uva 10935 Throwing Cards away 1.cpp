#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int N;

int main (){
    while(scanf("%d",&N) && N){
         queue <int> Q;
         for(int i = 1; i <= N; i++) Q.push(i);
         int Th = 0;
         printf("Discarded cards:");
         while(N - Th > 1){
                 Th++;
                 if(Th == 1) printf(" %d",Q.front());
                 else printf(", %d",Q.front());
                 Q.pop();
                 int Tmp = Q.front();
                 Q.pop();
                 Q.push(Tmp);
                 }
         printf("\n");
         printf("Remaining card: %d\n",Q.front());                
         }
    return 0;
    }
