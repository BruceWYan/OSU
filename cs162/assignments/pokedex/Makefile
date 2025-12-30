CC=g++ -std=c++11
EXE_FILE=pokedex_run

all: $(EXE_FILE)

$(EXE_FILE): pokemon.o pokemon.h run_pokemon.o
	$(CC) pokemon.cpp run_pokemon.cpp -o $(EXE_FILE)

pokemon.o: pokemon.h pokemon.cpp
	$(CC) -c pokemon.cpp

driver.o: pokemon.h run_pokemon.cpp
	$(CC) -c run_pokemon.cpp

clean:
	rm -f *.o $(EXE_FILE)