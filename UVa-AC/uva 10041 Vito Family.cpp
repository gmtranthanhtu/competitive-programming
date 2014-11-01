#include <stdio.h>
#include <algorithm>
using namespace std;

int Ans, r, n, M[510], medi;

int main () {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
            scanf("%d",&r);
            for(int j = 1; j <= r; j++){
                    scanf("%d",&M[j]);
                    }
            sort(M + 1, M + r + 1);
            Ans = 0;
            if(r % 2) medi = r / 2 + 1;
            else medi = r / 2;
            for(int i = 1; i <= r; i++){
                    int Tmp = M[medi] - M[i];
                    if(Tmp < 0) Tmp *= -1;
                    Ans += Tmp;
                    }
            printf("%d\n",Ans);
            }
    return 0;
    }
