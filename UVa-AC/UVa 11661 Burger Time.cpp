/*
  Name: UVa 11661 Burger Time?
  Copyright: 
  Author: 3T
  Date: 27/05/10 01:46
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>

#define INP "11661.INP"
#define Max 2000005
int L,DD,DR,D;
char line[Max];

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d ",&L) && L){
        fgets(line,Max,f);
        D = Max;
        DD = DR = 0;
        for(int i = 0; i < L; i++){
                if(line[i] == 'Z'){
                           D = 0;
                           break;
                           }
                if(line[i] == '.'){
                           if(DD != 0) DD++;
                           if(DR != 0) DR++;
                           }
                else if(line[i] == 'D'){
//                     if(DD != 0) DD = 1;
                      if(DR != 0){
                          if(D > DR) D = DR;
                          DD = 1;
                          DR = 0;
                          }
                      else DD = 1;
                     }
                else if(line[i] == 'R'){
                     if(DD != 0){
                          if(D > DD) D = DD;
                          DR = 1;
                          DD = 0;
                          }
                     else DR = 1;
                     }
                }  
        printf("%d\n",D);             
        }
    
//    getchar();
    return 0;
    }
