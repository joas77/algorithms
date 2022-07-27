CC = g++
LIBS = ../libs
CPPFLAGS = -std=c++17 -Wall -g -I $(LIBS)

test: *.cpp
	$(CC) $(CPPFLAGS) $^ -o $@
	./test

clean:
	rm ./test
