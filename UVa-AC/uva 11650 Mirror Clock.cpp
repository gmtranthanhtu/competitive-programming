/*
  Name: UVa 11650 Mirror Clock
  Copyright: 
  Author: 3T
  Date: 29/06/10 02:48
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int H,M,n;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
            scanf("%d:%d",&H,&M);
            if(M == 0){
                 if(H == 0) H = 12;
                 else if(H != 12 && H != 6) H = 12 - H;
                 }
            else{
                 M = 60 - M;
                 if(H == 0 || H == 12) H = 11;
                 else if(H == 11) H = 12;
                 else {
                      H = 11 - H;
                      }
                 }
            if(H < 10) printf("0%d:",H);
            else printf("%d:",H);
            if(M < 10) printf("0%d\n",M);
            else printf("%d\n",M);
            }
    return 0;
    }
