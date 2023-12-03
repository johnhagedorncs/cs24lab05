CC = g++
CFLAGS = -std=c++11

all: examheap

examheap: examheap.o heap.o
	$(CC) $(CFLAGS) -o examheap examheap.o heap.o

examheap.o: examheap.cpp heap.h
	$(CC) $(CFLAGS) -c examheap.cpp

heap.o: heap.cpp heap.h
	$(CC) $(CFLAGS) -c heap.cpp

clean:
	rm -f *.o examheap