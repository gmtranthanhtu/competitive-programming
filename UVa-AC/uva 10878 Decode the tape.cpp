/*
  Name: UVa 10878 Decode the tape   
  Copyright: 
  Author: 3T
  Date: 07/12/10 17:38
  Description: string
*/
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

char S[100];
int Mu2[]={1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int Convert(){
    int R = 0;
    int Mu = 0;
    for(int i = 9; i >= 1; i--){
        if(S[i] == ' '){
            Mu++;
            }
        else if(S[i] == 'o'){
            R = R + Mu2[Mu];
            Mu++;
            }
        }
    return R;
    }

int main (){
    //freopen("10878.INP", "r", stdin);
    //freopen("10878.OUT", "w", stdout);
    int Num = 0;
    while(1){
        gets(S);
        if(strcmp(S, "___________") == 0) {Num++; if(Num == 1) continue;
        else if(Num == 2) break;}
        int Ans = Convert();
        printf("%c",Ans);
        }
        
    return 0;
    }
