/*
  Name: UVa 489 Hangman Judge
  Copyright: 
  Author: 3T
  Date: 04/09/10 04:44
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int r, w, n;
char line1[500], line2[500];
bool Appear[30], Used[30];

bool isWin(){
     for(int i = 0; i < 26; i++){
             if(Appear[i]) return false;
             }
     return true;
     }

int main () {
    //printf("%d %d %d",'a','z',122 - 97);
    while(scanf("%d",&n) && n != -1){
         gets(line1);
         gets(line1);
         gets(line2);  
         memset(Appear, false, sizeof Appear);
         memset(Used, false, sizeof Used);
         
         for(int i = 0; i < strlen(line1); i++){
                 Appear[(int)line1[i] - 97] = true;
                 }              
         w = 0;
         r = 0;
         for(int i = 0; i < strlen(line2); i++){
                 if(Used[(int)line2[i] - 97]) continue;
                 Used[(int)line2[i] - 97] = true;
                 if(Appear[(int)line2[i] - 97]){
                                    Appear[(int)line2[i] - 97] = false;
                                    if(isWin()){
                                                r = 1;
                                                break;
                                                } 
                                    }
                 else{
                      w++;
                      if(w == 7){
                           r = 2;
                           break;
                           }
                      }
                 }
         printf("Round %d\n",n);
         if(!r) printf("You chickened out.\n");
         else if(r == 1)printf("You win.\n");
         else printf("You lose.\n");
         }
   // getchar();
    return 0;
    }
