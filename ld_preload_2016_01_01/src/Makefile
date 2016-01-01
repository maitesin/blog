all: app shared

app: vulnerable_app.c
	gcc vulnerable_app.c -o app

shared: our_patch.so
our_patch.so: our_patch.c
	gcc -shared -fPIC our_patch.c -o our_patch.so

clean:
	rm app our_patch.so
