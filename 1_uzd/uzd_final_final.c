#include <stdio.h>

int main(){
	
	int single_digit;
	int one_counter = 0;
	int altered_positive_number;
	int temp_number_saver;
	int term_of_sequence = 0;
	int altered_number;	
	int user_input;
	
	while(1){
		printf("Iveskite sveika skaiciu: ");
		
		if((scanf("%d", &user_input) == 1) && (user_input >= -99999999) && (user_input < 99999999)){
			altered_number = user_input;
			printf("Skaicius ivestas teisingai\n\n");
			break;	
			
		}while(getchar() != '\n')
			;
	}   
   	
	printf("..........................................\n\n");
	printf("\nVisi gauti sekos rezultatai:\n\n");
	printf("Xn\t\tSekos nariai\n");
	
	if(altered_number == 0){
		printf("\n!!! Su nuliu seka begaline !!!\n\n");
		return 0;
	}
	
	while(1){	
		printf("X%d ............ %d\n", term_of_sequence, altered_number);
		
		if(altered_number < 0){
			altered_positive_number = - altered_number;	
			}else{
				altered_positive_number = altered_number;
			}
			
		for(temp_number_saver = altered_positive_number; temp_number_saver != 0; temp_number_saver /= 10){
			single_digit = temp_number_saver % 10;
				
			if(single_digit == 1){
				++one_counter;
			}
		}
		
		if(one_counter == 0){
			if(altered_number % 2 == 0){
				altered_number /= 2;
			}else{
				altered_number = 3 * altered_number + 1;
			}
			
			++term_of_sequence;
			
		}else{
		
			printf("\nprograma baigesi.");
			return 0;
		}
	}	
}