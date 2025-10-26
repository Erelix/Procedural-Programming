#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char *myStrchr(char *str, int c){
	int i = 0;
	char * result;
	int size = strlen(str);
	
	for (; i < size; ++i){
		if (str[i] == c)
			break;
	}
	
	if(i == size){
		return NULL;
    }

	++i;
	int new_size = size - i + 1;
	result = (char *)malloc(new_size * sizeof(char));
	int j = 0;
	
	for(; j < (new_size - 1); ++i){
		result[j] = str[i];
		++j;
	}
	result[j] = '\0';

   return result;
}


int main(){
	
	assert(strcmp(myStrchr("lab.as", '.'), "as") == 0);
	assert(strcmp(myStrchr("lab.as", '.'), "a") != 0);
	assert(myStrchr("labas", '.') == NULL);
	assert(myStrchr("lab.as", '.') != NULL);
	assert(myStrchr("", '.') == NULL);
	assert(strcmp(myStrchr("du.trys.du", '.'), "trys.du") == 0);
	assert(strcmp(myStrchr("du.trys.du", '.'), "rys.du") != 0);
	assert(strcmp(myStrchr("pen\nki", '\n'), "nki") != 0);
	assert(strcmp(myStrchr("pen\nki", '\n'), "ki") == 0);
	assert(strcmp(myStrchr("123456789", '4'), "56789") == 0);
	assert(strcmp(myStrchr("123456789", '4'), "5678") != 0);

	
	
	
	return 0;
}