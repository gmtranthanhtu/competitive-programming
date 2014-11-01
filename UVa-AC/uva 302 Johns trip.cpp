/*
  Name: UVa 302 John's trip
  Copyright: 
  Author: 3T
  Date: 25/06/10 22:24
  Description: Euler, DPS
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

#define INP "302.INP"
#define MAXN 2000
#define MAXM 50
stack <int> Answer;
typedef struct Street{
        int s1;
        int s2;
        };
Street S[MAXN];
bool Used[MAXN];
int OK[MAXM];
int a,b,c,Start,n,m;

//DPS
void processEuler(int u, int last){
     for(int i = 1; i <= n; i++){
             if(!Used[i] && S[i].s1 == u){
                         Used[i] = true;
                         processEuler(S[i].s2, i);
                         }
             else if(!Used[i] && S[i].s2 == u){
                         Used[i] = true;
                         processEuler(S[i].s1, i);
                         }
             }
     Answer.push(last);
     }

int main () {
  //  FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d%d",&a,&b) == 2 && a && b){
         memset(Used,false,sizeof(Used));
         memset(OK,0,sizeof(OK));
         Start = min(a,b);
         fscanf(f,"%d",&c);
         S[c].s1 = a; S[c].s2 = b; OK[a]++; OK[b]++;
         n = 1;
         m = max(a,b);
         while(fscanf(f,"%d%d",&a,&b)== 2 && a && b){
               fscanf(f,"%d",&c);
               S[c].s1 = a; S[c].s2 = b; OK[a]++; OK[b]++;
               n++;
               m = max(m,max(a,b));                   
               }
         //check whether Eucler circle existed
         bool Existed(true);
         for(int i = 1; i <= m; i++){
                 if(OK[i] % 2){
                          Existed = false;
                          break;
                          } 
                 }
         //output
         if(!Existed){
                      cout << "Round trip does not exist." << endl << endl;
                      }
         else{
              //cout << "process later." << endl << endl;
              processEuler(Start,-1);
              Answer.pop(); //delete -1
              cout << Answer.top();
              Answer.pop();
              while(!Answer.empty()){
                                     cout << " " << Answer.top();
                                     Answer.pop(); 
                                     }
              cout << endl << endl;
              }                        
         }
//    getchar();
    return 0;
    }
