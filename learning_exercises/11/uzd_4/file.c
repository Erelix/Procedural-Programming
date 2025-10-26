#include "file.h"
#include <string.h>

int loadCount = 0;
int saveCount = 0;

void saveToFile(FILE *f_ptr, int *arr, int el_num){
    if(saveCount == 0 || saveCount == 1){
        f_ptr = fopen("m1m3.txt", "ab");
    }else if (saveCount == 2){
        f_ptr = fopen("m2.txt", "ab");
    }
	
	fprintf(f_ptr, "%d\n", el_num);
	for(int i = 0; i < el_num; ++i){
		fprintf(f_ptr, "%d\n", arr[i]);
	}
	++saveCount;
	fclose(f_ptr);
}

void loadFromFile(FILE *f_ptr, int **arr){
    if(loadCount == 0 || loadCount == 1){
        f_ptr = fopen("m1m3.txt", "r");
    }else if(loadCount == 2){
        f_ptr = fopen("m2.txt", "r");
    }
	
	char temp_str[8];
	fgets(temp_str, 8, f_ptr);
	int el_num = atoi(temp_str);
	
	*arr = (int *) malloc(el_num * sizeof(int));
	
	for(int i = 0; fgets(temp_str, 8, f_ptr) != NULL; ++i) {
		(*arr)[i] = atoi(temp_str);
	}
	++loadCount;
	fclose(f_ptr);
	
}