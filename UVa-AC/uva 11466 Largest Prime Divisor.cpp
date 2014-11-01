/*
  Name: UVa 11466 Largest Prime Divisors
  Copyright: 
  Author: 3T
  Date: 23/05/11 05:24
  Description: Sieve, prime, divisor
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;

const long long a = 100000000000000ll;
#define  MAX 10000000
#define N 664579

bool prime[MAX];
int Prime[N + 5];
long long l, Ans;

void Gen(){
    int t = 0;
    memset(prime, true, sizeof prime);
    prime[1] = false;
    for(int i = 2; i * i <= MAX; i++){
        if(!prime[i]) continue;
        for(int j = 2; j * i <= MAX; j++){
            prime[i * j] = false;
            }
        }   
    for(int i = 1; i <= MAX; i++){
        if(prime[i]){
            t++;
            Prime[t] = i;
            }
        }         
    }
    
void Process(){
    if(l < 0) l *= -1;
    int Num(0);
    for(int i = 1; i <= N; i++){
        if(l < Prime[i]) break;
        if(l % Prime[i] == 0){
            Num++;
            Ans = Prime[i];
            while(l % Prime[i] == 0) l /= Prime[i];
            }
        }
    if(l != 1){
        Num++;
        Ans = max(Ans, l);
        }
    if(Num <= 1) Ans = -1;
    }


int main () {
    //freopen("11466.INP", "r", stdin); freopen("11466.OUT", "w", stdout);
    Gen();
    while(cin >> l && l){
        Process();
        cout << Ans << endl;
        }
    return 0;
    }
