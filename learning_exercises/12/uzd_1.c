#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RAND_LIM 100

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

int main () {
	
	srand(time(NULL));
	int *array;
	int *array_for_sort;
	int size = 25;
	int true_or_false;
	

	myFillArray(&array, size);
	array_for_sort = (int *) malloc(size * sizeof(int));
	
	printf("\nGauti duomenys:");
	printf("\n**************************************************************************************************");
	printf("\nArlgoritmo funkc.\t|\tAr surikiavo\t|\tLyginimu sk.\t|\tPriskirimu sk.");
	printf("\n**************************************************************************************************");
	
	printf("\nBubbleSort");
	
	myCopyArrayToArray(array, &array_for_sort, size);
	myBubbleSort(&array_for_sort, size);
	true_or_false = myCheckArray(array_for_sort, size);
	if (true_or_false == 0)
		printf("\t\t|\tTaip");
	else 
		printf("\t\t|\tNe");
	
	printf("\t\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------");	
	
	printf("\nQuickSort");
	
	myCopyArrayToArray(array, &array_for_sort, size);
	myQuickSort(&array_for_sort, 0, size-1);
	true_or_false = myCheckArray(array_for_sort, size);
	if (true_or_false == 0)
		printf("\t\t|\tTaip");
	else 
		printf("\t\t|\tNe");
	
	printf("\t\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	
	printf("\n--------------------------------------------------------------------------------------------------");	
	printf("\nInsertionSort");
	myCopyArrayToArray(array, &array_for_sort, size);	
	myInsertionSort(&array_for_sort, size);
	true_or_false = myCheckArray(array_for_sort, size);
	if (true_or_false == 0)
		printf("\t\t|\tTaip");
	else 
		printf("\t\t|\tNe");
	
	printf("\t\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------");	
	printf("\nSelectionSort");
	myCopyArrayToArray(array, &array_for_sort, size);
	mySelectionSort(&array_for_sort, size);
	true_or_false = myCheckArray(array_for_sort, size);
	if (true_or_false == 0)
		printf("\t\t|\tTaip");
	else 
		printf("\t\t|\tNe");
	
	printf("\t\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------");
	
	printf("\nT-D MergeSort");
	
	myCopyArrayToArray(array, &array_for_sort, size);
	topDownMergeSort(&array, &array_for_sort, size);
	true_or_false = myCheckArray(array_for_sort, size);
	if (true_or_false == 0)
		printf("\t\t|\tTaip");
	else 
		printf("\t\t|\tNe");
	
	printf("\t\t|\t%d", comparison_count);
	printf("\t\t|\t%d", attribution_func_count);
	comparison_count = 0;
	attribution_func_count = 0;
	
	printf("\n--------------------------------------------------------------------------------------------------");
	
	printf("\n");
	
	free(array);
	free(array_for_sort);
	
	return 0;
}