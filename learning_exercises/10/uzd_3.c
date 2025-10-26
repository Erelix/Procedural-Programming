#include <stdio.h>
#include <assert.h>

int myStrncmp(char *word1, char *word2, int size){
	int i = 0;
	int result = 0;
	for(; word1[i] != '\0' && word2[i] != '\0' && i < size; ++i){
		if(word1[i] != word2[i]){	
			result = 1;
			break;
		}
	}
	if((word1[i] != '\0' || word2[i] != '\0') && i < size)
			result = 1;
	
	return result;
}

int main(){
		
	
	assert(myStrncmp("labas","labas", 2) == 0);
	assert(myStrncmp("kl","kp", 3) != 0);
	assert(myStrncmp("asdt","asdf", 4) != 0);
	assert(myStrncmp("124","123", 2) == 0);
	assert(myStrncmp("124","123", 3) != 0);
	assert(myStrncmp("124","123", 0) == 0);
	assert(myStrncmp("","", 5) == 0);
	assert(myStrncmp("\t\n","\t\n", 2) == 0);
	assert(myStrncmp("\t\n","\n", 2) != 0);
	assert(myStrncmp("00","000", 3) != 0);	
	
	
	return 0;
}