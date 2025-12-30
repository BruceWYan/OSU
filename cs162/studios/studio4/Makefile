CC=g++ -g
EXE_FILE=student_db_run

all: $(EXE_FILE)

$(EXE_FILE): student_db.o student_db.h driver.o
	$(CC) student_db.o driver.cpp -o $(EXE_FILE)

student_db.o: student_db.h student_db.cpp
	$(CC) -c student_db.cpp

driver.o: student_db.h driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f *.out *.o $(EXE_FILE)
	
	
