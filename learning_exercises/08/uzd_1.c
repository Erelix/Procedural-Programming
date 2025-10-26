#include <stdio.h>
#include <time.h>  
#include <stdlib.h>

int * createArray(int size){
	int *array_ptr;
	array_ptr = (int*)malloc(size * sizeof(int));
	return(array_ptr); 
}

void generateArray(int data[], int size, int low, int high){
	srand(time(NULL));
	if (low <= high)
		for(int i = 0; i < size; ++i){
			data[i] = rand() % (high - low + 1) + low;
		}
}

int main(){
	
	int size_input;
	int low_input;
	int high_input;
	
	
	printf("Programa sukuria \"size\" talpos masyva naudodama malloc ir ji uzpildo atsitiktinemis reiksmemis is intervalo [ low ; high].\n\n");
	
	printf("\nPrasome ivesti masyvo dydi\nsize: ");
	scanf("%d", &size_input);
	
	
	int * array;
	array = createArray(size_input);
	
	if(array != NULL){
	
		printf("\nPrasome mazesni rezi\nlow: ");
		scanf("%d", &low_input);
	
		printf("\nPrasome ivesti didesni rezi\nhigh: ");
		scanf("%d", &high_input);
	
		generateArray(array, size_input, low_input, high_input);
	
		printf("\n\nGautas masyvas:\n");
	
		if(low_input <= high_input){
			for(int i = 0; i < size_input; ++i){
				printf("%d ", array[i]);
			}
		}
		free(array);
		printf("\n\nRodykle i pirmaji masyvo elementa:\n");
		printf("%d", array);
	
	}else
		printf("\nNULL");
	
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}