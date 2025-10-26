#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_LIM 10000

int comparison_count = 0; 
int attribution_func_count = 0;


int myGenerateRandNum () {
	return rand()%RAND_LIM; 
}

void myCopyArrayToArray (int *arr1, int **arr2, int size) {
	for (int i = 0; i < size; ++i) 
		(*arr2)[i] = arr1[i];
}

void myFillArray (int **arr, int size) {
	(*arr) = (int *) malloc(size * sizeof(int));
	for (int i = 0; i < size; ++i)
		(*arr)[i] = myGenerateRandNum();
}


//a)
void myBubbleSort (int **arr, int size) {
	int temp_int;
	int swapped = 1;
	while (swapped == 1) {
		swapped = 0;
		for (int i = 1; i < size; ++i) {
			++comparison_count;
			if ((*arr)[i-1] > (*arr)[i]) {
				temp_int = (*arr)[i];
				(*arr)[i] = (*arr)[i-1];
				(*arr)[i-1] = temp_int;
				++attribution_func_count;
				swapped = 1;
			}
			++comparison_count;
		}
		++comparison_count;
	}
	++comparison_count;
	
}

//b
int myPartitionSort (int **arr, int lo, int hi) {
	int temp_int;
	int pivot = (*arr)[hi];
	int i = lo - 1;
	for	(int j = lo; j <= hi - 1; ++j) {
		++comparison_count;
		if ((*arr)[j] <= pivot){
			++i;
			temp_int = (*arr)[i];
			(*arr)[i] = (*arr)[j];
			(*arr)[j] = temp_int;
			++attribution_func_count;
		}
		++comparison_count;
	}
	++comparison_count;
	++i;
	temp_int = (*arr)[i];
	(*arr)[i] = (*arr)[hi];
	(*arr)[hi] = temp_int;
	++attribution_func_count;
	return i;
	
}

void myQuickSort (int **arr, int lo, int hi) {
	if (lo >= hi || lo < 0)
		return;
	int p = myPartitionSort(arr, lo, hi);
	myQuickSort(arr, lo, p - 1);
	myQuickSort(arr, p + 1, hi);
}



//c)
void myInsertionSort (int **arr, int size) {
	int temp_int;
	int i, j;
	i = 1;
	
	while (i < size) {
	++comparison_count;
		j = i;
		while (j > 0 && (*arr)[j-1] > (*arr)[j]) {
			++comparison_count;
			temp_int = (*arr)[j-1];
			(*arr)[j-1] = (*arr)[j];
			(*arr)[j] = temp_int;
			--j;
			++attribution_func_count;
		}
		++comparison_count;
		++i;
	}
	++comparison_count;
}

//d)

void mySelectionSort (int **arr, int size) {
	int i, j, temp_int;
	for (i = 0; i < size-1; i++) {
		++comparison_count;
		int jMin = i;
		for (j = i + 1; j < size; j++) {
			++comparison_count;
			if ((*arr)[j] < (*arr)[jMin]) {
				jMin = j;
				continue;
			}
			++comparison_count;
		}
		++comparison_count;
		++comparison_count;
		if (jMin != i) {
			temp_int = (*arr)[i];
			(*arr)[i] = (*arr)[jMin];
			(*arr)[jMin] = temp_int;
			++attribution_func_count;
			
		}
	}
	++comparison_count;
}

//e)

void topDownMerge (int **b, int iBegin, int iMiddle, int iEnd, int **a) {
	int i, j;
	i = iBegin;
	j = iMiddle;
	
	for (int k = iBegin; k < iEnd; ++k) {
		++comparison_count;
		++comparison_count;
		if (i < iMiddle && (j >= iEnd || (*a)[i] <= (*a)[j])) {
			(*b)[k] = (*a)[i];
			++attribution_func_count;
			++i;
		} else {
			(*b)[k] = (*a)[j];
			++attribution_func_count;
			++j;
		}
	}
	++comparison_count;
}

void topDownSplitMerge (int **b, int iBegin, int iEnd, int **a) {
	if (iEnd - iBegin <= 1)
		return;
	int iMiddle = (iEnd + iBegin) / 2;
	topDownSplitMerge(a, iBegin, iMiddle, b);
	topDownSplitMerge(a, iMiddle, iEnd, b);
	topDownMerge(b, iBegin, iMiddle, iEnd, a);	
}


