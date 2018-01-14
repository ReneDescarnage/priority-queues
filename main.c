#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>

#include "input.h"
#include "./doubly-linked-list/doubly_linked_list_pq.h"
#include "./skewed-heap/skewed_heap_pq.h"

void to_lowercase(char *string);

void run_tests(
    int queue_impl,
    int queue_size,
    int hold,
    char* dist_filepath,
    int num_ops,
    int num_trials,
    char* save_name
);

int main(int argc, char *argv[]) {
    int queue_impl = 0; // 0 for linked list and 1 for heap
    int queue_size = 0;
    int hold = 1;
    char* dist_filepath = NULL;
    char* save_filepath = NULL;
    int num_ops = 0;
    int num_trials = 0;

    int index;
    int c;
    char* impl;

    while ((c = getopt (argc, argv, "i:q:h:d:s:o:t:")) != -1) {
        switch (c) {
            case 'i':
                impl = optarg;
                to_lowercase(impl);
                if (strcmp(impl, "heap") == 0) {
                    queue_impl = 1;
                    printf("heap\n");
                } else if (strcmp(impl, "list") == 0) {
                    queue_impl = 0;
                    printf("list\n");
                } else {
                    fprintf(stderr, "Only 'list' and 'heap' are valid options!\n");
                    exit(1);
                }
                break;
            case 'q':
                queue_size = atoi(optarg);
                break;
            case 'h':
                hold = atoi(optarg);
                break;
            case 'd':
                dist_filepath = optarg;
                break;
            case 's':
                save_filepath = optarg;
                break;
            case 'o':
                num_ops = atoi(optarg);
                break;
            case 't':
                num_trials = atoi(optarg);
                break;
            case '?':
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf (stderr,
                       "Unknown option character `\\x%x'.\n",
                       optopt);
                return 1;
            default:
                abort();
        }
    }

    printf("Running experiment with following options:\n");
    printf ("queue_implementation = %s, queue_size = %d, hold = %d, dist_filepath = %s, save_filepath = %s, num_ops = %d, num_trials = %d\n",
      impl, queue_size, hold, dist_filepath, save_filepath, num_ops, num_trials);
    printf("--------->\n");

    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);

    run_tests(queue_impl, queue_size, hold, dist_filepath, num_ops, num_trials, save_filepath);
    return 0;
}

// Add argument for data structure to use??
void run_tests(int queue_impl, int queue_size, int hold, char* dist_filepath, int num_ops, int num_trials, char* save_name) {
    clock_t start, end;
    double exec_time;
    double execution_times[num_trials];

    if (hold) {
        double sample_list[queue_size + num_ops];
        int i, j, l;
        
        read_data(dist_filepath, sample_list, (queue_size + num_ops));
          
        // Start of trials...
        for (l = 0; l < num_trials; l++){
            // Prepare queue with starting configuration
            queue_impl == 0 ? reset_queue() : reset_heap();
            for (j = 0; j < queue_size; j++){
                queue_impl == 0 ? enqueue(sample_list[j]) : enqueue_heap(sample_list[j]);
            }

            start = clock();
            
            // Run HOLD method
            for (i = 0; i < num_ops; i++){
                // DQ and throw away
                queue_impl == 0 ? dequeue() : dequeue_heap();
                // Enqueue new item
                queue_impl == 0 ? enqueue(sample_list[j]) : enqueue_heap(sample_list[j]);
                j++;
            }
            
            end = clock();
            
            exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            execution_times[l] = exec_time;
            // printf("Exec time was: %f\n", exec_time);
        }
    } else {
        double sample_list[queue_size];
        read_data(dist_filepath, sample_list, queue_size);
        int j, l;

        for (l = 0; l < num_trials; l++) {
            queue_impl == 0 ? reset_queue() : reset_heap();
            start = clock();
        
            // Fill queue
            for (j = 0; j < queue_size; j++) {
                queue_impl == 0 ? enqueue(sample_list[j]) : enqueue_heap(sample_list[j]);
            }

            // Empty queue
            for (j = 0; j < queue_size; j++) {
                queue_impl == 0 ? dequeue() : dequeue_heap();
            }

            end = clock();
            exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
            execution_times[l] = exec_time;
            // printf("Exec time was: %f\n", exec_time);
        }
    }

    //We are done. Let's save experiment data.
    save_data(save_name, execution_times, num_trials);
}

void to_lowercase(char *string) {
    for (int i = 0; string[i]; i++){
        string[i] = tolower(string[i]);
    }
}
