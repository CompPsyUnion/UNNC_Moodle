#include <stdio.h>

int main(void)
{
   	char choice = 0;

	printf("Main Menu:\n");
	printf("1: Load Data From File\n");
	printf("2: Save Current Data to File\n");
	printf("3: View Students\n");
	printf("4: Add Students\n");
	printf("5: Delete Students\n");
	printf("6: Show Class Status\n");
	printf("7: Show Final Grades\n");
	printf("8: Quit\n");
	
	do
	{
   		scanf(" %c", &choice);

   		if(choice == '1')
 	   		printf("You have chosen option 1\n");
   		else if(choice == '2')
 	   		printf("You have chosen option 2\n");
   		else if(choice == '3')
 	   		printf("You have chosen option 3\n");
   		else if(choice == '4')
 	   		printf("You have chosen option 4\n");
   		else if(choice == '5')
 	   		printf("You have chosen option 5\n");
   		else if(choice == '6')
 	   		printf("You have chosen option 6\n");
   		else if(choice == '7')
 	   		printf("You have chosen option 7\n");
   		else if(choice == '8')
 	   		printf("You have chosen option 8\n");
 	   	else	
 	   		printf("Please choose one option from 1-8\n");
 	   		
 	}while(choice!='8');
   
   return 0;
}

