all: hello

hello.o: hello.asm
	nasm -f elf hello.asm

hello: hello.o
	ld -m elf_i386 -s -o hello hello.o

clean:
	rm -f *.o hello

