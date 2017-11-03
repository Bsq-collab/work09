all: dir.o
	gcc -o work9 dir.o

dir.o: dir.c
	gcc -c dir.c

run: all
	./work9

clean:
	rm -f work9
	rm -f *~
	rm -f *.o
