/*
  Name: UVa 10261 Ferry Loading
  Copyright: 
  Author: 3T
  Date: 03/06/10 21:35
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

#define INP "10261.INP"
#define MaxCar 200
#define MaxLen 10000

stack <int> Store;

typedef struct Table {
        bool Able;
        int Lane;
        };

int Case,n,Car[MaxCar + 5],temp,Length,N,last,S[MaxCar + 5];
Table M[MaxCar + 5][MaxLen + 5];

void printLane(int a){
     if(a == 1){
          cout << "port" << endl;
          }
     if(a == 2){
          cout << "starboard" << endl;
          }
     }

int main () {
  //  FILE *f = fopen (INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&Case);
    for(int i = 1; i <= Case; i++){
            if(i > 1) cout << endl;
            fscanf(f,"%d",&Length);
            Length *= 100;
            n = 1;
            S[0] = Car[0] = 0;            
            while(fscanf(f,"%d",&temp) && temp){
                   if(n <= MaxCar){
                        Car[n] = temp;
                        S[n] = S[n - 1] + Car[n];
                        n++;
                        }                    
                   }
            n--;
            N = 0;
            last = 0;
            for(int j = 0; j <= n; j++){
                    for(int k = 0; k <= Length; k ++){
                            M[j][k].Able = false;
                            M[j][k].Lane = 0;
                            }
                    }
            M[0][0].Able = true;
            for(int j = 0; j < n; j++){
                    for(int k = 0; k <= Length; k++){
                            if(M[j][k].Able){
                                if(k + Car[j + 1] <= Length){
                                     M[j + 1][k + Car[j + 1]].Able = true;
                                     M[j + 1][k + Car[j + 1]].Lane = 1;
                                     N = j + 1;
                                     last = k + Car[j + 1];
                                     }  
                                     
                                 if(S[j] - k + Car[j + 1] <= Length){
                                         M[j + 1][k].Able = true;
                                         M[j + 1][k].Lane = 2;
                                         N = j + 1;
                                         last = k;
                                         }           
                                }
                            }
                    }
            cout << N << endl;
            for(int j = N, k = last; j > 0 && M[j][k].Lane ; j--){
                    Store.push(M[j][k].Lane);
                    if(M[j][k].Lane == 1) k = k - Car[j];
                    }
            while(!Store.empty()){
                printLane(Store.top());
                Store.pop();                  
                }
            }   
//    getchar();
    return 0;
    }
