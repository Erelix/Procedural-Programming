#include <stdio.h>
#include <assert.h>

int myStrlen(char *word) {
	int i;
	for(i = 0; word[i] != '\0'; ++i);
	return i;
}

int main(){
	
	assert(myStrlen("labas") == 5);
	assert(myStrlen("Devyniasdesimt") == 14);
	assert(myStrlen("As grazi, bet nelaiminga.") == 25);
	assert(myStrlen("0123456789") == 10);
	assert(myStrlen("][;,.//? ()") == 11);	
	assert(myStrlen("\nOP\n") == 4);
	assert(myStrlen("") == 0);	
	
	return 0;
}