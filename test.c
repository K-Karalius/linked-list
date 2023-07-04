#include "myfuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// should write some better tests...

int main()
{

    FILE *inFile;
    FILE *outFile;
    Node *start = NULL;

    assert(FileNameFormat("3333.ctxt") == 0);
    assert(FileNameFormat(".txt") == 0);
    assert(FileNameFormat("labas.txt") == 1);

    assert(IsInteger("3a3a3rfd3a3", 0) == 0);
    assert(IsInteger("2.3", 0) == 0);
    assert(IsInteger("2223", 0) == 1);
    assert(IsInteger("", 0) == 0);

    OpenFile(&inFile, "neegzistuoja.txt", 'r');
    assert(inFile == NULL);
    fclose(inFile);

    OpenFile(&inFile, "data.txt", 'r');
    assert(inFile != NULL);
    OpenFile(&outFile, "rez.txt", 'w');
    assert(outFile != NULL);

    CreateList(inFile, &start);
    assert(start != NULL);
    fclose(inFile);

    PrintList(start, outFile);

    RemoveLargestFromList(start);
    PrintList(start, outFile);

    RemoveLargestFromList(start);
    PrintList(start, outFile);

    fclose(outFile);

    DeleteList(&start);
    assert(start == NULL);


    return 0;
}