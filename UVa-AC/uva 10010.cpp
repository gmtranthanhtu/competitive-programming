/*
  Name: UVa 10010
  Copyright: 
  Author: 3T
  Date: 10/04/10 17:11
  Description: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxLength 51

int Case,c,d,i,j,k,s,p,m,n,q;
char Grid[MaxLength][MaxLength];
char word[MaxLength],line[MaxLength];

//bool CheckUpper();
//bool CheckUpperLeft();
//bool CheckRight();
//bool CheckUpperRight();
//bool CheckLower();
//bool CheckLowerLeft();
//bool CheckLeft();
//bool CheckLowerRight();

char up(char r){
     char result = r;
     if(r >= 'a' && r <= 'z') result = toupper(r);
     return result;
     }

     
bool CheckLower(int row, int col, char w[]){
     if(m - row + 1 < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row + p][col] != up(w[p])) return false;
           }
     return true;
     }  
     
bool CheckUpper(int row, int col, char w[]){
     if(row < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row - p][col] != up(w[p])) return false;
           }
     return true;
     } 
     
bool CheckLeft(int row, int col, char w[]){
     if(col < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row][col - p] != up(w[p])) return false;
           }
     return true;
     }
     
bool CheckRight(int row, int col, char w[]){
     if(n - col + 1 < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row][col + p] != up(w[p])) return false;
           }
     return true;
     }
     
bool CheckUpperLeft(int row, int col, char w[]){
     if(row < s && col < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row - p][col - p] != up(w[p])) return false;
           }
     return true;
     } 

bool CheckUpperRight(int row, int col, char w[]){
     if(row < s && n - col + 1 < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row - p][col + p] != up(w[p])) return false;
           }
     return true;
     }  
     
bool CheckLowerLeft(int row, int col, char w[]){
     if(m - row + 1 < s && col < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row + p][col - p] != up(w[p])) return false;
           }
     return true;
     }   
     
bool CheckLowerRight(int row, int col, char w[]){
     if(m - row + 1 < s && n - col + 1 < s) return false;
     for(p = 1; p < s; p++){
           if(Grid[row + p][col + p] != up(w[p])) return false;
           }
     return true;
     } 
     

void Search(char w[]){
     for(i = 1; i <= m; i++)
         for(j = 1; j <= n; j++){
               if(Grid[i][j] == up(w[0])){
                             if( CheckUpper(i,j,word) ) return;
                             if( CheckUpperLeft(i,j,word)) return;
                             if( CheckLower(i,j,word) ) return;
                             if( CheckLowerLeft(i,j,word)) return;
                             if( CheckLeft(i,j,word) ) return;
                             if( CheckUpperRight(i,j,word)) return;
                             if( CheckRight(i,j,word) ) return;
                             if( CheckLowerRight(i,j,word)) return;
               }
     }
}
int main () {
    scanf("%d",&Case);
    
    for(c = 0; c < Case; c++){
          scanf("%d%d ",&m,&n);
          for(p = 1;p <= m;p++){
                gets(line);
                for (q = 0; q < n; q++){
                    Grid[p][q+1] = up(line[q]);
                    }  
                }
                
          scanf("%d ",&k);
          
          for(d = 0; d < k; d++){
                i = 0; j = 0;
                gets(word);
                s = strlen(word);
                Search(word);
                printf("%d %d\n",i,j);
                }
          if(c < Case - 1)
          printf("\n");
          }
//    getchar();
    return 0;
    }
