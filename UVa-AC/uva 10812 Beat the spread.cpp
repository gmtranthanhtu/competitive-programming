#include <stdio.h>
#include <stdlib.h>

int main () {
    int n,aa ,bb;
    double s, d, a, b;
    
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
            scanf("%lf %lf",&s, &d);
            a = (s + d) / 2;
            b = (s - d) / 2;
            aa = (int) a;
            bb = (int) b;
            if(a != aa || b != bb || a < 0 || b < 0) printf("impossible\n");
            else printf("%d %d\n",aa, bb);
            }
    return 0;
    }
