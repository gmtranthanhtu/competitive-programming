/*
  Name: Uva 11776 On Your Royal Greediness
  Copyright: 
  Author: 3T
  Date: 21/04/10 20:53
  Description: Bubble sort
*/
#include <stdio.h>
#include <stdlib.h>

#define Max 2000

typedef struct Time{
        int atTime; //when?
        int SorE;   //Start or End? If Start, store 1; if End store -1
        };
Time T[Max];
int N,i,j,k,u,v,total,max,temp,p,q;

// Sort ascending by time, if time equal, S first then E
void Sort(){ 
     for(p = 0; p <= k - 2; p++){
             for(q = k - 1; q >= p + 1; q--){
//                     if(T[q].atTime < T[q-1].atTime || (T[q].atTime == T[q-1].atTime && T[q].SorE > T[q-1].SorE)){
                       if(T[q].atTime < T[q-1].atTime){
                                    temp = T[q].atTime;
                                    T[q].atTime = T[q-1].atTime;
                                    T[q-1].atTime = temp;
                                    temp = T[q].SorE;
                                    T[q].SorE = T[q-1].SorE;
                                    T[q-1].SorE = temp;                                   
                                    }
                       else if (T[q].atTime == T[q-1].atTime && T[q].SorE > T[q-1].SorE){
                                    temp = T[q].atTime;
                                    T[q].atTime = T[q-1].atTime;
                                    T[q-1].atTime = temp;
                                    temp = T[q].SorE;
                                    T[q].SorE = T[q-1].SorE;
                                    T[q-1].SorE = temp;                              
                            }
                     }
             }
     }

int main () {
    int Case = 1;
    while(scanf("%d",&N) && N != -1){
         k = 0;
         for(i = 0; i < N; i++){
               scanf("%d%d",&u,&v);
               T[k].atTime = u;
               T[k].SorE = 1;
               k++;
               T[k].atTime = v;
               T[k].SorE = -1;
               k++;
               }
//         printf("Test: %d\n",k);
//         for(int p = 0; p < k; p++){
//               printf("%d ",T[p].atTime);
//         for(int p = 0; p < k; p++){
//               printf("%d ",T[p].SorE);}
//               }
         Sort(); 
  
         total = 0;
         max = 0;
         for(i = 0; i < k; i++){
               total = total + T[i].SorE;
               if(total > max) max = total;
               }
         printf("Case %d: %d\n",Case,max);
         Case++ ;            
         }
    return 0;
    }
