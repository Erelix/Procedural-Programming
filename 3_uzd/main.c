#include "myFunctions.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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