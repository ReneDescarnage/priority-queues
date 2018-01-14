#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "./doubly_linked_list_pq.h"

void test_enqueue_list() {
    // setup
    reset_queue();

    // test
    assert(traversal_count() == 0);
    enqueue(1.0);
    assert(traversal_count() == 1);

    // cleanup
    reset_queue();
}

void test_dequeue_list() {
    // setup
    reset_queue();
    enqueue(1.0);

    // test
    assert(traversal_count() == 1);
    dequeue();
    assert(traversal_count() == 0);
    
    // cleanup
    reset_queue();
}

void test_reset_list() {
    // setup
    reset_queue();
    enqueue(1.0);
    enqueue(2.0);

    // test
    assert(traversal_count() == 2);
    reset_queue();
    assert(traversal_count() == 0);
    
    // cleanup
    reset_queue();
}

void test_dequeue_smallest_element() {
    // setup
    reset_queue();
    enqueue(2.0);
    enqueue(3.0);
    enqueue(1.0);
    enqueue(6.0);

    // test
    assert(dequeue() == 1.0);
    
    // cleanup
    reset_queue();
}

void test_queue_maintains_internal_order() {
    // setup
    reset_queue();
    double values[6] = {1.715646, 0.763207, 1.044174, 1.336052, 1.487733, 0.851104};
    for (int i = 0; i < 6; i++) {
        enqueue(values[i]);
    }

    // test
    double pred = dequeue();
    for (int i = 1; i < 6; i++) {
        double current = dequeue();
        assert(pred < current);
        pred = current;
    }
    
    // cleanup
    reset_queue();
}

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
