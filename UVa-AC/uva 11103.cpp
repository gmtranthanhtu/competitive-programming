/*
  Name: UVa 11103 WFF 'N PROOF
  Copyright: 
  Author: 3T
  Date: 17/10/10 21:52
  Description: ad hoc, string
*/
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

char S[105], WWF[105], Symb[105];
int len, NumWWF, NumS, NumN, MaxL;


int main () {
   // freopen("11103.INP", "r", stdin);
   // freopen("11103.OUT", "w", stdout);
    
    while(gets(S) && strcmp(S, "0")){
        len = strlen(S);
        NumWWF = NumS = NumN = 0;
        for(int i = 0; i < len; i++){
                if(S[i] == 'N') NumN++;
                else if(S[i] == 'K' || S[i] == 'A' || S[i] == 'C' || S[i] == 'E'){
                     Symb[NumS] = S[i];
                     NumS++;
                     }
                else if(S[i] == 'p' || S[i] == 'q' || S[i] == 'r' || S[i] == 's' || S[i] == 't'){
                     WWF[NumWWF] = S[i];
                     NumWWF++;
                     }
                }          
        // if no WWF
        if(!NumWWF){
                    printf("no WFF possible\n");
                    continue;
                    }     
        else{
             for(int i = 1; i <= NumN; i++) printf("N");
             MaxL = min(NumWWF - 1, NumS);
             if(!MaxL) printf("%c",WWF[0]);
             else{
                  for(int i = 0; i < MaxL; i++){
                          printf("%c%c",Symb[i],WWF[i]);
                          }
                  printf("%c",WWF[MaxL]);
                  }
             }     
        printf("\n");
        }
    return 0;
    }
