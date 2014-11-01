/*
  Name: UVa 11660 Look and Say Sequences
  Copyright: 
  Author: 3T
  Date: 04/06/10 00:18
  Description: string
*/
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 1000

string x;
int i,j;

string generateSequence(string x, int i){
       string temp = "";
       for(int loop = 1; loop < i; loop++){
               char tempchar = x[0];
               int position = 0;
               int count = 1;
               while(temp.size() <= MAX && position < x.size()){
                                 position++;
                                 if(tempchar == x[position]){
                                            count++;
                                            }
                                 else{
                                      temp += count + '0';
                                      temp += tempchar;
                                      tempchar = x[position];
                                      count = 1;
                                      }
                                 }
               x = temp;
               temp = "";
               }
       return x;
       }






int main () {
    while (cin >> x >> i >> j){
          if(x == "0" && i == 0 && j == 0) break;
          else  cout << generateSequence(x, i)[j - 1] << endl;
          }
    return 0;
    }
