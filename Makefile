# Compiler to use
CC = gcc

# Compiler flags, e.g. for debugging and for additional warnings
CFLAGS = -Wall -Wextra -g

# Target executable name
TARGET = mysync

# Source files
SRCS = mysync.c searchDir.c list.c hashtable.c

# Object files are generated from source files and are the input to the linker
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to link the object files to create the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile source files into object files
# This is an implicit rule in make, and is included here for clarity
.c.o:
	$(CC) $(CFLAGS) -c $<  -o $@

# Rule to clean up the build directory
clean:
	rm -f $(OBJS) $(TARGET)
