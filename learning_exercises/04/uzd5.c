#include <stdio.h>

#define MAX_DOUBLE 99999999
#define MIN_DOUBLE -9999999
#define SIZE 1000

int main(){

	int n = -1;
	int a = 0;
	double sum;
	double average;
	double min = MAX_DOUBLE;
	double max;
	double num = -1;
	int counter = 0;
	
	printf("\nPrograma papraso skaiciaus n, kur skaicius n bus, kiek reikes ivesti realiuju skaiciu. Tada bus prasoma ivesti n realiuju skaiciu. Programa suskaiciuos visu ivesciu suma, vidurki, bei isrinks didziausia ir maziausia reiksmes\n");
	printf("\n\nPrasome ivesti skaiciu n, kur n sveikas skaicius (reziai [0;%d]):\n", SIZE);
	
	
	//prasoma n ivestis (validacija)
	a = 0;
	while(a == 0){
		printf("n: ");
		if (scanf("%d", &n) == 1 && n >= 0 && n <= SIZE && getchar() == '\n'){
			printf("n ivestis issaugota (n = %d)\n", n);
			++a;
		}else{
			printf("n ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", SIZE);
			while(getchar() != '\n')
				;
		}
	}
	
	// prasomi ir validuojami n skaicius elementu saugomi max, min ir sumuojama

	printf("\n\nPrasome ivesti %d elementu(-us)(-a), kurie yra Realieji skaiciai tarp reziu [%d;%d]\n", n, MIN_DOUBLE, MAX_DOUBLE);
	
	while(counter < n){  
	
	  printf("x%d: ", counter);
		if((scanf("%lf", &num) == 1) && (getchar() == '\n')){
			if((num > MIN_DOUBLE) && (num <= MAX_DOUBLE)){
				printf("Skaicius ivestas teisingai (x%d = %f)\n\n", counter, num);	
				sum += num;
				if (max < num)
					max = num;
				else if (min > num)
					min = num;
				++counter;
			}else{
				printf("Virsyti masyvo reziai (%d;%d]\n", MIN_DOUBLE, MAX_DOUBLE);
			}	
		}else{
			printf("Netinkama ivestis. Reikalingas teigiamas sveikas skaicius\n"); 
			while(getchar() != '\n')
				;
		}
	}
	
	printf("\n\n-----------------------------------------------------------------------\n");
	printf("Visu ivestu elementu suma, vidurkis, bei is visu elementu didziausias ir maziausias skaiciai:\n");
	
	average = sum / n;
	
	printf("\nSuma = %lf", sum);
	printf("\nVidurkis = %lf", average);
	
	if (n == 0)
		printf("\nMIN = %lf", 0);
	else
		printf("\nMIN = %lf", min);
	printf("\nMAX = %lf", max);
	

	return 0;
}