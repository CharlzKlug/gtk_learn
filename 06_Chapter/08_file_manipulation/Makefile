source = files.c
all: program

program: $(source)
	gcc -g $(source) -o $@ \
	`pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

clean:
	rm program
