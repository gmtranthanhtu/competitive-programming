/*
  Name: UVa 10222 Decode the mad man
  Copyright: 
  Author: 3T
  Date: 03/06/10 15:20
  Description: string
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char A[] = {"erty uiop[]dfghjkl;'cvbnm,."};
char B[] = {"qwer tyuiopasdfghjklzxcvbnm"};
char Inp[5000];

int main () {
    int j;
    gets(Inp);
    for(int i = 0; i < strlen(Inp); i++){
            for(j = 0; j < strlen(A); j++){
                    if(tolower(Inp[i]) == A[j]) break;
                    }
            Inp[i] = B[j];
            }
    puts(Inp);
//    getchar();
    return 0;
    }
