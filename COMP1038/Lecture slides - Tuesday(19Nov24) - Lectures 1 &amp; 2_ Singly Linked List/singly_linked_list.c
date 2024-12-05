#include<stdio.h>
#include<stdlib.h>

typedef struct Node 
{
        int data;
        struct Node *next;
}node;

void insertBegining(node **head_ref, int new_data) 
{ 
   // allocate node
   node *new_node = (node*) malloc(sizeof(node)); 
   //put in the data
   new_node->data = new_data; 
   //Make next of new node as head
   new_node->next = (*head_ref); 
   //Move the head to point to the new node
   (*head_ref) = new_node; 
} 

void insertEnd(node **head_ref, int new_data)
{
   node *tmp = *head_ref;
   //allocate node
   node *new_node = (node*) malloc(sizeof(node)); 
   //put in the data
   new_node->data = new_data;
   //This new node is going to be the last node, so make next of it as NULL
   new_node->next = NULL; 
   // If list is empty
   if(*head_ref == NULL)
   {
     //move the head to point to the new node
     (*head_ref) = new_node; 
     return;
   }
   //Iterate through the list till we encounter the last node.
   while(tmp->next!=NULL)
      tmp = tmp -> next;
   
   //Allocate memory for the new node and put data in it.
   tmp->next = new_node;
}

void insertAfter(node **head_ref, int new_data, int insert_after)
{
        node *tmp = *head_ref;

        //Search for the key to be inserted after
         while (tmp != NULL && tmp->data != insert_after) 
           tmp = tmp->next; 

        //If key was not present in linked list
        if (tmp == NULL)
         return;

        //allocate node
        node *new_node = (node*) malloc(sizeof(node)); 

        //put in the data
        new_node->data = new_data; 

        //Make next of new node as next of prev_node
        new_node->next = tmp->next;  
   
        //move the next of prev_node as new_node
        tmp->next = new_node; 
}

void deleteKey(node **head_ref, int key)
{       
        
    node* tmp = *head_ref, *prev; 
  
    // If head node itself holds the key to be deleted 
    if (tmp != NULL && tmp->data == key) 
    { 
        *head_ref = tmp->next;   // Changed head 
        free(tmp);               // free old head 
        return; 
    } 
  
    // Search for the key to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 
    while (tmp != NULL && tmp->data != key) 
    { 
        prev = tmp; 
        tmp = tmp->next; 
    } 
  
    // If key was not present in linked list 
    if (tmp == NULL) return; 
  
    // Unlink the node from linked list 
    prev->next = tmp->next; 
  
    free(tmp);  // Free memory 
}

void deleteAtIndex(node **head_ref, int index)
{       
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   node* tmp = *head_ref; 
  
    // If head needs to be removed 
    if (index == 0) 
    { 
        *head_ref = tmp->next;   // Change head 
        free(tmp);               // free old head 
        return; 
    } 

    // Find previous node of the node to be deleted 
    for (int i=0; tmp!=NULL && i<index-1; i++) 
         tmp = tmp->next; 
  
    // If position is more than number of ndoes 
    if (tmp == NULL || tmp->next == NULL) 
         return; 
  
    // Node tmp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    node *next = tmp->next->next; 
    
    // Unlink the node from linked list 
      free(tmp->next);  // Free memory
      
    tmp->next = next;  // Unlink the deleted node from list
} 

void printList(node **head_ref)
{
        node *tmp = *head_ref;
        if(tmp==NULL)
        {
           printf("empty");  
           return;
        }
        while (tmp != NULL)
        {
           printf("%d ",tmp->data);
           tmp = tmp->next;
        }
}

int search(node **head_ref, int key)
{       
        node *tmp = *head_ref;
        //Iterate through the entire linked list and search for the key
        while(tmp!=NULL)
        {
                if(tmp->data == key) //key is found.
                        return 1;
                tmp = tmp -> next;//Search in the next node.
        }
        //Key is not found
        return 0;
}

int main()
{
        /* start always points to the first node of the linked list.
           temp is used to point to the last node of the linked list.*/
        int query;
        node *head= NULL;
        /* Here in this code, we take the first node as a dummy node.
           The first node does not contain data, but it used because to avoid handling special cases
           in insert and delete functions.
         */
        printf("1. Insert begining\n");
        printf("2. Insert end\n");
        printf("3. Insert after\n");
        printf("4. Delete key\n");
        printf("5. Delete at index\n");
        printf("6. Print\n");
        printf("7. Find\n");
        printf("8. Exit\n");
        do
        {
                printf("Enter your choice: ");
                scanf("%d",&query);
                if(query==1)
                {
                        int new_data;
                        printf("Enter a number: ");
                        scanf("%d",&new_data);
                        insertBegining(&head,new_data);
                }
                else if(query==2)
                {
                        int new_data;
                        printf("Enter a number: ");
                        scanf("%d",&new_data);
                        insertEnd(&head,new_data);
                }
                else if(query==3)
                {
                        int new_data, insert_after;
                        printf("Enter a number: ");
                        scanf("%d",&new_data);
                        printf("Inser after the number: ");
                        scanf("%d",&insert_after);
                        insertAfter(&head,new_data,insert_after);
                }
                else if(query==4)
                {
                        int key;
                        printf("Enter a number: ");
                        scanf("%d",&key);
                        deleteKey(&head,key);
                }
                else if(query==5)
                {
                        int index;
                        printf("Enter a index: ");
                        scanf("%d",&index);
                        deleteAtIndex(&head,index);
                }
                else if(query==6)
                {
                        printf("The list is:");
                        printList(&head);
                        printf("\n");
                }
                else if(query==7)
                {
                        int data;
                        printf("Enter a number: ");
                        scanf("%d",&data);
                        int status = search(&head,data);
                        if(status)
                        {
                                printf("Element Found\n");
                        }
                        else
                        {
                                printf("Element Not Found\n");

                        }
                }
                else if(query==8)
                {
                  exit(0);
                }
                else
                {
                  printf("Invalid input.\n");
                }
        }while(1);


}
