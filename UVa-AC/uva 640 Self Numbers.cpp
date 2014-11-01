/*
  Name: UVa 640 Self number
  Copyright: 
  Author: 3T
  Date: 11/12/10 16:00
  Description: ad hoc
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000000

bool Pass[MAX + 5];

void Run(int i){
    int Tmp = i;
    while(i > 0){
        Tmp += (i % 10);
        i /= 10;
        }
    if(Tmp > MAX) return;
    Pass[Tmp] = true;
    //Run(Tmp);
    }

int main () {
    for(int i = 1; i <= MAX; i++) Pass[i] = false;
    for(int i = 1; i <= MAX; i++){
        if(!Pass[i]) printf("%d\n",i);
        Run(i);
        }
    //system("pause");
    return 0;
    }
