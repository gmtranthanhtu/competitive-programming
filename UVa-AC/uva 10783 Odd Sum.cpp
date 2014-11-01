#include <stdio.h>
#include <stdlib.h>

int main () {
    int N,a, b,Total;
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            scanf("%d%d",&a,&b);
            Total = 0;
            for(int j = a; j <= b; j++){
                    Total += j % 2 ? j : 0;
                    }
            printf("Case %d: %d\n",i,Total);
            }
    
    return 0;
    }
