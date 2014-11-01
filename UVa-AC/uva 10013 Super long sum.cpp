/*
  Name: UVa 10013 Super long sum
  Copyright: 
  Author: 3T
  Date: 23/10/10 09:13
  Description: bignum, addition
*/
#include <iostream>
#include <algorithm>

using namespace std;
int N, M, a, b, Num[1000010], k = 0;

int main () {
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
            scanf("%d",&M);
            for(int j = 1; j <= M; j++){
                    scanf("%d %d",&a,&b);
                    Num[j] = a + b;
                    }
            if(i > 1) printf("\n");
            for(int j = M; j > 0; j--){
                    if(Num[j] >= 10){
                              Num[j] = Num[j] % 10;
                              Num[j - 1]++;
                              }
                    }
            for(int j = 1; j <= M; j++) printf("%d",Num[j]);
            printf("\n");
            }
    
    return 0;
    }
