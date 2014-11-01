#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

int N, len, si;
unsigned long int Total;
char S[25];
bool Check[25];

unsigned long int Giaithua(int n){
         if(n == 0 || n == 1) return 1;
         else return n * Giaithua(n - 1);
         }

unsigned long int Tohop(int t, int n){
     return Giaithua(n) / Giaithua(t) / Giaithua(n - t);
     }

int main () {
    cin >> N;
    for(int i = 1; i <= N; i++){
           // getline(cin, S);
            cin >> S;
            si = 0;
            Total = 1;
            len = strlen(S);
            memset(Check, false, sizeof Check);
            for(int j = 0; j < len; j++){
                    if(Check[j]) continue;
                    else{
                         Check[j] = true;
                         char a = S[j];
                         int t = 0;
                         for(int k = j; k < len; k++){
                                 if(S[k] == a) {t++; Check[k] = true;}
                                 }
                           //      cout << t << endl;
                         if(t == 1) {si++;}
                         else{
                              Total *= Tohop(t, len);
                              }
                         }
                    }
           // cout << si<< endl;
            Total *= Giaithua(si);
            cout << "Data set " << i << ": " << Total << endl;
            }
    
    return 0;
    }
