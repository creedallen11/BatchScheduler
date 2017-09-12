CC=gcc
CFLAGS=-Wall -Wpedantic -Werror

default: part1 part2 part3

all: part1 part2 part3
part1: part1.c
	$(CC) $(CFLAGS) part1.c -o part1
part2: part2.c
	$(CC) $(CFLAGS) part2.c -o part2
part3: part3.c
	$(CC) $(CFLAGS) part3.c -o part3
clean:
	rm -f part1
	rm -f part2
	rm -f part3