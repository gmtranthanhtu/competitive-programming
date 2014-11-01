/*
  Name: UVa 11729 Commando War
  Copyright: 
  Author: 3T
  Date: 09/05/10 23:57
  Description: Bubble Sort
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define Max 10005
#define INP "11729.INP"

typedef struct Soldier{
        int B;
        int J;
        };
Soldier S[Max];        
int N,Case(1),temp,MaxTime,s,temptime;

void Sort(){
     for(int i = 0; i < N - 1; i++){
             for(int j = N - 1; j >= i + 1; j--){
                     if(S[j].J > S[j - 1].J){
                               temp = S[j].J;
                               S[j].J = S[j - 1].J;
                               S[j - 1].J = temp;
                               temp = S[j].B;
                               S[j].B = S[j - 1].B;
                               S[j - 1].B = temp;
                               }
                     else if(S[j].J == S[j - 1].J && S[j].B < S[j - 1].B){
                               temp = S[j].J;
                               S[j].J = S[j - 1].J;
                               S[j - 1].J = temp;
                               temp = S[j].B;
                               S[j].B = S[j - 1].B;
                               S[j - 1].B = temp;                          
                          }
                     }
             }
     }

int main () {
//        FILE *f = fopen(INP,"r");
    FILE *f = stdin;
        while(fscanf(f,"%d",&N) && N){
            MaxTime = 0;
            s = 0;
            for(int i = 0; i < N; i++){
                    fscanf(f,"%d%d",&S[i].B,&S[i].J);
                    }     
            Sort();
            //test
//            for(int i = 0; i < N; i++){
//                    printf("%d %d\n",S[i].B,S[i].J);
//                    }  
            for(int i = 0; i < N; i++){
                    temptime = s + S[i].B + S[i].J;
                    MaxTime = std::max(MaxTime,temptime);
                    s = s + S[i].B;
                    }  
            printf("Case %d: %d\n",Case,MaxTime); 
            Case++;          
            }
            
//    getchar();
    return 0;
    }
