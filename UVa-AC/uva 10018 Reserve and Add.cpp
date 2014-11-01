#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

typedef long long mt;

int T, Time;
mt N, Mu10[20], So[20], Ans;

void Init() {
     Mu10[0] = 1;
     for(int i = 1; i <= 15; i++){
             Mu10[i] = Mu10[i - 1] * 10;
             }     
     }
     
mt Convert(mt a){
     int Tmp = 0;
     while(a >= 10){
             So[Tmp++] = a % 10;
             a = a / 10;
             }         
     So[Tmp] = a;
     mt b = 0;
     int Loop = Tmp;
     for(int i = 0; i <= Loop; i++){
             b = b + So[i] * Mu10[Tmp];
             Tmp--;
             }
     return b;
     }
     
void runProcess(){
     Ans = Convert(N);
     while(Ans != N){
               N = N + Ans;
               Ans = Convert(N);
               Time++;
               }
     }

int main () {
    Init();
    cin >> T;
    for(int i = 1; i <= T; i++){
            cin >> N;
            Time = 0;
            runProcess();
            cout << Time << " " << Ans << endl;
            }
    return 0;
    }
