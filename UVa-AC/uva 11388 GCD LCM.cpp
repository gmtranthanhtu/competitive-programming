#include <stdio.h>

int main () {
    int T, a, b;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&a,&b);
            if(b % a) printf("-1\n");
            else printf("%d %d\n",a,b);
            }
    return 0;
    }
