#include <stdio.h>
#include <string.h>

int R, C, N, Case(1), Row[2010], Col[2010], sr, sc;

bool OK(int r, int c){
     for(int i = 1; i <= N; i++){
             if(Row[i] == r || Col[i] == c) return false;
             }
     return true;
     }

bool canEscape(){
     if(OK(sr, sc)) return true;
     if(sr - 1 >= 0){
           if(OK(sr - 1, sc)) return true;
           }
     if(sc - 1 >= 0){
           if(OK(sr, sc - 1)) return true;
           }
     if(sr + 1 < R){
           if(OK(sr + 1, sc)) return true;
           }
     if(sc + 1 < C){
           if(OK(sr, sc + 1)) return true;
           }
     return false;               
     }

int main () {
    while(scanf("%d%d%d",&R, &C, &N) && R){
           for(int i = 1; i <= N; i++){
                   scanf("%d%d",&Row[i], &Col[i]);
                   }                  
           scanf("%d%d",&sr,&sc);
           printf("Case %d: ",Case++);
           printf( canEscape() ? "Escaped again! More 2D grid problems!\n" : "Party time! Let's find a restaurant!\n");
           }
    return 0;
    }
