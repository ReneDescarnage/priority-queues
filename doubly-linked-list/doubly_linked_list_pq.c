// #include<stdio.h>
// #include<stdlib.h>

// struct node {
//     struct node *next;
//     struct node *previous;
//     double priority;
// };

// typedef struct node Node;

// Node *head = NULL;
// Node *tail = NULL;

// // // void enqueue() {

// // // }

// // // struct node* dequeue() {

// // // }

// void insert_at_head(Node *head, Node *tail, double priority) {
//     printf("ins\n");

//     struct node *newNode = (struct node*) malloc(sizeof(struct node));
//     newNode->priority = priority;

//     if (head == NULL) {
//         tail = newNode;
//     } else {
//         head->previous = newNode;
//     }

//     newNode->next = head;
//     head = newNode;

// }

// // void insert_at_tail(Node *head, Node *tail, double priority) {
    
// //     struct node *newNode = (struct node*) malloc(sizeof(struct node));
// //     newNode->priority = priority;

// //     if (head == NULL) {
// //         tail = newNode;
// //     } else {
// //         tail->next = newNode;
// //         newNode->previous = tail;
// //     }

// //     tail = newNode;

// // }

// void traverse(Node *head) {
//     printf("trav %s\n", (char *)&head);
//     struct node *temp = head;
//     // printf("node: %.f\n", temp->priority);
//     while(temp->next != NULL) {
//         // printf("node: %.f\n", temp->priority);
//         temp = temp->next;
//     }
// }

// int main() {
//     printf("main\n");
//     insert_at_head(head, tail, 1.0);
//     insert_at_head(head, tail, 2.0);
//     traverse(head);
// }

#include <stdio.h>
#include <stdlib.h>

struct node  {
	double priority;
	struct node* next;
	struct node* previous;
};

struct node* head;

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
		head = newNode;
		return;
	}
	head->previous = newNode;
	newNode->next = head; 
	head = newNode;
}

void append(double priority) {
	struct node* temp = head;
	struct node* newNode = create_new_node(priority);
	if (head == NULL) {
		head = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next;
	temp->next = newNode;
	newNode->previous = temp;
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

int main() {

	head = NULL;
	
    prepend(1.0);
    prepend(2.0);
    traversal_print();
	
}