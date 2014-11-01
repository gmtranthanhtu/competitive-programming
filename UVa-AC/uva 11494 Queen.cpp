#include <stdio.h>

int main () {
    int x1, y1, x2, y2, Ans;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2) && x1){
           if(x1 == x2 && y1 == y2) Ans = 0;
           else if(x1 == x2 || y1 == y2) Ans = 1;
           else{
                int tempx = x2 - x1;
                int tempy = y2 - y1;
                if(tempx == tempy || tempx * -1 == tempy) Ans = 1;
                else Ans = 2;
                }
           printf("%d\n",Ans);                                 
           }
    
    
    return 0;
    }
