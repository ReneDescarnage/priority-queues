#include <stdio.h>
#include <stdlib.h>

struct node {
	double priority;
	struct node* next;
	struct node* previous;
};

struct node* head;
struct node* tail;

struct node* create_new_node(double priority) {
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->priority = priority;
	newNode->previous = NULL;
	newNode->next = NULL;
	return newNode;
}

void prepend(double priority) {
	struct node* newNode = create_new_node(priority);

	if (head == NULL) {
		tail = newNode;
	} else {
        head->previous = newNode;
    }

	newNode->next = head; 
	head = newNode;
}

void append(double priority) {
	struct node* newNode = create_new_node(priority);

	if (head == NULL) {
		tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
    }

	tail = newNode;
}

void traversal_print() {
	struct node* temp = head;
	printf("List: ");

	while (temp != NULL) {
		printf("%f ", temp->priority);
		temp = temp->next;
	}

	printf("\n");
}

// void enqueue() {}

// struct node* dequeue() {}

int main() {

	head = NULL;
    tail = NULL;
	
    prepend(1.0);
    prepend(2.0);
    append(3.0);
    traversal_print();
	
}