#include <stdio.h>
#include <string.h>

int T, n1, n2;

char S1[30], S2[30];

int Pow2(int k){
    if(k == 0) return 1;
    int R = 1;
    for(int i = 1; i <= k; i++) R *= 2;
    return R;
    }

int Convert(char S[30]){
    int len = strlen(S);
    int R = 0, t = len - 1;
    for(int i = 0; i < len; i++){
            if(S[i] == '0'){
                    t--;
                    continue;
                    }
            R = R + Pow2(t);
            t--;
            }
    return R;
    }
    
int GCD(int a, int b){
    if(a % b) return GCD(b, a % b);
    return b;
    }

int main () {
    scanf("%d",&T);
    scanf(" ");
    for(int i = 1; i <= T; i++){
            gets(S1);
            gets(S2);
            n1 = Convert(S1);
            n2 = Convert(S2);
            if(GCD(n1, n2) == 1) printf("Pair #%d: Love is not all you need!\n",i);
            else printf("Pair #%d: All you need is love!\n",i);
            }
    
    return 0;
    }
