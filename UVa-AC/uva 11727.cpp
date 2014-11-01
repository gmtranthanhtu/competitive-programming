#include <stdio.h>
#include <algorithm>
using namespace std;

int main () {
    int T,a,b,c, R;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d%d",&a,&b,&c);
            if((a > b && b > c) || (c > b && b > a)) R = b;
            else if((a > c && c > b) || (b > c && c > a)) R = c;
            else R = a;
            printf("Case %d: %d\n",i,R); 
            }
    return 0;
    }
