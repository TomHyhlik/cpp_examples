# call it as:
# $ make app=<applicationName>


# app = tcp_server
app = tcp_client

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


