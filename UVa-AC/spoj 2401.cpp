#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int Mina, Minb, a, b, N;

int main (){
    scanf("%d",&N);
    Mina = 1000000001;
    Minb = 1000000001;
    for(int i = 1; i <= N; i++){
        scanf("%d",&a);
        Mina = min(Mina, a);
        }
    for(int i = 1; i <= N; i++){
        scanf("%d",&b);
        Minb = min(Minb, b);
        }    
    printf("%d",Mina + Minb);
    //system("pause");
    return 0;
    }
