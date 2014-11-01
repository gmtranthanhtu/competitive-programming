/*
  Name: UVa 10137 The Trip
  Copyright: 
  Author: 3T
  Date: 12/12/10 09:36
  Description: ad hoc
*/
#include <stdio.h>
#include <algorithm>

using namespace std;

int N, M[1010], Avg, Pen, a, b, Sum, Ans;
double AA;

bool myfun(int a, int b){
    return b < a;
    } 

int main () {
    while(scanf("%d",&N) && N){
        Sum = 0;
        Ans = 0;
        for(int i = 1; i <= N; i++){
            scanf("%d.%d",&a,&b);
            int Tmp = a * 100 + b;
            M[i] = Tmp;
            Sum += Tmp;
            }
        Avg = Sum / N;
        Pen = Sum % N;
      //  printf("Avg: %d, Pen: %d\n",Avg,Pen);
        sort(M + 1, M + N + 1, myfun);
        int S = 1; 
        int E = N;
        bool Stop = false;
        for(int i = 1; i <= N; i++){

            if(Stop) break;
            int Tmp2 = 0;
            if(Pen){
                if(M[i] > Avg + 1){
                    Tmp2 = M[i] - (Avg + 1);
                    M[i] = Avg + 1;
                  //  Ans += Tmp2;
                    Pen--;
                    }
                }
            else{
                if(M[i] > Avg){
                    Tmp2 = M[i] - Avg;
                  //  Ans += Tmp2;
                    M[i] = Avg;
                    }
                }
            if(!Tmp2) continue;

            for(int l = N; l >= 1; l--){
                if(Tmp2 == 0) break;
                if(M[l] < Avg){
                    int Tmp3 = M[l] + Tmp2;
                    if(Tmp3 >= Avg){
                        Ans += (Avg - M[l]);                        
                        M[l] = Avg;
                        Tmp2 = Tmp3 - Avg;                        
                        }
                    else{
                        M[l] = M[l] + Tmp2;
                        Ans += Tmp2;
                        Tmp2 = 0;
                        }
                    }
                } 
            }
        if(Pen) Ans += Pen;
        AA = (double) Ans / 100.0;
        printf("$%.2lf\n",AA);
    }
    
    return 0;
    }
