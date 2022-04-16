CC=g++
CPPVER=c++11
CFLAGS=-Wall -Wextra -pedantic -g -O0

NAME=SuperSmartPointer
SOURCE_FILE=test.cpp

$(NAME): $(SOURCE_FILE)
	$(CC) $(CFLAGS) -std=$(CPPVER) -o $(NAME) $(SOURCE_FILE)
	
clean:
	rm $(NAME)