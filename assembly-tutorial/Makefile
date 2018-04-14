all: hello

hello.o: hello.asm
	nasm -f elf hello.asm

hello: hello.o
	ld -m elf_i386 -s -o hello hello.o

clean:
	rm -f *.o bo1

bo1: bo1.c
	gcc -g -m32 -z execstack -o bo1 bo1.c
