/*
  Name: UVa 10816 Travel in Desert
  Copyright: 
  Author: 3T
  Date: 05/07/10 00:41
  Description: Floyd, multiple-graph, shortest path,....and get over the tricks :D
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INP "10816.INP"
#define BIGD 6000.0
#define MAXNODE 105
#define MAXEDGE 10005 
typedef struct Edge{
        int From;
        int To;
        double R;
        double D;
        };
Edge Ed[MAXEDGE];
int N,E,S,D,a,b,Trace[MAXNODE][MAXNODE];
double c,d,Dis[MAXNODE][MAXNODE],Temp[MAXNODE][MAXNODE],MinTemp;

int main () {
//    FILE *f = fopen(INP, "r");
   FILE *f = stdin;
    while(fscanf(f,"%d%d",&N,&E) == 2){
           fscanf(f,"%d%d",&S,&D);

           //Init
           for(int i = 1; i <= N; i++){
                   for(int j = 1; j <= N; j++){
                           Dis[i][j] = Temp[i][j] = BIGD;
                           Trace[i][j] = j;
                           }
                   Dis[i][i] = Temp[i][i] = 0;
                   } 
           //input edges
           for(int i = 1; i <= E; i++){
                   fscanf(f,"%d%d%lf%lf",&Ed[i].From,&Ed[i].To,&Ed[i].R,&Ed[i].D);
                   if(Temp[Ed[i].From][Ed[i].To] > Ed[i].R){
                                                 Temp[Ed[i].From][Ed[i].To] = Temp[Ed[i].To][Ed[i].From] = Ed[i].R;
                                                 }
                   } 
           //get min temperature using Floyd
           for(int k = 1; k<= N; k++){
               for(int i = 1; i <= N; i++){
                     for(int j = 1; j<= N; j++){
                           Temp[i][j] = min(Temp[i][j], max(Temp[i][k],Temp[k][j]));
                                               }
                                           }
                                      }        
            MinTemp = Temp[S][D];
           //Re-store necessary distances to array
           for(int i = 1; i <= E; i++){
                   a = Ed[i].From;
                   b = Ed[i].To;
                   c = Ed[i].R;
                   d = Ed[i].D;
                   if(Dis[a][b] > d && c <= MinTemp){
                        Dis[a][b] = Dis[b][a] = d;
                        }
                   }         
           //get min distance using Floyd on fixed distance array
             for(int i = 1; i <= N; i++){
                    for(int j = 1; j <= N; j++){
                            for(int k = 1; k <= N; k++){
                                         if(Dis[j][k] > Dis[j][i] + Dis[i][k]){
                                                      Dis[j][k] = Dis[j][i] + Dis[i][k];
                                                      Trace[j][k] = Trace[j][i];
                                                      } 
                                           }}}  
            //output
            if(S == D){
                 printf("%d\n",D);
                 printf("0.0 0.0\n");
                 }
            else{
            int temp = S;
            while(S != D){
                    printf("%d ",S);
                    S = Trace[S][D];
                    }
            printf("%d\n",D);
            printf("%.1lf %.1lf\n", Dis[temp][D],MinTemp); 
               }  
           }
//    getchar();
    return 0;
    }
