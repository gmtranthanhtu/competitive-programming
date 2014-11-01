/*
  Name: UVa 490 Rotating Sentences
  Copyright: 
  Author: 3T
  Date: 04/09/10 02:48
  Description: string
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char Input[150][150];

int main (){
    int n, MaxL = -1;
    for(n = 0; gets(Input[n]) != NULL; n++){
          int Tmp = strlen(Input[n]);
          MaxL = max(MaxL, Tmp);
          }    
    for(int i = 0; i < MaxL; i++){
            for(int j = n - 1; j >= 0; j--){
                    if(i >= strlen(Input[j])) printf(" ");
                    else printf("%c",Input[j][i]);
                    }
            printf("\n");
            }
    return 0;
    }
