/*
  Name: UVa 10422 Knights in FEN
  Copyright: 
  Author: 3T
  Date: 28/08/10 23:30
  Description: Backtracking
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define INP "10422.INP"
#define BLANK 10

int N, Board[5][5], SRow, SCol, MaxLv, Solved;
int Goal[5][5] = {{1,1,1,1,1}, {0,1,1,1,1}, {0,0,BLANK,1,1}, {0,0,0,0,1}, {0,0,0,0,0}};
//Valid move 
int MoveR[8] = {-1, 1, -2, 2, -1, 1, -2, 2};
int MoveC[8] = {2, 2, 1, 1, -2, -2, -1, -1};

char line[100];

bool foundGoal(){
     for(int i = 0; i < 5; i++){
             for(int j = 0; j < 5; j++){
                     if(Board[i][j] != Goal[i][j]) return false;
                     }
             }
     return true;
     }

void backtrack(int Lv, int BlRow, int BlCol, int PreRow, int PreCol){
     if(Lv > 10) return;
     if(Lv >= MaxLv) return;
     if(foundGoal()){
                     MaxLv = Lv;
                     Solved = 1;
                     return;
                     }
     for(int i = 0; i < 8; i++){
             int NextRow = BlRow + MoveR[i];
             int NextCol = BlCol + MoveC[i];
             if(NextRow < 0 || NextRow > 4 || NextCol < 0 || NextCol > 4) continue;
             if(NextRow == PreRow && NextCol == PreCol) continue;
             //backtrack here
             swap(Board[NextRow][NextCol], Board[BlRow][BlCol]);
             backtrack(Lv + 1, NextRow, NextCol, BlRow, BlCol);
             swap(Board[NextRow][NextCol], Board[BlRow][BlCol]);
             }
     }

int main (){
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&N);
    fgets(line, 100, f);
    for(int i = 1; i <= N; i++){
            for(int j = 0; j < 5; j++){
                    fgets(line, 100, f);
                    for(int k = 0; k < 5; k++){
                            if(line[k] == ' '){
                                       Board[j][k] = BLANK;
                                       SRow = j;
                                       SCol = k;
                                       }
                            else Board[j][k] = line[k] - '0';
                            }
                    }
            MaxLv = 11;
            Solved = 0;
            backtrack(0, SRow, SCol, -1, -1);
            if(Solved) printf("Solvable in %d move(s).\n",MaxLv);
            else printf("Unsolvable in less than 11 move(s).\n");
            }
    //getchar();
    return 0;
    }
