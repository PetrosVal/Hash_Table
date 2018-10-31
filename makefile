SOURCE	= caller_bucket.c  caller_hashtable.c main.c calle_bucket.c calle_hashtable.c heap.c
CC	= gcc
CFLAGS	= -c 
DEBUG	= -g 

all: werhauz


werhauz: caller_bucket.o caller_hashtable.o calle_bucket.o calle_hashtable.o heap.o main.o 
	$(CC) $(DEBUG)  caller_bucket.o caller_hashtable.o calle_bucket.o calle_hashtable.o heap.o -lm  main.o   -o werhauz 

calle_bucket.o:	calle_bucket.c
		$(CC) $(CFLAGS) calle_bucket.c

caller_bucket.o:	caller_bucket.c
		$(CC) $(CFLAGS) caller_bucket.c

caller_hashtable.o:	caller_hashtable.c
		$(CC) $(CFLAGS) caller_hashtable.c

calle_hashtable.o:	calle_hashtable.c
		$(CC) $(CFLAGS) calle_hashtable.c

heap.o:	heap.c
		$(CC)  $(CFLAGS) heap.c  -lm

main.o: main.c
		$(CC) $(CFLAGS) main.c

	

clean:
	rm -f *.o
	rm -f werhauz
	