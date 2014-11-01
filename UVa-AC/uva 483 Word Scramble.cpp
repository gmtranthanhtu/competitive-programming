/*
  Name: UVa 483 Word Scramble
  Copyright: 
  Author: 3T
  Date: 06/12/10 21:42
  Description: string
*/
#include <stdio.h>
#include <string.h>

char line[1010], Tmp;

void Reverse(int s, int d){
    if(s == d) return;
    for(int i = 0; i <= (d - s) / 2; i++){
        Tmp = line[s + i];
        line[s + i] = line[d - i];
        line[d - i] = Tmp; 
        }
    }

void Solve(){
    int len = strlen(line) - 1;
    int s, d;
    s = 0;
    for(int i = 0; i <= len; i++){
        if(i == len){
            d = i;
            Reverse(s, d);
            }
        else if(line[i] == ' '){
            d = i - 1;
            Reverse(s, d);
            s = i + 1;
            }
        }
    }


int main () {
  //  freopen("483.INP", "r", stdin); freopen("483.OUT", "w", stdout);
    while(gets(line)){
        Solve();
        puts(line);
        }
    return 0;
    }
