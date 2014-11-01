/*
  Name: UVa 256 quirksome squares
  Copyright: 
  Author: 3T
  Date: 23/10/10 08:27
  Description: math
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

string R[10];

int main () {
    //freopen("673.INP", "r", stdin);
    //freopen("673.OUT", "w", stdout);
    int N;
          R[2] = "00\n01\n81\n";
          R[4] = "0000\n0001\n2025\n3025\n9801\n";
          R[6] = "000000\n000001\n088209\n494209\n998001\n";
          R[8] = "00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001\n";
    while(scanf("%d",&N) != EOF){
//          int E = 1;
//          int sochia = 1;
//          for(int i = 1; i <= N; i++) {
//                  if(i <= N/2)
//                  sochia *= 10;
//                  E = E * 10;
//                  }
//          E--;
//         // printf("sochia: %d, E = %d\n",sochia,E);
//          for(int i = 0; i <= E; i++){
//                  int D = i % sochia;
//                  int M = i / sochia;
//                  if((D + M) * (D + M) == i) printf("%d\n",i);
//                  }  
          cout << R[N]; 
          }
    
    return 0;
    }
