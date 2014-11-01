/*
  Name: UVa 10154 Weights and Measures
  Copyright: 
  Author: 3T
  Date: 30/04/10 11:15
  Description: Dynamic Programming, Bubble Sort
*/
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#define Max 5610
#define BIG 1900000000

typedef struct Turtle{
        int Weight;
        int Strength;
        };

Turtle T[Max];
int F[Max][Max];  //Bang quy hoach dong, F[i][j] luu tong khoi luong nho nhat to the xep chong j turtle. j nam trong doan 1 toi i (da sap xep)
int Lighter[Max]; //Lighter[i] la khoi luong nhe nhat cua i turtle dau tien sau khi sap xep
int i,j,id,temp,t;   
char line[256];

//Sap xep theo tang dan cua Strength
void Sort(){
     Turtle Temp;
     for(i = 1; i <= id - 2;i++){
           for(j = id - 1; j >= i + 1;j--){
                 if(T[j].Strength < T[j - 1].Strength){
                                  Temp = T[j];
                                  T[j] = T[j - 1];
                                  T[j - 1] = Temp;
                                  }
                 }
           }
     }

int main () {
    id = 1;
    while(gets(line) && line[0] != '\0'){
                     sscanf(line,"%d %d",&T[id].Weight,&T[id].Strength);
                     id++;
                     }
                     
    Sort();
//    Test;
//    for(i = 1; i <= id - 1; i++){
//          printf("%d %d\n",T[i].Weight,T[i].Strength);
//          }

    //Khoi tao 2 mang Lighter[]
    Lighter[1] = T[1].Weight;
    for(i = 2; i < id; i++){
          if(T[i].Weight < Lighter[i - 1]) Lighter[i] = T[i].Weight;
          else Lighter[i] = Lighter[i - 1];
          }
          
    //Khoi tao bang quy hoach
    //F[i][j] voi j > i luon bang BIG vi khong xay dung dc
    for(i = 1; i < id; i++)
        for(j = i + 1; j < id; j++)
             F[i][j] = BIG;
    
    for(i = 1; i < id; i++) F[i][1] = Lighter[i];
    
    //Xay dung bang quy hoach
    for(i = 2; i < id; i++){
          for(j = 2; j <= i; j++){
                //Neu T[i] co kha nang mang chong [j-1] turtle tren lung 
                if(T[i].Strength >= T[i].Weight + F[i - 1][j - 1]){
                                 //Neu cung la 1 chong xep dc j con thi chon chong nao co F[i][j] nho nhat
                                 temp = F[i - 1][j - 1] + T[i].Weight; //Cong them khoi luong cua T[i]
                                 if(temp <= F[i - 1][j]) F[i][j] = temp; //Chon T[i] thi cap nhat lai
                                 else F[i][j] = F[i - 1][j]; //Neu khong chon T[i] thi gan bang gia tra cua F[i-1][j]
                                 }
                                 
                //Else: Neu T[i] khong co kha nang mang chong [j - 1] turtle tren lung
                //va F[i-1][j] la xac dinh, tuc la voi i - 1 turtle dau tien, co the xep duoc chong j turtle
                //thi lay gia tri do
                //Neu khong thi lay gia tri BIG (khong xep duoc)
                else F[i][j] = F[i - 1][j];
                }
          }
          
    //Ket qua     
    //Voi id - 1 turtle, tim j lon nhat ma khac BIG      
    for(t = 1; t < id; t++){
          if(F[id - 1][t] == BIG) break;
          }
    printf("%d\n",t - 1);
      
//    getch();
    return 0;
    }
