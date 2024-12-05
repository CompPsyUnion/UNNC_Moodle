#include <stdio.h>

int full_div(int a, int b, int *quotient, int *remainder)
{
	if(b = 0)
	{
		exit(1);
	}
	else
	{
		*quotient = a / b;
		*remainder = a % b;
	}
}



int main(int argc, char *argv[])
{
	int a, b, *q, *r, m;
	int n = 0;

	while(n == 0)
	{	
		printf("Enter a: ");
		scanf("%d", &a);
		if(a == -1)
		{
			printf("\n");
			exit(0);
		}

		printf("Enter b: ");
		scanf("%d", &b);
		
		m = full_div(a, b, *q, *r);

		if(m == 1)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("Quotient %d\n", *q);
			printf("Remainder %d\n", *r);
		}
	}
			
	

}






