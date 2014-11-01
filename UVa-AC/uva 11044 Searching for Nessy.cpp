#include <math.h>
#include <stdio.h>

int t; double n, m;
int Ans;

int main () {
    scanf("%d",&t);
    while(t--){
        scanf("%lf %lf",&n,&m);
        Ans = ceil((n - 2) / 3.0) * ceil((m - 2) / 3.0);
        printf("%d\n",Ans);
        }
    
    return 0;
    }
