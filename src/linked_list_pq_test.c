#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "linked_list_pq.h"

/*
Test if the linked list can correctly enqueue a new
element and hence grows in size of one.
*/
void test_enqueue_list() {
    // setup
    reset_list();

    // test
    assert(count_list_elements() == 0);
    enqueue_list(1.0);
    assert(count_list_elements() == 1);

    // teardown
    reset_list();
}

/*
Test if the linked list can correctly dequeue an element
and hence decrease in size of one.
*/
void test_dequeue_list() {
    // setup
    reset_list();
    enqueue_list(1.0);

    // test
    assert(count_list_elements() == 1);
    dequeue_list();
    assert(count_list_elements() == 0);
    
    // teardown
    reset_list();
}

/*
Test if the linked list can be correctly reset, i.e. all
elements are removed.
*/
void test_reset_list() {
    // setup
    reset_list();
    enqueue_list(1.0);
    enqueue_list(2.0);

    // test
    assert(count_list_elements() == 2);
    reset_list();
    assert(count_list_elements() == 0);
    
    // teardown
    reset_list();
}

/*
Test if the dequeue() methods returns the smallest element
in the list, i.e. the element with highest priority.
*/
void test_dequeue_smallest_element() {
    // setup
    reset_list();
    enqueue_list(2.0);
    enqueue_list(3.0);
    enqueue_list(1.0);
    enqueue_list(6.0);

    // test
    assert(dequeue_list() == 1.0);
    
    // teardown
    reset_list();
}

/*
Test if the list maintains a correct internal order of
the elements based on priority. In such case, in a
sequence of dequeue operations, every dequeued element
should be smaller (i.e. has higher priority) than the
element previously dequeued.
*/
void test_queue_maintains_internal_order() {
    // setup
    reset_list();
    double values[6] = {1.715646, 0.763207, 1.044174, 1.336052, 1.487733, 0.851104};
    for (int i = 0; i < 6; i++) {
        enqueue_list(values[i]);
    }

    // test
    double pred = dequeue_list();
    for (int i = 1; i < 6; i++) {
        double current = dequeue_list();
        assert(pred < current);
        pred = current;
    }
    
    // teardown
    reset_list();
}

/*
Run all the tests. If any assertion fails it will throw
an error and abort the program.
*/
int main() {
    printf("Testing 'test_enqueue_list'... ");
    test_enqueue_list();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_dequeue_list'... ");
    test_dequeue_list();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_reset_list'... ");
    test_reset_list();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_dequeue_smallest_element'... ");
    test_dequeue_smallest_element();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_queue_maintains_internal_order'... ");
    test_queue_maintains_internal_order();
    printf("\x1B[32mPASS\x1B[37m\n");

    return 0;
}
