#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 255
#define MAX_FILE_NAME 255

FILE * myFileOpen(FILE *f_ptr, char *f_purpose){
	char file_name[MAX_FILE_NAME];
	int a = 0;
	while(a == 0){
		printf("\nPavadinimas: ");
		if(scanf("%s", &file_name) == 1 && getchar() == '\n'){
			f_ptr = fopen(file_name, f_purpose);
			
			if(f_ptr == NULL){
				if(f_purpose == "r")
					printf("Failas skaitymui nerastas.\n", file_name);
				else if(f_purpose == "w")
					printf("Failas rasymui nei rastas nei sukurtas.\n", file_name);
			}else
				++a;
		}
	}
	if(f_purpose == "r")
		printf("Failas \"%s\" rastas skaitymui.\n", file_name);
	else if(f_purpose == "w")
		printf("Failas \"%s\" rastas arba sukurtas rasymui.\n", file_name);
	return f_ptr;
}	
	
int myReadLine(FILE *f_ptr, char **string){
	int rez = 0;
	*string = (char *) calloc(MAX_LINE_LENGTH, sizeof(char));
	if(fgets(*string, MAX_LINE_LENGTH, f_ptr) != NULL)
		rez = 1;
	return rez;
}	

void myFputc(FILE *f_ptr, char *string){
	fputs(string, f_ptr);
}

int myConnect(char *string, int str_len, int i){
	for(; i < str_len; ++i)
		string[i] = string[i+1];
	--str_len;
	return str_len;
}

char * myChecker(char *string){
	int str_len = strlen(string);
	for(int i = 1; i < str_len; ++i){
		if(string[i] == 45){
			if(((string[i-1]>64 && string[i-1]<90) || (string[i-1]>96 && string[i-1]<123))){
				if(((string[i+1]>64 && string[i+1]<90) || (string[i+1]>96 && string[i+1]<123))){
					str_len = myConnect(string, str_len, i);
				}
			}
		}
	}
	string = (char *)realloc(string, str_len * sizeof(char));
	return string;
}

int main(){
	
	FILE *f_data_ptr;
	FILE *f_res_ptr;
	char *purpose;
	
	char *string = NULL;
	
	purpose = "r";
	printf("\nPrasome ivesti duomenu failo pavadinima.");
	f_data_ptr = myFileOpen(f_data_ptr, purpose);
	
	purpose = "w";
	printf("\nPrasome ivesti rezultatu failo pavadinima.");
	f_res_ptr = myFileOpen(f_res_ptr, purpose);
	
	
	while(myReadLine(f_data_ptr, &string) != 0){
		string = myChecker(string);
		  myFputc(f_res_ptr, string);
		    free(string);
	}
	
	fclose(f_data_ptr);
	fclose(f_res_ptr);
	
	printf("\n\nPrograma baigesi.");
	
	return 0;
}
