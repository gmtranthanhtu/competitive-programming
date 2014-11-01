/*
  Name: UVa 11786 Global Raining at Bididibus
  Copyright: 
  Author: 3T
  Date: 17/05/10 21:01
  Description: just like a stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INP "11786.INP"
#define Max 10005

typedef struct Bididibus{
        int S;
        int Height;
        };
Bididibus B[Max];

int n,s,temp,Total;
char line[Max];

int Convert(char a){
    if (a == '\\') return -1;
    if (a == '/') return 1;
    if (a == '_') return 0;
    }

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&n);
    for(int i = 1; i <= n; i++){
            fgets(line,Max,f);
            s = strlen(line) - 1;
            memset(B,0,sizeof(B));
            temp = 0;
            for(int j = 0; j < s; j++){
                    B[j].S = Convert(line[j]);
                    B[j].Height = temp + B[j].S;
                    temp = B[j].Height;
                    }
            Total = 0;
            for(int j = 0; j < s; j++){
                    if(B[j].S == -1){
                              for(int k = j + 1; k < s; k++){
                                      if(B[k].S == 1 && B[k].Height == B[j].Height + 1){
                                                Total = Total + k - j;
                                                break;
                                                }
                                      }
                              }
                    }
            printf("%d\n",Total);
            }
    
//    getchar();
    return 0;
    }
