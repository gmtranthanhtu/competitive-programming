/*
  Name: UVa 10201 Adventures in Moving part IV
  Copyright: 
  Author: 3T
  Date: 16/05/10 14:40
  Description: DP
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define INP "10201.INP"

typedef struct GasStation{
        int DGS;
        int Price;
        };
        
GasStation GS[110];
int n,D,NumberOfGS,a,b,cost,temp,j,loop,RemainFuel,tempindex,aa;
int MinCost[110];
char line[256],c;

bool IsImpossible(){
     if((D != 0 && (D - GS[NumberOfGS].DGS > 100 || NumberOfGS == 0))||GS[1].DGS > 100) return true;
     else {
          for(int i = 1; i < NumberOfGS; i++){
                  if(GS[i + 1].DGS - GS[i].DGS > 200) return true;
                  }
          }
     return false;
     }

void Generate(){
     memset(MinCost,0,sizeof(MinCost));
     for(int i = 0; i <= NumberOfGS; i++){
             temp = j = i;
             if(i == 0) loop = 100;
             else loop = 200; 
             while(GS[j].DGS - GS[i].DGS <= loop && j <= NumberOfGS){
                    if(GS[j].Price < GS[temp].Price) temp = j;
                    j++;         
                    }
             MinCost[i] = temp;
             }
             //fix
     for(int i = 0; i <= NumberOfGS; i++){
             if(D - GS[i].DGS <= 100){
                  loop = i;
                  break;
                  }
             }
                            //test
//                       for(int k = 0; k <= NumberOfGS; k++){
//                               printf("MinCost[%d] = %d\n",k,MinCost[k]);
//                               }
     temp = 5000;
     //test
//     printf("loop: %d\n\n",loop);
     for(int i = loop; i <= NumberOfGS; i++){
             if(GS[MinCost[i]].Price < temp) {
                                     temp = GS[MinCost[i]].Price;
                                     tempindex = MinCost[i];
                                     }

             }
     for(int i = loop; i <= NumberOfGS; i++){
             MinCost[i] = tempindex;
             }
     } 

int main () {
    //FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    fscanf(f,"%d ",&n);
    for(int i = 1; i <= n; i++){
            memset(GS,0,sizeof(GS));
            cost = 0;
            fscanf(f,"%d",&D);
            fgets(line,256,f); //go to the new line
            NumberOfGS = 0;
            while(fgets(line,256,f) && strlen(line) != 1){
                    sscanf(line,"%d%d",&a,&b);
                    if(a <= D){
                    GS[NumberOfGS+1].DGS = a;
                    GS[NumberOfGS+1].Price = b;
                    NumberOfGS++;    
                           }            
                    }
            GS[0].Price = 5000;
            
            if(i > 1) printf("\n");
            //test
//            printf("%d\n",D);
//            for(int j = 1; j <= NumberOfGS; j++){
//                    printf("%d %d\n",GS[j].DGS,GS[j].Price);
//                    }

            if(IsImpossible()){
                               printf("Impossible\n");
                               continue;
                               } 
            else{
//                 printf("Process later!\n");
                  if(D == 0) cost = 0;
                  else{
                       Generate();
                       //test
//                       for(int k = 0; k <= NumberOfGS; k++){
//                               printf("MinCost[%d] = %d\n",k,MinCost[k]);
//                               }

                        RemainFuel = 100;
                        for(int k = 0; k <= NumberOfGS; k++){
                                if(k > 0) RemainFuel = RemainFuel - (GS[k].DGS - GS[k - 1].DGS);
                                //test
                       //         printf("Remain buoc %d: %d\n",k,RemainFuel);
                                if(MinCost[k] == k){
                                              if(D - GS[k].DGS > 100){
                                              cost = cost + (200 - RemainFuel) * GS[k].Price;
                                              //test
                                     //         printf("Cost tam: %d\n",cost);
                                              RemainFuel = 200;
                                              }
                                              else{
                                                   cost = cost + (100 - RemainFuel + D - GS[k].DGS) * GS[k].Price;
                                                   //test
                                          //        printf("Cost tam: %d\n",cost);
                                                   }
                                              }
                                else{
                                     //
                                     aa = k;
                                     while(GS[aa].Price >= GS[k].Price) aa++;
                                     int s = GS[aa].DGS - GS[k].DGS - RemainFuel;
                                     if(s > 0){
                                          cost = cost + s * GS[k].Price;
                                          //test
                                    //          printf("Cost tam: %d\n",cost);
                                          RemainFuel = RemainFuel + s;
                                          }
                                     }
                                }
                       
                       }
                  printf("%d\n",cost);
                 }



            }
    
 //   getchar();
    return 0;
    }
