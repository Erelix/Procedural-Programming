#include "file.h"
#include <time.h>

#define RAND_LIM 100

void fillArray(int **arr, int el_num){
	*arr = (int *) malloc(el_num * sizeof(int));

	for(int i = 0; i < el_num; ++i){
		(*arr)[i] = rand()%RAND_LIM;
	}
}

void printArray(int *arr, int el_num){
	for(int i = 0; i < el_num; ++i)
		printf("%d ", arr[i]);
}

int main(){

	FILE * file_m1m3_ptr;
	FILE * file_m2_ptr;
	int number_of_elements = 10;
	int *m1;
	int *m2;
	int *m3;
	
	int *result;
	
	srand(time(NULL));
	
	fillArray(&m1, number_of_elements);
	fillArray(&m2, number_of_elements);
	fillArray(&m3, number_of_elements);
	
	
	saveToFile(file_m1m3_ptr, m1, number_of_elements);
	saveToFile(file_m1m3_ptr, m3, number_of_elements);
	free(m1);
	free(m3);
	loadFromFile(file_m1m3_ptr, &result);
	free(result);
	
	saveToFile(file_m2_ptr, m2, number_of_elements);
	free(m2);
	
	loadFromFile(file_m1m3_ptr, &result);
	free(result);
	
	loadFromFile(file_m2_ptr, &result);
	free(result);
	
	printf("\n\n%d kartus irasyta.\n%d kartus nuskaityta.\n\n", saveCount, loadCount);
	
	if(saveCount == 3 && loadCount == 3)
		printf("\nAll good");
	else
		printf("\nSomething's wrong");	
	
	printf("\n\n\nPress enter to end");
	char ok;
	scanf("%c", &ok);
	
	return 0;
}