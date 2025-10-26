#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	
	int all_sequence_numbers[100] = {0}; 
	char user_input[20];
	int single_digit;
	int one_counter = 0;
	int altered_positive_number;
	int temp_number_saver;
	int term_of_sequence = 0;
	int incorrect_char = 1;
	int altered_number;
	int z;
	
	
	//validacija

	while(incorrect_char > 0){
		incorrect_char = 0;
		z = 0;
		
		printf("Prasome ivesti sveika skaiciu: ");
		scanf(" %s", &user_input);
		
		if(strlen(user_input) > 9){
			++incorrect_char;
		}
		
		if(user_input[0]==45 || user_input[0]==43){
			++z;
			printf("\nSkaicius su zenklu\n");
		}
	
		for(; user_input[z] != '\0'; ++z) { 
			if (user_input[z]<48 || user_input[z]>57){
				++incorrect_char;
			}
		}
	}
	
	printf("\nJusu pasirinktas skaicius ( %s )\n", user_input);
	
	altered_number = atoi(user_input); // is stringo i int pakeitimas

	all_sequence_numbers[term_of_sequence] = altered_number;	
	
	while(1){	
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
			printf("\n%d\tlaikinas teigiamas skaicius\n%d\tskaitmuo\n%d\tvienetu skaiciuokle\n", temp_number_saver, single_digit, one_counter);		
		}
		
		if(one_counter == 0){
			if(altered_number % 2 == 0){
				printf("\nSkaicius ( %d ) lyginis, todel %d / 2\tGauname:", altered_number, altered_number);
				altered_number /= 2;
			}else{
				printf("\nSkaicius ( %d ) nelyginis, todel %d * 3 + 1\tGauname:", altered_number, altered_number);
				altered_number = 3 * altered_number + 1;
			}
			
			printf("( %d )\n\n",altered_number);
			++term_of_sequence;
			
		}else{
			//Jei skaiciuje 1 isvedama lentele:
			
			printf("\n..........................................\n\n");
			printf("\nVisi gauti sekos rezultatai:\n\n");
			printf("Xn\t\tSekos nariai\n");
			
			for(int i = 0; i <= term_of_sequence; ++i){	
				printf("X%d ............ %d\n",i, all_sequence_numbers[i]);
			}
				
				printf("\nprograma baigesi.");
			  return 0;
			}
			
		all_sequence_numbers[term_of_sequence] = altered_number; // issaugojam gauta skaiciu all_sequence_numbers arrayjuje
	}	
}