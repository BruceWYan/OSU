CC=g++ -std=c++11
EXE_FILE=lab7

all: $(EXE_FILE)

$(EXE_FILE): square.o square.h rectangle.o rectangle.h circle.o circle.h shape.o shape.h application.o
	$(CC) square.cpp rectangle.cpp circle.cpp shape.cpp application.cpp -o $(EXE_FILE)

application.o: rectangle.h circle.h application.cpp
	$(CC) -c application.cpp

shape.o: shape.h shape.cpp
	$(CC) -c shape.cpp

rectangle.o: rectangle.h rectangle.cpp
	$(CC) -c rectangle.cpp

circle.o: circle.h circle.cpp
	$(CC) -c circle.cpp

square.o: square.h square.cpp
	$(CC) -c square.cpp

clean:
	rm -f *.o $(EXE_FILE)