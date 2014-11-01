/*
  Name: UVa 10082
  Copyright: 
  Author: 3T
  Date: 04/04/10 21:34
  Description: 
*/

#include <stdio.h>
//#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char Input[256];
    int i,j,k,s;
    char Error[][12]= {'1','2','3','4','5','6','7','8','9','0','-','=',
                       'W','E','R','T','Y','U','I','O','P','[',']','\\',
                       'S','D','F','G','H','J','K','L','\;','\'',' ',' ',
                       'X','C','V','B','N','M',',','.','/',' ',' ',' '};
    char Replaced[][12]= {'`','1','2','3','4','5','6','7','8','9','0','-',
                          'Q','W','E','R','T','Y','U','I','O','P','[',']',
                          'A','S','D','F','G','H','J','K','L','\;',' ',' ',
                          'Z','X','C','V','B','N','M',',','.',' ',' ',' '}; 
                          
    while (gets(Input)){
          char Output[256];
          s = strlen(Input);
          for(i = 0; i < s; i++){
                for(j = 0; j < 4; j++)
                    for(k = 0; k < 12; k++){
                          if(Error[j][k] == Input[i]) Output[i] = Replaced[j][k];
//                          break;
                          }
                }
          Output[s] = '\0';
          puts(Output);
//          printf("\n"); 
          }
// Print the keyboard                          
//    for ( int i = 0; i < 4; i++){
//       for (int j = 0; j < 12;j++)
//          printf("%c ",Replaced[i][j]);
//       printf("\n");
//          }


//    getch();
    return 0;
    }
