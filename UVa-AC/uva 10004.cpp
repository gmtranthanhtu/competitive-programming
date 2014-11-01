/*
  Name: UVa 10004
  Copyright: 
  Author: 3T
  Date: 14/04/10 04:34
  Description: Depth First Search, backtracking
*/


#include <stdio.h>
#include <stdlib.h>

#define Max 200

typedef struct Node{
        bool Painted;
        int Color;
        };
Node N[Max];
int n,l,i,j,a,b,color;
int Edge[Max][Max];

bool Try(int m){
     for(int k = 0; k < n; k++){
             if(Edge[m][k] == 1){
                           if(N[k].Painted == true && N[k].Color == N[m].Color) return false;
                           else if(N[k].Painted == false){
                                if(color == 1) color = 2;
                                else color = 1;
                                N[k].Painted = true;
                                N[k].Color = color;
                                if(!Try(k)) return false;
                                if(color == 1) color = 2;
                                else color = 1;      
      
                    
                                }
                           }
             }
     return true;
     }



bool Bicolorable(){
     for(i = 0; i < n; i++){
           if(N[i].Painted == false){
               color = 1;
               N[i].Painted = true;
               N[i].Color = color;  
               if(!Try(i)) return false;          
               }
//           if(!Try(i)) return false;
           }
     return true;
     }

int main () {
    while(scanf("%d",&n) && n != 0){
            scanf("%d",&l);
            for(i = 0; i < n; i++)
               for(j = 0; j < n; j++) Edge[i][j] = 0;
            for(i = 0; i < l; i++){
                  scanf("%d%d",&a,&b);
                  Edge[a][b] = Edge[b][a] = 1;
                  }
//            for(i = 0; i < n; i++){
//               for(j = 0; j < n; j++) printf("%d ",Edge[i][j]);printf("\n");}

            for(i = 0; i < n; i++){
                  N[i].Painted = false;
                  N[i].Color = 0;
                  } 
            if(Bicolorable()) printf("BICOLORABLE.\n");    
            else printf("NOT BICOLORABLE.\n");       
            }
    return 0;
    }
