#include <stdio.h>
#include <string.h>

char S1[50], S2[50];
int n1, n2;
double Ans;

int getVal(char S[50]){
    int len = strlen(S);
    int R = 0;
    for(int i = 0; i < len; i++){
            if(S[i] >= 'A' && S[i] <= 'Z'){
                    int Tmp = S[i] - 'A' + 1;
                    R += Tmp;
                    }
            else if(S[i] >= 'a' && S[i] <= 'z'){
                    int Tmp = S[i] - 'a' + 1;
                    R += Tmp;
                    }
            }
    //xu ly R lai
    while(R >= 10){
            int Tmp = 0;
            while(R > 0){
                    Tmp += (R % 10);
                    R /= 10;
                    }
            R = Tmp;
            }
    return R;
    }

int main () {
    while(gets(S1)){
                    gets(S2);
                    n1 = getVal(S1);
                    n2 = getVal(S2);
                    if(n1 < n2) Ans = (double)n1 / (double)n2;
                    else Ans = (double)n2 / (double)n1;
                    printf("%.2lf %%\n",Ans * 100);
                    }
    return 0;
    }
