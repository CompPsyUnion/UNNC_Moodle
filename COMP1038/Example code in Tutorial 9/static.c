#include <stdio.h>

int global=0;
void func(void);

int main(int argc, char *argv[])
{ 
   	int local = 1;
   	static int a = 2;
   
	printf("Global address: %d %p\n", global,&global);
	printf("Local address:  %d %p\n", local,&local);
	printf("Static address: %d %p\n", a,&a);

	func();
	func();
	func();	
	return 0;
}

void func(void)
{
	static int b = 0;
	
	printf("Static address: %d %p\n", b,&b);
	b++;
}
