CC=gcc
OUTPUT = program.exe
SOURCE = uzduotis_4.c

all:
	$(CC) $(SOURCE) funcs.c -o $(OUTPUT)
	./$(OUTPUT)
testing:
	$(CC) test.c funcs.c -o $(OUTPUT)
	./$(OUTPUT)
clean:
	$(RM) $(OUTPUT)