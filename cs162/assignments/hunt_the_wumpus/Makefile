CC=g++ -std=c++11
EXE_FILE=wump

all: $(EXE_FILE)

$(EXE_FILE): game.o game.h room.o room.h event.o event.h gold.o gold.h wumpus.o wumpus.h bats.o bats.h pit.o pit.h hunt.o
	$(CC) game.cpp room.cpp event.cpp gold.cpp wumpus.cpp bats.cpp pit.cpp hunt.cpp -o $(EXE_FILE)

hunt.o: game.h hunt.cpp
	$(CC) -c hunt.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

room.o: room.h room.cpp
	$(CC) -c room.cpp

event.o: event.h event.cpp
	$(CC) -c event.cpp

gold.o: gold.h gold.cpp
	$(CC) -c gold.cpp

pit.o: pit.h pit.cpp
	$(CC) -c pit.cpp

bats.o: bats.h bats.cpp
	$(CC) -c bats.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) -c wumpus.cpp

clean:
	rm -f *.o $(EXE_FILE)

