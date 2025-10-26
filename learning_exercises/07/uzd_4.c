#include <stdio.h>
#include <time.h>  
#include <stdlib.h>

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
	
	printf("Programa uzpildo \"size\" talpos masyva atsitiktinemis reiksmemis is intervalo [ low ; high].\n\n");
	
	printf("\nPrasome ivesti masyvo dydi\nsize: ");
	scanf("%d", &size_input);
	
	int array[size_input];
	
	printf("\nPrasome mazesni rezi\nlow: ");
	scanf("%d", &low_input);
	
	printf("\nPrasome ivesti didesni rezi\nhigh: ");
	scanf("%d", &high_input);
	
	generateArray(array, size_input, low_input, high_input);
	
	printf("\n\nGautas masyvas:\n");
	
	for(int i = 0; i < size_input; ++i){
		printf("%d ", array[i]);
	}
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}