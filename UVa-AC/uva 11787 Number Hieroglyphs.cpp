/*
  Name: UVa 11787 Number Hieroglyphs
  Copyright: 
  Author: 3T
  Date: 16/05/10 23:14
  Description: no algorithm needed
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INP "11787.INP"

int n,s,j,k,m,Sum,check;
char c,line[1000];

int Convert(char a){
    switch (a) {
           case 'B': return 0;
           case 'U': return 1;
           case 'S': return 2;
           case 'P': return 3;
           case 'F': return 4;
           case 'T': return 5;
           case 'M': return 6;
           }
    }
    
int Power10(int a){
    int result = 1;
    if(a == 0) return result;
    for(int i = 1; i <= a; i++){
            result *= 10;
            }
    return result;
    }

void Process(){
     Sum = 0;
     s = strlen(line) - 1;
     j = 0;
     for(k = 0; k < s; k++){
           if(line[k] != line[j]) break;
           }
     if(k > 9){
          printf("error\n");
          return;
          }
     Sum = Sum + k * Power10(Convert(line[j]));
     if(k == s){
          printf("%d\n",Sum);
          return;
          }
     //check
     check = Convert(line[k]) - Convert(line[j]);
     //
     j = k;
     for(k = j; k < s; k++){
           if(line[k] != line[j]) break;
           }
     m = k - j;
     if(m > 9){
          printf("error\n");
          return;
          }
     Sum = Sum + m * Power10(Convert(line[j]));
     if(k == s){
          printf("%d\n",Sum);
          return;
          }
          
     //3 --> end
     m = k;
 //    printf("test: %d %d %d\n",m,j,check);
     while(m < s){
             if((Convert(line[m]) - Convert(line[j])) * check < 0){ //check order
                        printf("error\n");
                        return;           
                       }
             for(k = m; k < s; k++){
                   if(line[k] != line[m]) break;
                   }
             j = k - m;
             if(j > 9){
           printf("error\n");
           return;
          }
          Sum = Sum + j * Power10(Convert(line[m]));
           if(k == s){
          printf("%d\n",Sum);
          return;
          }
          j = m;
          m = k;
             }
     }

int main () {
  //  FILE *f = fopen (INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&n);
    for(int i = 1; i <= n; i++){
            fgets(line,1000,f);
            Process();
            }
    
 //   getchar();
    return 0;
    }
