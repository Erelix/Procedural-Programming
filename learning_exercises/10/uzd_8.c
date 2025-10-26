#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>


char *myStrpbrk(char *str, char *sec_str){
	int j = 0;
	if (strlen(sec_str) != 0){
		for(; j < strlen(sec_str); ++j){
			for(int i = 0; i < strlen(str); ++i){
				if(str[i] == sec_str[j])
					return (str + i);
			}
		}
	}else
		return NULL;
		
	if(j == strlen(sec_str))
		return NULL;
}

int main(){

	assert(myStrpbrk("labas", "bs") == strchr("labas", 'b'));
    assert(myStrpbrk("labas", "rs") == strchr("labas", 's'));
    assert(myStrpbrk("\n\n\t\n", "\t") == strchr("\n\n\t\n", '\t'));
	assert(myStrpbrk("labas", "f") == NULL);
	assert(myStrpbrk("", "") == NULL);
    assert(myStrpbrk("1234567", "9846") == strchr("1234567", '4'));
	assert(myStrpbrk("321", "123") == strchr("321", '1'));
	

	return 0;
}