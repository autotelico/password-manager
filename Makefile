compile: main.c vault.c crypto.c
	gcc main.c vault.c crypto.c -o main && ./main
