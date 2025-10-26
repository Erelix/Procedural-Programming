#include <stdio.h>
#include <math.h>

#define MIN 10
#define MAX 1000

int main(){
	
	double num, before_comma;
	double after_comma = 1;
	int digit_counter = 0;
	int end = 0;
	FILE * inFile;
	int a = 1;
	char file_name[100];
	
	printf("Programa paima is \"in.txt\" irasyta realuji skaiciu ir patikrina, ar jis ne mazesnis uz %d ir ne didesnis uz %d bei ar su ne daugiau kaip 3 skaiciais po kablelio, jeigu ivestas skaicius neatitinka siu reikalavimu, yra prasoma pavadinimo txt failo, kur jau yra skaicius atitinkantis siuos reikalavimus.\n\n", MIN, MAX);
	
	
	while (end == 0){
		//int.txt paziurejimas
		if(a == 1){
			inFile = fopen("in.txt", "r");
		
			if(inFile == NULL){
				printf("\n\"in.txt\" failas neegzistuoja.");
			}else{
				printf("\n\"in.txt\" failas rastas.\n");
				
			}
		}
	
		//ivesties validacija bei failo ieskojimas
		while(a == 0){
			printf("\n\n\nPrasome ivesti failo varda, kuriame esantis skaicius atitinka reikalavimus: ");
			if(scanf("%s", &file_name) == 1 && getchar() == '\n'){
				inFile = fopen(file_name, "r");
				
				if(inFile == NULL){
					printf("\nToks failas neegzistuoja.");
				}else{
					printf("\n\"%s\" failas rastas\n", file_name);
					++a;
				}
			}else{
				printf("\nBloga ivestis.");
				while(getchar() != '\n')
					;
			}
		} 	

		//Tikrinimas, ar atitinka kriterijus
		if(fscanf(inFile, "%lf", &num) == 1){
			printf("\nFaile esantis skaicius: %lf", num);

			if((num > MIN) && (num < MAX)){
				int counter = 0;
				after_comma = modf(num, &before_comma);		
			
				while (after_comma != 0 && counter <= 3){
					num *= 10;
					//kartojasi eilute :(
					after_comma = modf(num, &before_comma);	
					++counter;
				}
				
				if(counter <= 3){
					int num_int = num;
				
					for(digit_counter = 0; num_int > 0; ++digit_counter){
						num_int /= 10;
					}	
					printf("\nyra tarp reziu (%d,%d) ir po kablelio neturi daugiau 3 skaiciu. Todel:",MIN, MAX);
					printf("\n-----------------------------------------------------------------------------------------------\nRezultatas:");
					printf("\nSkaicius esantis faile turi tiek skaitmenu: %d", digit_counter);
					++end;
				}else
					printf("\nturi daugiau nei 3 skaicius po kablelio.");
			}else
				printf("\nneatitinka reziu (%d;%d)", MIN, MAX);
		}else         
			printf("\nFaile ivestas ne skaicius.");
		
	a = 0;
	fclose(inFile);
	
	}
	
	printf("\n\nPrograma baigesi.");
	
  return 0;
}