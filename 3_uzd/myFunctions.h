#include <stdio.h>

FILE * myFileOpen(FILE *f_ptr, char *f_purpose);

int myReadLine(FILE *f_ptr, char **string);

char * myChecker(char *string);

int myConnect(char *string, int str_len, int i);

void myFputc(FILE *f_ptr, char *string);
