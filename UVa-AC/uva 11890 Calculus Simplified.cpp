/*
  Name: UVa 11890  Calculus Simplified
  Copyright: 
  Author: 3T
  Date: 31/10/10 10:07
  Description: ad hoc
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 100005

int T, N, len, l, nega, R, Top, Temp;
int X[50010], Dien[50010];
char line[10], S[MAX];

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        //gets(line);
        scanf(" ");
        gets(S);
        //puts(S);
        scanf("%d",&N);
        for(int j = 1; j <= N - 1; j++){
            scanf("%d",&X[j]);
            }
        scanf("%d",&X[N]);
        sort(X + 1, X + N + 1);
        //danh dau
        nega = 0;
        len = strlen(S);
        l = 0;
        Top = 0;
        for(int j = 0; j < len; j++){
            if(S[j] == '('){
                if(j == 0){
                   Dien[++Top] = 1;
                    }
                else
                    if(S[j - 1] == '-'){
                        Dien[++Top] = -1;
                        l++;                        
                        }
                    
                else{
                    Dien[++Top] = 1;
                    }
                }
                
            else if(S[j] == ')'){
                if(Dien[Top] > 0){
                    Top--;
                    }
                else if(Dien[Top] < 0){
                    Top--;
                    l--;
                    }
                }
           else if(S[j] == '+' && l % 2){
                nega++;
                }
           else if(S[j] == '-' && l % 2 == 0)nega++;
            }
        //cal
        R = 0;
        for(int j = 1; j <= nega; j++){
            R -= X[j];
            }
        for(int j = nega + 1; j <= N; j++) R += X[j];
        
        printf("%d\n",R);
        }
    
    return 0;
    }
