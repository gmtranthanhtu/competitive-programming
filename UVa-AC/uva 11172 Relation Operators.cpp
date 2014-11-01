#include <stdio.h>

int T, a, b;

char getChar(int a, int b){
     if(a == b) return '=';
     if(a > b) return '>';
     if(a < b) return '<';
     }

int main (){
    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
            scanf("%d%d",&a,&b);
            printf("%c\n",getChar(a,b));
            }
    return 0;
    }
