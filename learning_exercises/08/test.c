#include <stdio.h>
#include <stdlib.h>

int splitData(int *big_array, int size_big_array, int size_1_side, int **array_1, int **array_2){
    int result = 0;
    int size_2_side = size_big_array - size_1_side;
	
	if(0 < size_2_side || 0 < size_1_side){
	
		*array_1 = (int *)malloc(size_1_side * sizeof(int));
		*array_2 = (int *)malloc(size_2_side * sizeof(int));

		if(*array_1 == NULL || *array_2 == NULL)
			result = -1;
		
		else{
			for(int i = 0; i < size_1_side; ++i)
				(*array_1)[i] = big_array[i];
			
			for(int i = size_1_side; i < size_big_array; ++i)
				(*array_2)[i - size_1_side] = big_array[i];	
		}
	}
	else
		result = -1;
	
	return(result);
}

int main(){
    int *num_array;
    int size_num_array;
    int size_1_array;
	int result;
    int *arr_1;
    int *arr_2;

	printf("Programa papraso didesnio masyvo dydzio. Ji sukuria, tada papraso pirmos puses masyvo dydzio. Tada sukuria du mazesnius masyvus, atitinkamai, pagal vartotojo ivesta dydi. Juos atititnkamai uzpildo didesniojo masyvo elementais. Jei pavyko rezultatas 0, jei ne - rezultatas -1.\n\n");
    printf("Didelio masyvo dydis: ");
    scanf("%d", &size_num_array);

    num_array = (int *)malloc(size_num_array * sizeof(int));

    if(num_array == NULL){
        printf("\nNULL");
        exit(0);
    }else{
		/*
		// Pavyzdys
        for(int i = 0; i < size_num_array; ++i)
            num_array[i] = i + 1;
        */

        printf("\nPirmojo masyvo dydis: ");
        scanf("%d", &size_1_array);

        result = splitData(num_array, size_num_array, size_1_array, &arr_1, &arr_2);

		/*
		// Pavyzdys
		if(result == 0){
		
			printf("\nMasyvas 1:\n");
			for(int i = 0; i < size_1_array; ++i)
				printf("%d ", arr_1[i]);
        

			printf("\n\nMasyvas 2:\n");
			for(int i = 0; i < (size_num_array - size_1_array); ++i)
				printf("%d ", arr_2[i]);
		}
		*/
		
        free(num_array);
        free(arr_1);
        free(arr_2);
    }

	printf("\n\nRezultatas:\n%d", result);
	
	printf("\n\nPrograma baigesi.");

    return 0;
}
