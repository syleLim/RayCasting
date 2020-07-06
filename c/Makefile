TARGET = RAYCASTER
CC = gcc
OPTION = -Wall -Werror -Wextra
HEADER = -I ./HEADER
LIBRC = ./LIB/*/*.c
PARSER = ./PARSER/*.c
SRC = ./main.c ./SRC/raycaster.c ./SRC/*/*.c
LIB = -lm

$(TARGET) : $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(PARSER) $(LIBRC) $(HEADER) $(LIB)