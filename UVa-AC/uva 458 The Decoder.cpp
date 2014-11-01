/*
  Name: UVa 458 The Decoder
  Copyright: 
  Author: 3T
  Date: 17/05/10 23:58
  Description: -7 ascii
*/
#include <stdio.h>
#include <string.h>
//#include <conio.h>

#define INP "458.INP"

int s;
char line[10000],Output[10000];

int main () {
   // FILE *f = fopen (INP, "r");
   FILE *f = stdin;
    while(fgets(line,10000,f)){
         memset(Output,'\0',sizeof(Output));
         s = strlen(line) - 1;
         for(int i = 0; i < s; i++){
                 Output[i] = line[i] - 7;
                 }
         Output[s]='\0';
         printf("%s\n",Output);
         }
  //  getchar();
    return 0;
    }
