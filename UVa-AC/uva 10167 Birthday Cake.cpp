/*
  Name: UVa 10167 Birthday Cake
  Copyright: 
  Author: 3T
  Date: 26/08/10 11:19
  Description: Geometry, Line
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
#define MAX 500
#define INP "10167.INP"
//#define Pair pair <int, int>

int N,a,b;
pair <int, int> M[110];

void doThat(){
     int j,k;
     for(j = -500; j <= 500; j++){
             for(k = -500; k <= 500; k++){
                   int n(0),p(0);
                   bool equal0(false);
                   for(int i = 1; i <= 2 * N; i++){
                           long tmp = j * M[i].first + k * M[i].second;
                           if(!tmp){
                                    equal0 = true;
                                    break;
                                    }
                           else if(tmp < 0) n++;
                           else p++;
                           }     
                   if(!equal0 && (n == p)){
                              printf("%d %d\n",j,k);
                              return;
                              }
                   }
             }
     }

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d",&N) && N){
            for(int i = 1; i <= 2 * N; i++){
                    fscanf(f,"%d%d",&a,&b);
                    M[i] = make_pair(a, b);
                    }                
            doThat();
            }
//    getchar();
    return 0; 
    }
