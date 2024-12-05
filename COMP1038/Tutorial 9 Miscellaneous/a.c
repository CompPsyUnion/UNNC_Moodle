#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

////////////////////////////////////////////////////////////////////////////////
// Internal definition and functions.  Only to be used by the trie
// functions themselves.

#define TRIE_WIDTH 26

// Internal structure of each level.
struct trie_node {
   int valid[TRIE_WIDTH];	           // Is this the end of a valid word?
   struct trie_node *children[TRIE_WIDTH];  // The rest of any words with this prefix.
};

// Overall data-type.
struct trie {
   struct trie_node *root;
};

struct trie_node *create_trie_node();
void trie_destroy_rec(struct trie_node *n);

////////////////////////////////////////////////////////////////////////////////
// External definitions and functions.  The "public interface" to the Trie.
typedef struct trie Trie;

Trie *trie_create();
void trie_destroy(Trie * t);
int trie_add(Trie *t, const char *str);
int trie_contains(Trie *t, const char *str);

////////////////////////////////////////////////////////////////////////////////
// Implementation of the functions.

/* Internal function to allocate and initialise a new level of the trie.
** Returns NULL on failure. */
struct trie_node *create_trie_node()
{
   struct trie_node *n = malloc(sizeof(struct trie_node));
   if(n == NULL)
   {
      return NULL;
   }

   for(int i = 0; i < TRIE_WIDTH; i++)
   {
      n->valid[i] = 0;
      n->children[i] = NULL;
   }

   return n;
}

/* Create a new Trie object.
** Should be destroyed with trie_destroy() when finished with.
** Returns NULL on failure.
*/
Trie *trie_create()
{
   Trie *t = malloc(sizeof(Trie));
   if(t == NULL)
   {
      return NULL;
   }

   t->root = create_trie_node();
   if(t->root == NULL)
   {
      free(t);
      return NULL;
   }
   
   return t;
}

/** Given a Trie, free all allocated memory.
 ** Once this function is called, t is no longer a valid reference and
 ** should no longer be used.
 */
void trie_destroy(Trie * t)
{
   if(t == NULL)
   {
      return;
   }

   struct trie_node *cur = t->root;
   trie_destroy_rec(cur);
   free(t);
}

/* Internal function to recursively destroy trie levels. */
void trie_destroy_rec(struct trie_node *n)
{
   for(int i = 0; i < TRIE_WIDTH; i++)
   {
      if(n->children[i] != NULL)
      {
	 trie_destroy_rec(n->children[i]);
      }
   }
   free(n);
}

/* Add the given non-empty string to the Trie.
** str is assumed to contain only the characters 'A'..'Z'.
** Adding the same string multiple times has no effect.
**
** Returns false if t or str are NULL.
** Returns true if successfully added, false otherwise.  If false, memory
**   which was allocated in this function may not be immediately freed but
**   it will be accessible and freed when trie_destroy() is eventually called.
*/
int trie_add(Trie *t, const char *str)
{
   if(t == NULL || str == NULL)
   {
      return 0;
   }
   
   struct trie_node *cur = t->root;
   int len = strlen(str);
   int pos;
   for(int sIdx = 0; sIdx < len; sIdx++)
   {
      pos = str[sIdx] - 'A'; // convert captial letters into 0..25
      
      if(cur->children[pos] == NULL)
      {
	 cur->children[pos] = create_trie_node();
	 if(cur->children[pos] == NULL)
	 {
	    return 0;
	 }
      }
      cur = cur->children[pos];
   }
   cur->valid[pos] = 1;
   return 1;
}

/* Does the Trie contain the given non-empty string?
** str is assumed to contain only the characters 'A'..'Z'.
** Returns true/false if it does/doesn't.
** Returns false if t or str are NULL.
*/
int trie_contains(Trie *t, const char *str)
{
   // TODO
   // CORRECTLY IMPLEMENT THIS FUNCTION
   
   if(t == NULL || str == NULL)
   {
      return 0;
   }
   
   struct trie_node *cur = t->root;
   int len = strlen(str);
   int pos;  
   
   for(int sIdx = 0; sIdx < len; sIdx++)
   {
      pos = str[sIdx] - 'A'; // convert captial letters into 0..25
      
      if(cur->children[pos] != NULL)
	  cur = cur->children[pos];
      else
	  return 0;
   }
      
   return 1;			
}


////////////////////////////////////////////////////////////////////////////////
// main function for testing.

int main(int argc, char *argv[])
{
   Trie *t = trie_create();
   if(t == NULL)
   {
      printf("Error creating trie.\n");
      exit(1);
   }

   assert(!trie_contains(NULL, "A"));
   assert(!trie_contains(t, NULL));
   
   assert(!trie_contains(t, "A"));
   assert(!trie_contains(t, "TEST"));

   assert(trie_add(t, "TEST"));
   assert(trie_contains(t, "TEST"));
   assert(!trie_contains(t, "TESTING"));
   assert(!trie_contains(t, "A"));
   assert(!trie_contains(t, "BOO"));

   assert(trie_add(t, "TESTING"));
   assert(trie_contains(t, "TEST"));
   assert(trie_contains(t, "TESTING"));
   assert(!trie_contains(t, "EDT"));
   assert(!trie_contains(t, "STRING"));
   assert(!trie_contains(t, "A"));
   assert(!trie_contains(t, "BOO"));

   assert(trie_add(t, "A"));
   assert(trie_contains(t, "A"));
   assert(!trie_contains(t, "AA"));

   assert(trie_add(t, "A"));
   assert(trie_contains(t, "A"));
   assert(!trie_contains(t, "AA"));

   assert(trie_add(t, "AA"));
   assert(trie_contains(t, "A"));
   assert(trie_contains(t, "AA"));
   assert(!trie_contains(t, "AAA"));

   assert(trie_add(t, "AB"));
   assert(trie_add(t, "BA"));
   assert(trie_contains(t, "A"));
   assert(trie_contains(t, "AA"));
   assert(trie_contains(t, "AB"));
   assert(trie_contains(t, "BA"));
   assert(!trie_contains(t, "BB"));
   assert(!trie_contains(t, "AAA"));
   
   trie_destroy(t);
   
   printf("Tests passed\n");
}
