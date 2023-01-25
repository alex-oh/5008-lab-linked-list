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
    printf("wins: %d year: %d\n", node->num_wins, node->year);
}

void free_node(node_t* node){
	if (node == NULL){
		return;
	}
	free(node);
}

node_t* build_list(int* wins, int* years, int size) {
    node_t* head = new_node(0, 0, NULL);
    node_t* p = new_node(0, 0, head);
    int i = 0;
    while (i < size){
        if(i == 0) {
            head->next = new_node(wins[i], years[i], NULL);
            p->next = head->next;
        }
        else {
            p->next->next = new_node(wins[i], years[i], NULL);
            p->next = p->next->next;
        }
        i++;
    }
    free_node(p);
    //returns head pointing to first element of the list
    return head;
}

void print_list(node_t* head){
    node_t* p = new_node(0, 0, head);
    
    while(p->next != NULL){
        print_node(p->next);
        p->next = p->next->next;
    }
    free_node(p);
}

int free_list(node_t* head){
    node_t* p = new_node(0, 0, head);
    node_t* temp = new_node(0, 0, NULL);
    while(p->next->next != NULL){
        if(p->next->next != NULL) {
            temp->next = p->next->next;
        }
        // free the node p is pointing at
        free_node(p->next);
        // point p at the same node temp is pointing at
        if(temp->next != NULL && temp!= NULL){
            p->next = temp->next;
        }
        else {
            printf("exit the lOOP\n");
            p->next = NULL;
        }
    }
    free_node(temp);
    free_node(p->next);
    free_node(p);
    return 1;
}

int main()
{
    int test_years[5] = {2018, 2017, 2016, 2015, 2014};
    int test_wins[5] = {108, 93, 93, 78, 71};

    // TODO: Implement me!
    // build list
    node_t* head = build_list(test_wins, test_years, 5);
    // print list. since head is pointing to the first element,
    // we pass head->next into print_list
    print_list(head->next);


    free_list(head);
    
    return 0;
}