#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	
	srand(time(NULL));
	int a = -1;
	int b = -1;
	int c = -1;
	int z = 0;
	int random_number = 0;
	
	printf("Programa is userio gautus skaicius: a, b, c. Atspausdina atsitiktinai sugeneruotu c elementu, kurie yra tarp reziu [a;b]\n");
	
	printf("\nPrasome ivesti a ir b, kur a ir b yra sveiki skaiciai reziuose [0;%d] \n", RAND_MAX);
	
	
	// a ivestis (validacija)
	while(z == 0){
		printf("a: ");
		if (scanf("%d", &a) == 1 && a >= 0 && a <= RAND_MAX && getchar() == '\n'){
			printf("a ivestis issaugota (a = %d)\n", a);
			++z;
		}else{
			printf("a ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", RAND_MAX);
			while(getchar() != '\n')
				;
		}
	}
	
	
	// b ivestis (validacija)
	z = 0;
	while(z == 0){
		printf("b: ");
		if (scanf("%d", &b) == 1 && b >= 0 && b <= RAND_MAX && a < b && getchar() == '\n'){
			printf("b ivestis issaugota (b = %d)\n", b);
			++z;
		}else if(a >= b){
			printf("Ivestis b negali buti mazesne ar lygi uz ivesti a\n");
			while(getchar() != '\n')
				;
		}else{
			printf("b ivestis neissaugota, neatitinka reziu [0;%d], prasome ivesti sveika skaiciu atitinkanti rezius.\n", RAND_MAX);
			while(getchar() != '\n')
				;
		}
	}	
	
	
	
	//c ivestis (validacija)
	printf("\nPrasome ivesti c, kur c yra sveikas skaicius reziuose [0;1000]:\n");
	z = 0;
	while(z == 0){
		printf("c: ");
		if (scanf("%d", &c) == 1 && c >= 0 && c <= 1000 && getchar() == '\n'){
			printf("c ivestis issaugota (c = %d)\n", c);
			++z;
		}else{
			printf("c ivestis neissaugota, neatitinka reziu [0;1000], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	
	int array[c];
	for (int i = 0; i < c; ++i){
		random_number = a + rand() % ((b - a) + 1);
		array[i] = random_number;
	}
	
	
	//Rezultatai
	printf("\n---------------------------\n");
	printf("\nReziai [%d;%d], elementu skaicius = %d;\n", a, b, c);
	printf("Sugeneruotas sio masyvo turinys:\n\n");
	
	for (int i = 0; i < c; ++i){
		printf("%d ", array[i]);
	}
	
	return 0;
}