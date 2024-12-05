#include<stdio.h>
#include<string.h>

int main()
{
	char src[20] = "hello PGA";
	char *ptr = "hello PGA";     // what are the difference between ptr and src? 
	
	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	*(src+6) = '\0';
	*(ptr+6) = '\0';  // Do you think this is correct?

//	src[6] = '\0';
//	ptr[6] = '\0';
	
	printf("Length of src: %ld\n", strlen(src));	
	printf("Length of ptr: %ld\n", strlen(ptr));	
	
	return 0;
}
