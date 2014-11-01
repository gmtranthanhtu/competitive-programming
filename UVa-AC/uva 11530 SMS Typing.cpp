/*
  Name: UVa 11530 SMS Typing
  Copyright: 
  Author: 3T
  Date: 05/07/10 02:00
  Description: string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
//    printf("%d\n",'a'); 97
//    printf("%d\n",'z'); 122 
//    printf("%d\n",' '); 32
    int M[123],N,R;
    char line[200];
    for(int i = 1; i <= 122; i++){
            if((char) i == 'b' || (char) i == 'e' ||(char) i == 'h' || (char) i == 'k' || (char) i == 'n' || (char) i == 'q' ||
                 (char) i == 'u' || (char) i == 'x') M[i] = 2;
            else if((char) i == 'c' || (char) i == 'f' ||(char) i == 'i' || (char) i == 'l' || (char) i == 'o' || (char) i == 'r' ||
                 (char) i == 'v' || (char) i == 'y') M[i] = 3;
            else if((char) i == 's' || (char) i == 'z') M[i] = 4;
            else M[i] = 1; 
            }
    scanf("%d",&N);
    gets(line);
    for(int i = 1; i <= N; i++){
            gets(line);
            R = 0;
            for(int j = 0; j < strlen(line); j++){
                    R += M[(int)line[j]];
                    }
            printf("Case #%d: %d\n",i,R);
            }
    
//    getchar();
    return 0;
    }
