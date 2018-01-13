#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"
#include "./doubly-linked-list/doubly_linked_list_pq.h"

// Declerations
void run_tests(int queue_size, char hold, char* dist_filepath, int num_ops, int num_trials, char* save_name);

int main(void) {
	char* dist_filepath = "samples/triangular.txt" ;
	char* save_filepath = "samples/triangular_exec" ;
	char hold = 1
	run_tests(50,hold,dist_filepath,1000,5,save_filepath);
}

// Add argument for data structure to use??
void run_tests(int queue_size, char hold, char* dist_filepath, int num_ops, int num_trials, char* save_name) {
	clock_t start, end;
	double exec_time;
	double execution_times[num_trials];

	if(hold) {
		double sample_list[queue_size + num_ops];
		int i,j,l;
  		read_data(dist_filepath, sample_list, (queue_size + num_ops));
  		// Start of trials...
  		for(l = 0; l < num_trials; l++){ 
	  		// Prepare queue with starting configuration
			reset_queue();
	  		for(j = 0; j < queue_size; j++){
				  enqueue(sample_list[j]);
	  		}

	  		// k = j;
	  		start = clock();
	  		// Run HOLD method
	  		for(i = 0; i < num_ops; i++){
	  			// DQ and throw away
	  			dequeue();
	  			// Enqueue new item
	  			enqueue(sample_list[j]);
	  			j++;
	  		}
	  		end = clock();
	  		exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	  		execution_times[l] = exec_time;
	  		printf("Exec time was: %f\n", exec_time);
  		}
	} else {
		double sample_list[queue_size];
		read_data(dist_filepath, sample_list, queue_size);
  		int j, l;

  		for(l = 0; l < num_trials; l++){ 
			reset_queue();
			start = clock();
			//Fill queue
	  		for(j = 0; j < queue_size; j++){
				  enqueue(sample_list[j]);
	  		}

	  		//Empty queue
	  		for(j = 0; j < queue_size; j++){
			  	dequeue();
	  		}
	  		end = clock();
	  		exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	  		execution_times[l] = exec_time;
	  		printf("Exec time was: %f\n", exec_time);
  		}
	}
	//We are done. Let's save experiment data
	save_data(save_name, execution_times, num_trials);
}




