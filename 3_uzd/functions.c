#include "myFunctions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
//4 - 12 var
FILE * myFileOpen(FILE *f_ptr, char *f_purpose){
	char file_name[255];
	int a = 0;
	while(a == 0){
		printf("\nPavadinimas: ");
		if(scanf("%s", &file_name) == 1 && getchar() == '\n'){
			f_ptr = fopen(file_name, f_purpose);
			
			if(f_ptr == NULL){
				if(strcmp(f_purpose, "r") == 0)
					printf("Failas skaitymui nerastas.\n", file_name);
				else if(strcmp(f_purpose, "w") == 0)
					printf("Failas rasymui nei rastas nei sukurtas.\n", file_name);
			}else
				++a;
		}
	}
	if (strcmp(f_purpose, "r") == 0)
		printf("Failas \"%s\" rastas skaitymui.\n", file_name);
	else if(strcmp(f_purpose, "w") == 0)
		printf("Failas \"%s\" rastas arba sukurtas rasymui.\n", file_name);
	return f_ptr;
}	


/*
//------------------------------------------------
//Buvusi funkcija
//------------------------------------------------
	
int myReadLine(FILE *f_ptr, char **string){
	int rez = 0;
	*string = (char *) calloc(255, sizeof(char));
	if(fgets(*string, 255, f_ptr) != NULL)
		rez = 1;
	return rez;
}
*/


//------------------------------------------------
//Pataisyta funkcija:
//------------------------------------------------

int myReadLine(FILE *f_ptr, char **string){
    int rez = 0;
    int i = 0;
	char c;
    long int line_start = ftell(f_ptr);

    for(; (c = fgetc(f_ptr)) != '\n' && c != EOF && i < 256; ++i)
		;

    if(i > 0){
        *string = (char *)malloc((i + 1) * sizeof(char)); 

        fseek(f_ptr, line_start, SEEK_SET);
		
		if(i == 256)
			i -= 2;
		
        if(fgets(*string, i + 1, f_ptr) != NULL){
			rez = 1;
            (*string)[i] = '\n';
			(*string)[i+1] = '\0';
        }else{
			free(*string);
			*string = NULL;
        }
    }

    while((c = fgetc(f_ptr)) != '\n' && c != EOF);

    return rez;
}

//------------------------------------------------


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
					string[str_len] = '\0';
				}
			}
		}
	}
	string = (char *)realloc(string, (str_len+1) * sizeof(char));
	return string;
}



