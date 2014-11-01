/*
  Name: UVa 10703 Free spots
  Copyright: 
  Author: 3T
  Date: 12/12/10 10:05
  Description: ad hoc
*/
#include <stdio.h>
#include <algorithm>
using namespace std;

int W, H, N, x1, y1, x2, y2, xa, ya, xb, yb, Ans;
bool M[510][510];

int main () {
    while(scanf("%d%d%d",&W,&H,&N) && W){
        for(int i  = 1; i <= H; i++){
            for(int j = 1; j <= W; j++) M[i][j] = true;
            }
        for(int i = 1; i <= N; i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            xa = min(x1, x2); xb = max(x1, x2);
            ya = min(y1, y2); yb = max(y1, y2);
            for(int j = ya; j <= yb; j++){
                for(int k = xa; k <= xb; k++) M[j][k] = false;
                }
            }
        Ans = 0;
        for(int i  = 1; i <= H; i++){
            for(int j = 1; j <= W; j++) if(M[i][j]) Ans++;
            }        
        if(Ans == 1) printf("There is one empty spot.\n");
        else if(Ans == 0) printf("There is no empty spots.\n");
        else printf("There are %d empty spots.\n",Ans);
        }
    return 0;
    }
