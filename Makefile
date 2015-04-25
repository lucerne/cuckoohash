#
# 'make'        build executable file
# 'make clean'  removes all .o and executable files
#

CC=g++
CFLAGS=-Wall -Wextra -O3
DEPS = cuckoohash.h hashfunctions.h 
OBJ = main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)


.PHONY: clean

clean:
	rm -f *.o main 