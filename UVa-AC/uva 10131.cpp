/*
  Name: UVa 10131
  Copyright: 
  Author: 3T
  Date: 15/04/10 02:23
  Description: Dynamic Programming, Bubble Sort
*/
#include <stdio.h>
#include <stdlib.h>


#define Max 1002

typedef struct Elephant{
               int weight;
               int IQ;
               int number;
               };
Elephant E[Max];
int i,j,id,jmax;
int T[Max],F[Max],Temp[Max];
char line[20];


void Sort(){
     Elephant Temp;
     for(i = 1; i < id - 2; i++){
           for(j = id - 1;j >= i + 1; j--){
                 if(E[j].weight < E[i].weight){
                                Temp = E[j];
                                E[j] = E[i];
                                E[i] = Temp;
                                }
                 }
           }
     }

int main(){
    id = 1;


  
//    while(1){
//             if(scanf("%d%d",&x,&y)!=2) break;
//             E[id].weight = x;
//             E[id].IQ = y;
//             id++;
//             }
    while(gets(line) && line[0] != '\0'){
                     sscanf(line,"%d %d",&E[id].weight,&E[id].IQ);
                     E[id].number = id;
                     id++;
                     }
    //Re-arrange by weight (ascending)
    Sort();

    //Basic configuration
    E[0].weight = 0;
    E[id].weight = 10001;
    E[0].IQ = 10001;
    E[id].IQ = 0;
    F[id] = 0;
    
    //process
    for(i = id - 1; i >= 0; i--){
          jmax = id;
          for(j = i + 1; j <= id; j++){
                if((E[j].weight != E[i].weight) && (E[j].IQ < E[i].IQ) && (F[j] > F[jmax])) jmax = j;
                }
          F[i] = F[jmax] + 1;
          T[i] = jmax;
          
          }
    
    //tracing, output      
    printf("%d\n",F[0] - 1);
    i = T[0];
    while (i != id){
          printf("%d\n",E[i].number);
          i = T[i];
          }



//      for(i = 1; i < id; i++){
//            printf("%d %d %d\n",E[i].number,E[i].weight,E[i].IQ);
//            }
          
//    for(i = 0; i <= id; i++) printf("%d ",F[i]);
//    printf("\n");
//    for(j = 0; j <= id; j++) printf("%d %d\n",E[j].weight,E[j].IQ);


// accepted
//       F[0] = 1;
//       for(i = 1; i <= id; i++){
//             jmax = 0;
//             for (j = i - 1; j >= 0; j--){
//                 if(E[j].weight != E[i].weight && E[j].IQ > E[i].IQ && F[j] > F[jmax]) jmax = j;
//                 }
//             F[i] = F[jmax] + 1;
//             T[i] = jmax;
//             }
//       printf("%d\n",F[id] - 2);
//           i = T[id];
//           j = 1;
//    while (i != 0){
//          Temp[j] = i;
//          j++;
//          i = T[i];
//          }
//    for(i = j-1; i >= 1; i--) printf("%d\n",E[Temp[i]].number);




//     while(!EOF){
//                 scanf("%d%d",&E[i].weight,&E[i].IQ);
//                 i++;
//                 }
//
//    
//    for(j = 0; j <= id; j++) printf("%d %d\n",E[j].weight,E[j].IQ);



//    getchar();
    return 0;
    }
