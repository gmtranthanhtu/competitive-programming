/*
  Name: UVa 439 Knight Move
  Copyright: 
  Author: 3T
  Date: 31/05/11 01:25
  Description: BFS
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define BIG 999

typedef struct Cell{
        int CX;
        int CY;
        };

queue <Cell> Q;

char S[10], s1[10], e1[10];
int xs, ys, xe, ye, Ans;
int X[] = {0, 1, -1, 2, -2, 1, -1, 2, -2};
int Y[] = {0, 2, -2, 1, -1, -2, 2, -1, 1};
bool B[10][10];
int D[10][10];

int CtoN(char c){
    if(c == 'a') return 1;
    if(c == 'b') return 2;
    if(c == 'c') return 3;
    if(c == 'd') return 4;
    if(c == 'e') return 5;
    if(c == 'f') return 6;
    if(c == 'g') return 7;
    if(c == 'h') return 8;
    }
    
bool isValid(int x, int y){
     if(x > 8 || x < 1 || y > 8 || y < 1) return false;
     return true;
     }
    

void doBFS(int x, int y){
     for(int i = 1; i <= 8; i++){
             int xx = x + X[i];
             int yy = y + Y[i];
             if(!isValid(xx, yy)) continue;
             if(!B[xx][yy]) continue;
             B[xx][yy] = false;
             D[xx][yy] = D[x][y] + 1;
             Cell C = {xx, yy};
             Q.push(C);
             }
     }

int main () {
    //freopen("439.INP", "r", stdin); freopen("439.OUT", "w", stdout);
    while(gets(S) && strlen(S) != 0){
        sscanf(S, "%s %s",&s1, &e1);
        xs = CtoN(s1[0]);
        xe = CtoN(e1[0]);
        ys = s1[1] - '0';
        ye = e1[1] - '0';     
        for(int i = 1; i <= 8; i++){
                for(int j = 1; j <= 8; j++){
                        B[i][j] = true;
                        }
                }
        D[xs][ys] = 0;
        //process
        B[xs][ys] = false;
        Cell C = {xs, ys};
        Q.push(C);
        while(!Q.empty()){
        int xt = Q.front().CX;
        int yt = Q.front().CY;
        Q.pop();
        doBFS(xt, yt);
        }  
        printf("To get from %s to %s takes %d knight moves.\n",s1,e1,D[xe][ye]);
        }
    
    return 0;
    }
