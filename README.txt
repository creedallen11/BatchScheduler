Team members: Creed Allen, Samuel Nelson

There are three programs: part1.c, part2.c, and part3.c

To compile all: make
To compile an individual c file: make {part1, part2 or part3}
To remove executables: make clean
For flags, see the Makefile. 


To run.
Part 1 run "./part1" There is no other user input. There will be a 10 second
  delay before any output is seen.
Part 2 run "./part2" Enter a single process ID ti kill and press return/enter.
Part 3 run "./part3" The scheduler will run a list of executable programs as input
and split on whitespace. Note, the full path must be provided. Ex. './program1' 
runs program1 in the current directory. The scheduler can also execute linux 
commands that do not have flags or arguments, ex. 'ls'. For more execution examples
see out 'sample.txt' file.  


Design choices.
Part 1: Process Creation & Part 2: Process Termination
There were no monumental design choices made for part 1 and part 2. The
implementations are what were deemed to be the simplest and most
straight-forward to solve the problems. Without error handling, part 2 would be
~5 lines of code.

Part 3: Batch Scheduler
The general structure of the program is not open to much interpreation and dictated by the assignment.
Below are some interesting notes on design within the outlined steps. 
How to get user input: I decided on fgets over alternatives because it is fairly safe and
this is a simple user script. One might consider building the input buffer with malloc and resizing it
with realloc, to fit the user's program list. However, the hard limit on BUFSIZ will be sufficient
for our needs. 
Tokenization: Given the specifications in our assignment, our implementation involving entering
the path is sufficient. I considered finding the path of the program recursively from the current directory but this gets complicated and leads to more problems. Another more sophisticated approach might be to find a way to pass argument variables to each program and. The *args array and execvp are capable of handling arguments in addition to the program name but we would need a more complciated method of tokenizing in order to do so. A possible alternative would be to enter each program, followed by its arguments one at a time, pressing enter in between entries and then telling the batch-shell to run. 
