#include <stdio.h>

int main(void)
{
    int input;
    int digit[4];

    printf("Enter a 4-digit number:");
    scanf("%d",&input);
//    printf("The input is: %d\n", input);
       
// Split the number into its digits
    digit[0] = input / 1000;
    digit[1] = (input / 100) % 10;
    digit[2] = (input / 10) % 10;
    digit[3] = input % 10;
//    printf("The 4 digits are: %d %d %d %d\n", digit[0],digit[1],digit[2],digit[3]);
       
// Add 7 to each digit and take modulo 10
    digit[0] = (digit[0] + 7)%10;
    digit[1] = (digit[1] + 7)%10;
    digit[2] = (digit[2] + 7)%10;
    digit[3] = (digit[3] + 7)%10;
        
// Swap the first with the third, and the second with the fourth
	int temp = digit[0];
	digit[0] = digit[2];
	digit[2] = temp;
	temp = digit[1];
	digit[1] = digit[3];
	digit[3] = temp;	
	
    printf("The encrypted number is: ");
	for(int i=0; i<4; i++)
		printf("%d",digit[i]);
	printf("\n");
		
    return 0;
}

