#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1000000

int Case(1), n, a, b, Ans, DP[MAX], Ma[MAX], Mb[MAX];
char S[MAX + 5];

void runDP(){
     int len = strlen(S);
     DP[0] = S[0] - 48;
     for(int i = 1; i < len; i++){
             if(S[i] == '0') DP[i] = DP[i - 1];
             else DP[i] = DP[i - 1] + 1;
             }
     }
     
bool Check(int a, int b){
     if(a == b) return true;
     int Temp = a;
     a = min(a,b); b = max(Temp,b);
     int Sum = b - a + 1;
     int Tmp = DP[b] - DP[a];
     if(S[a] == '1') Tmp++;
     if(!Tmp) return true;
     else if(Tmp == Sum) return true;
     return false;
     }

int main  () {
    //freopen("10324.INP", "r", stdin);
    //freopen("10324.OUT", "w", stdout);
    while(gets(S)){
          //puts(S);
          runDP();
          scanf("%d",&n);
          for(int i = 1; i <= n; i++){
                  scanf("%d%d",&Ma[i],&Mb[i]);
                  if(i == n) scanf(" ");
                  //printf("later\n");
                  //printf(Check(a, b) ? "Yes\n" : "No\n");
                  }         
          printf("Case %d:\n",Case++);
          for(int i = 1; i <= n; i++){
                  printf(Check(Ma[i], Mb[i]) ? "Yes\n" : "No\n");
                  }                   
          }
    return 0;
    }
