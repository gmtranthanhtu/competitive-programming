#include <stdio.h>
//brute force

int a, b, c, d, L;

int main () {
    while(scanf("%d%d%d%d%d",&a,&b,&c,&d,&L)){
        if(a == 0 && b == 0 && c == 0 && d == 0 && L == 0) break;
        int Ans = 0;
        int Temp;
        for(int i = 0; i <= L; i++){
            Temp = i * i * a + b * i + c;
            if(Temp % d == 0) Ans++;
            }
        printf("%d\n",Ans);
        }
    return 0;
    }
