/*
  Name: UVa 10906 Strange Integration
  Copyright: 
  Author: 3T
  Date: 07/07/10 03:26
  Description: string, BNF
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#define INP "10906.INP"

typedef struct Expression{
        char V[15],L[15],R[15],O[2];
        bool NumL, NumR, OK;
        string S;
        };
Expression E[55];
int T,N;

bool checkNumber(char S[15]){
     return (S[0] >= '0' && S[0] <= '9') ? true : false;
     }

string copyValue(int Des, int Sou, char Side, char Op){
     string Temp = "";
     bool Para(false);
     if(Op == '+'){
           if(E[Des].O[0] == '*') Para = true;
           else{
                if(Side == 'R') Para = true;
                }
           }
     else{
          if(Side == 'R' && E[Des].O[0] == '*') Para = true;
          }
     Temp += E[Sou].S;
     if(Para){
              Temp += ")";
              Temp.insert(0,"(");
              }
     return Temp;
     }

void solveIt(){
     string TempR;
     char TrackL[2],TrackR[2];
     for(int i = 1; i <= N; i++){
             if(E[i].OK) continue;
             if(!E[i].NumL){
                            //copy to NumL
                            for(int j = i - 1; j >=1; j--){
                                    if(!strcmp(E[i].L,E[j].V)){
                                                               TrackL[0] = E[j].O[0];
                                                               //copy
                                                               E[i].S = copyValue(i, j, 'L', TrackL[0]);
                                                               break;
                                                               }
                                    }
                            if(E[i].NumR){
                                          //update string 
                                          E[i].S += E[i].O;
                                          E[i].S += E[i].R;
                                          E[i].OK = true;
                                          }
                            else{
                                 //copy to NumR
                                 for(int j = i - 1; j >= 1; j--){
                                         if(!strcmp(E[i].R,E[j].V)){
                                                                    TempR = "";
                                                                    TrackR[0] = E[j].O[0];
                                                                    //copy
                                                                    TempR = copyValue(i, j, 'R', TrackR[0]);
                                                                    break;
                                                                    }
                                         }
                                 //update string
                                 E[i].S += E[i].O;
                                 E[i].S += TempR;
                                 E[i].OK = true;
                                 }
                            }
             else{
                  //copy to NumR
                  for(int j = i - 1; j >= 1; j--){
                         if(!strcmp(E[i].R,E[j].V)){
                               TrackR[0] = E[j].O[0];
                                //copy
                                E[i].S = copyValue(i, j, 'R', TrackR[0]);
                                break;
                                }
                           }
                  //update string
                  E[i].S.insert(0,E[i].O);
                  E[i].S.insert(0,E[i].L);
                  E[i].OK = true;
                  }
             }
     }

int main () {
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d",&T);
    for(int i = 1; i <= T; i++){
            fscanf(f,"%d ",&N);
            for(int j = 1; j <= N; j++){
                    fscanf(f,"%s = %s %s %s",&E[j].V,&E[j].L,&E[j].O,&E[j].R);
                    E[j].NumL = checkNumber(E[j].L) ? true : false;
                    E[j].NumR = checkNumber(E[j].R) ? true : false;      
                    //Store
                    E[j].OK = (E[j].NumL && E[j].NumR) ? true : false;
                    E[j].S = "";
                    if(E[j].OK){
                                E[j].S += E[j].L; E[j].S += E[j].O; E[j].S += E[j].R;  
                                }              
                    }
            //solve
            solveIt();
                    
            //output
            printf("Expression #%d: ",i);
            cout << E[N].S << endl;           
            }
//    getchar();
    return 0;
    }
