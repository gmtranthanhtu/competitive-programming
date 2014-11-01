#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;

#define BIG 5000000

int L[50],T,a,k;
long long Result;

void Sort(){
     for(int i = 1; i < k; i++){
             for(int j = k; j > i; j--){
                     if(L[j] > L[i]) swap(L[j], L[i]);
                     }
             }
     }
     
long long Pow(int A, int N){
     if(!N) return 1;
     long long R = 1;
     for(int i = 1; i <= N; i++){
             R = R * A;
             }
     return R;
     }

int main () {
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            k = 1;
            while(scanf("%d",&a) && a){
                 L[k++] = a;                
                 }
            k--;
            Sort();
            Result = 0;
            for(int j = 1; j <= k; j++){
                    Result = Result + (2 * Pow(L[j], j));
                    if(Result > BIG) break;
                    }
            if(Result <= BIG) cout << Result << endl;
            else cout << "Too expensive\n";
            }
    return 0;
    }
