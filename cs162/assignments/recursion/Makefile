CC=g++ -std=c++11
EXE_FILE=fractal

all: $(EXE_FILE)

$(EXE_FILE): recursive_fractal.o
	$(CC) recursive_fractal.cpp -o $(EXE_FILE)

recursive_fractal.o: recursive_fractal.cpp
	$(CC) -c recursive_fractal.cpp

clean:
	rm -f *.o $(EXE_FILE)