import subprocess

compile_command = [
		"gcc",
		"main.c",
		"input.c",
		"doubly-linked-list/doubly_linked_list_pq.c",
		"skewed-heap/skewed_heap_pq.c",
	]

queue_sizes = [10, 50, 100, 200, 500, 1000, 5000]
num_ops = 1000
data_structures = ["heap", "list"]
num_trials = 500
hold = [1, 0]
distribution = ["categorical_5", "compound", "constant_1", "exponential_samples", "triangular", "uniform_samples", "uniform_samples_limited"]

def construct_command(i, q, h, d, o, t):
	dist_filepath = "samples/" + d + ".txt"
	save_filepath = "output/" + d + "_q_" + str(q) + "_ds_" + str(i) + "_h_" + str(h) 
	run_command = ["./a.out","-i",i,"-q",str(q),"-h",str(h), "-d", dist_filepath, "-s", save_filepath, "-o", str(o), "-t", str(t)]
	return run_command


# Compile program.
subprocess.run(compile_command)

# Loop over all possible configs and run experiments.
for ds in data_structures:
	for h in hold:
		for dist in distribution:
			for q in queue_sizes:
				run_command = construct_command(ds, q, h, dist, num_ops, num_trials)
				# Will wait for process to complete before returning.
				subprocess.run(run_command)

# run_command = construct_command(data_structures[0], queue_sizes[0], hold[0], distribution[4], num_ops, num_trials)
# subprocess.run(run_command)



