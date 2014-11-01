#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
using namespace std;

int main () {
    //freopen("272.INP", "r", stdin);
   // freopen("272.OUT", "w", stdout);
    string A;
    char c;
    int t = 1;
    while(getline(cin, A)){
           int lena = A.length();
           for(int i = 0; i < lena; i++){
           if(A[i] != '"') printf("%c",A[i]);
           else{
                printf(t ? "``" : "''");
                t = t ? 0 : 1;
                }
              }  
           printf("\n");            
           }
    return 0;
    }
