CC=g++ -std=c++11
EXE_FILE=linked_list

all: $(EXE_FILE)

$(EXE_FILE): node.h linked_list.h linked_list.o test_linked_list.o
	$(CC) linked_list.cpp test_linked_list.cpp -o $(EXE_FILE)

test_linked_list.o: linked_list.h test_linked_list.cpp
	$(CC) -c test_linked_list.cpp

linked_list.o: node.h linked_list.h linked_list.cpp
	$(CC) -c linked_list.cpp

clean:
	rm -f *.o $(EXE_FILE)