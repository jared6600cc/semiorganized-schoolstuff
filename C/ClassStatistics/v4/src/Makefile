$ cat Makefile

SRC = main.c stats.c grades_dist.c
OBJ = main.o stats.o grades_dist.o
PROG = grades_dist

$(PROG): $(OBJ)
        gcc $(OBJ) -o $(PROG)
		
$(OBJ): $(SRC)

libgdist.a: grades_dist.o
        ar rcs $@ $^

libstats.a: stats.o
        ar rcs $@ $^