#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>


int main(){
      
     char WORDS[10][20]={"Apple","Banana","Cucumber","Dumpling","Eggplant","Fish","Garlic","Ham","Icecream","Jellies"}; 
       
      int num;
      printf("Enter the number of words to guess (<=10):");
      scanf("%d",&num);
      int count[num]; 
 
      srand(time(NULL));
           
      for(int i=0;i<num;i++)
      {
          count[i] = (int)strlen(WORDS[i]);
          printf("%s\n",WORDS[i]);
      }
      printf("\n");
            
   
    char again = 'y';
    while(again == 'y'){

            int x=rand()%(num);
            int life=5;
            char guess[20];
            
            printf("Word:");
            
            char new[20];
            for(int i=0;i<count[x];i++)
            {
                *(new+i) = '_';
            }
            for(int i=0;i<count[x];i++)
            {
                printf(" %c", new[i]);
            }
            printf("\n\n");
            
            
            for(;life>0;)
            {
                printf("Guess (%d lives): ",life);
                scanf("%s",guess);
                printf("\n");
                                
                if(strlen(guess)!=1)
                {
                    if(strlen(guess)==strlen(WORDS[x]))
                    {
                        int judge = 0;
                        for(int i=0;i<count[x];i++)
                        {
                            if(guess[i]!= WORDS[x][i])
                            {
                                break;
                            }
                            judge++;
                        }
                        if(judge==count[x])
                        {
                            printf("Correct!\n");
                            printf("Do you want to play again (y/n)? ");
                            scanf(" %c",&again);
		            break;
                        }
                    }
                    printf("Word:");
                    for(int i=0;i<count[x];i++)
                    {
                        printf(" %c", new[i]);
                    }
                    printf("\n\n");
                    life--;
                }
                else  
                {
                    
                    printf("Word:");
                    if (strstr(WORDS[x],guess)!= NULL)
                    {
                        for(int i=0;i<count[x];i++)
                        {
                            if(guess[0]==(char)WORDS[x][i])
                            {
                                *(new+i) = guess[0];
                            }
                        }
                        int correct = 0;
                        for(int i=0;i<count[x];i++)
                        {
                            if(new[i]!='_')
                            {
                                correct++;
                                continue;
                            }
                            break;
                        }
                        for(int i=0;i<count[x];i++)
                        {
                            printf(" %c", new[i]);
                        }
                        printf("\n\n");
                        if(correct == count[x]){
                            printf("Correct!\n");
                            printf("Do you want to play again? ");
			    scanf("%c",&again);
			      break;
                        }
                    }
                    else
                    {
                        for(int i=0;i<count[x];i++)
                        {
                            printf(" %c", new[i]);
                        }
                        printf("\n\n");
                    }
                    life--;
                    
                }
            }
            if(life == 0){
                printf("You have no more lives!\n");
                printf("Do you want to play again (y/n)? ");
                scanf(" %c",&again);
		
            }
    }
   
    exit(1);
}
