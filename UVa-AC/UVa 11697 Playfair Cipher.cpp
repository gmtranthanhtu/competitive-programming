/*
  Name: UVa 11697 Playfair Cipher
  Copyright: 
  Author: 3T
  Date: 27/05/10 01:38
  Description: string
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define INP "11697.INP"
#define MAX 1005

int N,j,k;
int Marked[125];
char Table[6][6],line1[MAX],line2[MAX];

void printTwoChar(char a, char b){
     int rowA,colA,rowB,colB;
     char A = toupper(a);
     char B = toupper(b);
     for(int j = 1; j <= 5; j++){
             for(int k = 1; k <= 5; k++){
                     if(Table[j][k] == A){
                                    rowA = j;
                                    colA = k;
                                    }
                     if(Table[j][k] == B){
                                    rowB = j;
                                    colB = k;
                                    }
                     }
             }
     if(rowA == rowB){
             colA++;
             if(colA == 6) colA = 1;
             colB++;
             if(colB == 6) colB = 1;
//             printf("%c%c",Table[rowA][colA],Table[rowB][colB]);
             }
     else if(colA == colB){
             rowA++;
             if(rowA == 6) rowA = 1;
             rowB++;
             if(rowB == 6) rowB = 1;
          }
     else{
          int temp = colA;
          colA = colB;
          colB = temp;
          }
     printf("%c%c",Table[rowA][colA],Table[rowB][colB]);
     }

int main () {
 //   FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&N);
    for(int i = 1; i <= N; i++){
            memset(Marked,0,sizeof(Marked));
            fgets(line1,MAX,f);
            fgets(line2,MAX,f);
            j = k = 1;
            for(int p = 0; p < strlen(line1) - 1; p++){
                    if(!Marked[(int) line1[p]] && line1[p] != ' '){
                                     Table[j][k] = toupper(line1[p]);
                                     Marked[(int) line1[p]] = 1;
                                     k++;
                                     if(k == 6 && j == 5){
                                          j = 6;
                                          break;
                                          }
                                     else if(k == 6 && j != 5){
                                          k = 1;
                                          j++;
                                          }
                                     }
                    }
            while(j != 6){
                         for(char p = 'a'; p <= 'z'; p++){
                                  if(!Marked[(int) p] && p != 'q'){
                                                   Table[j][k] = toupper(p);
                                                   Marked[(int) p] = 1;
                                                   k++;
                                                   if(k == 6){
                                                        k = 1;
                                                        j++;
                                                        }
                                                   }
                                  }
                         }
            //test
//            for(int e = 1; e <= 5; e++){
//                    for(int f = 1; f <= 5; f++){
//                            printf("%c",Table[e][f]);
//                            }
//                    printf("\n");
//                    }
//            printf("\n");

// end test
           j = 0;
           while(j != strlen(line2) - 1){
                   k = j + 1;
                   while(line2[k] == ' ') k++;
                   if(k == strlen(line2) - 1){
                        printTwoChar(line2[j],'X');
                        j = strlen(line2) - 1;
                        }
                   else if(line2[j] == line2[k]){
                        printTwoChar(line2[j],'X');
                        j = k;
                        }
                   else{
                        printTwoChar(line2[j],line2[k]);
                        j = k + 1;
                        while(line2[j] == ' ') j++;
                        }
                   }              
            

            printf("\n");
            }
 //   getchar();
    return 0;
    }
