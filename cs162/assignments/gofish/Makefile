CC=g++ -std=c++11
EXE_FILE=gofish

all: $(EXE_FILE)

$(EXE_FILE): game.o game.h player.o player.h hand.o hand.h deck.o deck.h card.o card.h run_gofish.o
	$(CC) game.cpp player.cpp hand.cpp deck.cpp card.cpp run_gofish.cpp -o $(EXE_FILE)

run_gofish.o: game.h run_gofish.cpp
	$(CC) -c run_gofish.cpp

game.o: game.h game.cpp
	$(CC) -c game.cpp

player.o: player.h player.cpp
	$(CC) -c player.cpp

hand.o: hand.h hand.cpp
	$(CC) -c hand.cpp

deck.o: deck.h deck.cpp
	$(CC) -c deck.cpp

card.o: card.h card.cpp
	$(CC) -c card.cpp


clean:
	rm -f *.o $(EXE_FILE)