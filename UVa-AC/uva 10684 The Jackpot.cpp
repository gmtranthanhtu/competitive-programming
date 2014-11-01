#include <stdio.h>
#include <algorithm>

using namespace std;

#define BIGN -1999999999

int DP[10010], M[10010], N, R;

int main () {
    while(scanf("%d",&N) && N){
          for(int i = 1; i <= N; i++){
                  scanf("%d",&M[i]);
                  }               
          R = BIGN;
          for(int i = 1; i <= N; i++){
                  if(i == 1) DP[i] = M[i];
                  else{
                       DP[i] = max(DP[i - 1] + M[i], M[i]);
                       }
                  R = max(R, DP[i]);
                  }
          if(R <= 0) printf("Losing streak.\n");
          else printf("The maximum winning streak is %d.\n",R);
          }
    return 0;
    }
