#include<stdio.h>
#define min(a,b)  (a<b? a:b)
#define min_3(a,b,c) min(min(a,b),c)



		    int main()
		    {

		      int num=0,p2,p3,p5,n;
		      long a[1501];
		      a[1]=p2=p3=p5=n=1;
		      while(1)
		      {
			a[++n]=min_3(2*a[p2],3*a[p3],5*a[p5]);
			if(a[n]==2*a[p2]) p2++;
			if(a[n]==3*a[p3]) p3++;
			if(a[n]==5*a[p5]) p5++;
			if(n==1500) break;

		     }

		     printf("The 1500'th ugly number is %ld.\n",a[n]);
		     return 0;
		    }
