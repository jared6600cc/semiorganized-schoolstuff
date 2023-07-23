CC = g++
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = P4.o dataSet.o inputParameters.o
TARGET = p4

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~