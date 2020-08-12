CC = g++

all:
	$(CC) -std=c++11 -o a.exe Huffman.cpp

clean:
	rm -f a.exe

