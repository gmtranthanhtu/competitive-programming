#include <stdio.h>

int n, m, Ans[1000], t;
bool B;

void Bored(){
     B = false;
     t = 1;
     Ans[t] = n;
     if(n < 2 || m < 2){
          B = true;
          return;
          }
     while(n > 1){
             if(n % m){
                  B = true;
                  return;
                  }
             t++;
             Ans[t] = n / m;
             n /= m;
             }
     }

int main (){
    while(scanf("%d%d",&n,&m) != EOF){
          Bored();
          if(B) printf("Boring!\n");
          else{
               for(int i = 1; i <= t; i++){
                       if(i == 1) printf("%d",Ans[i]);
                       else printf(" %d",Ans[i]);
                       }
               printf("\n");
               }                    
          }
    return 0;
    }
