#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node *next;
    struct node *previous;
    int data;
    int priority;
};

struct node *head = NULL;
struct node *tail = NULL;

void enqueue() {

}

struct node* dequeue() {

}

void insert_at_head(int data, int priority) {

    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;

    if (head == NULL) {
        tail = newNode;
    } else {
        head->previous = newNode;
    }

    newNode->next = head;
    head = newNode;

}

void insert_at_tail(int data, int priority) {
    
    struct node *newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->priority = priority;

    if (head == NULL) {
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->previous = tail;
    }

    tail = newNode;

}

