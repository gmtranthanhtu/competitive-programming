/*
  Name: UVa 10252 
  Copyright: 
  Author: 3T
  Date: 12/04/10 22:55
  Description: 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLength 1001

char line1[MaxLength],line2[MaxLength],subsequence[MaxLength],sub[MaxLength];
char c;
int i,j,k,s1,s2,m;


int main () {
//    while(gets(line1) && line1[0] != '\0'){  ----> wrong answer
//         gets(line2);
      while(gets(line1) && gets(line2)){
         s1 = strlen(line1);
         s2 = strlen(line2);
         int marked[s2];
         for(i = 0; i < s2; i++) marked[i]=0;
         k = 0;
         for(i = 0; i < s1; i++){
               for(j = 0; j < s2; j++){
                     if(line1[i] == line2[j] && !marked[j]){
                                 subsequence[k] = line1[i];
                                 k++;
                                 marked[j] = 1;
                                 break;
                                 }
                     }
               }
               
//         for(j = 97; j <= 122; j++){
//               for(i = 0; i < k; i++){
//                     if((int)subsequence[i] == j){
//                                  printf("%c",j);     
//                                  }
//                     }
//               }
//         printf("\n");


//         j = 0;
//         for(c = 'a'; c <= 'z'; c++){
//               for(i = 0; i < k; i++){
//                     if(subsequence[i] == c){
//                                  sub[j] = subsequence[i];
//                                  j++ ;   
//                                  }
//                     }
//               }
//         sub[j]='\0';
//         printf("%s\n",sub);  


//         j = 0;
//         for(m = 97; m <= 122; m++){
//               for(i = 0; i < k; i++){
//                     if((int)subsequence[i] == m){
//                                  sub[j] = subsequence[i];
//                                  j++ ;   
//                                  }
//                     }
//               }
//         sub[j]='\0';
//         printf("%s\n",sub);   

         for(c = 'a'; c <= 'z'; c++){
               for(i = 0; i < k; i++){
                     if(subsequence[i] == c){
                                  printf("%c",c);  
                                  }
                     }
               }
        printf("\n");                    
         }
    
    return 0;
    }
