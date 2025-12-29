# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Executable
TARGET = bowlingEXE

# Source files
SRC = main.cpp Game.cpp Player.cpp Scoreboard.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default target
all: $(TARGET)

# Link objects to create executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)