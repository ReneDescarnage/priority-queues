#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input.h"

// Declerations
void run_tests(int queue_size, int hold, char* dist_filepath, int num_ops, int num_trials, char* save_name);

int main(void) {
	char* dist_filepath = "samples/triangular.txt" ;
	char* save_filepath = "samples/triangular_exec.txt" ;
	run_tests(50,1,dist_filepath,500,2,save_filepath);
}

// Add argument for data structure to use??
void run_tests(int queue_size, int hold, char* dist_filepath, int num_ops, int num_trials, char* save_name) {
	//Hold method specified
	if(hold) {
		double sample_list[queue_size + num_ops];
		double execution_times[num_trials];
		int j;
  		int i;
  		int l;
  		int k;

  		read_data(dist_filepath, sample_list);
  		
  		// testing....
  		for(j = 0; j < 30; j++)
  			printf("%f\n", sample_list[j]);
  		printf("J is : %d\n", j);

  		// clock_t start, end;
  		// double exec_time;
  		// // Start of trials...
  		// for(l = 0; l < num_trials; l++){
	  	// 	// Create new, clean queue -> ds = linked_list() 
	  	// 	// Prepare queue with starting configuration
	  	// 	for(j = 0; j < queue_size; j++){
	  	// 		// best to pop from list? so we decrease it...?
	  	// 		// data_structure.enqueue(sample_list[j])
	  	// 	}

	  	// 	k = j;
	  	// 	start = clock();
	  	// 	// Run HOLD method
	  	// 	for(i = 0; i < num_ops; i++){
	  	// 		// DQ and throw away
	  	// 		// data_structure.dequeue()
	  	// 		// Enqueue new item
	  	// 		// data_structure.enqueue(sample_list[k])
	  	// 		k++;
	  	// 	}
	  	// 	end = clock();
	  	// 	exec_time = ((double) (end - start)) / CLOCKS_PER_SEC;
	  	// 	execution_times[l] = exec_time
  		// }

  		// //We are done. Let's save experiment data
  		// save_data(save_name, execution_times)
	}
}




