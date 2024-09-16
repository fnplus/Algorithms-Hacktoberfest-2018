/*	print this pattern:
		*****
		* ***
		** **
		*** *
		*****
*/
#include<stdio.h>
#include<conio.h>
void main()
{
 int n,i,j;
 clrscr();
 printf("enter the no. of layers:");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			{
				if(i==1||i==n)
					printf("*");
				else if (i==j)
					printf(" ");
				else
					printf("*");
			}
		printf("\n");
	}
 getch();
}