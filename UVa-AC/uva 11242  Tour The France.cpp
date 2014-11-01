#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

int f, r;
double x, y, Ans, Front[50], Rear[50], M[200];

int main () {
    while(scanf("%d",&f) && f){
        scanf("%d",&r);
        for(int i = 1; i <= f; i++){
            scanf("%lf",&Front[i]);
            }
        for(int i = 1; i <= r; i++){
            scanf("%lf",&Rear[i]);
            }
        int t = 0;
        for(int i = 1; i <= r; i++){
            for(int j = 1; j <= f; j++){
                t++;
                M[t] = Rear[i] / Front[j];
                }
            }
        sort(M + 1, M + t + 1);
        Ans = -10000000.0;
        for(int i = 1; i < t; i++){
            
                double Tmp = M[i + 1] / M[i];
                if(Tmp > Ans) {Ans = Tmp;
                    // x = M[j];
                   //  y = M[i];
                     }
                }
            
        //printf("%.2lf %.2lf\n",x,y);
        printf("%.2lf\n",Ans);
        }
    return 0;
    }
