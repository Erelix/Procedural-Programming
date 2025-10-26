#include "file.h"
#include <time.h>

#define RAND_LIM 100

void fillArray(int **arr, int el_num){
	*arr = (int *) malloc(el_num * sizeof(int));
	srand(time(NULL));
	for(int i = 0; i < el_num; ++i){
		(*arr)[i] = rand()%RAND_LIM;
	}
}

void printArray(int *arr, int el_num){
	for(int i = 0; i < el_num; ++i)
		printf("%d ", arr[i]);
}

int main(){

	FILE * file_ptr;
	int number_of_elements = 100;
	int *array;
	int *res_array;
	
	printf("m1:\n");
	fillArray(&array, number_of_elements);
	printArray(array, number_of_elements);
	printf("\n\n");
	
	printf("m2:\n");
	saveToFile(file_ptr, array, number_of_elements);
	loadFromFile(file_ptr, &res_array);
	printArray(res_array, number_of_elements);
	
	int rez = 0;
	for(int i = 0; i < number_of_elements; ++i){
		if(array[i] != res_array[i]){
			++rez;
		}
	}
	
	if(rez > 0)
		printf("\n\nSomething\'s wrong");
	else
		printf("\n\nAll good");
	
	free(array);
	free(res_array);
	
	printf("\n\n\nPress enter to end");
	char ok;
	scanf("%c", &ok);
	
	return 0;
}