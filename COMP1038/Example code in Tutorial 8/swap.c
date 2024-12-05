#include<stdio.h>

void swap(int* arg1, int* arg2)
{
	int* value = NULL;
	value = arg1; 
	arg1 = arg2;
	arg2 = value;
	printf("%p, %p\n", arg1, arg2); 
}

int main()
{
	int a = 1, b = 2;
	int *p1 = &a;
	int *p2 = &b;
	printf("%p, %p\n", p1, p2); 
	
	swap(p1, p2);
		
	printf("%p, %p\n", p1, p2);   	
}
