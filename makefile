CC=gcc
OUTPUT = program.exe
SOURCE = main.c

all:
	$(CC) $(SOURCE) funcs.c -o $(OUTPUT)
	./$(OUTPUT)
testing:
	$(CC) test.c funcs.c -o $(OUTPUT)
	./$(OUTPUT)
clean:
	$(RM) $(OUTPUT)