void copyArray (int **a, int iBegin, int iEnd, int **b) {
	for (int k = iBegin; k < iEnd; ++k) {
		++comparison_count;
		(*b)[k] = (*a)[k];
		++attribution_func_count;
	}
	++comparison_count;
}


void topDownMergeSort (int **a, int **b, int n) {
	copyArray(a, 0, n, b);
	topDownSplitMerge(b, 0, n, a);
}

//


int myCheckArray (int *arr, int size) {
	for (int i = 0; i < size; ++i){
		for (int j = i + 1; j < size; ++j){
			if (arr[i] > arr[j])
				return 1;
		}
	}
	return 0;
}

void myPrintArray (int *arr, int size) {
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}

void myCopy5Arrays (int *arr_1, int *arr_2, int *arr_3, int *arr_4, int *arr_5, int **arr1, int **arr2, int **arr3, int **arr4, int **arr5, int size) {
	myCopyArrayToArray(arr_1, arr1, size);
	myCopyArrayToArray(arr_2, arr2, size);
	myCopyArrayToArray(arr_3, arr3, size);
	myCopyArrayToArray(arr_4, arr4, size);
	myCopyArrayToArray(arr_5, arr5, size);
}

void t_or_n (int *arr, int size) {
	int true_or_false = myCheckArray(arr, size);
	if (true_or_false == 0)
		printf("T  ");
	else 
		printf("N  ");
}

void t_or_n_five_times(int *arr1, int *arr2, int *arr3, int *arr4, int *arr5, int size) {
	t_or_n(arr1, size);
	t_or_n(arr2, size);
	t_or_n(arr3, size);
	t_or_n(arr4, size);
	t_or_n(arr5, size);
}


