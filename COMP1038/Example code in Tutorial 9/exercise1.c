#include<stdio.h>

void func();

int main()
{
	for(int i=0; i<5; i++)
		func();
	return 0;
} 

void func()
{
	static int value = 0;
	value++;
	printf("Value: %d\n", value);
}

