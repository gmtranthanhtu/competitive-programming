/*
  Name: UVa 445 Marvelous Maze
  Copyright: 
  Author: 3T
  Date: 13/05/10 12:19
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INP "445.INP"

int sum;
char line[256];

int main () {
//    FILE *f = fopen(INP,"r");
    FILE *f = stdin;
    while(!feof(f)){
        fgets(line,256,f); 
        //test
//        printf("test\n");
//        puts(line);
        if(line[0] == '\0'){
                    printf("\n");
                   }   
        else if(!feof(f) && line[0] != '\0'){
        sum = 0;
        for(int i = 0; i < strlen(line) - 1; i++){
                if(line[i] >= '0' && line[i] <= '9') sum = sum + (line[i] - '0');
                else if((line[i] >= 'A' && line[i] <= 'Z') || line[i] == '*'){
                     for(int j = 1; j <= sum; j++) printf("%c",line[i]);
                     sum = 0;
                     }
                else if(line[i] == 'b'){
                     for(int j = 1; j <= sum; j++) printf(" ");
                     sum = 0;                     
                     } 
                else if(line[i] == '!') printf("\n");
                } 
        printf("\n"); 
        }    
        } 
    fclose(f);
 //  getchar();
    return 0;
    }
