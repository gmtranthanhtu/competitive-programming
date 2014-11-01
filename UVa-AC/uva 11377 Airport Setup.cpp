/*
  Name: UVa 11377 Airport Setup
  Copyright: 
  Author: 3T
  Date: 31/07/10 15:20
  Description: Disjktra
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INP "11377.INP"
#define OUT "11377.OUT"
#define MAX 10000000
#define MAXNODE 2010

int Q,T,N,M,K,a,b,Ma[MAXNODE][MAXNODE],Case(1);
bool Airport[MAXNODE];

int callDijsktra(int S, int D){
    int d[MAXNODE];
    for(int i = 1; i <= N; i++) d[i] = MAX;
    d[S] = 0;
    bool Free[MAXNODE];
    for(int i = 1; i <= N; i++) Free[i] = true;
    //---------
    while (1){
          int u = 0;
          int Min = MAX;
          for(int i = 1; i <= N; i++){
                  if(Free[i] && d[i] < Min){
                             Min = d[i];
                             u = i;
                             }
                  }
          if(u == 0 || u == D) break;
          Free[u] = false;
          for(int v = 1; v <= N; v++){
                  if(Free[v] && d[v] > d[u] + Ma[u][v]){
                             d[v] = d[u] + Ma[u][v];
                             }
                  }
          }
    if(d[D] == MAX) return -1;
    if(!Airport[S]) d[D]++;
    return d[D];
    }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
   // freopen(OUT, "w", stdout);
    fscanf(f,"%d",&T);
    for(int i = 1; i <= T; i++){
            fscanf(f,"%d%d%d",&N,&M,&K);
            for(int j = 1; j <= N; j++){
                    Airport[j] = false;
                    }
            for(int j = 1; j <= K; j++){
                    fscanf(f,"%d",&a);
                    Airport[a] = true;
                    }
            for(int j = 1; j <= N; j++){
                    for(int k = 1; k <= N; k++){
                            Ma[j][k] = MAX;
                            }
                    Ma[j][j] = 0;
                    }
            for(int j = 1; j <= M; j++){
                    fscanf(f,"%d%d",&a,&b);
                    if(Airport[a]){
                                   Ma[b][a] = 0;
                                   }
                    else Ma[b][a] = 1;
                    if(Airport[b]){
                                   Ma[a][b] = 0;
                                   }
                    else Ma[a][b] = 1;
                    }
            fscanf(f,"%d",&Q);
//            if(Case > 1) printf("\n");
            printf("Case %d:\n",Case);
            Case++;
            for(int j = 1; j <= Q; j++){
                    fscanf(f,"%d%d",&a,&b);
                    if(a == b) printf("0\n");
                    else
                    printf("%d\n",callDijsktra(a,b));
//                    printf("%d\n",10);

                    }
                    printf("\n");
            }
    
   // fclose(stdout);
  //  getchar();
    return 0;
    }
