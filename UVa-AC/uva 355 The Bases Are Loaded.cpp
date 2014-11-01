/*
  Name: UVa 355 The bases are loaded
  Copyright: 
  Author: 3T
  Date: 23/05/11 20:54
  Description: base conversion
*/
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

#define ll long long

int F, T, len, So;
ll C10;
char S[200];
int Du[200];

int StoN(char c){
    if(c >= '0' && c <= '9') return (c - '0');
    if(c == 'A') return 10;
    if(c == 'B') return 11;
    if(c == 'C') return 12;
    if(c == 'D') return 13;  
    if(c == 'E') return 14;
    if(c == 'F') return 15;      
    }
    
char NtoS(int c){
    if(c >= 0 && c <= 9) return (c + '0');
    if(c == 10) return 'A';
    if(c == 11) return 'B';
    if(c == 12) return 'C';
    if(c == 13) return 'D';  
    if(c == 14) return 'E';
    if(c == 15) return 'F';      
    }

ll Pow(int n, int k){
    ll R = 1;
    for(int i = 1; i <= k; i++){
        R *= n;
        }
    return R;
    }

ll Convert10(){
    ll R = 0;
    for(int i = 0; i < len; i++){
        R = R + (StoN(S[i])) * Pow(F, (len - i - 1));
        }
    return R;
    }
    
bool isLegal(){
    for(int i = 0; i < len; i++){
        if(StoN(S[i]) >= F) return false;
        }
    return true;
    }

void ConvertF(){
    So = 0;
    ll Tmp = C10;
    while(Tmp != 0){
        So++;
        Du[So] = Tmp % T;
        Tmp /= T;
        }
    }

int main () {
    //freopen("355.INP", "r", stdin); freopen("355.OUT", "w", stdout);
    while(scanf("%d%d",&F,&T) != EOF){
        scanf(" ");
        gets(S);
        //printf("%d %d %s\n",F,T,S);
        //process
        len = strlen(S);
        if(!isLegal()){
            printf("%s is an illegal base %d number\n",S,F);
            continue;
            }
        C10 = Convert10();
        //cout << "C10: "<< C10 << endl;
        ConvertF();
        if(So == 0){
            printf("%s base %d = 0 base %d\n",S,F,T);
            }
        else{
            printf("%s base %d = ",S,F);
            for(int i = So; i >= 1; i--){
                printf("%c",NtoS(Du[i]));
                }
            printf(" base %d\n",T);
            }
        }
    
    return 0;
    }
