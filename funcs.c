
#include "myfuncs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE *GetFile(char type)
{
    FILE *file;
    char *fileName = malloc(256 * sizeof(char));
    int fileSize;
    printf("Enter a file name <example.txt> (max length 255): ");
    while (1)
    {
        scanf("%s", fileName);
        if (FileNameFormat(fileName))
        {
            if (OpenFile(&file, fileName, type))
            {
                break;
            }
            printf("File cannot be opened, try again: ");
        }
        else
        {
            printf("File format should be <example.txt>, try again: ");
        }
    }
    printf("File is valid!\n");

    free(fileName);

    return file;
}

int FileNameFormat(char *name)
{
    int length = strlen(name);
    if (length < 5 || length > 255) 
        return 0;
    if (name[length - 1] != 't')
        return 0;
    if (name[length - 2] != 'x')
        return 0;
    if (name[length - 3] != 't')
        return 0;
    if (name[length - 4] != '.')
        return 0;

    return 1;
}

int OpenFile(FILE **file, char *name, char type)
{
    if (type == 'r')
        *file = fopen(name, "r");
    if (type == 'w')
        *file = fopen(name, "w");
    if (*file == NULL)
    {
        return 0;
    }
    return 1;
}

void CreateList(FILE *file, Node **start)
{
    if ((*start) != NULL)
    {
        DeleteList(start);
    }

    int data;

    fscanf(file, "%d", &data);
    (*start) = (Node *)malloc(sizeof(Node));
    (*start)->elem = data;
    (*start)->prev = *start;
    (*start)->next = *start;

    Node *newNode;
    Node *temp;
    while (!feof(file))
    {
        fscanf(file, "%d", &data);
        newNode = (Node *)malloc(sizeof(Node));
        newNode->elem = data;
        
        temp = (*start)->prev;
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = *start;
        (*start)->prev = newNode;
    }

    printf("List created!\n");
}

void DeleteList(Node **start)
{

    if ((*start) != NULL)
    {
        Node *next = (*start)->next;
        Node *temp;
        while (next && (next != *start))
        {
            temp = next;
            next = next->next;
            free(temp);
        }

        free(*start);
        *start = NULL;
    }
}

void PrintList(Node *start, FILE *file)
{

    if (start == NULL)
    {
        printf("There is no list to print!\n");
        return;
    }

    fprintf(file, "VALUES:\n");
    Node *temp = start;
    do
    {
        fprintf(file, "%d ", temp->elem);
        temp = temp->next;
    } while (temp != (start));
    putc('\n', file);

    printf("Listed is printed to the file\n");
}

void RemoveLargestFromList(Node *start)
{
    if (start == NULL)
    {
        return;
        printf("There is no list to delete from!\n");
    }

    int largestCount = 0;
    Node *largest = start;
    Node *temp = start;
    do
    {
        if (temp->elem > largest->elem)
        {
            largest = temp;
        }

        temp = temp->next;
    } while (temp != start);

    temp = start;
    do
    {
        if (largest->elem == temp->elem && largest != temp)
        {
            ++largestCount;
            break;
        }
        temp = temp->next;
    } while (temp != (start));

    if (largestCount == 0 && start != start->next)
    {
        temp = largest->prev;
        temp->next = largest->next;
        temp = largest->next;
        temp->prev = largest->prev;
        free(largest);
        printf("Largest value deleted!\n");
    }
    else
    {
        printf("There is no largest value!\n");
    }
}

int IsInteger(char str[], int count)
{
    if (count < strlen(str))
    {
        if (!isdigit(str[count]))
        {
            return 0;
        }
        IsInteger(str, count + 1);
    }
    else if(strlen(str) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}