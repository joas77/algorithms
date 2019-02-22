# FIXME: make file to compile calculator, NOT WORKING
CC = gcc
CFLAGS= -Wall -g -std=c11
# OBJECTS=vector.o ../vector/vector.o
# SOURCES=calc.c aritmetic.c ../vector/vector.c
# LDFLAGS= -lm

# calc:
# 	$(CC) $(FLAGS) $(SOURCES) -o calc

# depend:
# 	makedepend $(CFLAGS) $(SOURCES)

# clean:
# 	rm $(OBJECTS)

calc:
	$(CC) $(CFLAGS) -I ../vector  -o calc *.c ../vector/vector.c

clean:
	rm calc
	rm -rf calc.DSYM
