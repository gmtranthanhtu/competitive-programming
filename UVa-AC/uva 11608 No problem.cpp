/*
  Name: UVa 11608 No problem
  Copyright: 
  Author: 3T
  Date: 09/03/11 20:56
  Description: ad hoc
*/
#include <stdio.h>
#include <iostream>

using namespace std;

#define INP "11608.INP"
#define OUT "11608.OUT"
int A[15], Ans[15];
int  Case(0), N, x, Avai;


int main () {
    //freopen(INP , "r", stdin); freopen(OUT, "w", stdout);
    while(scanf("%d",&N) && N >= 0){
        Case++;
        A[1] = N;
        for(int i = 2; i <= 12; i++) scanf("%d",&A[i]);
        scanf("%d",&N);
        Avai = 0;
        for(int i = 1; i <= 12; i++){
            scanf("%d",&x);
            Avai += A[i];
            //printf("Thang %d: con %d, x = %d\n",i,Avai,x);
            if(Avai >= x){
                Ans[i] = 1;
                Avai = Avai - x;
                }
            else{
                Ans[i] = 0;
                }
            }
        printf("Case %d:\n",Case);
        for(int i = 1; i <= 12; i++){
            if(Ans[i] == 1) printf("No problem! :D\n");
            else printf("No problem. :\(\n");
            }
        }
    return 0;
    }
