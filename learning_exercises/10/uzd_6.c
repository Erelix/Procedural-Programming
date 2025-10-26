#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

int myStrcspn(char *str, char *search_str){
	int i = 0;
	for(; i < strlen(str); ++i){
		if(str[i] == *search_str)
			break;
	}
	return i;
}

int main(){
	
	assert(myStrcspn("lab.as", ".") == 3);
	assert(myStrcspn("lab.as", ".") != 4);
	assert(myStrcspn("123456", "6") == 5);
	assert(myStrcspn("labas", ".") == 5);
	assert(myStrcspn("labas", "ab") == 1);
	assert(myStrcspn("o\nras", "\n") == 1);	
	assert(myStrcspn("o\nras", "\n") == 1);	
	assert(myStrcspn("labas", "labas") == 0);
	assert(myStrcspn("", "") == 0);
	assert(myStrcspn("labas", "\0") == 5);
	
	
	return 0;
}