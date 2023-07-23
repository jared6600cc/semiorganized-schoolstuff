CC = g++
CFLAGS = -Wall
LDFLAGS = 
OBJFILES = p5.o directAccessFile.o longestCommonSubstring.o
TARGET = p5

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
	
clean:
	rm -f $(OBJFILES) $(TARGET) *~