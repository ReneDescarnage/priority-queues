#include <stdio.h>
#include <stdlib.h>

// Define node in the linked list.
struct node {
  double priority;
  struct node *next;
  struct node *previous;
};

// Declare pointers to head and tail of the list.
struct node *head = NULL;
struct node *tail = NULL;

// Create a new node with given priority.
struct node *create_new_node(double priority) {
  struct node *new_node = (struct node *)malloc(sizeof(struct node));
  new_node->priority = priority;
  new_node->previous = NULL;
  new_node->next = NULL;
  return new_node;
}

// Insert a new node starting from the head of the list.
void insert_from_head(double priority) {
  struct node *new_node = create_new_node(priority);
  struct node *temp = head;

  if (head == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    while (priority > temp->priority) {
      temp = temp->next;
    }
    new_node->next = temp;
    new_node->previous = temp->previous;
    if (temp->previous != NULL) {
      temp->previous->next = new_node;
    } else {
      head = new_node;
    }
    temp->previous = new_node;
  }
}

// Insert a new node starting from the tail of the list.
void insert_from_tail(double priority) {
  struct node *new_node = create_new_node(priority);
  struct node *temp = tail;

  if (tail == NULL) {
    head = new_node;
    tail = new_node;
  } else {
    while (priority < temp->priority) {
      temp = temp->previous;
    }
    new_node->previous = temp;
    new_node->next = temp->next;
    if (temp->next != NULL) {
      temp->next->previous = new_node;
    } else {
      tail = new_node;
    }
    temp->next = new_node;
  }
}

// Count the elements in the list.
int count_list_elements() {
  struct node *temp = head;
  int count = 0;

  while (temp != NULL) {
    count++;
    temp = temp->next;
  }

  return count;
}

// Compute the average priority of head and tail.
double average_priority() {
  double sum = 0;
  int count = 0;

  if (head != NULL) {
    sum += head->priority;
    count++;
  }
  if (tail != NULL) {
    sum += tail->priority;
    count++;
  }

  return count == 0 ? 0 : sum / count;
}

// Free the allocated space and reset head/tail pointers.
void reset_list() {
  struct node *temp = head;

  while (temp != NULL) {
    free(temp);
    temp = temp->next;
  }

  head = NULL;
  tail = NULL;
}

// Enqueue a new element.
void enqueue_list(double priority) {
  double averageHeadTail = average_priority();

  if (priority < averageHeadTail) {
    insert_from_head(priority);
  } else {
    insert_from_tail(priority);
  }
}

// Dequeue an element.
double dequeue_list() {
  if (head == NULL) {
    fprintf(stderr, "Cannot dequeue from an empty queue!\n");
    exit(1);
  }

  struct node *temp = head;
  double priority = temp->priority;
  head = head->next;
  if (head != NULL) {
    head->previous = NULL;
  }
  free(temp);

  return priority;
}
