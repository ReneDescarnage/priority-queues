#include <stdio.h>
#include <stdlib.h>

// Define node in the skewed heap.
struct node {
  double priority;
  struct node *left;
  struct node *right;
};

// Declare pointers to root of the heap.
struct node *root = NULL;

// Create a new node with given priority.
struct node *create_new_heap_node(double priority) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->priority = priority;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

// Merge two heap maintaining the balance.
struct node *merge(struct node *heap1, struct node *heap2) {
  struct node *temp;

  if (heap1 == NULL) {
    return heap2;
  } else if (heap2 == NULL) {
    return heap1;
  } else {
    if (heap1->priority > heap2->priority) {
      temp = heap1;
      heap1 = heap2;
      heap2 = temp;
    }
    temp = heap1->left;
    heap1->left = heap1->right;
    heap1->right = temp;
    heap1->left = merge(heap2, heap1->left);
  }

  return heap1;
}

// Traverse the heap and recursively count elements.
int traverse_count(struct node *node) {
  if (node != NULL) {
    return 1 + traverse_count(node->left) + traverse_count(node->right);
  }
  return 0;
}

// Count the elements in the heap.
int count_heap_elements() {
  return traverse_count(root); 
}

// Traverse the heap and recursively remove elements.
void traverse_reset(struct node *node) {
  if (node != NULL) {
    traverse_reset(node->left);
    traverse_reset(node->right);
    free(node);
  }
}

// Free the allocated space and reset root pointer.
void reset_heap() {
  traverse_reset(root);
  root = NULL;
}

// Enqueue a new element.
void enqueue_heap(double priority) {
  struct node *newNode = create_new_heap_node(priority);
  root = merge(root, newNode);
}

// Dequeue an element.
double dequeue_heap() {
  if (root == NULL) {
    fprintf(stderr, "Cannot dequeue from an empty heap!\n");
    exit(1);
  }

  struct node *temp1 = root->left;
  struct node *temp2 = root->right;
  double priority = root->priority;

  temp1 = merge(temp1, temp2);
  free(root);
  root = temp1;

  return priority;
}
