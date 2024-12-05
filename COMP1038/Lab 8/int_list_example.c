#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* Unsorted integer list. */
struct int_list {
   int value;
   struct int_list *next;
};
typedef struct int_list IntList;

// Given a list, print the values in the list.
void list_print(IntList *start)
{
   IntList *cur = start;
   printf("[");
   if(cur != NULL)
   {
      printf("%d", cur->value);
      while(cur->next != NULL)
      {
	 cur = cur->next;
	 printf(",%d", cur->value);
      }
   }
   printf("]\n");
}

// Given a list, append the given value to the list.
// CHANGE: return true/false on success/failure.
int list_append(IntList **start, int val)
{
   if(*start == NULL)
   {
      IntList *n = malloc(sizeof(IntList));
      if(n == NULL)
      {
	 // error, cannot allocate memory for new list node.
	 return 0;
      }
      n->value = val;
      n->next = NULL;
      *start = n;
   }
   else
   {
      IntList *cur = *start;
      while(cur->next != NULL)
      {
	 cur = cur->next;
      }
      IntList *n = malloc(sizeof(IntList));
      if(n == NULL)
      {
	 // error, cannot allocate memory for new list node.
	 return 0;
      }
      n->value = val;
      n->next = NULL;
      cur->next = n;
   }
   return 1;
}

// Given a list, prepend the given value to the list.
// CHANGE: return true/false on success/failure.
int list_prepend(IntList **start, int val)
{
   IntList *n = malloc(sizeof(IntList));
   if(n == NULL)
   {
      // error, cannot allocate memory for new list node.
      return 0;
   }
   n->value = val;
   n->next = NULL;

   if(*start == NULL)
   {
      // empty list
      *start = n;
   }
   else
   {
      // existing list
      n->next = *start;
      *start = n;
   }
   return 1;
}

// Given a list, free all the elements of the list and set the start to NULL
// so we don't accidentally use it in the future.
void list_free(IntList **start)
{
   IntList *cur = *start;
   while(cur != NULL)
   {
      IntList *temp = cur->next;
      free(cur);
      cur = temp;
   }
   *start = NULL;
}

// Given a list, return the value of the n'th position (zero-based).
// If n is out-of-bounds, return 0.
int list_get(IntList *start, int n)
{
   IntList *cur = start;
   if(n < 0)
   {
      return -1;
   }
   while(cur != NULL)
   {
      if(n == 0)
      {
	 return cur->value;
      }
      else
      {
	 n--;
	 cur = cur->next;
      }
   }
   return -1;
}

// Given a list, return the length of the list.
int list_length(IntList *start)
{
   int len = 0;
   IntList *cur = start;
   while(cur != NULL)
   {
      len++;
      cur = cur->next;
   }
   return len;
}

// Given a list, insert a new val after the n'th position of the list (zero-based).
// If n < 0, insert at beginning.  If n >= length, insert at end.
// CHANGE: return true/false on success/failure.
int list_insert(IntList **start, int n, int val)
{
   if(*start == NULL || n <= 0)
   {
      // if empty, just reuse the prepend function to put it in list.
      // if n == 0, then we should prepend anyway.
      return list_prepend(start, val);
   }
   else
   {
      n--; // we've already dealt with the first position above, so decrement n.
      IntList *prev = *start;
      IntList *cur = (*start)->next;
      
      IntList *el = malloc(sizeof(IntList));
      if(el == NULL)
      {
	 return 0;
      }
      el->value = val;
      el->next = NULL;  // we overwrite this later, setting NULL here is for safety in case we make a mistake and forget to set it later.

      while(cur != NULL)
      {
	 if(n == 0)
	 {
	    prev->next = el;
	    el->next = cur;
	    return 1;
	 }
	 n--;
	 prev = cur;
	 cur = cur->next;
      }
      prev->next = el;
      el->next = NULL;
      return 1;
   }
}

// Given a list and a value, return true if it is in the list, false otherwise.
int list_contains(IntList *start, int target)
{
   IntList *cur = start;
   while(cur != NULL)
   {
      if(cur->value == target)
      {
	 return 1;
      }
      cur = cur->next;
   }
   return 0;
}

int main(int argc, char *argv[])
{
	int value;
		
	for(;;)
	{
		printf("Input: ");
		scanf("%d", &value);
		if(value == 0)
			break;
	}
	return 1;
}





