.PHONY: clean rmt compressor 

all: compressor

CC = gcc

CFLAGS = -Wall -ggdb -Wextra -g3 -fsanitize=address,undefined -I. -Isrc/includes -Isrc/debug

LDFLAGS = -fsanitize=address,undefined -lm

SRC = src/main.c \
	  src/compression/sf_compressor.c \
	  src/compression/sorter.c \
	  src/decompressor/decompressor.c \
	  src/initialization/init_clean.c \
	  src/parsing/parser.c \
	  src/writing/strings.c \
	  src/writing/write_out.c \
	  src/debug/debug.c



OBJ = $(SRC:%.c=build/%.o)


compressor : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
	rm compressor

rmt:
	rm -f tests/*_zip.txt