/*
  Name: UVa 11743
  Copyright: 
  Author: 3T
  Date: 28/06/10 19:01
  Description: 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
    int N,S[17],j,k,sum1;
    char line[19];
    scanf("%d ",&N);
    for(int i = 1; i <= N; i++){
            gets(line);
            j = 1;
            for(k = 0; k < 19; k ++){
                  if(line[k] != ' '){
                             S[j++] = line[k] - '0';
                             }
                  }
            sum1 = 0;
            for(k = 1; k <= 16; k++){
                  if(k % 2){
                       int s = S[k] * 2;
                       if(s < 10) sum1 += s;
                       else if (s >= 10){
                            sum1 += s % 10;
                            sum1 += 1;
                            }
                       }
                  else sum1 += S[k];
                  }
            if(sum1 % 10) printf("Invalid\n");
            else printf("Valid\n");
            }
    return 0;
    }
