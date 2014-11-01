#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

string S[10];
int t = 0, Ans, Case(0);

bool Check(){
     for(int i = 1; i <= t; i++){
             for(int j = 1; j <= t; j++){
                     if(i == j) continue;
                     int leni = S[i].length();
                     int lenj = S[j].length();
                     if(leni == lenj) continue;
                     size_t Found;
                     int F;
                     if(leni > lenj){
                             Found = S[i].find(S[j]);
                             F = (int)Found;
                             if(F == 0) return false;
                             }
                     else{
                             Found = S[j].find(S[i]);
                             F = (int)Found;
                             if(F == 0) return false;                          
                          }
                     }
             }
     return true;
     }

int main () {
    //freopen("644.OUT", "r", stdin);
    //freopen("644.INP","w", stdout);
    while(cin >> S[++t]){
             if(S[t].compare("9") == 0){
                                  Case++;
                                  t--;
                                  //printf....
                                  printf("Set %d is ",Case);
                                  printf(Check() ? "immediately decodable\n" : "not immediately decodable\n");
                                  t = 0;
                                  continue;
                                  }
             }
    return 0;
    }
