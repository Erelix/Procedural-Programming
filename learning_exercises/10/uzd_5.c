#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char * myMemcpy(char **dest, char *source, int num){
	*dest = (char *)malloc(num);
		
	for(int i = 0; i < num; ++i){
		(*dest)[i] = source[i];
	}
	
	(*dest)[num] = '\0';
	return *dest;
}


int main(){	
	
	char *final_arr;
	assert(strcmp(myMemcpy(&final_arr, "labas", 4), "laba") == 0); 		free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "labas", 5), "labas") == 0); 	free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "labas", 6), "labas") == 0); 	free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "labas", 0), "") == 0);			free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "labas", 0), "kl") != 1);		free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "123456", 2), "12345") != 0);	free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "\n\n", 2), "\n\n") == 0);		free(final_arr);
	assert(strcmp(myMemcpy(&final_arr, "\n\n", 2), "\n\n") == 0);		free(final_arr);

	return 0;
}