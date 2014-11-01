#include <stdio.h>

int N, M[3010];
bool B[3010];

bool Check(){
     for(int i = 1; i <= N - 1; i++){
             if(!B[i]) return false;
             }
     return true;
     }

int main () {
    while(scanf("%d",&N) != EOF){
           for(int i = 1; i <= N - 1; i++) B[i] = false;
           for(int i = 1; i <= N; i++){
                   scanf("%d",&M[i]);
                   }              
           for(int i = 1; i < N; i++){
                   int Tmp = M[i] - M[i + 1];
                   if(Tmp < 0) Tmp *= -1;
                   B[Tmp] = true;
                   }
           printf(Check() ? "Jolly\n" : "Not jolly\n");
           }
    
    return 0;
    }
