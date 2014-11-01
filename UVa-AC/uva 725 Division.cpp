#include <stdio.h>
#include <string.h>

int Case(1), Count, N, Ans[20];
int Mu10[]={1, 10, 100, 1000, 10000, 100000};
bool Used[20];

void Print(){
     for(int i = 1; i <= 5; i++){
             printf("%d",Ans[i]);
             }
     printf(" / ");
     for(int i = 6; i <= 10; i++) printf("%d",Ans[i]);
     printf(" = %d\n",N);
     }

bool Check(){
     int Deno = 0;
     int Nume = 0;
     int t = 4;
     for(int i = 1; i <= 5; i++){
             Nume = Nume + Ans[i] * Mu10[t];
             Deno = Deno + Ans[i + 5] * Mu10[t];
             t--;
             }
     if(Nume % Deno == 0 && Nume / Deno == N) return true;
     return false;
     }

void backtrack(int m){
     if(m == 11){
          if(Check()){
                      Print();
                      Count++;
                      }
          }
     int t;
     if(m == 1) t = 1;
     else t = 0; 
     for(int i = t; i <= 9; i++){
             if(m == 6 && i > Ans[1]) continue;
             if(!Used[i]){
                          Used[i] = true;
                          Ans[m] = i;
                          backtrack(m + 1);
                          Used[i] = false;
                          }
             }
     }

int main () {
    while(scanf("%d",&N) && N){
           if(Case > 1) printf("\n");
           Case++;
           Count = 0;
           for(int i = 0; i < 10; i++) Used[i] = false;
           backtrack(1);
           if(!Count) printf("There are no solutions for %d.\n",N);              
           }
    
    
    return 0;
    }
