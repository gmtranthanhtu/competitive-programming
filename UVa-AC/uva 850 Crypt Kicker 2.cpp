#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <conio.h>
#define MaxLine 101
#define MaxLength 100

int Case,k,i,j,s,d,t;
int S[MaxLine];
int Marked[26];
char line[MaxLine][MaxLength];
char PlainText[] = {"the quick brown fox jumps over the lazy dog"};
char Alphabet[] = {"abcdefghijklmnopqrstuvwxyz"};
char Crypt[26];



int inAlphabet(char a) {
     int index;
     for(int i = 0; i < 26; i++){
             if(Alphabet[i] == a){
                            index = i;
                            break;
                            }
             }
     return index;
     }
     
int inCrypt(char a) {
     int index;
     for(int i = 0; i < 26; i++){
             if(Crypt[i] == a){
                            index = i;
                            break;
                            }
             }
     return index;
     }
     
bool check(){
     int count = 0;
     for(int i = 0; i < 26; i++) if(Marked[i]) count++;
     if (count == 26) return true;
     else return false;
     }

int main () {
    s = strlen(PlainText);
    scanf("%d ",&Case);
    for(int c = 1; c <= Case; c++){
            k = 1;
            while(gets(line[k]) && line[k][0] != '\0'){
                          S[k] = strlen(line[k]);
                          k++;                            
                          }
            for(i = 1; i < k; i++){
                  if(S[i] == s){
                          for(j = 0; j < 26; j++) Marked[j] = 0;
                          for(j = 0; j < s; j++){
                                if(line[i][j] == ' '){
                                              if(PlainText[j] != line[i][j]) break;
                                              }
                                else{
                                     int index = inAlphabet(PlainText[j]);
                                     if(!Marked[index]){
                                                        for(t = 1; t < 26; t++){
                                                                if(Marked[t]){
                                                                              if(Crypt[t] == line[i][j]){
                                                                                          break;
                                                                                          }
                                                                              }
                                                                }
                                                        if(t < 26) break;
                                                        Marked[index] = 1;
                                                        Crypt[index] = line[i][j];
                                                        }
                                     else{
                                          if(Crypt[index] != line[i][j]) break;
                                          }
                                     }
                                }
                          if(j == s && check()) break;
                          }
                  }
            if(i == k){
                 if(c > 1) printf("\n");
                 printf("No solution.\n");
                 }
            else{
//                 printf("Test: ");
//                 for(i = 0; i < 26; i++) printf("%c ",Crypt[i]);
//                 printf("\n");
                 if(c > 1) printf("\n");
                 for(i = 1; i < k; i++){
                       for(j = 0; j < S[i]; j++){
                             if(line[i][j] != ' '){
                                           int a = inCrypt(line[i][j]);
                                           line[i][j] = Alphabet[a];
                                           }
                             line[i][S[i]] = '\0';
                             }
                       }
                 for(i = 1; i < k; i++){
                       printf("%s\n",line[i]);
                       }
                 }
            }
//            getch();
    return 0;
    }
