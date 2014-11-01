/*
  Name: UVa 573 Snail       
  Copyright: 
  Author: 3T
  Date: 06/12/10 22:05
  Description: ad hoc
*/
#include <stdio.h>
#include <math.h>

double H, U, D, F, Fati, Pos;
int Day;

int Solve(){
    Day = 0;
    Pos = 0.0;
    Fati = U * F / 100.0;
    while(1){
        Day++;
        if(Day > 1) U = U - Fati;
        if(U <= 0) U = 0;
        Pos = Pos + U;
        if(Pos > H) return 1;
        Pos = Pos - D;
        if(Pos < 0) return 0;
        }
    }

int main () {
    //freopen("573.INP", "r", stdin); freopen("573.OUT", "w", stdout);
    while(scanf("%lf%lf%lf%lf",&H,&U,&D,&F) && H != 0.0){
        int a = Solve();
        if(a){
            printf("success on day %d\n",Day);
            }
        else printf("failure on day %d\n",Day);
        }
    
    return 0;
    }
