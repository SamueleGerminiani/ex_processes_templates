# Processes: lab templates

Five anomalies were reported on the lab server. Each exercise reproduces one of
them in a small C program, from a partially written template.

```
ex_processes_templates/
├── demo/      <- Part 1: the programs shown during the lecture
├── ese_1/     <- Exercise 1: the multiplying processes
├── ese_2/     <- Exercise 2: the worker that died in silence
├── ese_3/     <- Exercise 3: files in the wrong place
├── ese_4/     <- Exercise 4: the process that changed identity
├── ese_5/     <- Exercise 5: the vanished output
└── report/    <- the case report (needs the 5 confirmation codes)
```

The exercises are independent: solve them in any order.

To compile:
> cd ese_1
> make

To run the executable
> ./process_ese1 ...

To remove object file(s) and executable(s)
> make clean

To file the case report
> ./report/file_report.sh

It can be filed only with the 5 confirmation codes revealed by the demo
and by the exercises.
