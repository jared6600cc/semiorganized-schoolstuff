CC = g++
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = adjacencyMatrix.o TSP.o bruteForce.o geneticAlgorithm.o userInteraction.o
TARGET = p3

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~