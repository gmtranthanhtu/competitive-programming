/*
  Name: UVa 11520 Fill the Square
  Copyright: 
  Author: 3T
  Date: 11/07/10 10:35
  Description: string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    int T,n;
    char Input[15][15],Output[15][15];
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d ",&n);
            for(int j = 0; j < n; j++){
                    gets(Input[j]);
                    }
            memset(Output,'-', sizeof Output);
            for(int j = 0; j < n; j++){
                    for(int k = 0; k < n; k++){
                            Output[j + 1][k + 1] = Input[j][k];
                            }
                    }
            for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= n; k++){
                            if(Output[j][k] == '.'){
                                            for(char c = 'A'; c <= 'Z'; c++){
                                                     if(c != Output[j - 1][k] && c != Output[j + 1][k] && c != Output[j][k - 1] && c != Output[j][k + 1]){
                                                          Output[j][k] = c;
                                                          break;
                                                          }
                                                     }
                                            }
                            }
                    }
            
            printf("Case %d:\n",i);
            for(int j = 1; j <= n; j++){
                    for(int k = 1; k <= n; k++){
                            printf("%c",Output[j][k]);
                            }
                    printf("\n");
                    }            
            }
    return 0;
    }
