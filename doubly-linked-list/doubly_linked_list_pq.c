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

void insert_from_head(double priority) {
    struct node* newNode = create_new_node(priority);
    struct node* temp = head;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        while (priority > temp->priority) {
            temp = temp->next;
        }
        newNode->next = temp;
        newNode->previous = temp->previous;
        if (temp->previous != NULL) {
            temp->previous->next = newNode;
        } else {
            head = newNode;
        }
        temp->previous = newNode;
    }
}

void insert_from_tail(double priority) {
    struct node* newNode = create_new_node(priority);
    struct node* temp = tail;

    if (tail == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        while (priority < temp->priority) {
            temp = temp->previous;
        }
        newNode->previous = temp;
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->previous = newNode;
        } else {
            tail = newNode;
        }
        temp->next = newNode;
    }
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

double average_priority() {
    struct node* temp = head;
    double prioritySum = 0;
    int count = 0;

    while (temp != NULL) {
        prioritySum += temp->priority;
        count++;
        temp = temp->next;
    }

    return count > 0 ? prioritySum / count : 0;
}

void reset_queue() {
    struct node* temp = head;

    while (temp != NULL) {
        free(temp);
        temp = temp->next;
    }

    head = NULL;
    tail = NULL;
}

void enqueue(double priority) {
    double averagePriority = average_priority();

    if (priority < averagePriority) {
        // printf("Priority %f > %f (avg): inserting from head!\n", priority, averagePriority);
        insert_from_head(priority);
        // printf("Enqueue - ");
        // traversal_print();
        // printf("\n");
    } else {
        // printf("Priority %f < %f (avg): inserting from tail!\n", priority, averagePriority);
        insert_from_tail(priority);
        // printf("Enqueue - ");
        // traversal_print();
        // printf("\n");
    }
}

double dequeue() {
    if (head == NULL) {
        fprintf(stderr, "Cannot dequeue from an empty queue!\n");
        exit(1);
    }
    // traversal_print();

    struct node* temp = head;
    double priority = temp->priority;
    head = head->next; 
    if (head != NULL) // should be NULL if last element
        head->previous = NULL;
    free(temp);

    // printf("Dequeue - ");
    // printf("List after dequeue:\n");
    // traversal_print();
    // printf("\n");

    return priority;
}

// int main() {
    
//     enqueue(6.0);
//     enqueue(12.0);
//     enqueue(7.0);
//     enqueue(2.0);

//     traversal_print();

//     dequeue();
//     dequeue();

//     traversal_print();

//     reset_queue();

//     traversal_print();
// }