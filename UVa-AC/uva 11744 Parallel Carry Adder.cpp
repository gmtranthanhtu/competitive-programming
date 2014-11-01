/*
  Name: UVa 11744 Parallel Carry Adder
  Copyright: 
  Author: 3T
  Date: 11/05/10 10:49
  Description: no algorithm needed :D
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxBit 33
#define INP "11744.INP"

int n,j;
char a[MaxBit],b[MaxBit],c[MaxBit],d[MaxBit];
char line[101];

void Print(){
            for(j = 1; j <= 31; j++){
                  printf("%c",a[j]);
                  }
            printf(" ");
            for(j = 1; j <= 31; j++){
                  printf("%c",b[j]);
                  }            
            printf("\n");     
     }
     
void PrintOverflow(){
            for(j = 1; j <= 31; j++){
                  printf("%c",a[j]);
                  }
            printf(" ");
            printf("overflow");          
            printf("\n");     
     }

bool Overflow(){
     if(b[0]=='1') return true;
     else return false;
     }

bool Zero() {
     for(j = 1; j <= 31; j++){
           if(b[j]=='1') return false;
           }
     return true;
     }

int main (){
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&n);
    for(int i = 1; i <= n; i++){
            memset(a,'0',sizeof(a));
            memset(b,'0',sizeof(b));
            memset(c,'0',sizeof(c));
            memset(d,'0',sizeof(d));
            fgets(line,101,f);
            for(j = 0; j <= 30; j++){
                  a[j + 1] = line[j];
                  }
            for(j = 32; j <= 62; j++){
                  b[j - 31] = line[j];
                  }
            Print();
            while(!Zero() && !Overflow()){
                   for(j = 1; j <= 31; j++){
                         if(a[j] != b[j]) c[j] = '1';
                         else c[j] = '0';
                         if(a[j]=='1' && b[j]=='1') d[j] = '1';
                         else d[j] = '0';
                         } 
                   //a = c
                   for(j = 1; j <= 31; j++){
                         a[j] = c[j];
                         }
                   //b = 2 * d
                   for(j = 1; j <= 31; j++){
                         b[j - 1] = d[j];
                         }
                   b[31] = '0';
                   if(!Overflow()) Print();
                   else PrintOverflow();            
                   }
            
            if(i < n) printf("\n");
            }
    
//    getchar();
    return 0;
    }
