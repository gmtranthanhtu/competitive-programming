#include <stdio.h>
#include <math.h>
#include <string.h>

#define MAX 5000

int N;
bool prime[MAX + 5];
char S[50];

void GeneratePrime(){
     prime[1] = true; //in this problem, 1 should be considered as a prime number
     for(int i = 2; i <= MAX; i++) prime[i] = true;
     for(int i = 2; i <= MAX; i++){
             if(!prime[i]) continue;
             for(int j = 2; i * j <= MAX; j++) prime[i * j] = false;
             }
     }
     
bool Check(){
     int len = strlen(S);
     int R = 0;
     for(int i = 0; i < len; i++){
             if('A' <= S[i] && S[i] <= 'Z'){
                    int Tmp = S[i] - 'A' + 27;
                    R += Tmp;
                    }
             else if('a' <= S[i] && S[i] <= 'z'){
                  int Tmp = S[i] - 'a' + 1;
                  R += Tmp;
                  }
             }
     //printf("R: %d\n",R);
     if(prime[R]) return true;
     return false;
     }

int main (){
    GeneratePrime();
    while(gets(S)){
          printf(Check() ? "It is a prime word.\n" : "It is not a prime word.\n");         
          }
    return 0;
    }
