#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define RAND_LIM 100
#define MAX_FILE_LENTH 50


typedef struct List{
	int *array;
	int size_arr;
}List;


void myCreateEmptyList(List *stack){
	stack->size_arr = 0;
	stack->array = (int *)malloc(stack->size_arr * sizeof(int));
	
	if(stack->array == NULL){
		printf("\nStako sukurti nepavyko.\n");
		exit(1);
	}
}

void myDestroyList(List *stack){
	free(stack->array);
}

void myPrintList(List * stack){
	for (int i = 0; i < stack->size_arr; ++i) {
		printf("%d ", stack->array[i]);
	}
}

int myCountFileRows(FILE **file_ptr, char *file_name, List *stack){
	*file_ptr = fopen(file_name, "r");
	if (*file_ptr == NULL)
		return -1;
	
	
	char temp_str[8];
	int row_counter = 0;
	
	while (fgets(temp_str, 8, *file_ptr) != NULL)
		++row_counter;
		
	if (row_counter > 0) {
		stack->size_arr = row_counter;
		fseek(*file_ptr, 0, SEEK_SET);
	} else {
		fclose(*file_ptr);
	}
	return row_counter;
}

void myFillListFromFile(FILE *file_ptr, List *stack){
	stack->array = (int *) realloc(stack->array, stack->size_arr * sizeof(int));
	char temp_str[8];
	for (int i = 0; i < stack->size_arr; ++i) {
		fgets(temp_str, 8, file_ptr);
		stack->array[i] = atoi(temp_str);
	}
	fclose(file_ptr);
}

void myPrintListInFile(FILE **file_ptr, List *stack, char *file_name){
	*file_ptr = fopen(file_name, "w+");
	if (*file_ptr == NULL) {
		printf("Nepavyko atidaryti rezultatu failo");
		exit(1);
	}
	for (int i = 0; i < stack->size_arr; ++i)
		fprintf(*file_ptr, "%d\n", stack->array[i]);
	
	fclose(*file_ptr);
}

int myGenerateRandomNum(){
	int rand_num;
	rand_num = rand()%RAND_LIM;
	return rand_num;
}

void myReallocPlusOne(List * stack){
	stack->size_arr += 1;
	stack->array = (int *) realloc(stack->array, stack->size_arr * sizeof(int));
}

void myPushStackRight(List * stack){
	myReallocPlusOne(stack);
	stack->array[stack->size_arr-1] = myGenerateRandomNum();
}

void myPushStackLeft(List * stack){
	myReallocPlusOne(stack);
	for (int i = stack->size_arr - 1; i > 0; --i)
		stack->array[i] = stack->array[i-1];
	
	stack->array[0] = myGenerateRandomNum();
}

void mySortStack(List * stack){
	int temp_int;
	for (int i = 0; i < stack->size_arr; ++i) {
		for (int j = i + 1; j < stack->size_arr; ++j) {
			if(stack->array[i] > stack->array[j]){
				temp_int = stack->array[i];
				stack->array[i] = stack->array[j];
				stack->array[j] = temp_int;
			}
		}
	}
}

void myPrintMenu(){
	printf("\n0\tSukuriamas tuscias sarasas");
	printf("\n1\tNuskaitomi duomenys is nurodyto failo ir idedami i steka");
	printf("\n2\tSaraso spausdinimas");
	printf("\n3\tIterpiamas i staka is DESINES atsitiktinis skaicius(intervalas [0;%d])", RAND_LIM);
	printf("\n4\tIterpiamas i staka is KAIRES atsitiktinis skaicius(intervalas [0;%d])", RAND_LIM);
	printf("\n5\tSaraso istrinimas");
	printf("\n6\tAtspausdinamas programos menu");
	printf("\n7\tIseinama is programos");
}


