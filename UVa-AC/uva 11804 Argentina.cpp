/*
  Name: UVa 11804 Argentina
  Copyright: 
  Author: 3T
  Date: 28/06/10 15:50
  Description: Sorting
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef struct Player{
        char Name[25];
        int A;
        int D;
        };

Player P[11];
int T,temp;
char line[256],tempchar[25];

bool Smaller(char A[25], char B[25]){
     int sa = strlen(A);
     int sb = strlen(B);
     int i = 0;
     while (i < min(sa,sb)){
           if(A[i] > B[i]) return false;
           if(A[i] < B[i]) return true;
           if(A[i] == B[i]) i++; 
           }
     if(i == min(sa,sb)){
          if(sa <= sb) return true;
          else return false; 
          }
     }

void Sort(){
     for(int i = 1; i < 10; i++){
             for(int j = i + 1; j < 11; j++){
                     if(P[i].A < P[j].A || (P[i].A == P[j].A && P[i].D > P[j].D) || (P[i].A == P[j].A && P[i].D == P[j].D && !Smaller(P[i].Name,P[j].Name))){
                               strcpy(tempchar,P[i].Name);
                               strcpy(P[i].Name,P[j].Name);
                               strcpy(P[j].Name,tempchar);
                               
                               temp = P[i].A;
                               P[i].A = P[j].A;
                               P[j].A = temp;
                               
                               temp = P[i].D;
                               P[i].D = P[j].D;
                               P[j].D = temp;                                
                               }
                     }
             }
     }
     
void SortAgain1(){
     for(int i = 1; i < 5; i++){
             for(int j = i + 1; j < 6; j++){
                     if(!Smaller(P[i].Name,P[j].Name)){
                               strcpy(tempchar,P[i].Name);
                               strcpy(P[i].Name,P[j].Name);
                               strcpy(P[j].Name,tempchar);
                               
                               temp = P[i].A;
                               P[i].A = P[j].A;
                               P[j].A = temp;
                               
                               temp = P[i].D;
                               P[i].D = P[j].D;
                               P[j].D = temp;                                                          
                           }
                     }
             }
     }

void SortAgain2(){
     for(int i = 6; i < 10; i++){
             for(int j = i + 1; j < 11; j++){
                     if(!Smaller(P[i].Name,P[j].Name)){
                               strcpy(tempchar,P[i].Name);
                               strcpy(P[i].Name,P[j].Name);
                               strcpy(P[j].Name,tempchar);
                               
                               temp = P[i].A;
                               P[i].A = P[j].A;
                               P[j].A = temp;
                               
                               temp = P[i].D;
                               P[i].D = P[j].D;
                               P[j].D = temp;                                                          
                           }
                     }
             }
     }
        
int main () {
    scanf("%d ",&T);
    for(int i = 1; i <= T; i++){
            for(int j = 1; j <= 10; j++){
                    gets(line);
                    sscanf(line,"%s %d %d",&P[j].Name,&P[j].A,&P[j].D);
                    }
                    //test
//                    for(int j = 1; j <= 10; j++){
//                            printf("%s\n",P[j].Name);
//                            }
            Sort();
                                //test
//                    for(int j = 1; j <= 10; j++){
//                            printf("%s\n",P[j].Name);
//                            }
            SortAgain1();
            SortAgain2();
            //output
            printf("Case %d:\n",i);
            printf("(%s",P[1].Name);
            for(int j = 2; j <= 5; j++){
                    printf(", %s",P[j].Name);
                    }
            printf(")\n");
                        printf("(%s",P[6].Name);
            for(int j = 7; j <= 10; j++){
                    printf(", %s",P[j].Name);
                    }
            printf(")\n");
            }
            return 0;
    }
