
CC = g++
CFLAGS = -std=c++0x -Wall
TARGET=$(P)
all: $(TARGET)

$(TARGET): $(TARGET)/$(TARGET).cpp
	$(CC) $(CFLAGS) -o ./$(TARGET)/$(TARGET) ./$(TARGET)/$(TARGET).cpp

clean:
	$(RM) $(TARGET)/$(TARGET)

# Fix stupid error:
run: $(TARGET)/$(TARGET)
	./$(TARGET)/$(TARGET)
	