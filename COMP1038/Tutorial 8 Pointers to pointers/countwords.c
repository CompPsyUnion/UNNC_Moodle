#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include <ctype.h>
#include <time.h>

//int wordguess(char *word, char guess);

int main()
{
      	FILE *fp;
//	fp = (fopen("/usr/share/dict/linux.words", "r"));
 	fp = (fopen("/usr/share/dict/words", "r"));
  	if(fp == NULL)
   	{
       		printf("Error!");
       		exit(1);
   	}
   
    char word[50];
    int isWord;
    int length = 0;
 
    while(!feof(fp))
    {
    	isWord = 1;
            if(fscanf(fp,"%s",word) == EOF)
            	break;
            for(int i=0; i<strlen(word); i++)
            {
            	
            	if((word[i]<'A' || word[i]>'z') && word[i]!='-')
 //		if(word[i]<'9' && word[i]>'0')
            		isWord = 0;
            }
            if(isWord == 1)	
            	length++;
            else
            	isWord = 1;                     
   }
   
   printf("%d\n",length);
   fclose(fp);
}
