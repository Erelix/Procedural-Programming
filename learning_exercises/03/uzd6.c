#include <stdio.h>

int main(){
	int a;
	int b;
	int c;
	int min;
	int max;
	
	scanf("%d%d%d", &a, &b, &c);
	
	switch(a > b){
		case 0: {
			switch(a > c){
				case 0:{
					min = a;
					switch(b > c){
						case 0: 
							max = c;
							goto end;
						case 1: 
							max = b; 
							goto end;
					}
				}
				case 1:{
					min = c;
					max = b;
					goto end;
				}
			}
		}
		case 1: {
			switch(a > c){
				case 0: {
					min = b;
					max = c;
					goto end;
				}
				case 1:{
					max = a;
					switch(b > c){
						case 0: 
							min = b;
							goto end;
						case 1:
							min = c;
							goto end;
					}
				}
			}
		}
	}
	
	end:
		printf("Min = %d\nMax = %d", min, max);
		
   return 0;
}