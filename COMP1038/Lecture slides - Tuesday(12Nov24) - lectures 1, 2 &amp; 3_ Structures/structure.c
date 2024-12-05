//-------------------------------- example 1 ----------------------------------
/*#include <stdio.h>

struct card
{
	char *face;
	char *suit;
};

int main(void)
{
	struct card myCard = {"Three", "Hearts"};
	
	printf("%s\n", myCard.face);
	printf("%s\n", myCard.suit);
	
	return 0;
}*/

//-------------------------------- example 2 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	struct card
	{
		char *face;
		char *suit;
	};
	
	struct card myCard = {"Three", "Hearts"};
	
	printf("%s\n", myCard.face);
	printf("%s\n", myCard.suit);
	
	return 0;
}*/

//-------------------------------- example 3 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	struct card
	{
		char *face;
		char *suit;
	} myCard;
	
	myCard.face = "Three";
	myCard.suit = "Hearts";
	
	printf("%s\n", myCard.face);
	printf("%s\n", myCard.suit);
	
	return 0;
}*/

//-------------------------------- example 4 ----------------------------------
/*#include <stdio.h>

int test();

int main(void)
{
	struct card
	{
		char *face;
		char *suit;
	};
	
	struct card myCard = {"Three", "Hearts"};
	
	printf("%s\n", myCard.face);
	printf("%s\n", myCard.suit);
	
	return 0;
}

int test()
{
	struct card a;
}*/

//-------------------------------- example 5 ----------------------------------
/*#include <stdio.h>
#include <string.h> // memcpy

int main(void)
{
	struct card
	{
		char *face;
		char *suit;
	}card1, card2, *p;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	card2.face = "Nine";
	card2.suit = "Spades";
	
	printf("c1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	// copy the whole structure
	card2 = card1;
	
	printf("\n\ncard2 = card1\n");
	printf("c1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	card2.face = "Nine";
	card2.suit = "Spades";
	
	printf("\n\nc1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	// copy each member
	card2.face = card1.face;
	card2.suit = card1.suit;
	
	printf("\n\nCopy each member individually\n");
	printf("c1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	card2.face = "Nine";
	card2.suit = "Spades";
	
	printf("\n\nc1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	p = &card1;
	//memcpy(&card2, p, sizeof(card1));
	memcpy(&card2, &card1, sizeof(card1));
	
	printf("\n\nUse memcpy\n");
	printf("c1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("c2f: %s\n", card2.face);
	printf("c2s: %s\n", card2.suit);
	
	return 0;
}*/

//-------------------------------- example 6 ----------------------------------
/*#include <stdio.h>

struct card
{
	char *face;
	char *suit;
};

int main(void)
{
	struct card card1, *p;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	
	p = &card1;
	
	printf("c1f: %s\n", card1.face);
	printf("c1s: %s\n", card1.suit);
	printf("pf: %s\n", p->face);
	printf("ps: %s\n", p->suit);	
	printf("pf: %s\n", (*p).face);
	printf("ps: %s\n", (*p).suit);	
	
	return 0;
}*/

//-------------------------------- example 7 ----------------------------------
/*#include <stdio.h>

struct card
{
	char *face;
	char *suit;
};

int main(void)
{
	struct card card1, card2;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	card2.face = "Nine";
	card2.suit = "Spades";
	
	printf("face: %d\n", (card1.face == card2.face));
	printf("suit: %d\n", (card1.suit == card2.suit));
	
	card2 = card1;
	
	printf("face: %d\n", (card1.face == card2.face));
	printf("suit: %d\n", (card1.suit == card2.suit));
	
	return 0;
}*/

//-------------------------------- example 8 ----------------------------------
/*#include <stdio.h>

struct card
{
	char *face;
	char *suit;
};

int test(struct card c);

int main(void)
{
	struct card card1;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	
	printf("%s\n", card1.face);
	printf("%s\n", card1.suit);
	
	test(card1);
	
	printf("%s\n", card1.face);
	printf("%s\n", card1.suit);
	
	return 0;
}

int test(struct card c)
{
	c.face = "Nine";
	c.suit = "Spades";
	
	printf("%s\n", c.face);
	printf("%s\n", c.suit);
}*/

//-------------------------------- example 9 ----------------------------------
/*#include <stdio.h>

struct lottery
{
	int num[3];
};

int test(struct lottery c, int *n);

int main(void)
{
	struct lottery lot1;
	
	int number[3] = {1, 2, 3};
	
	lot1.num[0] = 10;
	lot1.num[1] = 20;
	lot1.num[2] = 30;
	
	printf("%d %d\n", lot1.num[0], number[0]);
	printf("%d %d\n", lot1.num[1], number[1]);
	printf("%d %d\n", lot1.num[2], number[2]);
	
	test(lot1, number);
	
	printf("%d %d\n", lot1.num[0], number[0]);
	printf("%d %d\n", lot1.num[1], number[1]);
	printf("%d %d\n", lot1.num[2], number[2]);
	
	return 0;
}

int test(struct lottery c, int *n)
{	
	c.num[0] = 40;
	c.num[1] = 50;
	c.num[2] = 60;
	
	n[0] = 4;
	n[1] = 5;
	n[2] = 6;
	
	printf("\n\nValues are changed by test function\n");
	printf("%d %d\n", c.num[0], n[0]);
	printf("%d %d\n", c.num[1], n[1]);
	printf("%d %d\n\n\n", c.num[2], n[2]);
}*/


