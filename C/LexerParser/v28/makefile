CC = g++
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = analytics.o dsap2.o heap.o simulation.o fifoQueue.o
TARGET = p2

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~