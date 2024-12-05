#include <stdio.h>

int main(int argc, char *argv[])
{ 
   	int a = 1;
   	int b = 2;
   
	int *p1 = &a;
	int *p2 = &b;
	printf("Address of a: %p\nAddress of b: %p\n", &a,&b);
	printf("Address of p1: %p\nAddress of p2: %p\n", &p1,&p2);
	printf("Value of p1: %p\nValue of p2: %p\n\n", p1,p2);

	int **pp1 = &p1;
	printf("%d    %p    %p\n", **pp1,*pp1, pp1);

	*pp1 = p2;	
			    	
	printf("%d    %p    %p\n", **pp1,*pp1, pp1);
	printf("%p    %p\n", &a,  &b);
	printf("%p    %p\n", p1,  p2);

	return 1;
}

