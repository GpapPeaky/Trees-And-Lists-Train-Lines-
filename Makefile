# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Source files
SRC = junctions.c lines.c locomotive.c main.c

# Header files
HDR = junctions.h lines.h locomotive.h _macros.h main.h

# Object files
OBJ = $(SRC:.c=.o)

# Executable name
TARGET = my_program

# Build rule
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Dependency rules
junctions.o: junctions.c $(HDR)
	$(CC) $(CFLAGS) -c junctions.c

lines.o: lines.c $(HDR)
	$(CC) $(CFLAGS) -c lines.c

locomotive.o: locomotive.c $(HDR)
	$(CC) $(CFLAGS) -c locomotive.c

main.o: main.c $(HDR)
	$(CC) $(CFLAGS) -c main.c

# Clean rule
clean:
	rm -f $(OBJ) $(TARGET)
