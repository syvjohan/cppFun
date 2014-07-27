#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
	int x;
	node *next;
};

int main() {
	node *root;       // This won't change, or we would lose the list in memory
  node *conductor;  // Points to each node as it traverses the list

  root = new node;  // Sets it to actually point to something
  root->next = NULL; // Otherwise it would not work well
  root->x = 12;

  conductor = root; // The conductor points to the first node
  if ( conductor != 0 ) {
    while ( conductor->next != NULL) {
      conductor = conductor->next;
  		printf("%i \n", conductor->x);	
  	}
  }
  conductor->next = new node;  // Creates a node at the end of the list
  conductor = conductor->next; // Points to that node
  conductor->next = NULL;         // Prevents it from going any further
  conductor->x = 42; //add a new value to the list
  printf("%i \n", conductor->x);

	return 0;
}
