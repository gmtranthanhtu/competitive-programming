#include <stdio.h>
#include <math.h>

#define MAX 1000000

int N, x, y;
bool prime[MAX + 5];

void GeneratePrime(){
     prime[1] = false;
     for(int i = 1; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             for(int j = 2; i * j <= MAX; j++) prime[i * j] = false;
             }
     }
     
void Split(int a){
     int M = a / 2;
     for(int i = 2; i <= M; i++){
             if(!prime[i]) continue;
             if(prime[a - i]){
                        x = i;
                        y = a - i;
                        return;
                        }
             }
     }


int main (){
    GeneratePrime();
    while(scanf("%d",&N) && N){
          printf("%d:\n",N);
          x = y = 0;
          Split(N);
          if(x == 0 && y == 0) printf("NO WAY!\n");
          else printf("%d+%d\n",x,y);               
          }
    return 0;
    }
