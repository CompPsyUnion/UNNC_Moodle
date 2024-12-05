#include <stdio.h>

int main() {
    int n = 0;

    // Prompt the user for a valid number of values
    printf("Enter number of values: ");
    
    do
    {
    	scanf("%d", &n);
       	if(n<=0)
       	{
       		printf("Invalid array length!\n");
        	printf("Enter a positive number: ");
        }
        while (getchar() != '\n'); // clear input buffer
    }while(n<=0);

    
    int arr[n];
 
    // Prompt the user to enter values into the array
    printf("Enter position 0 value: ");
    scanf("%d", &arr[0]);  // First number input without validation

    for (int i = 1; i < n; i++) 
    {
        int valid = 0;
        while (!valid) 
        {
            printf("Enter position %d value: ", i);
            int num;
            scanf("%d", &num);

            // The number must be greater than the first entered value
            if (num > arr[0]) 
            {
                arr[i] = num;
                valid = 1;
            }
        }
    }

    // Count and print even numbers
    int even_count = 0, odd_count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] % 2 == 0) 
        {
            printf("%d\n", arr[i]);
            even_count++;
        } 
        else 
        {
            odd_count++;
        }
    }

    // Print the summary of even and odd numbers
    printf("%d even numbers and %d odd numbers.\n", even_count, odd_count);

    return 0;
}

