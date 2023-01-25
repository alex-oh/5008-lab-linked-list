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
	free(node);
}

node_t* build_list(int* wins, int* years, int size) {

    node_t* node_array[size];

    for ( int i = 0; i < size; i++ ) {
        node_array[i] = new_node(wins[i], years[i], NULL);
    }

    for ( int i = size-1; i > 0; i-- ) {
        node_array[i-1]->next = node_array[i];
    }

    return node_array[0];
}

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Implement me!
    node_t* head = new_node(10, 5, NULL);
    node_t* new = new_node(1, 2, NULL);

    head->next = new;
    

    print_node(head);
    print_node(new);

    free_node(head);
    free_node(new);

    return 0;
}