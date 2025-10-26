#ifndef FUNC_DESCRIPTIONS
#define FUNC_DESCRIPTIONS
	
#include <stdio.h>
#include <stdlib.h>

extern int saveCount;
extern int loadCount;

void saveToFile(FILE *f_ptr, int *arr, int el_num);

void loadFromFile(FILE *f_ptr, int **arr);


#endif