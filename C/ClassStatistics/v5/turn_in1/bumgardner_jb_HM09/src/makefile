all: grades_dist

grades_dist: main.o stats.o grades_dist.o
	@echo "grades_dist"
	gcc  main.o stats.o grades_dist.o -o grades_dist.x -L../libs/ -I../include/ -lstats -lm -lgdist

main.o: main.c
	@echo "main.o"
	gcc -c main.c -I../include

stats.o: stats.c
	@echo "stats.o"
	gcc -c stats.c -I../include 
	ar cq ../libs/libstats.a stats.o 
	
grades_dist.o: grades_dist.c
	@echo "grades_dist.o"
	gcc -c grades_dist.c -I../include
	ar cq ../libs/libgdist.a grades_dist.o

clean:
	rm *o grades_dist.x ../libs/libstats.a 
