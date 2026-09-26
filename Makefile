CC = gcc

CFLAGS = -Wall -O3 -flto -DNDEBUG -I. -Iincludes

LDFLAGS = 

SRC = 


OBJ = $(SRC:%.c=build/%.o)


compressor : $(OBJ)
	$(CC) $(OBJ) -o $@ $(LCFLAGS)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build
	rm compressor