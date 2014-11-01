/*
  Name: UVa 929 Number Maze
  Copyright: 
  Author: 3T
  Date: 30/06/11 15:50
  Description: dijkstra 
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAXNODE 1010
typedef struct Node{
        int x, y;
        int Cost;
        };

bool Visited[MAXNODE][MAXNODE];
int C[MAXNODE][MAXNODE];
int Row, Col, Idn, T;

int main () {
    //freopen("929.INP", "r", stdin); freopen("929.OUT", "w", stdout);
    scanf("%d",&T);
    for(int t = 1; t <= T; t++){
            scanf("%d %d",&Row, &Col);
            for(int i = 0; i < Row; i++){
                    for(int j = 0; j < Col; j++){
                            scanf("%d",&C[i][j]);
                            Visited[i][j] = false;
                            }
                    }
            queue <Node> Q[10];
            Node Tmp, Tmp2;
            Tmp.x = 0; Tmp.y = 0; Tmp.Cost = C[0][0];
            Q[0].push(Tmp);
            Idn = 0;
            while(1){
                     while(Q[Idn].empty()) Idn = (Idn + 1) % 10;
                     if(Visited[Q[Idn].front().x][Q[Idn].front().y]){Q[Idn].pop(); continue;}
                     
                     if(Q[Idn].front().x == Row - 1 && Q[Idn].front().y == Col - 1){
                                         printf("%d\n",Q[Idn].front().Cost);
                                         break;
                                         }
                     
                     Tmp = Q[Idn].front();
                     Visited[Tmp.x][Tmp.y] = true;
                     //Q[Idn].front();

                     if(Tmp.x + 1 < Row){
                              Tmp2.x = Tmp.x + 1;
                              Tmp2.y = Tmp.y;
                              Tmp2.Cost = Tmp.Cost + C[Tmp2.x][Tmp2.y];
                              if(!Visited[Tmp2.x][Tmp2.y]){
                                                           Q[(Idn + C[Tmp2.x][Tmp2.y])%10].push(Tmp2);
                                                           }
                              }
                     if(Tmp.y + 1 < Col){
                              Tmp2.x = Tmp.x;
                              Tmp2.y = Tmp.y + 1;
                              Tmp2.Cost = Tmp.Cost + C[Tmp2.x][Tmp2.y];
                              if(!Visited[Tmp2.x][Tmp2.y]){
                                                           Q[(Idn + C[Tmp2.x][Tmp2.y])%10].push(Tmp2);
                                                           }
                              }
                     if(Tmp.x - 1 >= 0){
                              Tmp2.x = Tmp.x - 1;
                              Tmp2.y = Tmp.y;
                              Tmp2.Cost = Tmp.Cost + C[Tmp2.x][Tmp2.y];
                              if(!Visited[Tmp2.x][Tmp2.y]){
                                                           Q[(Idn + C[Tmp2.x][Tmp2.y])%10].push(Tmp2);
                                                           }
                              }                                                             
                     if(Tmp.y - 1 >= 0){
                              Tmp2.x = Tmp.x;
                              Tmp2.y = Tmp.y - 1;
                              Tmp2.Cost = Tmp.Cost + C[Tmp2.x][Tmp2.y];
                              if(!Visited[Tmp2.x][Tmp2.y]){
                                                           Q[(Idn + C[Tmp2.x][Tmp2.y])%10].push(Tmp2);
                                                           }
                              }
                     }
                                                                                         
            }
    return 0;
    }
