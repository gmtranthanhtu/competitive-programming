/*
  Name: UVa 11349 Symmetric Matrix
  Copyright: 
  Author: 3T
  Date: 08/04/11 13:50
  Description: ad hoc
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int t, N;
long A[105][105];
char line[50];
bool B;

bool Check(){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            if(A[i][j] != A[N + 1 - i][N + 1 - j]) return false;
            }
        }
    return true;
    }

int main () {
    //freopen("11349.INP", "r", stdin); freopen("11349.OUT", "w", stdout);
    scanf("%d",&t);
    for(int i = 1; i <= t; i++){
        B = true;
        scanf(" ");
        gets(line);
        sscanf(line, "N = %d",&N);
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                scanf("%ld",&A[j][k]);
                if(A[j][k] < 0) B = false;
                }
            }
        if(B){
            B = Check();
            } 
        if(B){
            printf("Test #%d: Symmetric.\n", i);
             } 
        else printf("Test #%d: Non-symmetric.\n", i);
        }
    return 0;
    }
