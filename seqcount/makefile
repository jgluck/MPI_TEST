all: hello

run: hello
	
hello: seqcount.o
	mpicc seqcount.o -o seqcount.exe
	
seqcount.o: seqcount.c
	mpicc -c seqcount.c
	
clean:
	rm -f *.o seqcount.exe
