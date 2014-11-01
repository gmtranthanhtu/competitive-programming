#include <stdio.h>

int Emp, R;

int main () {
    while(scanf("%d",&Emp) != EOF){
          R = Emp;
          while(Emp >= 3){
                    R += Emp / 3;
                    Emp = Emp / 3 + Emp % 3;
                    }                  
          if(Emp == 2) R++;
          printf("%d\n",R);
          }
    
    
    return 0;
    }
