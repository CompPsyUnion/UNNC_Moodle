// C program for array implementation of stack 
#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
  
// A structure to represent a stack 
struct Stack { 
    int top; 
    unsigned capacity; 
    int* array; 
}; 
  
// function to create a stack of given capacity. It initializes size of 
// stack as 0 
struct Stack* createStack(unsigned capacity) 
{ 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack)); 
    stack->capacity = capacity; 
    stack->top = -1; 
    stack->array = (int*)malloc(stack->capacity * sizeof(int)); 
    return stack; 
} 
  
// Stack is full when top is equal to the last index 
int isFull(struct Stack* stack) 
{ 
    return stack->top == stack->capacity - 1; 
} 
  
// Stack is empty when top is equal to -1 
int isEmpty(struct Stack* stack) 
{ 
    return stack->top == -1; 
} 
  
// Function to add an item to stack.  It increases top by 1 
void push(struct Stack* stack, int item) 
{ 
    if (isFull(stack)) 
        return; 
    stack->array[++stack->top] = item; 
    printf("%d pushed to stack\n", item); 
} 
  
// Function to remove an item from stack.  It decreases top by 1 
int pop(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top--]; 
}

void printStack(struct Stack* stack)
{
    if (isEmpty(stack))
       {
          printf("Stack is empty");
          return;
       }
    else
       {  int i;
          for(i=stack->top;i>=0;i--)
          {
              printf("%d ", stack->array[i]);
          }
        }
}
  
// Driver program to test above functions 
int main() 
{ 
    struct Stack* stack = createStack(100); 
    int query;
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        do
        {
                printf("Enter your choice: ");
                scanf("%d",&query);
                if(query==1)
                {
                        int data;
                        printf("Enter a number: ");
                        scanf("%d",&data);
                        push(stack,data);
                }
                else if(query==2)
                {
                        int p = pop(stack);
                        if(p == INT_MIN)
                            printf("Stack is empty\n");
                        else
                            printf("%d popped from stack\n", p); 
                }
                else if(query==3)
                {
                        printf("The stack is: ");
                        printStack(stack);
                        printf("\n");
                }
                else if(query==4)
                {
                  return 0;
                }
                else
                {
                  printf("Invalid input.\n");
                }
        }while(1);
  
    return 0; 
} 
