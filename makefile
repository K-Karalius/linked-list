CC=gcc
OUTPUT = program.exe

compile: main.c funcs.c
	$(CC) -o $(OUTPUT) main.c funcs.c
run: 
	$(OUTPUT)
clean:
	erase $(OUTPUT)
