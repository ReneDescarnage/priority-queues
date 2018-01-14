import subprocess
import pathlib

output_file = "src/experiment.out"
compile_command = [
    "gcc",
    "src/main.c",
    "src/input.c",
    "src/linked_list_pq.c",
    "src/skewed_heap_pq.c",
    "-o",
    output_file
  ]

queue_sizes = [10, 50, 100, 200, 500, 1000, 5000]
num_ops = 1000
data_structures = ["heap", "list"]
num_trials = 500
hold = [1, 0]
distribution = ["categorical_5", "compound", "constant_1", "exponential_samples", "triangular", "uniform_samples", "uniform_samples_limited"]

pathlib.Path('./output').mkdir(parents=True, exist_ok=True) 

def construct_command(i, q, h, d, o, t):
  dist_filepath = "samples/" + d + ".txt"
  save_filepath = "output/" + d + "_q_" + str(q) + "_ds_" + str(i) + "_h_" + str(h) 
  run_command = ["./" + output_file, "-i", i, "-q", str(q), "-h", str(h), "-d", dist_filepath, "-s", save_filepath, "-o", str(o), "-t", str(t)]
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



