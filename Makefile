# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I./include  # Add include folder to search path

# Source and object files
SRCDIR = src
INCDIR = include
OBJDIR = obj
OBJS = $(OBJDIR)/main.o $(OBJDIR)/displayFunctions.o $(OBJDIR)/personFunctions.o \
		$(OBJDIR)/relationFunctions.o $(OBJDIR)/inputFunctions.o $(OBJDIR)/menu.o

# Target executable
TARGET = myProgram

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)    # <-- Make sure this line starts with a tab

# Compile each .c file into an object file, placing objects in obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)   # <-- This line also needs to start with a tab
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(OBJDIR) $(TARGET)    # <-- This line also starts with a tab
