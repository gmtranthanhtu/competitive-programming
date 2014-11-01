/*
  Name: UVa 11342 Three-square
  Copyright: 
  Author: 3T
  Date: 08/04/11 13:27
  Description: ad hoc, pre calculate
*/
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

#define MAX 50000

typedef struct TwoSquare{
    bool Can;
    int L;
    int G;
    };
    
typedef struct ThreeSquare{
    bool Can;
    int Fi;
    int TSindex;
    };    

TwoSquare TS[MAX + 5];
ThreeSquare ThS[MAX + 5];

int N, a;

void Gen(){
    for(int i = 0; i <= MAX; i++){
        TS[i].Can = false;
        ThS[i].Can = false;
        }
    TS[0].Can = true; TS[0].L = 0; TS[0].G = 0;
    ThS[0].Can = true; ThS[0].Fi = 0; ThS[0].TSindex = 0;
    
    //gen TS
    for(int i = 0; i * i <= MAX; i++){
        for(int j = i; j * j + i * i <= MAX; j++){
            int Tmp = i * i + j * j;
            if(TS[Tmp].Can) continue;
            TS[Tmp].Can = true;
            TS[Tmp].L = i;
            TS[Tmp].G = j;
            }
        }
    
    //gen ThS
    for(int i = 1; i <= MAX; i++){
        for(int j = 0; j * j <= i; j++){
            int Tmp = i - j * j;
            if(TS[Tmp].Can){
                ThS[i].Can = true;
                ThS[i].Fi = j;
                ThS[i].TSindex = Tmp;
                break;
                }
            }
        }
    }

int main () {
    Gen();
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d",&a);
        if(!ThS[a].Can) printf("-1\n");
        else{
            printf("%d %d %d\n",ThS[a].Fi, TS[ThS[a].TSindex].L, TS[ThS[a].TSindex].G);
            }
        }
    return 0;
    }