//-------------------------------- example 10 ----------------------------------
/*#include <stdio.h>

struct letter
{
	int num;
	char upp;
	char low;
};

int main(void)
{
	struct letter alpha[26];
	
	int i = 0;
	for(i = 0; i < 26; i++)
	{
		alpha[i].num = 1 + i;
		alpha[i].upp = 65 + i;
		alpha[i].low = 97 + i;
	}
	
	for(i = 0; i < 26; i++)
	{
		printf("%d ", alpha[i].num);
	}
	printf("\n");
	for(i = 0; i < 26; i++)
	{
		printf("%c ", alpha[i].upp);
	}
	printf("\n");
	for(i = 0; i < 26; i++)
	{
		printf("%c ", alpha[i].low);
	}
	printf("\n");
	
	return 0;
}*/

//-------------------------------- example 11 ----------------------------------
/*#include <stdio.h>

typedef struct card
{
	char *face;
	char *suit;
} Card;

int main(void)
{
	Card card1;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	
	printf("%s\n", card1.face);
	printf("%s\n", card1.suit);
		
	return 0;
}*/

//-------------------------------- example 12 ----------------------------------
/*#include <stdio.h>

struct card
{
	char *face;
	char *suit;
};

int main(void)
{
	typedef struct card Card;
	Card card1;
	
	card1.face = "Three";
	card1.suit = "Hearts";	
	
	printf("%s\n", card1.face);
	printf("%s\n", card1.suit);
		
	return 0;
}*/

//-------------------------------- example 13 ----------------------------------
/*#include <stdio.h>

int main(void)
{
	typedef int Cat;
	Cat myCat = 1;
	
	// don't do this unless you have a very good reason to!!!
	// e.g. portability i.e. data size varies from machine to machine

	printf("%d\n", myCat);
		
	return 0;
}*/

//-------------------------------- example 14 ----------------------------------
/*// Example: custom data-type to represent a point in 2D space.
// Several functions are given in both the pointer and non-pointer versions 
// in order to demonstrate the syntax for accessing elements of a structure 
// via a pointer.

#include <stdio.h>
#include <stdlib.h>

struct point {
   int x;
   int y;
};
typedef struct point Point;

// Function to print out the coordinate represented by the point.
void point_print(Point p)
{
	printf("%d,%d\n", p.x, p.y);
}

// Version of the print function that takes a pointer instead. 
void point_p_print(Point *p)
{
	printf("%d,%d\n", p->x, p->y);
}

// Are two points equal? 
int point_equal(Point a, Point b)
{
	return ((a.x == b.x) && (a.y == b.y));
}

// Version of the equal function that takes pointers instead.
int point_p_equal(Point *a, Point *b)
{
   return ((a->x == b->x) && (a->y == b->y));
}

// Function to create and initalise a point to the given values.
// Returns a pointer to the new Point or NULL on error.
Point *point_create(int x, int y)
{
	Point *p = malloc(sizeof(Point));
	if(p == NULL)
	{
		return NULL;
	}
	
	p->x = x;
	p->y = y;
	
	return p;
}

// Destroys a point created by point_create and frees any associated memory.
void point_destroy(Point *p)
{
	free(p);
}

int main(void)
{
	Point p1 = {2, 6};
	Point p2;
	
	p2.x = 2;
	p2.y = 9;
	
	point_print(p1);
	if(point_equal(p1, p2))
	{
		printf("p1 equal to p2\n");
	}
	else
	{
		printf("p1 NOT equal to p2\n");
	}
	
	Point p3 = {-3, 76};
	Point *p4 = &p3;
	Point *p5 = point_create(-3, 76);
	
	point_p_print(p4);
	if(point_p_equal(p4, p5))
	{
		printf("p4 equals p5\n");
	}
	else
	{
		printf("p4 NOT equals p5\n");
	}

	point_destroy(p5);
}*/

//-------------------------------- example 15 ----------------------------------
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prompt.h"

struct student {
	int id;
	char *name;
	float avg_mark;
};

// Print the details for a student.
void print_student(struct student s)
{
	printf("id = %d\n", s.id);
	printf("name = %s\n", s.name);
	printf("avg_mark = %f\n", s.avg_mark);
}

// Return true if two students are equal.
int equal_students(struct student a, struct student b)
{
	if(a.id != b.id)
	{
		return 0;
	}
	
	if(a.avg_mark != b.avg_mark)
	{
		return 0;
	}
	
	if(strcmp(a.name, b.name) != 0)
	{
		return 0;
	}
	
	return 1;
}

// Free any allocated resources for the given student.
void free_student(struct student s)
{
	free(s.name);
}

int main(int argc, char *argv[])
{
	struct student me;
	me.id = 12345;
	me.name = prompt("Name 1: ");
	me.avg_mark = 88;
	
	struct student you;
	you.id = 12345;
	you.name = prompt("Name 2: ");
	you.avg_mark = 88;
	
	if(equal_students(me, you))
	{
		printf("Same\n");
	}
	else
	{
		printf("Diff\n");
	}
	
	free_student(me);
	free_student(you);

	return 0;	
}*/

//-------------------------------- example 16 ----------------------------------
/*#include <stdio.h>

// structure definition
struct card
{
	char *face;
	char *suit;
	struct card card2; //error
	struct card *cardPtr;
};

int main(void)
{
	// myCard is a variable of type "struct card"
	struct card myCard = {"Three", "Hearts"};
	
	printf("%s\n", myCard.face);
	printf("%s\n", myCard.suit);
	
	return 0;
}*/