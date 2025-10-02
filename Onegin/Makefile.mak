CC = g++
CFLAGS = -c -Wall
OBJECTS = $(SOURCES: .cpp = .o)
EXECUTABLE = onegin

all: $(EXECUTABLE)

$(EXECUTABLE): main_onegin.cpp work_with_buffer.cpp bubble_sorts.cpp write_in_files.cpp another_functions.cpp my_functions.cpp
	$(CC) $(SOURCES) -o $(EXECUTABLE)

main_onegin.o: main_onegin.cpp
	$(CC) $(CFLAGS) main_onegin.cpp

work_with_buffer.o: work_with_buffer.cpp
	$(CC) $(CFLAGS) work_with_buffer.cpp

bubble_sorts.o: bubble_sorts.cpp
	$(CC) $(CFLAGS) bubble_sorts.cpp

write_in_files.o: write_in_files.cpp
	$(CC) $(CFLAGS) write_in_files.cpp

another_functions.o: another_functions.cpp
	$(CC) $(CFLAGS) another_functions.cpp

my_functions.o: my_functions.cpp
	$(CC) $(CFLAGS) my_functions.cpp

clean:
	rm -rf *.o $(EXECUTABLE)


