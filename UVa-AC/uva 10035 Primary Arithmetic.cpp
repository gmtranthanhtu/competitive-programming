/* 10035  C*/

#include<stdio.h>


int  main()
   {
       long n,m,i,carry,d;
       while(1)
       {
	  scanf("%ld %ld",&n,&m);
	  if(!n)
	   if(!m) break;
	  d = 0; carry = 0;
	  for(i = 1; i <= 10; i++)
	  {
	    if((n % 10 + m % 10 + d) > 9)
	    {
	       carry++;
	       d = 1;
	    }
	    else
	     d = 0;
	   n = n / 10; m = m / 10;
	   }
	   if(carry==0)
	    printf("No carry operation.\n");
	   else if(carry==1)
	    printf("%ld carry operation.\n",carry);
	   else
	    printf("%ld carry operations.\n",carry);
       }
       return 0;
    }
