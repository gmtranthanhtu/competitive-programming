/*
  Name: UVa 10340 All in All
  Copyright: 
  Author: 3T
  Date: 14/09/10 05:09
  Description: string
*/
#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
using namespace std;

int main () {
    string a, b;
    int lena, lenb, t;
    bool Yes, Exist;
    while(cin >> a >> b){
              lena = a.length();
              lenb = b.length();
              Yes = true;
              t = 0;
              for(int i = 0; i < lena; i++){
                      Exist = false;
                      for(int j = t; j < lenb; j++){
                              if(a[i] == b[j]){
                                      t = j + 1;
                                      Exist = true;
                                      break;
                                      }
                              }
                      if(!Exist){
                                 Yes = false;
                                 break;
                                 }
                      }
              printf("%s\n", Yes ? "Yes" : "No");
              }
    return 0;
    }
