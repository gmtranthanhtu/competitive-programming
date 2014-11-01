/*
  Name: UVa 11701 Cantor
  Copyright: 
  Author: 3T
  Date: 14/05/10 09:42
  Description: convert from decimal to tenary expansion 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INP "11701.INP"

float a,temp2;
char line[10];
bool result;

bool Cantor(){
     a = atof(line);

//       a = 0.0;
//       int len = strlen(line) - 1;
//       //test
//       printf("len: %d\n",len);
//       float k = 10.0;
//       for(int j = 2; j < len; j++){
//               float temp = line[j] - '0';
//               //test
//               printf("temp %.15f\n",temp);
//               temp2 = temp / 10;
//               //test
//               printf("temp2 %.30f\n",temp2);
//               a = a + temp2;
//               k = k * 10;
//               }
//
//     printf("test: %.15f\n",a);
     
     for(int i = 1; i <= 10; i++){
             //It's hard to verify the result of multiplications or devisions on floating number
             //When I increase the loop limit, the output was wrong!!!!!!!!!!
             //Fortunately, 10 is enough for the loop to give the correct answer
             float b = a * 3.0000000;
             if(b < 1){
                  a = b;
                  //test
                //  printf("%d %.10f %f\n",0,b,a);
                  }
             else if(b > 2){
                  a = b - 2;
                //  printf("%d %.10f %f\n",2,b,a);
                  }
             else return false;
             }
     return true;
     }

bool Equal(char line[10],char goal[10]){
     int len1 = strlen(line) - 1;
     int len2 = strlen(goal);
     if(len1 != len2) return false;
     else{
          for(int i = 0; i < len1; i++){
                  if(line[i] != goal[i]) return false;
                  }
          return true;
          }
     }

int main () {
   // FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fgets(line,10,f) && !Equal(line,"END")){
         if(Equal(line,"1")|| Equal(line,"0")) result = true; 
         else{
              result = Cantor();
              }     
         if(result) printf("MEMBER\n");
         else printf("NON-MEMBER\n");           
         }
    
 //   getchar();
    return 0;
    }
