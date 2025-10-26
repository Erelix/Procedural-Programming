#include <stdio.h>
#include <ctype.h>

int main(){

	int all_sequence_numbers[100] = {0}; 
	char given_number = -1;
	int single_digit;
	int one_counter = 0;
	int altered_number;
	int altered_positive_number;
	int temp_number_saver;
	int term_of_sequence = 0;
	int i = 0;
	char neg_or_pos = -1;
	
	

	while(isdigit(neg_or_pos) == 0){

		printf("Ar skaicius teigiamas ar neigiamas (0 = neigiamas, 1 = teigiamas)?\n",neg_or_pos);
		scanf(" %c",&neg_or_pos);
	}

	while(isdigit(given_number) == 0){
		printf("Prasome ivesti norima sveika skaiciu(ivesti teigiama): ");
		scanf(" %c",&given_number);
	}
	
	printf("%c %c",given_number, neg_or_pos);
	//	neg_or_pos = (int)(neg_or_pos);
	//	given_number = (int)(given_number);
		
	if(neg_or_pos == 0){
		altered_number = -given_number;
	}else if(neg_or_pos == 1){		
		altered_number = given_number;
	}else{
		printf("bad");
	}
	
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
					one_counter++;
				}
			printf("\n%d\tlaikinas teigiamas skaicius\n%d\tskaitmuo\n%d\tvienetu skaiciuokle\n", temp_number_saver, single_digit, one_counter);		
		}
		
		if(one_counter == 0){
			if(altered_number % 2 == 0){
				printf("\nSkaicius ( %d ) lyginis, todel %d / 2\tGauname:", altered_number, altered_number);
				altered_number /= 2;
				printf("( %d )\n\n",altered_number);
				term_of_sequence++;
	
			}else{
				printf("\nSkaicius ( %d ) nelyginis, todel %d * 3 + 1\tGauname:", altered_number, altered_number);
				altered_number = 3 * altered_number + 1;
				printf("( %d )\n\n", altered_number);
				term_of_sequence++;
			}
			
		}else{
			printf("\n..........................................\n\n");
			printf("\nVisi gauti sekos rezultatai:\n\n");
			printf("Xn\t\tSekos nariai\n");
			
			for(i; i <= term_of_sequence; i++){	
				printf("X%d ............ %d\n",i, all_sequence_numbers[i]);
			}
				
				printf("\nprograma baigesi.");
			  return 0;
			}
		all_sequence_numbers[term_of_sequence] = altered_number; // issaugojam gauta skaiciu all_sequence_numbers arrayjuje
	}	

}