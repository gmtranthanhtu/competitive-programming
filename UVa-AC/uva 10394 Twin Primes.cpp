#include <stdio.h>

#define MAX 20000000
#define MAX2 100000

bool prime[MAX + 5];
int APrime[MAX];
int Ans[MAX2 + 5];
int n;

void Generate_Prime(){
     prime[1] = false;
     int N = 0;
     for(int i = 2; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             N++;
             APrime[N] = i;
             for(int j = 2; j * i <= MAX; j++){
                     prime[i * j] = false;
                     }
             }
     }
     
void Init(){
     int t = 1;
     for(int i = 1; i <= MAX2; i++){
             for(int j = t; j <= MAX; j++){
                     if(prime[APrime[j] + 2]){
                                        Ans[i] = APrime[j];
                                        t = j + 1;
                                        break;
                                        }
                     }
             }
     }

int main () {
    Generate_Prime();
    Init();
    while(scanf("%d",&n) != EOF){
                         printf("(%d, %d)\n",Ans[n], Ans[n] + 2);
                         }
    return 0;
    }
