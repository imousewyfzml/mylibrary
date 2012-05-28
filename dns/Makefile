CC=gcc
LD=ld
CFLAGS=-ggdb -Wall

PROGRAM=simpledns

dns: dns.o hash.o
	$(CC) $(CFLAGS) dns.o hash.o -o $(PROGRAM)

dns.o: dns.c 
	$(CC) $(CFLAGS) -c dns.c -o dns.o

hash.o: hash.c
	$(CC) $(CFLAGS) -c hash.c -o hash.o
clean:
	rm *.o *~ $(PROGRAM)
