# Compiler and Flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executables
MAIN_EXEC = app
TEST_EXEC = run_tests
GRADE_EXEC = run_grade_tests

# Default target
all: $(MAIN_EXEC)

# Run main program
run: $(MAIN_EXEC)
	./$(MAIN_EXEC)

# Build main (ONLY main.cpp needed)
$(MAIN_EXEC): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(MAIN_EXEC)

# Build and run test file
test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o $(TEST_EXEC)
	./$(TEST_EXEC)

# Build and run hidden test file
grade: test_h.cpp
	$(CXX) $(CXXFLAGS) test_h.cpp -o $(GRADE_EXEC)
	./$(GRADE_EXEC)

# Clean
clean:
	rm -f $(MAIN_EXEC) $(TEST_EXEC) $(GRADE_EXEC) *.exe