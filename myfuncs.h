#ifndef MYFUNCS_H_INCLUDED
#define MYFUNCS_H_INCLUDED

#include <stdio.h>

struct Node
{
    struct Node *prev;
    struct Node *next;
    int elem;
} typedef Node;


FILE *GetFile(char type);
int OpenFile(FILE **file, char *name, char type);
void CreateList(FILE *file, Node **start);
void PrintList(Node *start, FILE *file);
void RemoveLargestFromList(Node *start);
void DeleteList(Node **start);
int IsInteger(char str[], int count);
int FileNameFormat(char *name);

#endif