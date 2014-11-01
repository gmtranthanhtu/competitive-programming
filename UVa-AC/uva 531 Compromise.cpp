/*
  Name: UVa 531 Compromise
  Copyright: 
  Author: 3T
  Date: 23/07/11 19:52
  Description: DP, LCS
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

typedef struct Cell{
        int ParX;
        int ParY;
        int Value;
        int Use;
        };
        
Cell DP[200][200];

string S[5][200], Ans[200];
string Line;
char line[1000];
int t = 1, len1 = 0, len2 = 0;

void parseString(){
     size_t Found, Found2;
     string Tmp;
     Found = Line.find(" ");
     while(Found != string::npos){
                 Tmp = Line.substr(0, Found);
                 Line = Line.substr(Found + 1);
                 Found2 = Line.find(" ");
                 while(Found2 == 0){
                              Line = Line.substr(Found2 + 1);
                              Found2 = Line.find(" ");
                              }
                 Found = Line.find(" ");
                 if(Tmp[0] != ' '){
                 if(t == 1){
                      len1++;
                      S[1][len1] = Tmp;
                      }
                 else if(t == 2){
                      len2++;
                      S[2][len2] = Tmp;
                      }
                      }
                 //test
                 }
                 Found2 = Line.find(" ");
                 while(Found2 == 0){
                              Line = Line.substr(Found2 + 1);
                              Found2 = Line.find(" ");
                              }                 
                 if(Line != " " && Line.length() != 0){
                 if(t == 1){
                      len1++;
                      S[1][len1] = Line;
                      }
                 else if(t == 2){
                      len2++;
                      S[2][len2] = Line;
                      }     
                      }
     }
     
void Test(){
     for(int i = 1; i <= len1; i++) cout << S[1][i] << endl; 
     cout << len1 << " " << len2 << endl;
     cout << "2"<< endl;
     for(int i = 1; i <= len2; i++) cout << S[2][i] << endl;
     }     
     
void Test2(){
     for(int i = 1; i <= len1; i++){
             for(int j = 1; j <= len2; j++) printf("%d ",DP[i][j].Value);
             cout << endl;
             }
     }     
     
void Process(){
     //Test();
     memset(DP, 0, sizeof DP);
     for(int i = 1; i <= len1; i++){
             DP[i][0].ParX = 0;
             DP[i][0].ParY = 0;
             DP[i][0].Value = 0;
             DP[i][0].Use = 0;
             }
     for(int i = 1; i <= len2; i++){
             DP[0][i].ParX = 0;
             DP[0][i].ParY = 0;
             DP[0][i].Value = 0;
             DP[0][i].Use = 0;
             }     
             DP[0][0].ParX = 0;
             DP[0][0].ParY = 0;
             DP[0][0].Value = 0;
             DP[0][0].Use = 0;     
             
     //DP
     for(int i = 1; i <= len1; i++){
             for(int j = 1; j <= len2; j++){
                     if(S[1][i] == S[2][j]){
                                DP[i][j].Value = DP[i - 1][j - 1].Value + 1;
                                DP[i][j].ParX = i - 1;
                                DP[i][j].ParY = j - 1;
                                DP[i][j].Use = 1;
                                }
                     else{
                                DP[i][j].Value = DP[i - 1][j - 1].Value;
                                DP[i][j].ParX = i - 1;
                                DP[i][j].ParY = j - 1;
                                DP[i][j].Use = 0;                          
                          }
                     //
                     if(DP[i - 1][j].Value > DP[i][j].Value){
                                DP[i][j].Value = DP[i - 1][j].Value;
                                DP[i][j].ParX = i - 1;
                                DP[i][j].ParY = j;
                                DP[i][j].Use = 0;                              
                             } 
                     if(DP[i][j - 1].Value > DP[i][j].Value){
                                DP[i][j].Value = DP[i][j - 1].Value;
                                DP[i][j].ParX = i;
                                DP[i][j].ParY = j - 1;
                                DP[i][j].Use = 0;                              
                             }                      
                     }
             }
     //Test2();
     int Num = DP[len1][len2].Value;
     int Tmpx = len1, Tmpy = len2;
     while(Num){
                if(DP[Tmpx][Tmpy].Use == 1){
                                      Ans[Num] = S[1][Tmpx];
                                      Num--;
                                      }
                int T1 = Tmpx;
                int T2 = Tmpy;
                Tmpx = DP[T1][T2].ParX;
                Tmpy = DP[T1][T2].ParY;
                }
     for(int i = 1; i <= DP[len1][len2].Value; i++){
             if(i > 1) cout << " ";
             cout << Ans[i];

             }
             cout << endl;
     }

int main () {
    //freopen("531.INP", "r", stdin); freopen("531.OUT", "w", stdout);
    while(getline(cin, Line)){
                       if(Line[0] == '#' && t == 2){
                                  Process();
                                  t = 1;
                                  len1 = 0;
                                  len2 = 0;
                                  continue;
                                  }
                       if(Line[0] == '#' && t == 1){
                                  t++;
                                  continue;
                                  }
                       parseString();                       
                       }    
    return 0;
    }
