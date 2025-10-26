#include <stdlib.h>
#include <stdio.h>

char * myFunction(int argc, char* argv[]){
	int counter;
	int temp_largest = 0;
	char * largest_file_yet_name_ptr;
	int size;
	
	largest_file_yet_name_ptr = (char*)malloc(argc * sizeof(char));
	
    for (int i = 1; i < argc; i++) {
		
		FILE * myFile;
		myFile = fopen(argv[i], "r");
		
		if(myFile != NULL){
			fseek(myFile, 0, SEEK_END);
			size = ftell(myFile);
			++counter;
		}
		
		fclose(myFile);
		
		if(size > temp_largest && myFile != NULL){
			temp_largest = size;
			largest_file_yet_name_ptr = argv[i];
		}
	}
	if(counter == 0)
		largest_file_yet_name_ptr = "";
	
	return(largest_file_yet_name_ptr);
}


int main(int argc, char* argv[]){
	
	printf("\nPrograma gauna agrc failu vardu per komandines eilutes parametrus ir grazina daugiasuiai baitu atmintyje uzemancio failo varda.\n");

	char * name_ptr;
	name_ptr = myFunction(argc, argv);
	
	if(name_ptr == "")
		printf("\n\nNULL");
	else
		printf("\nDaugiausiai baitu uzemancio failo vardas: \"%s\"", name_ptr);
	
	
	printf("\n\nPrograma baigesi.");
	free(name_ptr);

	return 0;
}