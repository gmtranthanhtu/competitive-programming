#include <stdio.h>
#define MAX 33000

int N,x,y;
bool prime[MAX + 5];

void GenPrime(){
     prime[1] = false;
     prime[0] = false;
     for(int i = 2; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             for(int j = 2; j * i <= MAX; j++) prime[i * j] = false;
             }   
     }
     
int Count(){
    int R = 0;
     for(int i = 2; i <= N / 2; i++){
             if(!prime[i]) continue;
             if(prime[N - i]){
                        //x = i;
                        //y = N - i;
                        R++;
                        }
             }
     return R;
     }

int main () {
    GenPrime();
   // for(int i = 1; i <= 100; i++) if(prime[i]) printf("%d ",i);
    while(scanf("%d",&N) && N){
                         printf("%d\n",Count());
                         }
    return 0;
    }
