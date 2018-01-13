#include <stdio.h>
#include <stdlib.h>

struct node {
	double priority;
	struct node* next;
	struct node* previous;
};

struct node* head = NULL;
struct node* tail = NULL;

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

double dequeue() {
    if (head == NULL) {
        fprintf(stderr, "Cannot dequeue from an empty queue!\n");
        exit(1);
    }

    struct node* temp = head;
    head = head->next;
    double priority = temp->priority;
    free(temp);

    return priority;
}

int main() {
	
    prepend(1.0);
    prepend(2.0);
    append(3.0);
    traversal_print();
	dequeue();
    dequeue();
    dequeue();
    traversal_print();

}