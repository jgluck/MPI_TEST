all: hello

run: hello
	
hello: hello.o
	mpicc hello.o -o hello.exe
	
hello.o: hello.c
	mpicc -c hello.c
	
clean:
	rm -f *.o hello.exe