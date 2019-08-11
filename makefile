all: webcam
clean:
	rm -rf *.o
main.o: main.c
	gcc -c -o main.o main.c
framebuffer.o: framebuffer.c
	gcc -c -o framebuffer.o framebuffer.c
webcam: main.o framebuffer.o
	gcc -o webcam main.o framebuffer.o -lm -ljpeg
install:
	sudo apt-get install libjpeg-dev