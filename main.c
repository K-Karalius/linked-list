

#include "myfuncs.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int choice = -1;
    char choiceStr[2];
    Node *start = NULL;
    FILE *inFile;
    FILE *outFile;

    printf("*****MENU*****\n");
    printf("1. Create a circular doubly linked list from file\n");
    printf("2. Print the list to file\n");
    printf("3. Remove largest element from the list\n");
    printf("4. Delete the list\n");
    printf("0. Exit the program\n");

    while (choice != 0)
    {
        printf("Enter a choice: ");
        scanf("%s", choiceStr);
        if (IsInteger(choiceStr, 0) == 0)
        {
            choice = -1;
        }
        else
        {
            choice = strtol(choiceStr, NULL, 0);
        }

        switch (choice)
        {
        case 1:
            inFile = GetFile('r');
            CreateList(inFile, &start);
            fclose(inFile);
            break;
        case 2:
            outFile = GetFile('w');
            PrintList(start, outFile);
            fclose(outFile);
            break;
        case 3:
            RemoveLargestFromList(start);
            break;
        case 4:
            DeleteList(&start);
            printf("List deleted or it was already empty!\n");
            break;
        case 0:
            DeleteList(&start);
            exit(0);
        default:
            printf("Select a valid option...\n");
        }
    }

    return 0;
}

