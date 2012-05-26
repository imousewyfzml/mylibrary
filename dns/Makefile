CC=gcc
LD=ld

PROGRAM=simpledns

dns: dns.o hash.o
	$(CC) dns.o hash.o -o $(PROGRAM)

dns.o: dns.c 
	$(CC) -c dns.c -o dns.o

hash.o: hash.c
	$(CC) -c hash.c -o hash.o
clean:
	rm *.o *~ $(PROGRAM)
