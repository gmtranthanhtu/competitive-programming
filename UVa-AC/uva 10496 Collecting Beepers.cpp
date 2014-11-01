/*
  Name: UVa 10496 Collectin Beepers
  Copyright: 
  Author: 3T
  Date: 27/08/10 18:19
  Description: Backtracking
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

#define INP "10496.INP"
#define BIG 100000

typedef struct Point{int x,y;};
Point B[15];
int N,w,l,sx,sy,NB,Best,Tmp;
bool Taken[15];

bool allTaken(){
     for(int i = 1; i <= NB; i++){
             if(!Taken[i]) return false;
             }
     return true;
     }

void backtrack(int x, int y, int m){
     if(m == NB + 1){
          if(allTaken()){
          int Temp = abs(x - sx) + abs(y - sy);
          Tmp += Temp;
          Best = min(Best, Tmp);
          Tmp -= Temp;
          }
          }
     else{
          int Temp = abs(x - B[m].x) + abs(B[m].y - y);
          Tmp += Temp;
          //if(Tmp >= Best && !allTaken()) return;
          Taken[m] = true;
          //backtrack(B[m].x, B[m].y, m + 1);
          for(int i = 1; i <= NB + 1; i++){
                  if(!Taken[i]) backtrack(B[m].x, B[m].y, i);
                  }
          Taken[m] = false;
          Tmp -= Temp;          
          }
     }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&N);
    for(int i = 1; i <= N; i++){
            fscanf(f,"%d%d",&w,&l);
            fscanf(f,"%d%d",&sx,&sy);
            fscanf(f,"%d",&NB);
            for(int j = 1; j <= NB; j++){
                    fscanf(f,"%d%d",&B[j].x,&B[j].y);
                    Taken[j] = false;
                    }
            Best = BIG;
            Tmp = 0;
            for(int k = 1; k <= NB; k++){
            backtrack(sx,sy,k);
            }
            printf("The shortest path has length %d\n",Best);
            }
    
    
    //getchar();
    return 0;
    }
