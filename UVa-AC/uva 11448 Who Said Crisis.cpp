/*
  Name: UVa 11448 Who Said Crisis
  Copyright: 
  Author: 3T
  Date: 15/07/10 23:42
  Description: bignum
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define MAX 10010
typedef struct CC{
        char Value[MAX];
        bool Pos;
        };
CC C;
int T;
char A[MAX], B[MAX];

bool greaterBig(char A[MAX], char B[MAX]){
     int sA = strlen(A);
     int sB = strlen(B);
     if(sA > sB) return true;
     if(sB > sA) return false;
     for(int i = 0; i < sA; i++){
             if(A[i] > B[i]) return true;
             if(A[i] < B[i]) return false;
             }
     return false;
     }

void reverseBig(char A[MAX]){
     int s = strlen(A);
     if(s > 1){
     for(int i = 0; i <= (s - 1) / 2; i++) swap(A[i],A[s - 1 - i]);}
     }

void subtractBig(char A[MAX], char B[MAX]){
     reverseBig(A);
     reverseBig(B);
     int s1 = strlen(A);
     int s2 = strlen(B);
     int r = 0;
     for(int i = 0; i < s2; i++){
             int temp1 = A[i] - '0';
             int temp2 = B[i] - '0';
             temp2 += r;
             if(temp1 >= temp2){
                      int tmp = temp1 - temp2;
                      C.Value[i] = tmp + '0';
                      r = 0;
                      }
             else{
                  temp1 += 10;
                  int tmp = temp1 - temp2;
                  C.Value[i] = tmp + '0';
                  r = 1;
                  }
             }
     if(s1 > s2){
           for(int i = s2; i < s1; i++){
                   int temp1 = A[i] - '0';
                   if(temp1 >= r){
                            int tmp = temp1 - r;
                            C.Value[i] = tmp + '0';
                            r = 0;
                            }
                   else{
                        temp1 += 10;
                        int tmp = temp1 - r;
                        C.Value[i] = tmp + '0';
                        r = 1;
                        }
                   }
           }

     }

void printBig(CC C){
     int k,i;
//     if(!C.Pos) printf("-");
     for(i = MAX - 1; i >= 0; i--){
             if(C.Value[i] != '0'){
                           k = i;
                           break;
                           }
             }
     if(i <= -1){
          printf("0");
          return;
          }
     if(!C.Pos) printf("-");
     for(i = k; i >= 0; i--){
             printf("%c",C.Value[i]);
             }
     }

int main (){
    char line[100];
    scanf("%d",&T);
    gets(line);
    for(int i = 1; i <= T; i++){
       scanf("%s %s",&A,&B);
       memset(C.Value,'0', sizeof C.Value);
 //      for(int i = 0; i <= 104; i++) C.Value[i] = '0';
       if(greaterBig(B,A)){
                           C.Pos = false;
                           subtractBig(B, A);
                           }
       else{
            C.Pos = true;
            subtractBig(A, B);
            }
       printBig(C);
       printf("\n");
       }
    return 0;
    }
