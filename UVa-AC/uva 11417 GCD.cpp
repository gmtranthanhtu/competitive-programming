
#include <stdio.h>

int a;

int GCD(int a, int b){
       return (!a) ? b : GCD(b%a, a);
    }

int TotGCD(int a){
    int G=0;
      for(int i=1;i<a;i++)
       for(int j=i+1;j<=a;j++)
       {
    G += GCD(i,j);
        }
    return G;
    }

int main () {
    while(scanf("%d",&a) && a){
            printf("%d\n", TotGCD(a));             
            }
    return 0;
    }
