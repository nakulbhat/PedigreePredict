# Compiler and flags
CC = gcc
CFLAGS = -Wall -g -I./include  # Add include folder to search path

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
TESTDIR = tests

# Source and object files
OBJS = $(OBJDIR)/main.o $(OBJDIR)/displayFunctions.o $(OBJDIR)/personFunctions.o \
		$(OBJDIR)/relationFunctions.o $(OBJDIR)/inputFunctions.o $(OBJDIR)/menu.o

# Target executables
TARGET = myProgram
TEST_TARGET = testProgram  # Test executable name

# Rule to build the main program executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile each .c file into an object file, placing objects in obj/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to build and run the test executable
test: $(filter-out $(OBJDIR)/main.o, $(OBJS)) $(TESTDIR)/tests.c
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(filter-out $(OBJDIR)/main.o, $(OBJS)) $(TESTDIR)/tests.c
	./$(TEST_TARGET)


# Clean up build files
clean:
	rm -rf $(OBJDIR) $(TARGET) $(TEST_TARGET)
