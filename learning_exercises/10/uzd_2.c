#include <stdio.h>
#include <assert.h>

int myStrcmp(char *word1, char *word2){
	int i = 0;
	int result = 0;

	for(; word1[i] != '\0' && word2[i] != '\0'; ++i){
		if(word1[i] != word2[i]){
			result = 1;
			break;
		}	
	}
	if(word1[i] != '\0' || word2[i] != '\0')
		result = 1;
	
	return result;
}

int main(){
	
	assert(myStrcmp("labas","labas") == 0);
	assert(myStrcmp("79831\n0239","79831\n0239") == 0);
	assert(myStrcmp("","") == 0);
	assert(myStrcmp("ddaw","lwpal") != 0);
	assert(myStrcmp("90","80") != 0);
	assert(myStrcmp("123","321") != 0);
	assert(myStrcmp(" a0"," A0") != 0);
	assert(myStrcmp("0","") != 0);
	assert(myStrcmp("0","000000000") != 0);
	assert(myStrcmp("","\n") != 0);
	assert(myStrcmp("\t","") != 0);
	
	
	return 0;
}