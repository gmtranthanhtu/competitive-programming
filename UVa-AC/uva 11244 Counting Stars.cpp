#include <stdio.h>
#include <string.h>

int r, c, Ans;
char M[150][150];
int X[]={-1, -1, -1, 0, 0, 1, 1, 1};
int Y[]={-1, 0, 1, -1, 1, -1, 0, 1};

bool Check(int i, int j){
     for(int k = 0; k < 8; k++){
             int x = i + X[k];
             int y = j + Y[k];
             if(x < 0 || y < 0 || x >= r || y >= c) continue;
             if(M[x][y] == '*') return false;
             }
     return true;
     }

int main () {
    while(scanf("%d%d",&r,&c) && r){
         scanf(" ");
         for(int i = 0; i < r; i++) gets(M[i]);
         Ans = 0;
         for(int i = 0; i < r; i++){
                 for(int j = 0; j < c; j++){
                         if(M[i][j] == '*'){
                                    if(Check(i, j)) Ans++;
                                    }
                         }
                 }
         printf("%d\n",Ans);                     
         }
    return 0;
    }
