all: hello hello-static doubleputs

hello-static: hello.c
	gcc -static hello.c -o hello-static

hello: hello.c
	gcc -fPIC -o hello hello.c

doubleputs: doubleputs.c
	gcc -shared -fPIC -o doubleputs.so doubleputs.c -ldl
	
clean:
	rm -f hello hello-static *.so

