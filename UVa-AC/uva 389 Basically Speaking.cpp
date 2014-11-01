/*
  Name: UVa 389 Basically Speaking
  Copyright: 
  Author: 3T
  Date: 11/11/10 17:50
  Description: math, base
*/
#include <stdio.h>
#include <string.h>

int N, BFrom, BTo, Val, Ans[10];
char line[100], Num[10];

int Pow(int x, int y){
    int R = 1;
    if(y == 0) return 1;
    else{
         for(int i = 1; i <= y; i++){
                 R *= x;
                 }
         }
    return R;
    }
    
int cTod(char c){
    if(c <= '9' && c >= '0') return (c - '0');
    else{
         int Tmp = (int) c - (int) 'A';
         return Tmp + 10;
         }
    }
    
void Convert2(int V, int B){
     N = 0;
     while(V > 0){
             N++;
             Ans[N] = V % B;
             V /= B;
             }
     if(N == 0){
          N++;
          Ans[N] = 0;
          }
     }
     
char dToc(int d){
     if(d <= 9 && d >= 0) return (d + '0');
     else{
          int Tmp = d - 10;
          return Tmp + 'A';
          }
     }

int main () {
    freopen("389.INP", "r", stdin);
    freopen("389.OUT", "w", stdout);
    while(gets(line) != NULL){
                      sscanf(line,"%s %d %d",&Num, &BFrom, &BTo);
                     // printf("%s %d %d\n",Num,BFrom,BTo);
                     
                     //convert 1
                     Val = 0;
                     int len = strlen(Num);
                     int Tmp = len - 1;
                     for(int i = 0; i < len; i++){
                             int Tmp1 = Pow(BFrom, Tmp);
                             Tmp--;
                             int Tmp2 = cTod(Num[i]);
                             Val = Val + Tmp2 * Tmp1;
                             }
                     // printf("%d\n",Val);
                     
                     //convert 2
                     Convert2(Val, BTo);
                     if(N > 7) printf("  ERROR\n");
                     else{
                          for(int i = N + 1; i <= 7; i++){
                                  printf(" ");
                                  }
                          for(int i = N; i >= 1; i--){
                                  printf("%c", dToc(Ans[i]));
                                  }
                          printf("\n");
                          }
                      }
    
    return 0;
    }
