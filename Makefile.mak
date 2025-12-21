# 1. Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -g -Iinc 
# -Wall: Turn on all warnings (good for debugging)
# -g: Add info for the debugger (GDB)
# -Iinc: Look inside the 'inc' folder for header files

# 2. Source Files and Object Files
# This grabs all .cpp files in src/
SRCS = $(wildcard src/*.cpp)
# This converts them to .o files (compiled chunks)
OBJS = $(SRCS:.cpp=.o)

# 3. The Name of your Final Program
TARGET = Group_Expense_Optimizer

# 4. The Rules

# The default rule (what happens when you type 'make')
all: $(TARGET)

# Link all object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile each .cpp file into a .o file
# This is a pattern rule: %.o depends on %.cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# A clean rule to remove generated files
clean:
	rm -f $(OBJS) $(TARGET)