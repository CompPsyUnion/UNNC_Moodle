#include<stdio.h>
#include <stdlib.h>
//self-referential structure

struct listnode{
	char data;//each list will contain a character
	struct listnode *nextPtr;//pointer to next node
};

typedef struct listnode ListNode;//synonym for struct listnode


//prototypes
void insert(ListNode **sPtr, char value);
char delete(ListNode **sPtr, char value);
int isEmpty(ListNode *sPtr);
void printList(ListNode *currentPtr);
void instructions(void);
void reverseList(ListNode **newList, ListNode *currentList);
void list_remove_last_node(ListNode **start);
void list_append(ListNode **start, int value);

int main(void)
{
	ListNode *startPtr = NULL;	//initially there are no nodes
	char item;//char input by user
	instructions();//print menu
	printf("%s","?");
	unsigned int choice;
	scanf("%u",&choice);

	//loop while user does not choose 3
	while (choice!=3)
	{
		switch (choice){
			case 1:
				printf("%s","Enter a character: ");
				scanf("\n%c",&item);
				insert(&startPtr,item);//insert item in list
				printList(startPtr);//print it
				break;
			case 2://delete an element
			//if the list is not empty
				if (!isEmpty(startPtr)){
					printf("%s","Enter character to be deleted: ");
					scanf("\n%c",&item);
					//if character is found, remove it
					if(delete(&startPtr, item)){//remove item
						printf("%c deleted.\n",item);
						printList(startPtr);
					}
					else{
						printf("%c not found\n\n",item);
					}
				}
				else{
					puts("List is empty.\n");
				}
				break;

			default:
				puts("Invalid choice.\n");
				instructions();
				break;
		}

		printf("%s","? ");
		scanf("%u",&choice);

	}

	ListNode *new = NULL;
	reverseList(&new, startPtr);
	printList(new);
	printList(startPtr);
	
	puts("End of run.");
}

//display program instruction to user

void instructions(void)
{
	puts("Enter your choice:\n1 to add \n 2 to delete\n 3 to end");
}

void insert(ListNode **sPtr, char value)
{
	 ListNode *newPtr = malloc(sizeof(ListNode)); //create node
	 if (newPtr!=NULL)
    {//is space available?
	 	newPtr->data = value;//place value in node
	 	newPtr->nextPtr = NULL;//nodes does not link to another one

	 	ListNode *previousPtr = NULL;
	 	ListNode *currentPtr = *sPtr;
	 	//loop to find current location in the list

	 	while (currentPtr!=NULL&&value>currentPtr->data){
	 		previousPtr = currentPtr;
	 		currentPtr = currentPtr->nextPtr;//interesting
		}
        if (previousPtr == NULL)
        {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        }
        else
        {
            previousPtr->nextPtr =newPtr;
            newPtr->nextPtr = currentPtr;
        }
	 }
	 else
     {
         printf("%c not inserted. No memory available,\n", value);
     }
}


//return 1 if the list is emppty
int isEmpty(ListNode *sPtr)
{
	return sPtr == NULL;
}


//print the list
void printList(ListNode *currentPtr) {
  //if List is empty
  if (isEmpty(currentPtr)) {
	puts("List is empty.\n");
  }
  else {
	while (currentPtr!=NULL) {
		printf("%c---> ", currentPtr->data);
		currentPtr = currentPtr->nextPtr;
	}
	puts("NULL\n");
  }
}
char delete(ListNode **sPtr, char value)
{
    //delete first node if a match is found
    if (value == (*sPtr)->data)
    {
        ListNode *tempPtr = *sPtr;    //hold onto node being removed
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);
        return value;
    }
    else
    {
        ListNode *previousPtr = *sPtr;
        ListNode *currentPtr = (*sPtr)->nextPtr;
        //loop to find the correct location in the list
        while(currentPtr != NULL && currentPtr->data!=value)
        {
            previousPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
        }
        //delete node
        if (currentPtr != NULL)
        {
            ListNode *tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        }
    }
    return '\0';
}

/*void insert(ListNodePtr* sPtr, char value)
{
	  ListNodePtr newPtr = malloc(sizeof(ListNode)); //create node
	 if (newPtr!=NULL)
    {//is space available?
	 	newPtr->data = value;//place value in node
	 	newPtr->nextPtr = (*sPtr)->nextPtr;//nodes does not link to another one
	 }
	 else
     {
         printf("%c not inserted. No memory available,\n", value);
     }
}*/

void yinsert(ListNode **sPtr, char value)
{
	 ListNode *newPtr = malloc(sizeof(ListNode)); //create node
	 if (newPtr!=NULL)
    {//is space available?
	 	newPtr->data = value;//place value in node
	 	newPtr->nextPtr = (*sPtr)->nextPtr;//nodes does not link to another one
       // (*sPtr)->nextPtr = newPtr;
 		(*sPtr)->nextPtr = newPtr;
 
 /*
  	previousPtr->nextPtr =newPtr;
	newPtr->nextPtr = currentPtr;*/
	 }
	 else
     {
         printf("%c not inserted. No memory available,\n", value);
     }
}

void reverseList(ListNode **newList, ListNode *currentList)
{
	ListNode *newNode = currentList;
	int i,length = 0;	
	while(newNode!=NULL)
	{
		length++;
		newNode = newNode->nextPtr;  		
	}
	
	int array[length];
	newNode = currentList;
	i = 0;
	while(newNode!=NULL)
	{
		array[i] = newNode->data;
		i++;
		newNode = newNode->nextPtr;  		
	}

	for(i=length-1;i>=0;i--)
		list_append(newList, array[i]);

}

void list_append(ListNode **start, int value)
{
  if(*start == NULL)
   {
      ListNode *n = malloc(sizeof(ListNode));
      if(n == NULL)
      {
	 // error, cannot allocate memory for new list node.
	 return;
      }
      n->data = value;
      n->nextPtr = NULL;
      *start = n;
   }
   else
   {
      ListNode *cur = *start;
      while(cur->nextPtr != NULL)
      {
	 cur = cur->nextPtr;
      }
      ListNode *n = malloc(sizeof(ListNode));
      if(n == NULL)
      {
	 // error, cannot allocate memory for new list node.
	 return;
      }
      n->data = value;
      n->nextPtr = NULL;
      cur->nextPtr = n;
   }
}
		
void list_remove_last_node(ListNode **start)
{
	ListNode *newNode = *start;
	ListNode *prev = *start;
	
	while (newNode->nextPtr!=NULL)
	{
		prev = newNode;
		newNode = newNode->nextPtr;
	}
	
	free(newNode); 
	prev->nextPtr = NULL;
}
  

