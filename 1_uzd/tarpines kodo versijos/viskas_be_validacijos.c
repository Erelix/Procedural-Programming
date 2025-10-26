#include <stdio.h>

int main(){
		
	int given_number=0;
	int single_digit;
	int one_counter = 0;
	int altered_positive_number;
	int temp_number_saver;
	int term_of_sequence = 0;
	int i = 0;
	
		
	printf("Prasome ivesti sveika skaiciu: ");
	scanf("%d",&given_number);
	
	while(given_number == 0){ // nulio validacija
		printf("Su nuliu seka negalima. Prasome ivesti sveika skaiciu (tik ne nuli): ");
		scanf("%d",&given_number);
	}
		
	int altered_number = given_number;
	int all_sequence_numbers[100] = {0}; 
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