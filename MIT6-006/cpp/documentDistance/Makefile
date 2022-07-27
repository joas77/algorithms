CC = g++
LIBS = ../libs
CPPFLAGS = -std=c++17 -Wall -g -I $(LIBS)

docDistance: *.cpp
	$(CC) $(CPPFLAGS) $^ -o $@

clean:
	rm ./docDistance