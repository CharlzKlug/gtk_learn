source = modules-plugin.c
source_program = modules.c

all: plugin.so program

plugin.so: $(source)
	gcc -shared $(source) -o $@ \
	`pkg-config --libs glib-2.0` \
	`pkg-config --cflags glib-2.0`

program: $(source_program)
	gcc $(source_program) -o $@ `pkg-config --cflags --libs glib-2.0` \
	`pkg-config --cflags --libs gmodule-2.0`
install: plugin.so
	cp plugin.so /usr/lib
uninstall:
	rm /usr/lib/plugin.so
clean:
	rm plugin.so program
