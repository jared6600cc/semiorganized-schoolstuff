all: hm09

hm09: main.o kernel_func.o image.o
	@echo "hm09"
	gcc main.o kernel_func.o image.o -o hm09.x -L../libs/ -I../include/ -Llibs -lm
	
main.o: main.c
	@echo "main.o"
	gcc -c main.c -I../include
	
kernel_func.o: kernel_func.c
	@echo "kernel_func.o"
	gcc -c kernel_func.c -I../include
	ar cq ../libs/libkernel_func.a kernel_func.o
	
image.o: image.c
	@echo "image.o"
	gcc -c image.c -I../include
	ar cq ../libs/libimage.a image.o
	
clean:
	rm *o hm09.x ../libs/libimage.a ../libs/libkernel_func.a