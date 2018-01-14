#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "skewed_heap_pq.h"

void test_enqueue_heap() {
    // setup
    reset_heap();

    // test
    assert(traversal_count_heap() == 0);
    enqueue_heap(1.0);
    assert(traversal_count_heap() == 1);

    // cleanup
    reset_heap();
}

void test_dequeue_heap() {
    // setup
    reset_heap();
    enqueue_heap(1.0);

    // test
    assert(traversal_count_heap() == 1);
    dequeue_heap();
    assert(traversal_count_heap() == 0);
    
    // cleanup
    reset_heap();
}

void test_reset_heap() {
    // setup
    reset_heap();
    enqueue_heap(1.0);
    enqueue_heap(2.0);

    // test
    assert(traversal_count_heap() == 2);
    reset_heap();
    assert(traversal_count_heap() == 0);
    
    // cleanup
    reset_heap();
}

void test_dequeue_smallest_element() {
    // setup
    reset_heap();
    enqueue_heap(2.0);
    enqueue_heap(3.0);
    enqueue_heap(1.0);
    enqueue_heap(6.0);

    // test
    assert(dequeue_heap() == 1.0);
    
    // cleanup
    reset_heap();
}

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
    
    // cleanup
    reset_heap();
}

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