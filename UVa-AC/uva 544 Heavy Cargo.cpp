/*
  Name: UVa 544 Heavy Cargo
  Copyright: 
  Author: 3T
  Date: 16/06/10 01:15
  Description: Shortest Path, Floyd
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define INP "544.INP"
#define MAXCITY 201


int n,r,j,k,m,Temp,NumCity,M[MAXCITY][MAXCITY],Case(1),S,D;
char City[MAXCITY][35],line[100],a[35],b[35];

int checkAppear(char a[35]){
    for(int i = 1; i <= NumCity; i++){
          if(!strcmp(a,City[i])) return i;
          }
    return -1;
    }

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    
    while(fscanf(f,"%d%d ",&n,&r) && n){
          NumCity = 0;
          memset(M,0,sizeof(M));
          for(int i = 1; i <= r; i++){
                  fgets(line,100,f);
                  sscanf(line,"%s %s %d",&a,&b,&Temp);
                  if(NumCity == 0){
                             strcpy(City[NumCity + 1],a);
                             NumCity++;
                             strcpy(City[NumCity + 1],b);
                             NumCity++;
                             M[NumCity][NumCity - 1] = M[NumCity - 1][NumCity] = Temp;
                             }
                  else{
                       j = checkAppear(a);
                       if(j == -1){
                            NumCity++;
                            strcpy(City[NumCity],a);
                            j = NumCity;
                            }
                       k = checkAppear(b);
                       if(k == -1){
                            NumCity++;
                            strcpy(City[NumCity],b);
                            k = NumCity;
                            }
                       M[j][k] = M[k][j] = Temp;
                       }
                  } 
          fgets(line,100,f);
          sscanf(line,"%s %s",&a,&b);
          S = checkAppear(a);
          D = checkAppear(b);
          //Floyd
          for(j = 1; j <= NumCity; j++){
                for(k = 1; k <= NumCity; k++){
                      for(m = 1; m <= NumCity; m++){
                            if(j != k && k != m){
                                 M[j][k] = M[k][j] = max(M[j][k],min(M[j][m],M[m][k]));
                                 }
                            }
                      }
                }
          printf("Scenario #%d\n",Case);
          Case++;
          //test
          printf("%d tons\n",M[S][D]);
          printf("\n");              
          }
  //  getchar();
    return 0;
    }
