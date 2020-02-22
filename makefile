# call it as:
# $ make APP=<applicationName>

CC = g++
FLAGS = -std=c++17

BINARY = ./build/binary

all: compile run

compile:
	$(CC) ./$(APP).cpp -o $(BINARY) $(FLAGS)

run:
	$(BINARY)

clean:
	rm -f $(BINARY)


