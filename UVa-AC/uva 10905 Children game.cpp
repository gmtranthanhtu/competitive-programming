#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int N;
string M[100];

bool Bigger(string a, string b){      //a placed before b?
     string AF = "";
     AF += a; AF += b;
     string BF = "";
     BF += b; BF += a;
     if(AF > BF) return true;
     return false;
     }

void Sort(){
     for(int i = 1; i < N; i++){
             for(int j = N; j >= i + 1; j--){
                     if(Bigger(M[j], M[j - 1])) swap(M[j], M[j - 1]);
                     }
             }
     }

int main (){
    while(scanf("%d",&N) && N){
           scanf(" ");         
           for(int i = 1; i <= N; i++){
                   cin >> M[i];
                   }
           Sort();
           for(int i = 1; i <= N; i++) cout << M[i];
           printf("\n");              
           }
    
    return 0;
    }
