#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef unsigned long long mt;
int Base, Num2[100], N;
mt m, Remainder;
char line[1500], Num[1010], M[50];

mt Pow(int x, int y){
    mt R = 1;
    if(y == 0) return 1;
    else{
         for(int i = 1; i <= y; i++) R *= x;
         }
    return R;
    }

int Convert(){
    int len = strlen(M);
    mt R = 0;
    int Mu = len - 1;
    for(int i = 0; i < len; i++){
            int Tmp = M[i] - '0';
            R = R + Tmp * Pow(Base, Mu);
            Mu--;
            }
    return R;
    }
    
mt BigMod(int p, int k, int q){
    if(k == 0){
         return 1;
         }
    if(k % 2 == 0){
         int Tmp = BigMod(p, k/2, q);
         return (Tmp * Tmp) % q;
         }
    else{
         return ((p % q) * BigMod(p, k - 1, q)) % q;
         } 
    }
    
void findRemainder(){
     Remainder = 0;
     int len = strlen(Num);
     //printf("len: %d\n",len);
     int Mu = len - 1;
     for(int i = 0; i < len; i++){
             int Tmp = Num[i] - '0';
          //   printf("%d\n",Tmp);
             if(Tmp == 0){
                    Mu--;
                    continue;
                    }
             //mt TmpBM = BigMod(Base, Mu, m);
             //cout << Base << " " << Mu << " " << m << " ";
             //cout << TmpBM << endl;
             mt Tmp2 = ((Tmp % m) * BigMod(Base, Mu, m)) % m;
             //printf("Tmp2: "); cout << Tmp2 << endl;
             Remainder = Remainder + Tmp2;
             Mu--;
             //if(Remainder > m) Remainder = Remainder % m;
            // printf("R: %I64d\n",Remainder);
             }
     Remainder = Remainder % m;
     }
     
void Convert2(){
     mt V = Remainder;
     N = 0;
     while(V > 0){
             N++;
             Num2[N] = V % Base;
             V /= Base;
             }
     if(N == 0){
          N++;
          Num2[N] = 0;
          }
     }

int main () {
    while(1){
             gets(line);
             if(strcmp(line, "0") == 0) break;
             sscanf(line, "%d %s %s",&Base, &Num, &M);
             //Convert M
             m = Convert();
             //printf("m: %d\n",m);
             findRemainder();
             Convert2();
             for(int i = N; i >= 1; i--){
                     printf("%d",Num2[i]);
                     }
             printf("\n");
             }
    return 0;
    }
