#include <stdio.h>

int H1, M1, H2, M2, R;

int main () {
    while(scanf("%d%d%d%d",&H1,&M1,&H2,&M2)){
          if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0) break;
          int T1 = H1 * 60 + M1;
          int T2 = H2 * 60 + M2;
          if(T2 >= T1) R = T2 - T1;
          else R = 1440 - T1 + T2;
          printf("%d\n",R);                                   
          }
    
    return 0;
    }
