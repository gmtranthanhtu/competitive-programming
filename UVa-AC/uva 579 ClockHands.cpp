#include <stdio.h>

int H, M;

int main () {
    while(scanf("%d:%d",&H,&M)){
             if(H == 0 && M == 0) break;
             if(H == 12) H = 0;
             double angleH = H * 30 + (double) M / 2.0;
             double angleM = M * 6;
             double Ans = angleM - angleH;
             if(Ans < 0) Ans = Ans * -1.0;
             if(Ans > 180) Ans = 360 - Ans;
             printf("%.3lf\n",Ans);                   
             }
    return 0;
    }
