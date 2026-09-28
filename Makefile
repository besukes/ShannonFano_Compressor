CC = gcc

CFLAGS = -Wall -ggdb -Wextra -g3 -fsanitize=address,undefined -I. -Iincludes 

LDFLAGS = -fsanitize=address,undefined

SRC = src/main.c \
	  src/compression/compressor.c \
	  src/compression/sorter.c \
	  src/decompressor/decompressor.c \
	  src/initialization/init_clean.c \
	  src/parsing/parser.c \
	  src/writing/strings.c \
	  src/writing/write_out.c \



OBJ = $(SRC:%.c=build/%.o)


compressor : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
	rm compressor