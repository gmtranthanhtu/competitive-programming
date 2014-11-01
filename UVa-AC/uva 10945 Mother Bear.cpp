#include <stdio.h>
#include <string.h>
#include <ctype.h>

char S[5000];

bool Check(){
     char C1, C2;
     int len = strlen(S);
     int dau = 0;
     int cuoi = len - 1;
     while(dau < cuoi){
               bool Null = true;
               for(int i = dau; i < cuoi; i++){
                      if((S[i] <= 'Z' && S[i] >= 'A') || (S[i] <= 'z' && S[i] >= 'a')){
                          C1 = toupper(S[i]);
                          //printf("%c\n",C1);
                          dau = i;
                          Null = false;
                          break;
                          }
                      }
               if(Null) return true;       
               for(int i = cuoi; i > dau; i--){
                       if((S[i] <= 'Z' && S[i] >= 'A') || (S[i] <= 'z' && S[i] >= 'a')){
                           C2 = toupper(S[i]);
                           if(C2 != C1) return false;
                           //printf("%c %c\n",C1, C2);
                           cuoi = i;
                           break;     
                           }
                       }      
               dau++;
               cuoi--;
               }
     return true;
     }

int main (){
    while(gets(S)){
            if(!strcmp(S, "DONE")) break;
            printf(Check() ? "You won't be eaten!\n" : "Uh oh..\n");      
            }
    
    return 0;
    }
