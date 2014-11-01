#include <stdio.h>
#include <string.h>

int Ans;

char In[100];

int Pow2(int a){
    int R = 1;
    for(int i = 1; i <= a; i++) R *= 2;
    return R;
    }

int main () {
    while(1){
             gets(In);
             if(In[0] == '0') break;
             int len = strlen(In);
             int Tmp = len;
             Ans = 0;
             for(int i = 0; i < len; i++){
                     int t = In[i] - '0';
                     Ans = Ans + (t * (Pow2(Tmp) - 1));
                     Tmp--;
                     }
             printf("%d\n",Ans);
             }
    return 0;
    }
