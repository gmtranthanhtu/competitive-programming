/*
  Name: UVa 661 Blowing Fuse
  Copyright: 
  Author: 3T
  Date: 06/12/10 23:19
  Description: ad hoc
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int Case(0), N, M, C, MaxA, Op[1010], Cap[100];
bool On[100];

int Solve(){
    MaxA = -1000;
    int CurC = 0;
    for(int i = 1; i <= M; i++){
        int Tmp = Op[i];
        if(On[Tmp]){
            CurC -= Cap[Tmp];
            On[Tmp] = false;
            }
        else{
            CurC += Cap[Tmp];
            On[Tmp] = true;
            MaxA = max(MaxA, CurC);
            if(CurC > C) return 1;
            }
        }
    return 0;
    }

int main () {
    //freopen("661.INP", "r", stdin); freopen("661.OUT", "w", stdout);
    while(scanf("%d%d%d",&N,&M,&C) && N){
        for(int i = 1; i <= N; i++){
            scanf("%d",&Cap[i]);
            On[i] = false;
            }
        for(int i = 1; i <= M; i++){
            scanf("%d",&Op[i]);
            }
        int Ans = Solve();
        Case++;
        printf("Sequence %d\n",Case);
        if(Ans){
            printf("Fuse was blown.\n\n");
            }
        else{
            printf("Fuse was not blown.\n");
            printf("Maximal power consumption was %d amperes.\n\n",MaxA);
            }
        }
    return 0;
    }
