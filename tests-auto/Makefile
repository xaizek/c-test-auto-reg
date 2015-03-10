SRC := $(wildcard *.c)
OBJ := $(SRC:.c=.o)

$(notdir $(abspath .)) : $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -c -o $@ $<
