#ifndef FUNC_DESCRIPTIONS
#define FUNC_DESCRIPTIONS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RAND_LIM 100
#define MAX_LINE_SIZE 255
#define MAX_FILE_NAME 50

typedef struct Node {
    struct Node* prev;
    int data;
    struct Node* next;
} Node;

int myGenerateRandomNum();

void myPushListRight(Node** head, int number);

void myPrintListCMD(Node *head);

void myPrintListFile(FILE **file_ptr, char *file_name, Node *head);

int myCheckFileForUnwantedSymbols(FILE **file_ptr, char *file_name);

int myPutFileContentIntoList(FILE *file_ptr, char *file_name, Node **head);

//BE REKURSIJOS
void myDestroyList(Node** head);

//SU REKURSIJA
void myDestroyListREC(Node** head);

void mySortList(Node* head);

void myPrintMenu();

#endif