/*
  Name: UVa 10109 Solving System of Linear Equations
  Copyright: 
  Author: 3T
  Date: 08/07/10 00:48
  Description: Gaussian Elimination Method, string, fraction
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define INP "10109.INP"
#define MAXLEN 1001
#define MAX 55
#define FType long long

typedef struct Fraction{
        FType Nume,Deno;
        };
Fraction F00 = {0,1},F01 = {1,1},F_1 = {-1,1};

FType GCD(FType a, FType b)
{
    while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return (FType)abs(b);
		b = b % a;
        if( b == 0 )
			return (FType)abs(a);
    }
}

bool Equal0(Fraction F){
     return (F.Nume) ? false : true;
     }

Fraction simplifyFraction(Fraction F){
         if(F.Deno < 0){
                   F.Nume *= -1;
                   F.Deno *= -1;
                   }
         while(F.Nume != 0 && F.Deno != 1 && GCD(F.Nume,F.Deno) != 1){
                      FType Temp = GCD(F.Nume,F.Deno);
                      F.Nume = F.Nume / Temp;
                      F.Deno = F.Deno / Temp;
                      }
         if(F.Nume == 0) F.Deno = 1;
         return F;
         }
     
Fraction plusFraction(Fraction F1, Fraction F2){
         Fraction F3;
         if(F1.Deno == F2.Deno){
                    F3.Nume = F1.Nume + F2.Nume;
                    F3.Deno = F1.Deno;
                    }
         else{
              F3.Deno = F1.Deno * F2.Deno;
              F3.Nume = F1.Nume * F2.Deno + F2.Nume * F1.Deno;
              }
         return simplifyFraction(F3);
         }
         
Fraction subtractFraction(Fraction F1, Fraction F2){
         F2.Nume *= -1;
         return plusFraction(F1, F2);
         }
         
         
bool Equal(Fraction F1, Fraction F2){
     return (simplifyFraction(F1).Nume == simplifyFraction(F2).Nume && simplifyFraction(F1).Deno == simplifyFraction(F2).Deno) ? true : false;
     }

Fraction multiplyFraction(Fraction F1, Fraction F2){
         Fraction F3 = {F1.Nume * F2.Nume, F1.Deno * F2. Deno};
         return simplifyFraction(F3);
         }
         
Fraction reverseFraction(Fraction F){
         swap(F.Nume, F.Deno);
         if(F.Deno < 0){
                   F.Nume *= -1;
                   F.Deno *= -1;
                   }
         return simplifyFraction(F);
         }

void printFraction(Fraction F){
     F = simplifyFraction(F);
     if(F.Nume == 0) {
               printf("0");
               return;
               }
     if(F.Deno == 1){
               printf("%lld",F.Nume);
               return;
               }
     printf("%lld/%lld",F.Nume,F.Deno);  // -----> presentation here when I use &I64d, I don't know why
     }

Fraction getFraction(char S[MAXLEN]){
         Fraction F;
         bool fr = false;
         FType mark = 1,Temp = 0;
         for(int i = 0; i < strlen(S);i++){
                 if(S[i] == '-') mark *= -1;
                 if(S[i] >= '0' && S[i] <= '9'){
                         Temp = Temp * 10 + S[i] - '0';
                         }
                 if(S[i] == '/'){
                         F.Nume = Temp * mark;
                         Temp = 0;
                         mark = 1;
                         fr = true;
                         }
                 if(i == strlen(S) - 1){
                      if(!fr){
                              F.Nume = Temp * mark;
                              F.Deno = 1;
                              }
                      else F.Deno = Temp * mark;
                      }
                 }
         return F;
         }

// get ABS
Fraction getABS(Fraction F){
     F.Nume = (FType) abs(F.Nume);
     F.Deno = (FType) abs(F.Deno);
     return F;
     }    
     
//check whether F greater than 0
bool greater0(Fraction F){
     if(Equal0(F)) return false;
     else{
          F = simplifyFraction(F);
          return (F.Nume > 0) ? true : false;
          }
     }
     
//check whether F1 greater than F2
bool greaterF(Fraction F1, Fraction F2){
     Fraction F = subtractFraction(F1,F2);
     return greater0(F);
     }

//variable declaration
int N,U,E;
char line[MAXLEN];
Fraction G[MAX][MAX],Answer[MAX];

int main () {
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    int stupid_line = 0;
    while(fscanf(f,"%d",&N) && N){
          fscanf(f,"%d%d",&U,&E);
          fgets(line,MAXLEN,f);
          for(int i = 1; i <= E; i++){
                  for(int j = 1; j <= U + 1; j++){
                          fscanf(f,"%s",&line);
                          //get fraction
                          G[i][j] = getFraction(line);
                          }
                  } 

          int i(1), j(1);
          while(i <= E && j <= U){
                  int maxi = i;
                  for(int k = i + 1; k <= E; k++){
                          if(greaterF(getABS(G[k][j]),getABS(G[maxi][j]))){
                                                                          maxi = k;
                                                                          }
                          }
                  if(!Equal0(G[maxi][j])){
                                          for(int k = 1; k <= U + 1; k++){
                                                  swap(G[maxi][k],G[i][k]);
                                                  }
                                          Fraction Temp = reverseFraction(G[i][j]);
                                          for(int k = 1; k <= U + 1; k++){
                                                  G[i][k] = multiplyFraction(G[i][k],Temp);
                                                  }

                                          for(int u = i + 1; u <= E; u++){
                                                  Fraction Temp1 = multiplyFraction(G[u][j],G[i][j]);
                                                  for(int k = 1; k <= U + 1; k++){
                                                          Fraction Temp = multiplyFraction(Temp1,G[i][k]);
                                                          G[u][k] = subtractFraction(G[u][k],Temp);
                                                          }
                                                  }

                                          i++;
                                          }
                  j++;
                  }
           //yes or no
           int not0 = 0,Arbitrary;
           bool nosolution(false),noanswer(false);
           for(i = 1; i <= E; i++){
                   for(j = 1; j <= U; j++){
                           if(!Equal0(G[i][j])){
                                                not0++;
                                                break;
                                                }
                           }
                   if(j == U + 1){
                        if(!Equal0(G[i][j])){
                                             nosolution = true;
                                             break;
                                             }
                        }
                   }
                   
           if(!nosolution){
                           if(not0 != U){
                                   noanswer = true;
                                   Arbitrary = U - not0;
                                   }
                           }
           if(!noanswer){
                         Answer[U] = G[U][U + 1];
                         for(i = U - 1; i >= 1; i--){
                               Fraction Temp = F00;
                               for(j = i + 1; j <= U; j++){
                                     Fraction Temp1 = multiplyFraction(G[i][j],Answer[j]);
                                     Temp = plusFraction(Temp,Temp1);
                                     }
                               Answer[i] = subtractFraction(G[i][U + 1],Temp);
                               }
                         }
                  
          //output
          if(stupid_line > 0) {fgets(line,MAXLEN,f);printf("\n");}
          stupid_line++;
          printf("Solution for Matrix System # %d\n",N);
           if(nosolution) printf("No Solution.\n");
           else if(noanswer) printf("Infinitely many solutions containing %d arbitrary constants.\n",Arbitrary);
           else {
                for(i = 1; i <= U; i++){
                      printf("x[%d] = ",i);
                      printFraction(Answer[i]);
                      printf("\n");
                      }
                }
          }
//    getchar();
    return 0;
    }
