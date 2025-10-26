#include <stdio.h>

long getFileSize(char *fileName){
	int size = -1;
	
	FILE * myFile;
	
	myFile = fopen(fileName, "r");
	if(myFile != NULL){
		fseek(myFile, 0, SEEK_END);
		size = ftell(myFile);
	}
	
	fclose(myFile);
	return (size);
}

int main(){
	
	long size;
	char file_name[] = "test.txt";
	
	printf("Programa patikrina ar yra toks failas kaip \"%s\". Jeigu nera, tai atspausdina -1. Jeigu yra, tada su ftell paskaiciuoja jo uzemama vieta baitais.\n", file_name);
	
	size = getFileSize(file_name);
	
	printf("\n%ld", size);
	
	printf("\n\nPrograma baigesi.");
	return 0;
}