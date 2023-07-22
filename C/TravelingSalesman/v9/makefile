project3: main.o bruteForceTSP.o geneticTSP.o completeGraph.o globals.o
	gcc -o project3 main.o bruteForceTSP.o -lm 
bruteForceTSP.o : bruteForceTSP.c bruteForceTSP.h
	gcc -c -Wall bruteForceTSP.c
geneticTSP.o : geneticTSP.c geneticTSP.h
	gcc -c -Wall geneticTSP.c
completeGraph.o : completeGraph.c completeGraph.h
	gcc -c -Wall completeGraph.c
globals.o : globals.c globals.h
	gcc -c -Wall globals.c
main.o : main.c bruteForceTSP.h geneticTSP.h completeGraph.h globals.h
	gcc -c -Wall main.c
clean :
	rm project3 main.o bruteForceTSP.o geneticTSP.o completeGraph.o globals.o




