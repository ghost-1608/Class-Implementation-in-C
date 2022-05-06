/* Concept code to implement classes in C
   Currently only implements the feature of class methods
   Uses struct to store an int value and a function pointer to a function defined elsewhere
   Separate function implemented outside struct to emulate class constructor */


#include <stdio.h>
#include <stdlib.h>

// Create the struct with one "element" (value) and one "class method" (function pointer to 'display')
struct Foo
{
	int value;
	void (*display)(struct Foo*);
};

// Define the "class method" (void display). Function accepts the struct pointer to access the elements
// Since this is the last "class method", the struct pointer needs to be freed in this function
void display(struct Foo* s)
{
	printf("%d", s->value);
	free(s);
}

// Function created to emulate behaviour of a class constructor
// Important as it maps the 'display' function pointer to the 'display' void function just created
struct Foo* Foo(int a)
{
	struct Foo* f = (struct Foo*) malloc(sizeof(struct Foo));
	f->value = a;
	f->display = &display;
	return f;
}

int main()
{
	struct Foo* f = Foo(69);	// Create struct Foo variable f and call the "constructor" (struct Foo* function) Foo()

	(*(f->display))(f);	// De-references the 'display' member of the struct pointer 'f', then passes 'f' as a parameter
}