#include <stdio.h>

	int main(){
		
		int numbers[8] = {65, 100, 114, 105, 97, 110, 97, 115};
		int i;
		
		for(i = 0; i <= 7; i++){
			printf("%c", numbers[i]);
		}
		return 0;
	}