#include <stdio.h>
#define MAX 1000000

bool prime[MAX + 5];
int a, b, Ans, N, DP[MAX + 5];

bool isDigitPrime(int m){
     if(!prime[m]) return false;
     int R = 0;
     while(m > 0){
             R += (m % 10);
             m /= 10;
             }
     if(prime[R]) return true;
     else return false;
     }

void Init(){
     prime[0] = false;
     prime[1] = false;
     for(int i = 2; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             for(int j = 2; j * i <= MAX; j++) prime[i * j] = false;
             }
     //DP
     DP[1] = 0;
     for(int i = 2; i <= MAX; i++){
             if(isDigitPrime(i)) DP[i] = DP[i - 1] + 1;
             else DP[i] = DP[i - 1];
             }
     }

int main () {
    Init();
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            scanf("%d%d",&a,&b);
            Ans = DP[b] - DP[a];
            if(isDigitPrime(a)) Ans++;
            printf("%d\n",Ans); 
            }
    return 0;
    }
