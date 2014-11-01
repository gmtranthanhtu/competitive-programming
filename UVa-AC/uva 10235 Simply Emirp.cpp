#include <stdio.h>

#define MAX 1000000

bool Prime[MAX + 5];
int N, So[10], Mu10[]={1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

void GenPrime(){
     Prime[1] = false;
     for(int i = 2; i <= MAX; i++){
             Prime[i] = true;
             }
     for(int i = 2; i <= MAX; i++){
             //while(i <= MAX && !Prime[i]) i++;
             if(!Prime[i]) continue;
             for(int j = 2; j  * i <= MAX; j++){
                     Prime[i * j] = false;
                     }
             }
     }
     
bool DePrime(){
     //if(N < 10) return false;
     int n = 0, Tmp = N, t, Num = 0;
     while(Tmp >= 10){
               So[++n] = Tmp % 10;
               Tmp /= 10;
               }
     So[++n] = Tmp;
     t = n - 1;
     for(int i = 1; i <= n; i++){
             Num = Num + So[i] * Mu10[t--];
             }
     if(N == Num) return false;
     if(Prime[Num]) return true;
     return false;
     }     

int main () {
    GenPrime();
    while(scanf("%d",&N) != EOF){
              if(!Prime[N]) printf("%d is not prime.\n",N);
              else if(DePrime()) printf("%d is emirp.\n",N);
              else printf("%d is prime.\n",N);          
              }
    return 0;
    }
