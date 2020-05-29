# call it as:
# $ make app=<applicationName>

CC = g++
FLAGS = -std=c++17

BINARY = ./build/binary

all: compile run

compile:
	$(CC) ./$(app).cpp -o $(BINARY) $(FLAGS)

run:
	$(BINARY)

clean:
	rm -f $(BINARY)


