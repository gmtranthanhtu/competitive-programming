#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
    int M[1005][1005];

int main () {
    string a, b;
    int lena, lenb, t, Total;

    //bool Exist;
    while(getline(cin, a)){
                       getline(cin, b);
              lena = a.length();
              lenb = b.length();
              //memset(M, 0, sizeof M);
              for(int i = 1; i <= lena; i++) M[i][0] = 0;
              for(int i = 0; i <= lenb; i++) M[0][i] = 0;
              for(int i = 1; i <= lena; i++){
                      for(int j = 1; j <= lenb; j++){
                              if(a[i - 1] == b[j - 1]){
                                     M[i][j] = M[i - 1][j - 1] + 1;
                                     }
                              else{
                                   M[i][j] = max(M[i - 1][j], M[i][j - 1]);
                                   }
                              }
                      } 
              //t = 0;
//              Total = 0;
//              for(int i = 0; i < lena; i++){
//                    //  Exist = false;
//                      for(int j = t; j < lenb; j++){
//                              if(a[i] == b[j]){
//                                      Total++;
//                                      t = j + 1;
//                                      break;
//                                      }
//                              }
//                      }
              printf("%d\n",M[lena][lenb]);
              }
    return 0;
    }
