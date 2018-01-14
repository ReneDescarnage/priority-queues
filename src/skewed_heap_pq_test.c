#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "skewed_heap_pq.h"

/*
Test if the skewed heap can correctly enqueue a new
element and hence grows in size of one.
*/
void test_enqueue_heap() {
    // setup
    reset_heap();

    // test
    assert(traversal_count_heap() == 0);
    enqueue_heap(1.0);
    assert(traversal_count_heap() == 1);

    // teardown
    reset_heap();
}

/*
Test if the skewed heap can correctly dequeue an element
and hence decrease in size of one.
*/
void test_dequeue_heap() {
    // setup
    reset_heap();
    enqueue_heap(1.0);

    // test
    assert(traversal_count_heap() == 1);
    dequeue_heap();
    assert(traversal_count_heap() == 0);
    
    // teardown
    reset_heap();
}

/*
Test if the skewed heap can be correctly reset, i.e. all
elements are removed.
*/
void test_reset_heap() {
    // setup
    reset_heap();
    enqueue_heap(1.0);
    enqueue_heap(2.0);

    // test
    assert(traversal_count_heap() == 2);
    reset_heap();
    assert(traversal_count_heap() == 0);
    
    // teardown
    reset_heap();
}

/*
Test if the dequeue() methods returns the smallest element
in the heap, i.e. the element with highest priority.
*/
void test_dequeue_smallest_element() {
    // setup
    reset_heap();
    enqueue_heap(2.0);
    enqueue_heap(3.0);
    enqueue_heap(1.0);
    enqueue_heap(6.0);

    // test
    assert(dequeue_heap() == 1.0);
    
    // teardown
    reset_heap();
}

/*
Test if the heap maintains a correct internal order of
the elements based on priority. In such case, in a
sequence of dequeue operations, every dequeued element
should be smaller (i.e. has higher priority) than the
element previously dequeued.
*/
void test_queue_maintains_internal_order() {
    // setup
    reset_heap();
    double values[6] = {1.715646, 0.763207, 1.044174, 1.336052, 1.487733, 0.851104};
    for (int i = 0; i < 6; i++) {
        enqueue_heap(values[i]);
    }

    // test
    double pred = dequeue_heap();
    for (int i = 1; i < 6; i++) {
        double current = dequeue_heap();
        assert(pred < current);
        pred = current;
    }
    
    // teardown
    reset_heap();
}

/*
Run all the tests. If any assertion fails it will throw
an error and abort the program.
*/
int main() {
    printf("Testing 'test_enqueue_heap'... ");
    test_enqueue_heap();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_dequeue_heap'... ");
    test_dequeue_heap();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_reset_heap'... ");
    test_reset_heap();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_dequeue_smallest_element'... ");
    test_dequeue_smallest_element();
    printf("\x1B[32mPASS\x1B[37m\n");

    printf("Testing 'test_queue_maintains_internal_order'... ");
    test_queue_maintains_internal_order();
    printf("\x1B[32mPASS\x1B[37m\n");

    return 0;
}