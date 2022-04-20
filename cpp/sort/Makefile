CC=g++
CPPVER=c++17
CFLAGS=-Wall -Wextra -pedantic -g

NAME=quickSort
SOURCE_FILE=test.cpp

$(NAME): $(SOURCE_FILE) quickSort.h utils.h
	$(CC) $(CFLAGS) -std=$(CPPVER) -o $(NAME) $(SOURCE_FILE)
	
clean:
	rm $(NAME)