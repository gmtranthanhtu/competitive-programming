#include <stdio.h>
#include <algorithm>
#include <math.h>

double getAvg(int T1, int T2, int T3){
       if(T1 <= T2 && T1 <= T3) return (double)(T3 + T2) / 2.0;
       if(T2 <= T3 && T2 <= T1) return (double)(T3 + T1) / 2.0;
       if(T3 <= T2 && T3 <= T1) return (double)(T2 + T1) / 2.0;       
       }
       
char getMark(double Total){
     if(Total >= 90) return 'A';
     if(Total >= 80 && Total < 90) return 'B';
     if(Total >= 70 && Total < 80) return 'C';
     if(Total >= 60 && Total < 70) return 'D';     
     else return 'F';
     }

int main () {
    int T, Term1, Term2, Final, Att, T1, T2, T3;
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d%d%d%d%d%d",&Term1, &Term2, &Final, &Att, &T1, &T2, &T3);
            double Avg = getAvg(T1, T2, T3);
            double Total = Term1 + Term2 + Final + Att + Avg;
            printf("Case %d: %c\n",i,getMark(Total));
            }
    return 0;
    }
