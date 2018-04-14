all: pic nonpic

SOURCE=pic.c

pic: $(SOURCE)
	g++ -fPIC -c $(SOURCE) -o pic.o

nonpic: $(SOURCE)
	g++ -c $(SOURCE) -o pic_nopic.o

clean:
	rm -f *.o

