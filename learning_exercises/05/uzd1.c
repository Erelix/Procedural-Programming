#include <stdio.h>

int main(){
	
	printf("b) Masyvas, galintis sutalpinti 10 elementu, kurio visi elemtai yra nuliai:\n\n");
	int array[10] = {0};
	
	//isveda mayva
	for (int i = 0; i < 10; ++i){
		printf("%d", array[i]);
	}
	
	printf("\n\nf) Masyvas, kurio pirmam, ketvirtam ir desimtam elementams atitinkamai priskirtos reiksmes: 1, 2, 3. Taip pat, jo treciasis elementas yra istrintas bei iterptas naujas elementas 4, kuris po iterpimo yra septintas elementas:\n\n");
	array[0] = 1;
	array[3] = 2;
	array[8] = 3;
	

	//istrina 3 elementa
	for (int j = 2; j < 10; ++j){
		array[j] = array[j+1];
	}
	
	//iterpia nauja reiksme 4 indeksu septyni
	for (int j = 9; j > 5; --j){
		array[j] = array[j-1];
	}
	array[6] = 4;
	
	//isveda masyva
	for (int i = 0; i < 10; ++i){
		printf("%d", array[i]);
	}
	
	
	// praso x ir y (validacija)
	int x = -1;
	int y = -1;
	int a = 0;

	printf("\n\ng) Prasome ivesti 2 sveikus skaicius x ir y (reziai [0;9]), kur x yra indeksas, o y reiksme, kuri bus priskirta x indeksu:\n");
	while(a == 0){
		printf("x: ");
		if (scanf("%d", &x) == 1 && x >= 0 && x < 10 && getchar() == '\n'){
			printf("x ivestis issaugota (x = %d)\n", x);
			++a;
		}else{
			printf("x ivestis neissaugota, neatitinka reziu [0;9], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	a = 0;
	printf("\nDabar prasome ivesti y ivesti:");
	while(a == 0){
		printf("\ny: ");
		if (scanf("%d", &y) == 1 && y >= 0 && y < 10 && getchar() == '\n'){
			printf("y ivestis issaugota (y = %d)\n", y);
			++a;
		}else{
			printf("y ivestis neissaugota, neatitinka reziu [0;9], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	// y reiksme istato x indeksu
	array[x] = y;
	
	
	//praso x (validaciija)
	a = 0;
	x = -1;
	printf("\n\nh) Prasome ivesti sveika skaiciu x (reziai [0;9]), bus istrintas masyvo elementas su x indeksu:\n");
		while(a == 0){
		printf("x: ");
		if (scanf("%d", &x) == 1 && x >= 0 && x < 10 && getchar() == '\n'){
			printf("x ivestis issaugota (x = %d)\n", x);
			++a;
		}else{
			printf("x ivestis neissaugota, neatitinka reziu [0;9], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	
	//istrina is masyvo reiksme indeksu x
	for (int j = x; j < 10; ++j){
		array[j] = array[j+1];
	}
	

	printf("\n");
	// praso x ir y (validacija)
	x = -1;
	y = -1;
	a = 0;
	
	printf("\n\ni(su nosine) ) Prasome ivesti 2 sveikus skaicius x ir y (reziai [0;9]), kur i masyva bus iterptas naujas elementas su reiksme y, kad po iterpimo jo indeksas butu x:\n");
	while(a == 0){
		printf("x: ");
		if (scanf("%d", &x) == 1 && x >= 0 && x < 10 && getchar() == '\n'){
			printf("x ivestis issaugota (x = %d)\n", x);
			++a;
		}else{
			printf("x ivestis neissaugota, neatitinka reziu [0;9], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}
	a = 0;
	printf("\nDabar prasome ivesti y ivesti:");
	while(a == 0){
		printf("\ny: ");
		if (scanf("%d", &y) == 1 && y >= 0 && y < 10 && getchar() == '\n'){
			printf("y ivestis issaugota (y = %d)\n", y);
			++a;
		}else{
			printf("y ivestis neissaugota, neatitinka reziu [0;9], prasome ivesti sveika skaiciu atitinkanti rezius.\n");
			while(getchar() != '\n')
				;
		}
	}

	
	//iterpia nauja y reiksme indeksu x
	for (int j = 9; j > (x - 1); --j){
		array[j] = array[j-1];
	}
	array[x] = y;
	
	
	//isvesits
	printf("\nPo visu ivedimu ir keitimu gautas masyvas:\n");
	
	for (int i = 0; i < 10; ++i){
		printf("%d", array[i]);
	}
	
	
	return 0;
}