#include <stdio.h>

#define MIN_WHOLE -9999999
#define MAX_WHOLE 99999999
#define SIZE 1000

int main(){

	int a = 0;
	int all_num[SIZE];
	int num = -1;
	int counter = 0;
	int digit_counter;
	int temporary_num;
	int max_digit = 0;
	int num_with_most_digits;
	int i;
	
	
	printf("\nPrograma praso is vartotojo sveiku teigiamu skaiciu iki kol vartotojas iveda neteigiama skaiciu. Tada programa is visu ivestu skaiciu atrenka skaiciu su daugiausiai skaitmenu.\n");
	printf("\n\nPrasome vesti sveikus teigiamus skaicius, nebent norite uzbaigti vedima, tada iveskite neteigiama reiksme:\n");
	
	//ivesciu rinkejas ir validuotojas
	while(counter < SIZE && a == 0){  
	
	  printf("x%d: ", counter);
		if((scanf("%d", &num) == 1) && (getchar() == '\n')){
			if((num > 0) && (num <= MAX_WHOLE)){
				
				printf("Skaicius ivestas teisingai (x%d = %d)\n\n", counter, num);	
				all_num[counter] = num;
				++counter;
				
			}else if (num <= 0){
				printf("\nSkaiciu ivedinejimas baigesi, kadangi buvo ivestas neteigiamas skaicius ( %d )\n", num);
				++a;
			}else{
				printf("Virsyti masyvo reziai [%d;%d]\n", MIN_WHOLE, MAX_WHOLE);
			}	
		}else{
			printf("Netinkama ivestis. Reikalingas sveikas skaicius\n"); 
			while(getchar() != '\n')
				;
		}
	}
	
	// skaiciaus su daugiausiai skaitmenu ieskotojas
	for (i = 0; i < counter; ++i){
		temporary_num = all_num[i];
		for (digit_counter = 0; temporary_num > 0; ++digit_counter){
			temporary_num = temporary_num / 10;
		}
		if (digit_counter >= max_digit){
			max_digit = digit_counter;
			num_with_most_digits = all_num[i];
		}
	}
	
	//Rezultatai
	
	printf("\n\n---------------------------------------------------------------\n");
	printf("Is visu naturaliu teigiamu skaiciu skaicius su daugiausiai skaitmenu:\n");
	printf("\n%d", num_with_most_digits);

	
	
	return 0;
	
}