#include <stdio.h>

#define MAX 50

bool prime[50];
void Init(){
     prime[1] = false;
     for(int i = 2; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             for(int j = 2; j * i <= MAX; j++) prime[i * j] = false;
             }
     }
     
void Check(int N){
     if(N == 2) printf("Perfect: 6!\n");
     else if(N == 3) printf("Perfect: 28!\n");
     else if(N == 5) printf("Perfect: 496!\n");
     else if(N == 7) printf("Perfect: 8128!\n");
     else if(N == 13) printf("Perfect: 33550336!\n");
     else if(N == 17) printf("Perfect: 8589869056!\n");
     else if(N == 19) printf("Perfect: 137438691328!\n");
     else if(N == 31) printf("Perfect: 2305843008139952128!\n");
     else{
          if(prime[N]) printf("Given number is prime. But, NO perfect number is available.\n");
          else printf("Given number is NOT prime! NO perfect number is available.\n");
          }
     }

int main () {
    Init();
    int N;
    while(scanf("%d",&N) && N){
                         Check(N);
                         
                         }
    return 0;
    }
