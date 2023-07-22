CC=gcc
OUTPUT = program.exe
SOURCE = main.c

all:
	$(CC) $(SOURCE) funcs.c -o $(OUTPUT)
	./$(OUTPUT)
clean:
	$(RM) $(OUTPUT)