int main(){
	
	FILE * data_file_ptr = NULL;
	FILE * result_file_ptr = NULL;
	char data_file_name[MAX_FILE_LENTH];
	char result_file_name[MAX_FILE_LENTH];
	int user_input;

	
	srand(time(NULL));

	List two_way_stack;

	myPrintMenu();
	printf("\n");

	int g = 0;
	while (g == 0) {
	printf("\n");
		if ((scanf("%1d", &user_input) == 1) && (getchar() == '\n')) {
				
		
			if (user_input == 0) {
				myCreateEmptyList(&two_way_stack);
				printf("\nSukurtas tuscias sarasas.");
			}
		
			
			if (user_input == 1) {
				int number_of_rows = 0;
				printf("\nPrasome ivesti failo pavadinima, is kurio bus skaitomi duomenys.\nPavadinimas:");
				if ((scanf("%[^\n]", &data_file_name)) == 1 && (getchar() == '\n')){
					number_of_rows = myCountFileRows(&data_file_ptr, data_file_name, &two_way_stack);
					if (number_of_rows < 0)
						printf("\nNepavyko atidaryti duomenu failo.");				
					else if (number_of_rows == 0)
						printf("\nFaile nera duomenu.\n");
					else {
						two_way_stack.size_arr = number_of_rows;
						myFillListFromFile(data_file_ptr, &two_way_stack);
						printf("\nDuomenys is failo nuskaityti ir ideti i sarasa.");
						
					}					
				}
					
			}
			
			
			if (user_input == 2) {
				char *file_or_cmd;
				int a = 0;
				printf("\nPrasome pasirinkti spausdinsite staka faile - \"f\" ar darbalaukyje - \"d\"?\n");
				while (a == 0) {	
					
					if ((scanf("%[^\n]c", &file_or_cmd) == 1) && (getchar() == '\n')) {
						int number_of_rows = 0;
						if (strcmp(file_or_cmd, "f") == 0) {
							printf("\nPrasome ivesti failo pavadinima, i kuri bus rasomi duomenys.\nPavadinimas:");
							if ((scanf("%s", &result_file_name)) == 1 && (getchar() == '\n')) {
								number_of_rows = myCountFileRows(&result_file_ptr, result_file_name, &two_way_stack);
								if (number_of_rows < 0) {
									myPrintListInFile(&result_file_ptr, &two_way_stack, result_file_name);
									printf("\nSukurtas naujas failas \"%s\" ir jame irasytas stakas.", result_file_name);
									
								} else if (number_of_rows > 0) {
									int b = 0;
									char yes_or_no;
									printf("\nFailas rastas, bet jis nera tuscias.");
									while (b == 0) {
										printf("\nAr tikrai norite, kad filas butu overwrit'intas? Taip - \"t\", Ne - \"n\"\n");
										if ((scanf("%[^\n]c", &yes_or_no) == 1) && (getchar() == '\n')) {
											if (yes_or_no == 't'){
												myPrintListInFile(&result_file_ptr, &two_way_stack, result_file_name);
												printf("\nSarasas irasytas i \"%s\".", result_file_name);
												++b;
												++a;
											} else if (yes_or_no == 'n'){
												printf("\nSarasas nebuvo irasytas i \"%s\".", result_file_name);
												++b;
												
											} else {
												printf("\nNetinkama ivestis.");
											//	while(getchar() != '\n')
											//		;
											}
										}
									}
								} else if (number_of_rows == 0){
									printf("\nFailas rastas ir jis yra tuscias.");
									myPrintListInFile(&result_file_ptr, &two_way_stack, result_file_name);
									printf("\nSarasas nebuvo irasytas i \"%s\".", result_file_name);
									++a;
								
								} else {
									printf("\nNenuspeta salyga.");
									++a;
								}
							}
						} else if (strcmp(file_or_cmd, "d") == 0) {
							printf("\nAtspausdinamas saras darbalaukyje:\n");
							myPrintList(&two_way_stack);
							++a;
						} else {
							printf("\nNetinkama ivestis.");
						//	while(getchar() != '\n')
						//		;
						}
					}
				}
			}
			
			if (user_input == 3){
				myPushStackRight(&two_way_stack);
				printf("\nI staka is DESINES buvo iterpatas skaicius(intervalas [0;%d])", RAND_LIM);
			}
			
			if (user_input == 4){
				myPushStackLeft(&two_way_stack);
				printf("\nI staka is KAIRES buvo iterpatas skaicius(intervalas [0;%d])", RAND_LIM);
			}
			
			if (user_input == 5){
				if (two_way_stack.size_arr > 0) {
				int f = 0;
				char yes_or_no;
				while (f == 0) {
					printf("\nAr tikrai norite istrinti jau egzistuojanti sarasa? Taip - \"t\", Ne - \"n\"\n");
					if ((scanf("%c", &yes_or_no) == 1) && (getchar() == '\n')) {
						if (yes_or_no == 't'){
							myDestroyList(&two_way_stack);
							printf("\nSarasas buvo istrintas.");
							++f;
						}
						else if (yes_or_no == 'n') {
						printf("\nSarasas nebuvo istrintas.");
						++f;
					} else {
						printf("\nNetinkama ivestis.");
					//	while(getchar() != '\n')
					//		;
					}					
					
					} 
				}
				
				} else {
					myDestroyList(&two_way_stack);
					printf("\nSarasas buvo istrintas.");
				}
			}
			
			if (user_input == 6) {
				myPrintMenu();
				printf("\n");
			}
			
			if (user_input == 7) {
				myDestroyList(&two_way_stack);
				++g;
			}		
			
		}
		//while(getchar() != '\n')
		//	;
	
	}
	
	printf("\nPrograma baigesi.");
	
	return 0;
}