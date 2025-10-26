#include <stdio.h>

int main(){
	
//a{ is dvejataines i desimtaine
	printf("\na)\n");
	int bin_numbers[3] = {0b11011, 0b10010100, 0b11001011010101};
	int j;
	
	for(j = 0; j < 3; j++){
		switch(j){
			case 0: 
				printf("11011b");
				break;
			case 1: 
				printf("10010100b");
				break;
			case 2: 
				printf("11001011010101b");
				break;
		}
		printf("\t=\t%dd\n", bin_numbers[j], bin_numbers[j]);
	}
//}	
	
	

// b{ is desimtaines i dvejetaine
	printf("\nb)\n");
	int dec_b_numbers[3] = {37, 241, 2487};
	int zero_one_saver[100] = {0};
	int division_count;
	int remains;
	int temporary_number;
	int z;

	for(z = 0; z < 3; z++){
		division_count = 0;
		printf("%dd\t=\t", dec_b_numbers[z]);
		
		zero_one_saver[0] = '\0';
		for(temporary_number = dec_b_numbers[z]; temporary_number != 0; temporary_number /= 2){
			remains = temporary_number % 2;
			
			switch(remains){
				case 0: 
					zero_one_saver[division_count] = 0; 
					break;
				case 1:
					zero_one_saver[division_count] = 1; 
					break;
			}
			division_count++;
		}
		for( ; division_count >= 0; division_count--){
			printf("%d", zero_one_saver[division_count]);
		}
		division_count = 0;
		printf("b\n");	
	}
//}
	
	
	
	
//c{ is sesioliktainio i desimtaine
	printf("\nc)\n");
	int hex_numbers[3] = {0x6E2, 0xED33, 0x123456};
	int i;
	
	for(i = 0; i < 3; i++){
		printf("%Xh\t=\t%dd\n", hex_numbers[i], hex_numbers[i]);
	}
//}




// d{ is desimtaines i sesioliktaine
	printf("\nd)\n");
	int dec_d_numbers[3] = {243, 2483, 4612};
	int k;
	
	for(k = 0; k < 3; k++){
		printf("%dd\t=\t%xh\n", dec_d_numbers[k], dec_d_numbers[k]);
	}
//}
	
  return 0;
}