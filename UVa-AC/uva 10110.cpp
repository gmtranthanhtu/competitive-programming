#include <stdio.h>
#include <math.h>

int main ()
{
//FILE *f = fopen("pro10110.inp", "r");
//FILE *f = stdin;


unsigned int n;

//while(scanf("%u",&n) && n != 0)
//{                     
//unsigned int count = 0;
//for(i = 1; i <= n; i++ )
//{
//if( n % i == 0 ) count++;      
//}
//if ( count % 2 != 0 )
//{
//printf("yes\n");     
//}
//else printf("no\n");                     
//} 


//cach 2: kiem tra n co phai la so chinh phuong hay khong. neu co thi yes.   
while(scanf("%u",&n) && n > 0)
{
unsigned int r = (int) sqrt(n);
if( r * r == n) 
{
printf("yes\n");    
} 
else printf("no\n");                   
}
//getchar();
return 0;
}
