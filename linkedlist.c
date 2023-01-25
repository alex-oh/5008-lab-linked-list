// Modify this file
// compile with: gcc linkedlist.c -o linkedlist.out

#include <stdio.h>
#include <stdlib.h> // contains the functions free/malloc

// TODO: Create your node_t type here

// TODO: Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

// node defined above, assume defined as node_t
typedef struct node {
    int num_wins;
    int year;
    struct node* next;
}node_t;

node_t* new_node(int wins, int year, node_t* next) {

   node_t* newNode = (node_t*) malloc(sizeof(node_t));// allocate a new node, we have to put it on the heap! 

   newNode->num_wins = wins;
   newNode->year = year;
   newNode->next = next; 

   return newNode;
}

void print_node(node_t* node) {
    printf("wins: %d, year: %d", node->num_wins, node->year);
}

void free_node(node_t* node){
	if (node == NULL){
		return;
	}
    /*
	// free the data inside vector
	if (&(node->num_wins) != NULL){
		free(&(node->num_wins));
	}
    if (&(node->year) != NULL) {
        free(&(node->year));
    }
    */
	// free node
	free(node);
}

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Implement me!
    node_t* head = new_node(10, 5, NULL);
    print_node(head);

    free_node(head);

    return 0;
}