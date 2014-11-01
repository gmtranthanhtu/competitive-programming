/*
  Name: 
  Copyright: 
  Author: 
  Date: 12/11/10 01:40
  Description: NOT AC YET
*/
#include <stdio.h>
#include <iostream>
using namespace std;

typedef long long mt;

mt N;

bool isPrime(mt a){
     if(a == 1) return false;
     if(a == 2) return true;
     if(a % 2 == 0) return false;
     for(mt i = 3; i * i <= a; i++){
            if(a % i == 0) return false;
            }
     return true;
     }

void findXY(){
     mt X = N / 2;
     mt Y = N / 2;
     if(X % 2 == 0){
          X--;
          Y++;
          }
     while(1){
              if(isPrime(X) && isPrime(Y)){
                            cout << X << " and " << Y << "." << endl;
                            return;
                            }
              X -= 2;
              Y += 2;
              }
     }

int main () {
    while(cin >> N){
              if(N == 1 || N == 2 || N == 3 || N == 4) cout << N << " is not the sum of two primes!" << endl;
              else if(N == 5) cout << "5 is the sum of 2 and 3." << endl;
              else if(N % 2) cout << N << " is not the sum of two primes!" << endl;
              else{
                   cout << N <<" is the sum of ";
                   //find
                   findXY();
                   }
              }
    return 0;
    }
