/*
  Name: UVa 10008 What's Cryptanalysis
  Copyright: 
  Author: 3T
  Date: 23/10/10 08:55
  Description: string
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct FF{
        int Count;
        int Index;
        };

FF F[27];

int N;
char line[10];
string S;

void Init(){
     for(int i = 0; i <= 25; i++){
             F[i].Index = i;
             F[i].Count = 0;
             }
     }

int toI(char c){
    if(c >= 'A' && c <= 'Z') return (int)c - 65;
    if(c >= 'a' && c <= 'z') return (int)c - 97;
    }

void Sort(){
     for(int i = 0; i < 25; i++)
         for(int j = 25; j >= i + 1; j--){
                 if((F[j].Count > F[j - 1].Count) || (F[j].Count == F[j - 1].Count && F[j].Index < F[j - 1].Index)) swap(F[j], F[j - 1]);
                 }
     }

int main () {
    //freopen("10008.INP","r", stdin);
    //freopen("10008.OUT", "w", stdout);
    Init();
    scanf("%d",&N);
    gets(line);
    for(int i = 1; i <= N; i++){
            getline(cin, S);
            for(int i = 0; i < S.length(); i++){
                    if((S[i] >= 'A' && S[i] <= 'Z') || (S[i] >= 'a' && S[i] <= 'z')){
                             F[toI(S[i])].Count++;
                             }
                    }
            }
    Sort();
    for(int i = 0; i < 26; i++) {
            if(F[i].Count == 0) break;
            printf("%c %d\n",F[i].Index + 65,F[i].Count);
            }
    return 0;
    }