int main () {
	
	srand(time(NULL));
	int *array_1;
	int *array_2;
	int *array_3;
	int *array_4;
	int *array_5;
	int *array_6;
	int *array_7;
	int *array_8;
	int *array_9;
	int *array_10;
	
	int *array_for_sort_1;
	int *array_for_sort_2;
	int *array_for_sort_3;
	int *array_for_sort_4;
	int *array_for_sort_5;
	int *array_for_sort_6;
	int *array_for_sort_7;
	int *array_for_sort_8;
	int *array_for_sort_9;
	int *array_for_sort_10;
	
	int size = 10000;
	int true_or_false;
	

	myFillArray(&array_1, size);
	myFillArray(&array_2, size);
	myFillArray(&array_3, size);
	myFillArray(&array_4, size);
	myFillArray(&array_5, size);
	myFillArray(&array_6, size);
	myFillArray(&array_7, size);
	myFillArray(&array_8, size);
	myFillArray(&array_9, size);
	myFillArray(&array_10, size);
	
	array_for_sort_1 = (int *) malloc(size * sizeof(int));
	array_for_sort_2 = (int *) malloc(size * sizeof(int));
	array_for_sort_3 = (int *) malloc(size * sizeof(int));
	array_for_sort_4 = (int *) malloc(size * sizeof(int));
	array_for_sort_5 = (int *) malloc(size * sizeof(int));
	array_for_sort_6 = (int *) malloc(size * sizeof(int));
	array_for_sort_7 = (int *) malloc(size * sizeof(int));
	array_for_sort_8 = (int *) malloc(size * sizeof(int));
	array_for_sort_9 = (int *) malloc(size * sizeof(int));
	array_for_sort_10 = (int *) malloc(size * sizeof(int));
	
	
	
	printf("Testuojama su 10 atsitiktinai sugeneruotu masyvu su %d elementu tarp reziu [0;%d]\n\nGauti duomenys:", size, RAND_LIM);
	printf("\n**************************************************************************************************************************************");
	printf("\nArlgoritmo funkc.\t|\tAr surikiuoti el.\t|\tLaikas sek.\t|\tLyginimu sk. \t|\t Priskirimu sk.");
	printf("\n**************************************************************************************************************************************");
	
	printf("\nBubbleSort\t\t| ");
	
	myCopy5Arrays(array_1, array_2, array_3, array_4, array_5, &array_for_sort_1, &array_for_sort_2, &array_for_sort_3, &array_for_sort_4, &array_for_sort_5, size);
	myCopy5Arrays(array_6, array_7, array_8, array_9, array_10, &array_for_sort_6, &array_for_sort_7, &array_for_sort_8, &array_for_sort_9, &array_for_sort_10, size);
	
	clock_t t; 
    t = clock(); 
	myBubbleSort(&array_for_sort_1, size);
	myBubbleSort(&array_for_sort_2, size);
	myBubbleSort(&array_for_sort_3, size);
	myBubbleSort(&array_for_sort_4, size);
	myBubbleSort(&array_for_sort_5, size);
	myBubbleSort(&array_for_sort_6, size);
	myBubbleSort(&array_for_sort_7, size);
	myBubbleSort(&array_for_sort_8, size);
	myBubbleSort(&array_for_sort_9, size);
	myBubbleSort(&array_for_sort_10, size);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    
	t_or_n_five_times(array_for_sort_1, array_for_sort_2, array_for_sort_3, array_for_sort_4, array_for_sort_5, size);
	t_or_n_five_times(array_for_sort_6, array_for_sort_7, array_for_sort_8, array_for_sort_9, array_for_sort_10, size);
	
	
	printf("|\t%f", time_taken); 
	
	printf("\t|\t%d", comparison_count);
	printf("\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------");	
	
	printf("\nQuickSort\t\t| ");
	
	myCopy5Arrays(array_1, array_2, array_3, array_4, array_5, &array_for_sort_1, &array_for_sort_2, &array_for_sort_3, &array_for_sort_4, &array_for_sort_5, size);
	myCopy5Arrays(array_6, array_7, array_8, array_9, array_10, &array_for_sort_6, &array_for_sort_7, &array_for_sort_8, &array_for_sort_9, &array_for_sort_10, size);
	
	
    t = clock(); 
	myQuickSort(&array_for_sort_1, 0, size-1);
	myQuickSort(&array_for_sort_2, 0, size-1);
	myQuickSort(&array_for_sort_3, 0, size-1);
	myQuickSort(&array_for_sort_4, 0, size-1);
	myQuickSort(&array_for_sort_5, 0, size-1);
	myQuickSort(&array_for_sort_6, 0, size-1);
	myQuickSort(&array_for_sort_7, 0, size-1);
	myQuickSort(&array_for_sort_8, 0, size-1);
	myQuickSort(&array_for_sort_9, 0, size-1);
	myQuickSort(&array_for_sort_10, 0, size-1);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	t_or_n_five_times(array_for_sort_1, array_for_sort_2, array_for_sort_3, array_for_sort_4, array_for_sort_5, size);
	t_or_n_five_times(array_for_sort_6, array_for_sort_7, array_for_sort_8, array_for_sort_9, array_for_sort_10, size);
	
	printf("|\t%f", time_taken); 
	
	printf("\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------");	
	
	
	printf("\nInsertionSort\t\t| ");
	myCopy5Arrays(array_1, array_2, array_3, array_4, array_5, &array_for_sort_1, &array_for_sort_2, &array_for_sort_3, &array_for_sort_4, &array_for_sort_5, size);
	myCopy5Arrays(array_6, array_7, array_8, array_9, array_10, &array_for_sort_6, &array_for_sort_7, &array_for_sort_8, &array_for_sort_9, &array_for_sort_10, size);
	
	
    t = clock(); 
	myInsertionSort(&array_for_sort_1, size);
	myInsertionSort(&array_for_sort_2, size);
	myInsertionSort(&array_for_sort_3, size);
	myInsertionSort(&array_for_sort_4, size);
	myInsertionSort(&array_for_sort_5, size);
	myInsertionSort(&array_for_sort_6, size);
	myInsertionSort(&array_for_sort_7, size);
	myInsertionSort(&array_for_sort_8, size);
	myInsertionSort(&array_for_sort_9, size);
	myInsertionSort(&array_for_sort_10, size);

    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	t_or_n_five_times(array_for_sort_1, array_for_sort_2, array_for_sort_3, array_for_sort_4, array_for_sort_5, size);
	t_or_n_five_times(array_for_sort_6, array_for_sort_7, array_for_sort_8, array_for_sort_9, array_for_sort_10, size);
	
	
	printf("|\t%f", time_taken); 
	
	printf("\t|\t%d", comparison_count);
	printf("\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------");	
	
	
	printf("\nSelectionSort\t\t| ");
	myCopy5Arrays(array_1, array_2, array_3, array_4, array_5, &array_for_sort_1, &array_for_sort_2, &array_for_sort_3, &array_for_sort_4, &array_for_sort_5, size);
	myCopy5Arrays(array_6, array_7, array_8, array_9, array_10, &array_for_sort_6, &array_for_sort_7, &array_for_sort_8, &array_for_sort_9, &array_for_sort_10, size);
	

    t = clock(); 
	mySelectionSort(&array_for_sort_1, size);
	mySelectionSort(&array_for_sort_2, size);
	mySelectionSort(&array_for_sort_3, size);
	mySelectionSort(&array_for_sort_4, size);
	mySelectionSort(&array_for_sort_5, size);
	mySelectionSort(&array_for_sort_6, size);
	mySelectionSort(&array_for_sort_7, size);
	mySelectionSort(&array_for_sort_8, size);
	mySelectionSort(&array_for_sort_9, size);
	mySelectionSort(&array_for_sort_10, size);
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	t_or_n_five_times(array_for_sort_1, array_for_sort_2, array_for_sort_3, array_for_sort_4, array_for_sort_5, size);
	t_or_n_five_times(array_for_sort_6, array_for_sort_7, array_for_sort_8, array_for_sort_9, array_for_sort_10, size);
	
	printf("|\t%f", time_taken); 
	
	printf("\t|\t%d", comparison_count);
	printf("\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------");	
	
	printf("\nT-D MergeSort\t\t| ");
	
	myCopy5Arrays(array_1, array_2, array_3, array_4, array_5, &array_for_sort_1, &array_for_sort_2, &array_for_sort_3, &array_for_sort_4, &array_for_sort_5, size);
	myCopy5Arrays(array_6, array_7, array_8, array_9, array_10, &array_for_sort_6, &array_for_sort_7, &array_for_sort_8, &array_for_sort_9, &array_for_sort_10, size);
	


    t = clock(); 
	topDownMergeSort(&array_1, &array_for_sort_1, size);
	topDownMergeSort(&array_2, &array_for_sort_2, size);
	topDownMergeSort(&array_3, &array_for_sort_3, size);
	topDownMergeSort(&array_4, &array_for_sort_4, size);
	topDownMergeSort(&array_5, &array_for_sort_5, size);
	topDownMergeSort(&array_6, &array_for_sort_6, size);
	topDownMergeSort(&array_7, &array_for_sort_7, size);
	topDownMergeSort(&array_8, &array_for_sort_8, size);
	topDownMergeSort(&array_9, &array_for_sort_9, size);
	topDownMergeSort(&array_10, &array_for_sort_10, size);
	
	
    t = clock() - t; 
    time_taken = ((double)t)/CLOCKS_PER_SEC;
	
	t_or_n_five_times(array_for_sort_1, array_for_sort_2, array_for_sort_3, array_for_sort_4, array_for_sort_5, size);
	t_or_n_five_times(array_for_sort_6, array_for_sort_7, array_for_sort_8, array_for_sort_9, array_for_sort_10, size);
	
	printf("|\t%f", time_taken); 
	
	printf("\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------------------------------------------");	


	free(array_1);
	free(array_2);
	free(array_3);
	free(array_4);
	free(array_5);
	free(array_6);
	free(array_7);
	free(array_8);
	free(array_9);
	free(array_10);
	free(array_for_sort_1);
	free(array_for_sort_2);
	free(array_for_sort_3);
	free(array_for_sort_4);
	free(array_for_sort_5);
	free(array_for_sort_6);
	free(array_for_sort_7);
	free(array_for_sort_8);
	free(array_for_sort_9);
	free(array_for_sort_10);
	
	return 0;
}