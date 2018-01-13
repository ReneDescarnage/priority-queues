# priority-queues

Following arguments are accepted:
- q: queue_size (int)
- h: specifies HOLD method (1) or UP-DOWN (0)
- d: path to distribution to use
- s: path where to save results
- o: number of operations to perform (only for hold method)
- t: number of trials to run

Example input:
./a.out -q 10 -h 1 -d samples/triangular.txt -s samples/triangular_exec -o 100 -t 5
