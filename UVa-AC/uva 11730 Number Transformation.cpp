/*
  Name: UVa 11730 Number Transformation
  Copyright: 
  Author: 3T
  Date: 06/05/10 04:20
  Description: Graph, BFS, Prunning, Shortest Path
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define Max 1001
#define BIG 1000000
#define INP "11730.INP"

int S,T,Case(1);
int G[Max][Max],d[Max],p[Max];
bool Prime[Max];

queue <int> myqueue;

void Generate_Prime(){
     memset(Prime,true,sizeof(Prime));
     Prime[0] = false;
     Prime[1] = false;
     for(int i = 2; i < Max; i++){
             while(!Prime[i] && i <= Max) i++;
             for(int j = 2; i * j <= Max; j++)
                if(Prime[i * j]) Prime[i * j] = false;
             }
     }

// Dung DFS. khong cat tia, chay rat lau
     
//void Generate_Graph(int TempS) {
//     if(TempS < T){
//            int temp = TempS;
//            for(int i = 2; i <= TempS / 2; i++){
//                    if(Prime[i] && temp % i == 0){
//                                   while(temp % i == 0)temp = temp / i;
//                    int adjency = TempS + i;
//                    if(adjency <= T){
//                        G[TempS][adjency] = G[adjency][TempS] = 1;
//                        int TempD = d[TempS] + 1;
//                        d[adjency] = std::min(TempD, d[adjency]);
//                        Generate_Graph(adjency);
//                        }
//                        }
//                    }     
//            }
//     }

int main () {

    Generate_Prime();
//    FILE *f = fopen(INP, "r");
    FILE *f = stdin;
    while(fscanf(f,"%d %d",&S,&T) && S){
           if(S == T){
                printf("Case %d: 0\n",Case);
                Case++;
                continue;
                }
           if(S > T){
                printf("Case %d: -1\n",Case);
                Case++;
                continue;
                }
           //Initiate     
           for(int i = S + 1; i <= T; i++) d[i] = BIG;
           d[S] =  0;
//           memset(G,0,sizeof(G));            
//           Generate_Graph(S);   
           //test
//           printf("%d %d\n",S,T);
//           for(int i = S; i <= T; i++) printf("%d ",d[i]);
//           printf("\n");
           myqueue.push(S);
           p[S] = S;
           do{
                int TempS = myqueue.front();
                myqueue.pop();
                if(d[p[TempS]] != BIG && d[p[TempS]] >= d[T]) continue; //cat tia
                if(TempS < T){
            int temp = TempS;
            for(int i = 2; i <= TempS / 2; i++){
                    if(Prime[i] && temp % i == 0){
                           while(temp % i == 0)temp = temp / i;
                    //test
//                    printf("TempS: %d\n",TempS);
                    int adjency = TempS + i;
                    if(adjency <= T){
                    if(d[adjency] == BIG) {myqueue.push(adjency); p[adjency] = TempS;}
                    //test
//                    printf("test size: %d\n",myqueue.size());
//                    printf("to go: %d\n",myqueue.front());
//                    printf("newest: %d\n",myqueue.back());
 //                       G[TempS][adjency] = G[adjency][TempS] = 1;
                        int TempD = d[TempS] + 1;
                         if(TempD < d[adjency]) {
                                  d[adjency] = TempD;
                                  p[adjency] = TempS;
                                  }
                        }
                        }                         
                         } 
                         }          
                           }while (!myqueue.empty());

           if(d[T] == BIG) printf("Case %d: -1\n",Case);
           else printf("Case %d: %d\n",Case,d[T]);
           Case++;         
           }
//    getchar();
    return 0;
    }
