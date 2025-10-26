#include "file.h"
#include <string.h>

void saveToFile(FILE *f_ptr, int *arr, int el_num){
	f_ptr = fopen("masyvas.txt", "wb");
	fprintf(f_ptr, "%d\n", el_num);
	for(int i = 0; i < el_num; ++i){
		fprintf(f_ptr, "%d\n", arr[i]);
	}
	fclose(f_ptr);
}

void loadFromFile(FILE *f_ptr, int **arr){
	f_ptr = fopen("masyvas.txt", "r");
	char temp_str[8];
	fgets(temp_str, 8, f_ptr);
	int el_num = atoi(temp_str);
	
	*arr = (int *) malloc(el_num * sizeof(int));
	
	for(int i = 0; fgets(temp_str, 8, f_ptr) != NULL; ++i) {
		(*arr)[i] = atoi(temp_str);
	}
	
	fclose(f_ptr);
}