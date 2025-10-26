#include <stdio.h>

#define MIN_WHOLE -999999
#define MAX_WHOLE 9999999
#define SIZE 1000

int main(){
	int all_num[SIZE];
	int all_prime_num[SIZE];
	int num;
	int without_residue_count;
	int prime_index = 0;
	int a = 0;
	int counter = 0;
	int icounter = 0;
	int jcounter = 0;
	
	
	// prasomi ir validuojami n skaicius elementu
	printf("\nPrograma praso is vartotojo sveiku teigiamu skaiciu iki kol vartotojas iveda neteigiama skaiciu. Tada programa atrenka visus priminius skaicius. Ir galiausiai istrina pasikartojancius pirminius skaicius\n");
	printf("\n\nPrasome vesti sveikus teigiamus skaicius, nebent norite uzbaigti vedima, tada iveskite neteigiama reiksme:\n");
	
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

	// atrenkami pirminiai skaiciai
	int b = 0;	
	while(b < counter){
		without_residue_count = 0;
			for(int i = 1;  i <= all_num[b]; ++i){
				if (all_num[b] % i == 0)
					++without_residue_count; 
			}
			if(without_residue_count == 2){
				all_prime_num[prime_index] = all_num[b];
				++prime_index;
			}
		++b;
	}
	
	//ismetami pasikartojantys pirminiai skaiciai
	while (icounter < prime_index){
			jcounter = icounter + 1;
		while (jcounter < prime_index){
			if(all_prime_num[icounter] == all_prime_num[jcounter]){
				for (int j = jcounter; j < prime_index; ++j)
					all_prime_num[j] = all_prime_num[j+1];
				--prime_index;
				--jcounter;
				--icounter;
			}
			++jcounter;
		}
		++icounter;
	}
	
	//rezultatas
	printf("\n-------------------------------------------------------------------------");
	printf("\n\nIs visu ivestu skaiciu sie yra pirminiai skaiciai:\n");
	
	for (int i = 0; i < prime_index; ++i)
		printf("%d ", all_prime_num[i]);
	
	
	return 0;
}