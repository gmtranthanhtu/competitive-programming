/*
  Name: UVa 494 Kindergarten Counting Game
  Copyright: 
  Author: 3T
  Date: 04/09/10 02:00
  Description: 
*/
#include <stdio.h>
#include <string.h>

bool isLetter(char a){
     return (a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z');
     }

int main () {
    int R;
    char line[1000];
    while(gets(line)){
          R = 0;
          for(int i = 0; i < strlen(line); i++){
                  if(!i){
                         if(isLetter(line[i])) R++;
                         }
                  else if(isLetter(line[i]) && !isLetter(line[i - 1])) R++;
                  } 
          printf("%d\n",R);           
          }
    return 0;
    }
