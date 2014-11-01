/*
  Name: UVa 10278 Fire Station
  Copyright: 
  Author: 3T
  Date: 24/06/10 22:02
  Description: Floyd (not the best option)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

#define INP "10278.INP"
#define BIG 100000000
#define MAXI 505

int n,F,I,temp,a,b,c,M[MAXI][MAXI],Result,Cost,mintemp;
char line[1000];
bool FS[MAXI];

int main () {
  //  FILE *f = fopen(INP , "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&n);
    if(n == 0) return 0;
    for(int i = 1; i <= n; i++){
            fgets(line,1000,f);
            sscanf(line,"%d %d",&F,&I);
            for(int j = 1; j <= I; j++) FS[j] = false;
            for(int j = 1; j <= F; j++){
                    fgets(line,1000,f);
                    sscanf(line,"%d",&temp);
                    FS[temp] = true;
                    }
            for(int j = 1; j <= I; j++)
                for(int k = 1; k <= I; k++){
                        if(j == k) M[j][k] = 0;
                        else M[j][k] = BIG;
                        }
            while(fgets(line,1000,f) && strlen(line) != 1){
                  sscanf(line,"%d %d %d",&a,&b,&c);
                  M[a][b] = M[b][a] = c;                   
                  }

            //Floyd
            for(int j = 1; j <= I; j++)
               for(int k = 1; k <= I; k++)
                   for(int l = 1; l <= I; l++){
                                      M[j][k] = M[k][j] = min(M[j][k], M[j][l] + M[l][k]);
                           }
            Result = 1;
            Cost = BIG;
            for(int j = 1; j <= I; j++){
                    if(!FS[j]){
                         FS[j] = true;
                         temp = 0;
                         for(int k = 1; k <= I; k++){
                                 if(!FS[k]){
                                           mintemp = BIG; 
                                           for(int l = 1; l <= I; l++){
                                                   if(FS[l]){
                                                             mintemp = min(mintemp, M[k][l]);
                                                             }
                                                   }
                                           temp = max(temp,mintemp);
                                           }

                                 }
                         if(temp < Cost){
                                 Cost = temp;
                                 Result = j;
                                 } 
                         FS[j] = false;    
                         }
                    }               
            
            //output
            if(i > 1) cout << endl;
            cout << Result << endl;
            }
  //  getchar();
    return 0;
    }
