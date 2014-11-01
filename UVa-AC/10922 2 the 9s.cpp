#include <stdio.h>
#include <string.h>

char S[1005];

int getSumFromChar(){
    int R = 0;
    int len = strlen(S);
    for(int i = 0; i < len; i++){
            R += (S[i] - 48);
            }
    return R;
    }
    
int getDegree(int N){
    if(N == 9) return 1;
    int R = 1;
    while(N != 9){
            int Tmp = 0;
            while(N > 0){
                    Tmp += (N % 10);
                    N /= 10;
                    }
            N = Tmp;
            R++;
            }
    return R;
    }

int main () {
    while(gets(S)){
         if(strcmp(S, "0") == 0) break;
         int N = getSumFromChar();
         if(N % 9) printf("%s is not a multiple of 9.\n",S);
         else{
              printf("%s is a multiple of 9 and has 9-degree ",S);
              printf("%d.\n",getDegree(N));
              }     
         }
    return 0;
    }
