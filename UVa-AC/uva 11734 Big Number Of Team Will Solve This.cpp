/*
  Name: UVa 11734 Big Number Of Teams Will Solve This
  Copyright: 
  Author: 3T
  Date: 13/05/10 18:30
  Description: string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INP "11734.INP"

int t,result,s1,s2;
char R[3][50] = {"Yes","Wrong Answer","Output Format Error"};
char line1[256],line2[256],templine[256];


bool AllSpace(){
//     if (line1[0] == '\0') return true;
     for(int i = 0; i < s1; i++){
             if(line1[i] != ' ') return false;
             }
     return true;
     }

int main () {
    FILE *f = fopen(INP,"r");
//   FILE *f = stdin;
    fscanf(f,"%d",&t);
    fgets(line1,256,f);
    for(int i = 1; i <= t; i++){
               result = 0;
               fgets(line1,256,f);
//               puts(line1);
               fgets(line2,256,f);
//               puts(line2);
               s1 = strlen(line1) - 1;
               s2 = strlen(line2) - 1;
               //test
//               printf("%d %d\n",s1,s2);
               if(s2 == 0){
                     if(s1 == 0) result = 0;
                     else if(s1 > 0){
                          if(AllSpace()) result = 2;
                          else result = 1;
                          }
                     }
               if(s2 > 0){
                     if(s1 == 0) result = 1;
                     else if(s1 > 0){
                          if(s2 > s1) result = 1;
                          else{
                               if(AllSpace()) result = 1;
                               else{
                                    int space = 0;
                                    int p = 0;
                                    for(int j = 0; j < s1; j++){
                                            if(line1[j] == ' ') space++;
                                            else{
                                                 templine[p] = line1[j];
                                                 p++;
                                                 }
                                            }
                                    if(p != s2) result = 1;
                                    else{
                                       int p2 = 0;
                                       for(int j = 0; j < p; j++){
                                            if(templine[j] == line2[j]) p2++;
                                            }
                                       if(p2 == p){
                                             if(space == 0) result = 0;
                                             else result = 2;
                                             }
                                       else result = 1;
                                       }
                                    }
                               }
                          }
                     }
               printf("Case %d: %s\n",i,R[result]);              
               }                     
    getchar();
    return 0;
    }
