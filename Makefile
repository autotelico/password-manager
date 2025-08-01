CFLAGS = --cflags gtk+-3.0
LIBS = --libs gtk+-3.0

window: window.c
	gcc `pkg-config $(CFLAGS)` `pkg-config $(LIBS)` window.c -o window 
