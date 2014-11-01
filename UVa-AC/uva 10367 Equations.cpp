/*
  Name: UVa 10367 Equations
  Copyright: 
  Author: 3T
  Date: 06/07/10 03:44
  Description: Fraction, Gauss, string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

#define INP "10367.INP"
#define MAXLEN 1001
typedef struct Fraction{
        int Nume,Deno;
        };
Fraction G[3][4];
Fraction F00 = {0,1},F01 = {1,1},F_1 = {-1,1};
typedef struct Equation{
        int x,y,n;
        };
Equation E[3];
int N,mark,temp,markn,constm;
char line[MAXLEN];
bool NumWriting,Infx,Infy;

int GCD(int a, int b)
{
    while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return (int)abs(b);
		b = b % a;
        if( b == 0 )
			return (int)abs(a);
    }
}

bool Equal0(Fraction F){
     return (F.Nume) ? false : true;
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
         return F3;
         }
Fraction subtractFraction(Fraction F1, Fraction F2){
         F2.Nume *= -1;
         return plusFraction(F1, F2);
         }
         
Fraction simplifyFraction(Fraction F){
         while(F.Nume != 0 && F.Deno != 1 && GCD(F.Nume,F.Deno) != 1){
                      int Temp = GCD(F.Nume,F.Deno);
                      F.Nume = F.Nume / Temp;
                      F.Deno = F.Deno / Temp;
                      }
         if(F.Nume == 0) F.Deno = 1;
         return F;
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
//     printf("process later\n");
     F = simplifyFraction(F);
     if(F.Nume == 0) {
               printf("0\n");
               return;
               }
     if(F.Deno == 1){
               printf("%d\n",F.Nume);
               return;
               }
     printf("%d/%d\n",F.Nume,F.Deno);
     }

int main () {
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&N);
//    fgets(line,MAXLEN,f);
    for(int i = 0; i < N; i++){
            fgets(line,MAXLEN,f);
            for(int j = 1; j <= 2; j++){
                    fgets(line,MAXLEN,f);
                    E[j].x = E[j].y = E[j].n = 0;
                    constm = 1;
                    temp = 0;
                    mark = constm;
                    NumWriting = false;
                    int len = strlen(line) - 1;
                    for(int k = 0; k < len; k++){
                            if(line[k] == '='){
                                       constm = -1;
                                       mark = constm;
                                       }
                            if(line[k] == '+'){
                                       mark *= 1;
                                       }
                            if(line[k] == '-') mark *= -1;
                            if(line[k] >= '0' && line[k] <= '9'){
                                       if(k ==len - 1){
                                            temp = temp * 10 + line[k] - '0';
                                            E[j].n += (mark * temp);
                                            }
                                       else{
                                       temp = temp * 10 + line[k] - '0';
                                       NumWriting = true;
                                           }
                                       }
                            if(line[k] == ' ' && NumWriting){
                                       E[j].n += (mark * temp);
                                       mark = constm;
                                       NumWriting = false;
                                       temp = 0;
                                       }
                            if(line[k] == 'x'){
                                       if(NumWriting){
                                                     E[j].x += (mark * temp);
                                                     mark = constm;
                                                     NumWriting = false;
                                                     temp = 0;
                                                      }
                                       else{
                                            temp = 1;
                                            E[j].x += (mark * temp);
                                            mark = constm;
                                            NumWriting = false;
                                            temp = 0;                                            
                                            }
                                       }
                            if(line[k] == 'y'){
                                       if(NumWriting){
                                                     E[j].y += (mark * temp);
                                                     mark = constm;
                                                     NumWriting = false;
                                                     temp = 0;
                                                      }
                                       else{
                                            temp = 1;
                                            E[j].y += (mark * temp);
                                            mark = constm;
                                            NumWriting = false;
                                            temp = 0;                                            
                                            }
                                       }
                            }
                    }
            if(i > 0) printf("\n");
            //fill in Gauss array
             E[1].n *= -1;
             E[2].n *= -1;      
             for(int j = 1; j <= 2; j++){
                     G[j][1].Nume = E[j].x;
                     G[j][2].Nume = E[j].y;
                     G[j][3].Nume = E[j].n;
                     for(int k = 1; k <= 3; k++){
                             G[j][k].Deno = 1;
                             }
                     } 
            //Gauss
            Infx = Infy = false;
            if(Equal0(G[1][1]) && !Equal0(G[2][1])) {
                               for(int j = 1; j <= 3; j++){
                                       swap(G[1][j],G[2][j]);
                                       }
                               }
            if(Equal0(G[1][1]) && Equal0(G[2][1])) Infx = true;
            else if(!Equal0(G[1][1])){ 
                 if(!Equal(G[1][1],F01)){
                           if(Equal(G[1][1],F_1)){
                                                  for(int k = 1; k <= 3; k++){
                                                          G[1][k] = multiplyFraction(G[1][k],F_1);
                                                          }
                                                  }
                           else{
                                Fraction Temp = reverseFraction(G[1][1]);
                                for(int k = 1; k <= 3; k++){
                                        G[1][k] = multiplyFraction(G[1][k],Temp);
                                        }
                                }              
                           }
                 if(!Equal0(G[2][1])){
                                      Fraction Temp = reverseFraction(G[2][1]);
                                      for(int k = 1; k <= 3; k++){
                                        G[2][k] = multiplyFraction(G[2][k],Temp);
                                        }
                                      for(int k = 1; k <= 3; k++){
                                        G[2][k] = subtractFraction(G[1][k],G[2][k]);
                                        }                                      
                                      }
                 }
                 if(Infx){
                          if(Equal0(G[1][2]) && Equal0(G[2][2])){
                                             printf("don't know\n");
                                             printf("don't know\n");
                                             }
                          else{
                               if(!Equal0(G[1][2])){
                                                    Fraction Y = multiplyFraction(G[1][3],reverseFraction(G[1][2]));
                                                    if(Equal(multiplyFraction(Y,G[2][2]), G[2][3])) {
                                                                                         printf("don't know\n");
                                                                                         printFraction(Y);
                                                                                         }
                                                    else{
                                                         printf("don't know\n");
                                                         printf("don't know\n");                                                         
                                                         }
                                                    }
                               else{
                                                    Fraction Y = multiplyFraction(G[2][3],reverseFraction(G[2][2]));
                                                    if(Equal(multiplyFraction(Y,G[1][2]), G[1][3])) {
                                                                                         printf("don't know\n");
                                                                                         printFraction(Y);
                                                                                         }
                                                    else{
                                                         printf("don't know\n");
                                                         printf("don't know\n");                                                         
                                                         }
                                                    }                                    
                                    }
                               }                                                
                 else{
                 if(Equal0(G[2][2])) Infy = true;
                 else{
                      Fraction Temp = reverseFraction(G[2][2]);
                      for(int k = 2; k <= 3; k++){
                          G[2][k] = multiplyFraction(G[2][k],Temp);
                          }                      
                      }
                 if(Infy){
                          if(!Equal0(G[2][3])){
                                               printf("don't know\n");
                                               printf("don't know\n");
                                               }
                          else{
                               if(!Equal0(G[1][2])){
                                                    printf("don't know\n");
                                                    printf("don't know\n");
                                                    }
                               else{
                                    printFraction(G[1][3]);
                                    printf("don't know\n");
                                    }
                               }
                          }
                 else{
                      Fraction X = subtractFraction(G[1][3], multiplyFraction(G[2][3], G[1][2]));
                      printFraction(X);
                      printFraction(G[2][3]);
                      }
                 }
            }
    
 //   getchar();
    return 0;
    }
