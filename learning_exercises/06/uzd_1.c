#include <stdio.h>
#define MAX_FACTORIAL_NUMBER 20

int main () {
   
	int user_input;
	long long int sum = 1;
	int a = 0;
	
	printf("Programa papraso is vartotojo vieno teigiamo sveiko skaiciaus ir suskaiciuoja jo faktoriala, kuri atspausdina ekrane ir taip pat iraso i rezultatu faila \"out.txt\"\n");
	
	//Validacija
	while(a == 0){
		printf("\nJusu skaicius: ");
		
    if((scanf("%d", &user_input) == 1) && (getchar() == '\n')){
        if((user_input >= 0)){
			printf("Skaicius ivestas teisingai\n\n");	
			++a;
        }else
			printf("Skaicius turi buti teigiamas\n");
        
	}else{
		printf("Netinkama ivestis. Iveskite sveika teigiama skaiciu.\n");	
		while(getchar() != '\n')
			;
		}
	}
	
	//skaiciuojamas faktorialas
	if(user_input == 0)
		sum = 0;
	for(int i = 1; i <= user_input; ++i)
		sum *= i;
	
	//Isvedama ir irasoma i out.txt
	if (user_input <= MAX_FACTORIAL_NUMBER){
	
		printf("\n!%d = %lld", user_input, sum);
		printf("\nRezultatas buvo irasytas i \"out.txt\"");
		printf("\n\nPrograma baigesi.");
	   
		FILE * outFile;
		outFile = fopen("out.txt", "w");
		fprintf(outFile, "\n!%d = %lld", user_input, sum);
   
		fclose(outFile);
	}else
		printf("Faktorialas yra per didelis, kad butu teisingai apskaiciuotas. Rezultatas nebetelpa i long long int");
	
  return 0;
}