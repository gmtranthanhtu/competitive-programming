/*
  Name: UVa 341 Non-Stop Travel
  Copyright: 
  Author: 3T
  Date: 31/05/11 00:08
  Description: graph, dijsktra
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 50
#define BIG 99999999

int Case(0), N, n, a, b, S, E, p, C[MAX][MAX], d[MAX], Trace[MAX], Path[MAX];
bool Free[MAX];

void Config(){
     for(int i = 1; i <= N; i++){
             Free[i] = true;
             d[i] = BIG;
             for(int j = 1; j <= N; j++){
                     C[i][j] = BIG;
                     }
             }
     }
     
void Dijsktra(){
     d[S] = 0;
     
     int u, Min;
     do{
         u = 0;
         Min = BIG;
         for(int i = 1; i <= N; i++){
                 if(Free[i] && d[i] < Min){
                            u = i;
                            Min = d[i];
                            }
                 }
         if(u == 0 || u == E) break;
         Free[u] = false;
         for(int i = 1; i <= N; i++){
                 if(Free[i] && d[i] > d[u] + C[u][i]){
                            d[i] = d[u] + C[u][i];
                            Trace[i] = u;
                            }
                 }
         } while(1);
     }
     
void findPath(){
     p = 0;
     p++;
     Path[p] = E;
     int Tmp = Trace[E];
     while(Tmp != S){
               p++;
               Path[p] = Tmp;
               Tmp = Trace[Tmp];
               }
     p++;
     Path[p] = S;
     }
     
void Print(){
     Case++;
     printf("Case %d: Path = ",Case);
     for(int i = p; i >= 1; i--){
             if(i == p) printf("%d",Path[i]);
             else
             printf(" %d",Path[i]);
             }
     printf("; %d second delay\n",d[E]);
     }

int main () {
    //freopen("341.INP", "r", stdin); freopen("341.OUT", "w", stdout);
    while(scanf("%d",&N) && N){
        //config
        Config();
        for(int i = 1; i <= N; i++){
                scanf("%d",&n);
                for(int j = 1; j <= n; j++){
                        scanf("%d%d",&a,&b);
                        C[i][a] = b;
                        }
                }   
        scanf("%d%d",&S,&E);
        //process
        Dijsktra();      
        findPath();       
        Print(); 
       //print("Case %d: Path = ", i);
       
        }
    
    
    return 0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
    }
