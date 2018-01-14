#### Royal Institute of Technology KTH - Stockholm
# Experimental Methodology - Engineering Skills for ICT (II1304)

_This repository contains code written during the fall semester 2017 by Cedric Seger and Simone Stefani_

#### Running the experiment
In order to run the experiment with custom parameters first compile the C files in `src/`:
```bash
$ cd src/

$ gcc input.c linked_list_pq.c main.c skewed_heap_pq.c -o experiment.out
```

Then run the executable:
`./experiment.out`

The following arguments are accepted/required:
- i: implementation of the PQ (valid values: `heap`and `list`)
- q: queue_size (int)
- h: specifies HOLD method (1) or UP-DOWN (0)
- d: path to distribution to use
- s: path where to save results
- o: number of operations to perform (only for hold method)
- t: number of trials to run

Example input:
`$ ./experiment.out -i heap -q 10 -h 1 -d samples/triangular.txt -s samples/triangular_exec -o 100 -t 5`

#### Running the Python script
This feature requires Python 3.5 or greater on the machine. In the main base folder run:
`$ python3 task_runner.py`

#### Running the tests
Move in the `src/` folder compile the test with the corresponding data structure implementation and run the executable:
```bash
$ cd src/

$ gcc linked_list_pq.c linked_list_pq_test.c -o linked_list_test.out

$ ./linked_list_test.out
```

