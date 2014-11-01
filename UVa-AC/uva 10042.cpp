#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#define Max 125000001
#define Max 10000001
int a[6000];
int k=0;
 

bool prime[Max];

void Generate_Primes(){
     prime[1] = false;
     for( unsigned int i = 2; i < Max; ++i){
          prime[i] = true;
          }
     for( unsigned int i = 2; i < Max; ++i){
//for(;i < Max  && !prime[i];++i){}
while(i < Max && !prime[i]){i++;}
          for( unsigned int j = 2; i * j < Max; ++j){
               prime[i * j] = false;
               } 
          }
          for(int i=1;i<=46400;i++)
		  if(prime[i])
			   a[k++]=i;  
     }
unsigned int SumOfAllDigits(unsigned int n){
    unsigned int s(0);
    unsigned int temp1 = n;
    if ( temp1 / 10 == 0 ){
         return temp1;
         }
    s = temp1 % 10;
    s += SumOfAllDigits( temp1 / 10 );
    return s;    
    }

     
//unsigned int Lowest_Smith(unsigned int n){
//         for (unsigned int i = n + 1;i < Max; i++ ){
//           if(!prime[i]){
//                         unsigned int j = 2, k = 0, temp = i;
//                         unsigned int term[4] = {0};
//                         while (j <= i/8){
//                               if (prime[j] && temp % j == 0){
//                                       term[k] = j;
//                                       k++;
//                                       if( k > 3 ) break;
//                                       temp /= j;
//                                       }
//                               j++;
//                               }
//                         unsigned int Sum(0),count(0);
//                         for (int u = 0; u < 4; u++){
//                             Sum += SumOfAllDigits(term[u]);
//                             if (term[u] != 0) count++;
//                             }
//                         if(count == 4 && Sum == SumOfAllDigits(i)) return i;
//                         }
//           
//           }
//         }
         
//unsigned int Lowest_Smith(unsigned int n){
//         for (unsigned int i = n + 1;; i++ ){
//           if(!prime[i]){
//                         unsigned int j = 2, temp = i;
//                         int Sum(0), Sumi = SumOfAllDigits(i);
//                         while (!prime[temp]){
//                               if (prime[j] && temp % j == 0){
//                                       Sum += SumOfAllDigits(j);
//                                       temp /= j;
//                                       if (prime[temp]) Sum += SumOfAllDigits(temp);
//                                       continue;
//                                       }
//                               j++;
//                               }
//                         if(Sum == Sumi) return i;
//                         }
//           
//           }
//         }

unsigned int Lowest_Smith(unsigned int n){
         for(unsigned int i = n + 1;; i++ ){
                      unsigned int Sum = 0, Sumi = 0;
                      Sumi = SumOfAllDigits(i);
                      unsigned int j, temp = i;
                      unsigned int s = (unsigned int) sqrt(temp);
                       for (j=0;a[j] <= s && Sum <= Sumi;j++){
                              if (temp % a[j] == 0){
                                     while (temp % a[j] == 0){
                                           Sum += SumOfAllDigits(a[j]);
                                           temp = temp / a[j];
                                           }

                              }
                              }

//                       while(j <= s && prime[j]){
//                               if(temp % j == 0){
//                                       Sum +=SumOfAllDigits(j);
//                                       printf("%u ",j);
//                                       temp = temp / j;
//                                       }
//                                j++;
//                               }
//                       printf("temp: %u\n",temp);
                       if(temp!=1 && Sum!=0) Sum += SumOfAllDigits(temp); 
                       if(Sumi == Sum) return i;
                      }
}


int main ()
{
unsigned int n;
int Case;
Generate_Primes();
scanf("%d",&Case);

       for(int l(0);l < Case; l++){
//               Generate_Primes();
       scanf("%u",&n);
       printf("%u\n",Lowest_Smith(n));
//       if(l > 1) printf("\n");
       }  
return 0;
}
