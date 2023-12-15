source = cutcopypaste.c
all: program.out

program.out: $(source)
	gcc -g $(source) -o $@ \
	`pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

clean:
	rm program
