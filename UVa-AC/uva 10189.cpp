#include <stdio.h>

#define MINE '*'

int main () {
// FILE *f = fopen("10189.inp" , "r");

//FILE *f = stdin;
int NumberOfField = 0;
int a,b,i,j;
char InputField[200][200], Input[200];
//if(!f)
//{
//printf("Input file not found");
//getchar();       
//}
   

while(1)
{
gets(Input);
sscanf(Input,"%d %d",&a,&b);
if (!a && !b)
{
return 0; 
} 

//Khoi tao output
int OutputField[200][200];
for( i = 0; i < 200; i ++)
 for( j = 0;j < 200; j++)
  OutputField[i][j] = 0;

//Doc InputField
for(i = 0; i < a; i++ )
{
gets(InputField[i]);  
}

//Cap nhat Output
for( i = 0; i < a; i++ )
{
for( j = 0; j < b; j++ )
{
if( InputField[i][j] == MINE ) {
OutputField[i-1][j-1]++;
OutputField[i-1][j]++;
OutputField[i-1][j+1]++;
					
				
OutputField[i][j-1]++;
OutputField[i][j+1]++;
					

OutputField[i+1][j-1]++;
OutputField[i+1][j]++;
OutputField[i+1][j+1]++; 
    }    
}     
}

//In output
if (NumberOfField > 0) {
				printf("\n");
			}
NumberOfField++;

printf("Field #%d:\n",NumberOfField);
for(i = 0; i < a; i++ )
{
for( j = 0; j < b; j++ )
{
if( InputField[i][j] == MINE ) printf("%c",InputField[i][j]);
else printf("%d",OutputField[i][j]);    
}
printf("\n");     
}
}
//getchar();
return 0;
}
