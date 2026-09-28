CC = gcc

CFLAGS = -Wall -O3 -flto -DNDEBUG -I. -Iincludes 

LDFLAGS = 

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
	$(CC) $(OBJ) -o $@ $(LCFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
	rm compressor