/*
  Name: UVa 10099 Tourguide
  Copyright: 
  Author: 3T
  Date: 03/05/10 11:16
  Description: Floyd algorithm, shortest path
*/

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define BIG 2000000
#define MaxLength 101


int i,j,k,N,R,C1,C2,P,S,D,T,u,v;
int Bus[MaxLength][MaxLength];

int main (){
    int Case = 1;
    while(scanf("%d%d",&N,&R)){
           if(N == 0){
                printf("\n");
                return 0;
                }
           for(i = 1; i <= N; i++)
               for (j = 1; j <= N; j++) Bus[i][j] = -1;                  
           
           for(i = 0; i < R; i++){
                 scanf("%d%d%d",&C1,&C2,&P);
                 Bus[C1][C2] = Bus[C2][C1] = P;
                 }   
           
           scanf("%d%d%d",&S,&D,&T);
           for(i = 1; i <= N; i++)
               for (j = 1; j <= N; j++){
                   if(Bus[i][j] != -1){
                                if(T % (Bus[i][j] - 1) == 0) Bus[i][j] = T / (Bus[i][j] - 1);
                                else Bus[i][j] = T / (Bus[i][j] - 1) + 1;
                                }
                   }
           for(i = 1; i <= N; i++)
               for (j = 1; j <= N; j++) 
                 if(Bus[i][j] == -1) Bus[i][j] = BIG;  
//           for(i = 1; i <= N; i++){
//               for (j = 1; j <= N; j++) printf("%d ",Bus[i][j]);    
//               printf("\n");
//               }            
//           printf("Test: %d %d\n",MaxOfMin,Trip);
           
           if(S == D) {
           if(Case > 1) printf("\n");
           printf("Scenario #%d\n",Case); 
           printf("Minimum Number of Trips = %d\n",1); 
           Case++;  
                }
           else{
           //Floyd
           for(k = 1; k <= N; k++){
                 for(u = 1; u <= N; u++){
                       for(v = 1; v <= N; v++){
                             if(u != v && v != k)
                             Bus[u][v] = Bus[v][u] = std::min(Bus[u][v], std::max(Bus[u][k],Bus[k][v]));
                             }
                       }
                 }
                      
           if(Case > 1) printf("\n");
           printf("Scenario #%d\n",Case); 
           printf("Minimum Number of Trips = %d\n",Bus[S][D]);
           Case++; 
           }            
    }
//    getchar();
    return 0;
    }
