TARGET = RAYCASTER
CC = gcc
OPTION = -Wall -Werror -Wextra
HEADER = -I ./HEADER
SRC = ./*.c ./SRC/*.c ./SRC/*/*.c
LIB = -lm

$(TARGET) : $(SRC)
	$(CC) -o $(TARGET) $(SRC) $(HEADER) $(LIB)