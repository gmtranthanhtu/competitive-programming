#include <stdio.h>
#include <string.h>

int Case(1), ll, N, S[110], M[5000];
bool Test;


bool Check(){
     for(int i = 1; i <= ll - 1; i++){
             for(int j = i + 1; j <= ll; j++){
                     if(M[i] == M[j]) return false;
                     }
             }
     return true;
     }

int main (){
    S[0] = 0;
    while(scanf("%d",&N) != EOF){
          Test = true;
          for(int i = 1; i <= N; i++){
                  scanf("%d",&S[i]);
                  if(S[i] < 1 || S[i] <= S[i - 1]) Test = false;
                  }           
          if(!Test){
                    printf("Case #%d: It is not a B2-Sequence.\n\n", Case++);
                    continue;
                    }    
          ll = 0;
          for(int i = 1; i <= N; i++){
                  for(int j = i; j <= N; j++){
                          M[++ll] = S[i] + S[j];
                          }
                  }
          Test = Check();
          if(!Test){
                    printf("Case #%d: It is not a B2-Sequence.\n\n", Case++);
                    } 
          else printf("Case #%d: It is a B2-Sequence.\n\n", Case++);
          }
    return 0;
    }
