#include <stdio.h>

void array_sort(int arr[], int length);
void array_unique_member_print(int arr[], int length);


int main()
{ 
	int len;
	printf("Enter the length of an array: ");
	scanf("%d", &len);
	
	int array[len];
	for(int i=0; i<len; i++)
	{
		printf("Enter item %d: ", i);
		scanf("%d", &array[i]);
	}

	printf("Unique members of the array:\n");
	array_unique_member_print(array, len);
	
	array_sort(array, len);
	printf("\nSorted array:\n");
	for(int i=0; i<len; i++)
		printf("%d\n", array[i]);
}

// Bubble sort
void array_sort(int arr[], int length)
{
	int i,j;
	for(i=0; i<length-1; i++)
		for(j=0; j<length-1-i; j++)
		{
			if(arr[j]>arr[j+1])
			{
				int value = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = value;
			}
		}
	
}


void array_unique_member_print(int arr[], int length)
{
	int i,j,k;
	for(i=0; i<length; i++)
	{
		k = 0;
		for(j=0; j<length; j++)
		{
			if(i!=j && arr[i] == arr[j])
				k = 1;
		}
		if(k==0)
			printf("%d\n", arr[i]);
	}
}

