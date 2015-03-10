SRC := $(sort $(wildcard *.c))
OBJ := $(SRC:.c=.o)

pos = $(strip $(eval T := ) \
              $(eval i := 0) \
              $(foreach elem, $1, \
                        $(if $(filter $2,$(elem)), \
                             $(eval i := $(words $T)), \
                             $(eval T := $T $(elem)))) \
              $i)

$(notdir $(abspath .)) : $(OBJ)
	$(CC) -o $@ $^

%.o: %.c $(dir %.c)/.
	$(CC) -DTESTID=$(call pos, $(OBJ), $@) -c -o $@ $<
