#include<stdio.h>

int main(int argc, char *argv[])
{

	int num;
	printf("Enter number of values: ");
	scanf("%d", &num);

	if(num <= 0)
	{
		printf("Invalid array length!\n");
		return 1;
	}

	int i;
	int array[num];

	for(i = 0; i < num; i++) 
	{
		printf("Enter position %d value:", i);
		scanf("%d",&array[i]);
		if(array[i]%2 != 0)
			i--;
	}


	for(int i = 0; i < num; i++)
	{
		if(array[i] > 0)		
			printf("%d\n",array[i]);
	}		
	return 0;
} 
