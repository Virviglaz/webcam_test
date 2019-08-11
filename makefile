all: webcam
clean:
	rm -rf *.o
main.o: main.c
	gcc -c -o main.o main.c
webcam: main.o
	gcc -o webcam main.o -lm -ljpeg
install:
	sudo apt-get install libjpeg-dev
