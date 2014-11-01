/*
  Name: UVa 11879 Multiple of 17
  Copyright: 
  Author: 3T
  Date: 01/11/10 01:43
  Description: bignum
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char S[105];

void getHieu(char Bitru[105], char Sotru[105],char *Hieu){
     if(Sotru[0] == '0' && Sotru[1] == '0')  {strcpy(Hieu, Bitru); return;}
     int sodu = 0;
     int t;
     int lenb = strlen(Bitru);
     if(Bitru[lenb - 1] < Sotru[1]){
                   sodu = 1;
                   Hieu[lenb - 1] = ((Bitru[lenb - 1] - '0') + 10 - (Sotru[1] - '0')) + '0';
                   }

     else{
          sodu = 0;
          Hieu[lenb - 1] = (Bitru[lenb - 1] - '0') - (Sotru[1] - '0') + '0';
          }
     if(Bitru[lenb - 2] - '0' < Sotru[0] - '0' + sodu){
                   Hieu[lenb - 2] = (Bitru[lenb - 2] - '0') + 10 - (Sotru[0] - '0' + sodu) + '0';
                   sodu = 1;
                   }
     else{
          Hieu[lenb - 2] = (Bitru[lenb - 2] - '0') - (Sotru[0] - '0' + sodu) + '0';
          sodu = 0;
          }
     if(!sodu){
               for(int i = 0; i < lenb - 2; i++){
                       Hieu[i] = Bitru[i];
                       }
               }
     
     else{
          
          for(int i = lenb - 3; i >= 0; i--){
                  if(Bitru[i] != '0') {t = i;break;}
                  }
          for(int i = t + 1; i <= lenb - 3; i++){
                  Hieu[i] = '9';
                  }
          Hieu[t] = (Bitru[t] - '0') - 1 + '0';
          for(int i = 0; i <= t - 1; i++) Hieu[i] = Bitru[i];
          }
     Hieu[lenb] = '\0';
     if(Hieu[0] == '0'){
                for(int i = 0; i <= lenb - 1; i++){
                        Hieu[i] = Hieu[i + 1];
                        }
                }
     return;
     }

int Check(char So[]){
    int i;
    int len = strlen(So);
    if(len <= 9){
           int SS;
           sscanf(So,"%d",&SS);
           return (SS % 17) ? 0 : 1;
           }
    int Tmp = (So[len - 1] - '0') * 5;
    char TmpC[3];
    TmpC[0] = (Tmp / 10) + '0';
    TmpC[1] = (Tmp % 10) + '0';
    TmpC[2] = '\0';
    char TmpS[105];

    char TmpSo[105];
    for(i = 0; i < len - 1; i++){
            TmpSo[i] = So[i];
            }
    TmpSo[i] = '\0';
    getHieu(TmpSo, TmpC, TmpS); 
    return (Check(TmpS) ? 1 : 0);
    }

int main () {
    while(gets(S)){
                   if(S[0] == '0') break;
                   printf("%d\n", Check(S));
                   }
    
    
    return 0;
    }
