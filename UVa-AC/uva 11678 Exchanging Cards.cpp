/*
  Name: UVa 11678 Exchanging Cards
  Copyright: 
  Author: 3T
  Date: 09/05/10 23:58
  Description: no algorithm needed :D
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define Max 100005
#define INP "11678.INP"

int a,b,c,sum1,sum2,result;
bool Marked1[Max],Marked2[Max];


int main () {
 //       FILE *f = fopen(INP,"r");
    FILE *f = stdin;
    
    while(fscanf(f,"%d%d",&a,&b) && a){
           memset(Marked1,false,sizeof(Marked1));
           memset(Marked2,false,sizeof(Marked2));
           sum1 = sum2 = 0;
           for(int i = 1; i <= a; i++){
                   fscanf(f,"%d",&c);
                   if(!Marked1[c]){
                        Marked1[c] = true;
                        sum1++;           
                        }
                   }  
           for(int i = 1; i <= b; i++){
                   fscanf(f,"%d",&c);
           //        if(Marked1[c]){
//                        sum1--;          
//                        }
//                   else{
//                        if(!Marked2[c]){
//                           Marked2[c] = true;
//                           sum2++;             
//                           }
//                        }
                    if(!Marked2[c]){
                        Marked2[c] = true;
                        if(Marked1[c]) sum1--;
                        else sum2++;            
                        }
                   }
           result = std::min(sum1,sum2);
           printf("%d\n",result);                    
           }
  //  getchar();
    return 0;
    }
