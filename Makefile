#Makefile

#builds book_requests (links readline.o, book.o, and book_requests.o) 
book_requests:readline.o book.o book_requests.o
	gcc -o book_requests readline.o book.o book_requests.o

#builds readline.o (compiles readline.c)
readline.o:readline.c readline.h
	gcc -c readline.c

#builds book.o (compiles book.c)
book.o:book.c book.h readline.h
	gcc -c book.c

#builds book_requests.o (compiles book_requests.c)
book_requests.o:book.c book.h readline.h
	gcc -c book_requests.c

clean:
	rm *.o
